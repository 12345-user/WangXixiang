
/*
 * File: RemoveComments.cpp
 * ------------------------
 * Prints out a file after removing comments.
 */
 // header file for local test
#include <iostream>
#include <iomanip>
//#include "csc300222fall/assignment1/RemoveComments.h" //for OJ
using namespace std;

#pragma GCC diagnostic ignored "-Wcomment"
/*
 * Function: removeComments
 * Usage: removeComments(is, os);
 * ------------------------------
 * Copies characters from the input stream is to the output stream os,
 * removing any comments it finds.  This program eliminates both the
 * /* and // comment forms but does not check to see if those characters
 * are embedded within strings.
 */

 //find all position of "//"
int* find1(string word, int* p) {
    int* List1 = new int[10];
    int start = 0;
    int pos = 0;
    int ret = word.find("//", start);
    while (ret != -1) {

        List1[pos] = ret;
        start = ret + 1;
        pos += 1;
        ret = word.find("//", start);
    }
    *p = pos;
    return List1;
}
//find all position of "/*"
int* find2(string word, int* p) {
    int* List2 = new int[10];
    int start = 0;
    int pos = 0;
    int ret = word.find("/*", start);
    while (ret != -1) {

        List2[pos] = ret;
        start = ret + 1;
        pos += 1;
        ret = word.find("/*", start);
    }
    *p = pos;
    return List2;
}
//find all position of "*/"
int* find3(string word, int* p) {
    int* List3 = new int[10];
    int start = 0;
    int pos = 0;
    int ret = word.find("*/", start);
    while (ret != -1) {

        List3[pos] = ret;
        start = ret + 1;
        pos += 1;
        ret = word.find("*/", start);
    }
    *p = pos;
    return List3;
}
//find all position of "\n"
int* find4(string word, int* p) {
    int* List4 = new int[10];
    int start = 0;
    int pos = 0;
    int ret = word.find("\n", start);
    while (ret != -1) {

        List4[pos] = ret;
        start = ret + 1;
        pos += 1;
        ret = word.find("\n", start);
    }
    *p = pos;
    return List4;
}
//删除a到b的字符串。
string DeleteS(string word, int a, int b) {
    for (int i = a; i < b; i++)
    {
        word[i] = '@';
    }
    return word;
}

void removeComments(istream& is, ostream& os) {
    //TODO
    char ch;
    string word;
    //cout << "Use # to finish the input" << endl;
    while (is.get(ch)) {
        if (ch == EOF or ch == '#') {
            break;
        }
        else
        {
            word.push_back(ch);
        }
    }
    int c1, c2, c3, c4;

    int* p2 = find2(word, &c2);
    int* p3 = find3(word, &c3);

    //for (int i = 0; i < c2; i++) {
        //cout << "/* Position:"<<p2[i] << endl;
    //}
    //for (int i = 0; i < c3; i++) {
        //cout << "*/ Position:"<<p3[i] << endl;
    //}


    //for "/*" and "*/"
    int last_pos = 0;
    for (int i = 0; i < c2; i++) {
        int cn2 = 1;
        for (int j = 0; j < c3; j++) {
            if (p2[i] < p3[j] and cn2 == 1 and p2[i]<p3[j] - 2 and p2[i]>last_pos) {
                word = DeleteS(word, p2[i], p3[j] + 2);
                //cout << "删除位置1：" << p2[i]<<','<< p3[j] + 1 << endl;
                cn2 = 0;
                last_pos = p3[j] + 2;
            }
        }
    }
    int* p1 = find1(word, &c1);
    int* p4 = find4(word, &c4);
    /*for (int i = 0; i < c1; i++) {
        cout << "// Postion: " << p1[i] << endl;
    }
    for (int i = 0; i < c4; i++) {
        cout << "Enter Position:" << p4[i] << endl;
    }
    */
    //for // and \n;
    for (int i = 0; i < c1; i++) {
        int cn1 = 1;
        for (int j = 0; j < c4; j++) {
            if (p1[i] < p4[j] and cn1 == 1) {
                word = DeleteS(word, p1[i], p4[j]);
                //cout << "删除位置2：" << p1[i] << ',' << p4[j] << endl;
                cn1 = 0;
            }
        }
    }
    //output:
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] != '@')
            os.put(word[i]);
    }
}

void TestRemoveComments() {
    removeComments(cin, cout);
}

// DO NOT modify the main() function
/*
 * sample output format:
 * input:  test file // this is a comment
           test file /* this is also a comment*/
           /* output: test file
                      test file
            */
int main(int argc, char* argv[]) {
    TestRemoveComments();
    return 0;
}
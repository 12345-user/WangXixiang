/* Q2:
 * File: FindDNAMatch.cpp
 * ----------------------
 * This file solves the DNA matching exercise from the text.
 */
 // header file for OJ system
 // #include <iostream>
 // #include <string>

 // using namespace std;

#include <iostream>
#include <string>

using namespace std;
//#include "csc300222fall/assignment1/RemoveComments.h" //for OJ
int is_correct(string a) {
    for (int i = 0; i < sizeof(a); i++) {
        if (a[i] == 'A' or a[i] == 'T' or a[i] == 'C' or a[i] == 'G') {
            return 1;
        }
        else
            return 0;
    }
}
/*
 * Function: findDNAMatch
 * Usage: int pos = findDNAMatch(s1, s2);
 *        int pos = findDNAMatch(s1, s2, start);
 * ---------------------------------------------
 * Returns the first index position at which strand s1 would bind to
 * the strand s2, or -1 if no such position exists.  If the start
 * parameter is supplied, the search begins at that index position.
 */
 //��startΪs2�Ŀ�ʼλ�ã����ʱ��������ж���ͬ��
 //��������ͬ����֤��������ԡ�
int findDNAMatch(string s1, string s2, int start) {
    // TODO
    int pos = 0;
    int Count = 0;
    int i = start;
    while (i < s2.length()) {
        if (s2[i] == s1[0]) {
            pos = i;
            int k = 0;
            while (k < s1.length()) {//����ƥ�䳤�Ȳ��ᳬ��s2���ܳ��ȡ�
                if (s1[k] == s2[i + k]) {
                    Count += 1;//�ӵ�һ�������Ժ�ÿ�ɹ�ƥ��һ�Σ�����һ��Cout, ��Cout����s1�ĳ�����ͬ����֤����ȫ��ͬ����ȫƥ�䡣
                }
                k++;
            }
        }
        i++;
        if (Count == s1.length()) {
            return pos;
        }
    }
    return -1;
}

/*
 * Function: matchingStrand
 * Usage: string match = matchingStrand(strand);
 * ---------------------------------------------
 * Returns a string in which each base has been replaced by its
 * counterpart base (C <-> G and A <-> T).  Any other characters
 * are replaced by an X.
 */

string matchingStrand(string strand) {
    // TODO
    int i = 0;
    while (i < strand.length()) {
        if (strand[i] == 'A') {
            strand[i] = 'T';
            i++;
        }
        if (strand[i] == 'T') {
            strand[i] = 'A';
            i++;
        }
        if (strand[i] == 'C') {
            strand[i] = 'G';
            i++;
        }
        if (strand[i] == 'G') {
            strand[i] = 'C';
            i++;
        }

    }
    return strand;
}

/*
 * Function: findAllMatches
 * Usage: findAllMatches(s1, s2);
 * ------------------------------
 * Finds all positions at which s1 can bind to s2.
 */

string findAllMatches(string s1, string s2) {
    // TODO
    if (is_correct(s1) == 0 or is_correct(s2) == 0) {
        cout << "Please enter the right string!" << endl;
        system("pause");
        return "";
    }
    else {
        //cout << "Right Enter!" << endl;
        string sn = s1;
        s1 = matchingStrand(s1);//ת��s1
        int* pos_Array = new int[10];
        int start_position = 0;
        int Count_number = 0;
        int ret = findDNAMatch(s1, s2, start_position);
        while (start_position < ((s2.length() - s1.length() + 1))) {//��֤ƥ��ʱ���ᳬ������

            if (ret == -1) {
                ret = findDNAMatch(s1, s2, start_position);
                start_position += 1;
            }
            else {
                pos_Array[Count_number] = ret;
                Count_number++;
                start_position = (ret + 1);
                ret = findDNAMatch(s1, s2, start_position);
            }
        }
        if (Count_number == 0) {
            cout << "There is no peoper posotion for s1." << endl;
        }
        else
            for (int i = 0; i < Count_number; i++) {
                cout << sn << " maches " << s2 << " at posotion ";
                cout << pos_Array[i] <<endl;
        }
        return "";


    }
}

// DO NOT modify the main() function
/*
 * sample output:
 * input:  TTGCC TAACGGTACGTC
 * output: TTGCC matches TAACGGTACGTC at position 1
*/
int main(int argc, char* argv[]) {
    string s1, s2;
    cin >> s1 >> s2;
    findAllMatches(s1, s2);
    return 0;
}
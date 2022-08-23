/*
크로아티아 알파벳
č:	c=
ć:	c-
dž:	dz=
đ:	d-
lj:	lj
nj:	nj
š:	s=
ž:	z=
단어가 주어졌을 때 몇 개의 크로아티아 알파벳으로 이루어졌는지 출력
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<string> croatia = {"c=", "c-", "dz=", "d-", "lj","nj","s=","z="};
    int index;
    string word;
    cin >> word;
    for(int i=0; i < croatia.size(); i++){
        while(true){
           index = word.find(croatia[i]);
           if(index == -1) break;
           word.replace(index,croatia[i].length(),"#"); 
        }
    }
    cout<<word.length();

    return 0;
}
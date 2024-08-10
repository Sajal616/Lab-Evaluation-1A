#include<iostream>
#include<sstream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<cctype>
using namespace std;
int main()
{
    string paragraph;
    unordered_map<char,int> mp;
    cout<<"Enter a paragraph: ";
    getline(cin,paragraph);
    for(char &it:paragraph)
    {
        it=tolower(it);
    }
    stringstream ss(paragraph);
    string word;
    while(ss>>word)
    {
        word.erase(remove_if(word.begin(),word.end(),::ispunct),word.end());
        for(char &it:word)
        {
            ++mp[it];
        }
    }
    cout<<"Frequencies of characters:"<<endl;
    for(const auto &it:mp)
    {
        cout<<it.first<<": "<<it.second<<endl;
    }
    return 0;
}

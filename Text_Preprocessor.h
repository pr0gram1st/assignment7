//
// Created by Adilet Kemelkhan on 09.11.2021.
//

#include <bits/stdc++.h>

using namespace std;

#ifndef ASSIGNMENT7_TEXT_PREPROCESSOR_H
#define ASSIGNMENT7_TEXT_PREPROCESSOR_H


class Text_Preprocessor{
private:
    string preprocessed_text;
    ifstream my_file;
public:
    Text_Preprocessor(char *name){
        cout << name << endl;
        my_file.open(name, ios::in);
        char ch;
        string x = "";
        string s;
        while(getline(my_file, s, '\0')){
            for(int i = 0; i < s.size(); ++i){
                char ch = s[i];
                x += ch;
            }
            if(my_file.eof()){
                break;
            }
        }
        this->preprocessed_text = x;
    }
    ~Text_Preprocessor(){
        my_file.close();
    }
    void preprocess_text(){
        string ans = "";
        string s = this->preprocessed_text;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] != ',' && s[i] != '"' && s[i] != '.' && s[i] != ';' && s[i] != ':' && s[i] != '!' && s[i] != '?'){
                if(isalpha(s[i])) {
                    ans += tolower(s[i]);
                }
                else{
                    ans += s[i];
                }
            }
        }
        string temp = "";
        string res = "";
        for(int i = 0; i < ans.size(); ++i){
            if(ans[i] == ' '){
                if(temp != "a" && temp != "an" && temp != "the" && temp != "in" && temp != "on"
                && temp != "at" && temp != "since" && temp != "for" && temp != "before" && temp != "ago" && temp != "to" && temp != "by"){
                    res += temp;
                    res += " ";
                }
                temp.clear();
            }
            else{
                temp += ans[i];
            }
        }
        if(temp != "a" && temp != "an" && temp != "the" && temp != "in" && temp != "on"
           && temp != "at" && temp != "since" && temp != "for" && temp != "before" && temp != "ago" && temp != "to" && temp != "by"){
            res += temp;
            res += " ";
        }
        temp.clear();
        this->preprocessed_text = res;
    }
    int search_word(const string& str){
        string s = this->preprocessed_text;
        string temp = "";
        int cur = 1;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '\n'){
                cur++;
                if(temp == str){
                    return cur;
                }
                temp.clear();
                continue;
            }
            if(s[i] == ' '){
                if(temp == str){
                    return cur;
                }
                temp.clear();
            }
            else{
                temp += s[i];
            }
        }
        if(temp == str){
            return cur;
        }
        return -1;
    }
    string getPreprocessed_text(){
        return this->preprocessed_text;
    }
};


#endif //ASSIGNMENT7_TEXT_PREPROCESSOR_H

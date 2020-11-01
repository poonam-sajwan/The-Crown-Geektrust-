//Geektrust problem
//https://www.geektrust.in/coding-problem/backend/tame-of-thrones

#include <bits/stdc++.h>
using namespace std;

class Southeros{

    unordered_map<string,string> KINGDOM;
    vector<int> freq;
    
    public:
    
    Southeros()
    {
        KINGDOM["LAND"]="PANDA";
        KINGDOM["WATER"]="OCTOPUS";
        KINGDOM["ICE"]="MAMMOTH";
        KINGDOM["AIR"]="OWL";
        KINGDOM["FIRE"]="DRAGON";
        
        for(int i=0;i<26;i++)
        freq.push_back(0);
    }
    
    //decrypt the secret message
    string decrypt(string secret,int cipher)
    {
        string secret_decrypted="";
        int n=secret.size();
        
        for(int i=0;i<n;i++)
        {
            if(secret[i]>='A' && secret[i]<='Z')
            {
                int curr=int(secret[i]-cipher);
                if(curr<65)
                curr+=26;
            
                secret_decrypted+=char(curr);    
            }
            
        }
        
        return secret_decrypted;
    }
    
    //If this king supports then return true
    bool check_support(string king,string secret)
    {
    	
        string emblem=KINGDOM[king];
        int n=emblem.size();
        
        string secret_decrypt=decrypt(secret,n);
        
        int m=secret_decrypt.size();
        
        // increase freq of secret char
        for(int i=0;i<n;i++)
        {
            int x=int(emblem[i])-65;
            freq[x]++;
        }
        
        //decrease freq for decrypted char
        for(int i=0;i<m;i++)
        {
            int x=int(secret_decrypt[i])-65;
            freq[x]--;
        }
        
        //if freq of char present is emblem is not 0, means freq of char in emblem != freq of char in decrypt, return false
        for(int i=0;i<n;i++)
        {
            int x=int(emblem[i])-65;
            if(freq[x]>0)
            return false;
        }
        
        return true;
    }
    
};


string helper(string line)
{
	Southeros s;
	
	int n=line.size(),i=0;
	string king="",secret="";
	
	//make the first word of line as the Kingdom name
	while(i<n && line[i]!=' ')
	king+=line[i++];
	
	//Rest of the line will be considered as secret message
	while(i<n)
	secret+=line[i++];
	
    bool flag=s.check_support(king,secret);

    if(flag)
    return king;
    
    return "";
}

int main() {
	
	 char choice;
	 
	 do{
	    string fileName;
     cout<<"Enter path"<<"\n";
     cin>>fileName;
    
    ifstream file(fileName);
    
    vector<string> supporters;
    supporters.push_back("SPACE");

    string line;
    while (getline(file,line))
    {
        string ans=helper(line);
        if(ans.size()>0)
        supporters.push_back(ans);
    }
    
    // if number of supporters is more than 3 apart from SPACE itself then Gorilla King of Space kingdom becomes king
    if(supporters.size()>3)
    {
        for(auto x: supporters)
        cout<<x<<" ";
        cout<<"\n";
    }
    else
    {
        cout<<"NONE";
    }	
    
    cout<<"\nPress y or Y to run again, any other key to exit  ";
    cin>>choice;
	 }
	 
	 while(choice=='y' || choice=='Y');
     
    return 0;
}

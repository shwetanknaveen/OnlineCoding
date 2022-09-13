//Problem link - https://leetcode.com/problems/utf-8-validation/

class Solution {
public:
    bool check10(int data)//this data byte starts with 10 or not
    {
        //Using 0b notation for binary number
        return ((data>>6)==0b10);//if we shift data 6 bits to right then only 10 should be left
    }
    int getSizeInByte(int data)
    {
        if(!(data&(1<<7))) return 1;//this is  1 byte encoding as it starts with 0
        
        //Now data starts with 1
        if(!(data&(1<<6))) return 0;//data can't start with 10
        
        //Now data starts with 11
        if(!(data&(1<<5))) return 2;//starts with 110
        
        //Now data starts with 111
        if(!(data&(1<<4))) return 3;//starts with 1110
        
        //Now data starts with 1111
        if(!(data&(1<<3))) return 4;//starts with 11110
        
        return 0;//encoding can't be greater than 4 bytes hence can't start with 11111...
    }
    bool validUtf8(vector<int>& data) 
    {
        for(int i=0;i<data.size();)
        {
            int size = getSizeInByte(data[i]);
            if(size==0) return false;
            if((i+size-1)>=data.size()) return false;//bytes ahead should exist
            int checkAhead = size-1;
            for(int ahead = 1;ahead<=checkAhead;ahead++)
            {
                if(!check10(data[i+ahead])) return false;
            }
            i=i+size;//skip all the bytes as per this number of bytes in this utf encoding
        }
        return true;
    }
};

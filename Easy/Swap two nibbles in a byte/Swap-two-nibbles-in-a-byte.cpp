/*
  Given a number n, Your task is to swap the two nibbles and find the resulting number. 

A nibble is a four-bit aggregation, or half an octet. There are two nibbles in a byte. For example, the decimal number 150 is represented as 10010110 in an 8-bit byte. This byte can be divided into two nibbles: 1001 and 0110.
  */

class Solution {
  public:
    int swapNibbles(int n) {
        // code here
        int left4 = n>>4;      
       
       int right4 = n & (15);
          right4 =right4 <<4 ;
      
      return left4 | right4 ;
    }
};

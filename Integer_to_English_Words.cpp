class Solution {
public:

string number_conversion(int number) {
    if (number == 1) return "One";
    if (number == 2) return "Two";
    if (number == 3) return "Three";
    if (number == 4) return "Four";
    if (number == 5) return "Five";
    if (number == 6) return "Six";
    if (number == 7) return "Seven";
    if (number == 8) return "Eight";
    if (number == 9) return "Nine";
    if (number == 10) return "Ten";
    if (number == 11) return "Eleven";
    if (number == 12) return "Twelve";
    if (number == 13) return "Thirteen";
    if (number == 14) return "Fourteen";
    if (number == 15) return "Fifteen";
    if (number == 16) return "Sixteen";
    if (number == 17) return "Seventeen";
    if (number == 18) return "Eighteen";
    if (number == 19) return "Nineteen";
    if (number >= 90) return "Ninety";
    if (number >= 80) return "Eighty";
    if (number >= 70) return "Seventy";
    if (number >= 60) return "Sixty";
    if (number >= 50) return "Fifty";
    if (number >= 40) return "Forty";
    if (number >= 30) return "Thirty";
    if (number >= 20) return "Twenty";
    return{};
}
 string numberToWords(int num) { 
     string str;
     if(num==0) {   
         str="Zero";
         return str;
     }  
     if(num/1000000000>0) {             
         int a=num/1000000000;
         str=numberToWords(a)+" Billion ";
         num=num-a*1000000000;
     }         
     if(num/1000000>0) {             
         int b=num/1000000;
         str=str+numberToWords(b)+" Million ";
         num=num-b*1000000;
     }         
     if(num/1000>0) {
         int c=num/1000;
         str=str+numberToWords(c)+" Thousand ";
         num=num-c*1000;        
     }         
     if(num/100>0) {
         int d=num/100; 
         str=str+number_conversion(d)+" Hundred ";
         num=num-d*100;
     }
     if(num>20) {
         int e=num/10;
         str=str+number_conversion(num); 
         if(num%10 != 0) {
             num=num-e*10;
             str=str+' '+number_conversion(num);
         }
     }
     else str=str+number_conversion(num);
     int last=str.size()-1; 
     if(str[last]==' '){             
         str.erase(last,1);
     }
return str;
}
};

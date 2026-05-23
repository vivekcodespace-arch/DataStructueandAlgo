//Beats 100%
class Solution {
public:
    string intToRoman(int num) {
        //count no. of thosand 
        string ans ="";

        for(int i=0;i<num/1000;i++){
            ans += "M";
        }
        num = num %1000;

        int hundreds = num/100;

        if(hundreds == 4){
            ans += "CD";
        }
        else if(hundreds == 9){
            ans += "CM";
        }
        else{
            if(hundreds >= 5){
                ans += "D";
                hundreds-=5;

                for(int i=0;i<hundreds;i++){
                    ans += "C";
                }
            }

            else{
                for(int i=0;i<hundreds;i++){
                    ans+="C";
                }
            }

        }
        num = num % 100;

        int tens = num/10;

        if(tens == 4){
            ans += "XL";
        }
        else if(tens == 9){
            ans += "XC";
        }
        else{
            if(tens >= 5){
                ans += "L";
                tens-=5;

                for(int i=0;i<tens;i++){
                    ans += "X";
                }
            }

            else{
                for(int i=0;i<tens;i++){
                    ans+="X";
                }
            }

        } 

        num = num % 10;

        

        if(num == 4){
            ans += "IV";
        }
        else if(num == 9){
            ans += "IX";
        }
        else{
            if(num >= 5){
                ans += "V";
                num-=5;

                for(int i=0;i<num;i++){
                    ans += "I";
                }
            }

            else{
                for(int i=0;i<num;i++){
                    ans+="I";
                }
            }

        }

        return ans;
    }
};

//Clean and intutuive app.
class Solution {
public:
    string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};

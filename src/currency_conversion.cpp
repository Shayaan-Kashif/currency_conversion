#include "currency_conversion.h"
#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

namespace CurrencyConversion {

string currency_conversion(double money){

    int dollars, cents, dollar_length, cents_length;
    string dollar_word, cents_word, dollars_result,cents_result, result;

    //Seperated the dollars and the cents 
    dollars  = floor(money);
    cents = round((money-dollars)*100);

    //Converted to strings
    dollar_word = to_string(dollars);
    cents_word  = to_string(cents);

    //Printing the number of cents in number form
    //cout<<"Dollars: "<<dollars<<endl;
    //cout<<"Cents: "<<cents<<endl<<endl;

    //Finding the length 
    dollar_length = dollar_word.length(); //max length of 6
    cents_length = cents_word.length(); // max length of 2

    //Calling functions 
    cents_result = Cents_To_Words(cents_word, cents_length);//Calling the cents to word function
    dollars_result = Dollars_To_Words(dollar_word, dollar_length);

    string dollar = "Dollar";
    string cent = "Cent";

    if(dollars_result != "One"){
        dollar = "Dollars";
       
    }

     if(cents_result != "One"){
        cent = "Cents";
       
    }


    result = dollars_result+" " +dollar+ " and "+cents_result+" "+ cent;
    return result;

    
    

 

}




string One_Word(string word){
    string word_amount;

    switch (word[0]){
        case '0':
            word_amount += "Zero";
            break;
        case '1':
            word_amount += "One";
            break;
        case '2':
            word_amount += "Two";
            break;

        case '3':
            word_amount += "Three";
            break;

        case '4':
            word_amount += "Four";
            break;

        case '5':
            word_amount += "Five";
            break;

        case '6':
            word_amount += "Six";
            break;

        case '7':
            word_amount += "Seven";
            break;

        case '8':
            word_amount += "Eight";
            break;
        case '9':
            word_amount += "Nine";
            break;
        
        default:
            cout<<"Amount not known 1";
            break;
        }

        return word_amount;// If the number is 0-9 cents only 

}


string Two_Word(string word, int word_length, bool forCents){

    string word_amount;//storing the entire result in this variable

    if(word_length == 1){

        return One_Word(word);

    }


    //If the first cent digit is equal to 1 then the pattern would fro from 10-19
    else if(word[0] == '1'){
        switch (word[1])
        {
        case '0':
            word_amount += "Ten";
            break;

        case '1':
            word_amount += "Eleven";
            break;
        
        case '2':
            word_amount += "Twelve";
            break;

        case '3':
            word_amount += "Thirteen";
            break;

        case '4':
            word_amount += "Fourteen";
            break;

        case '5':
            word_amount += "Fifteen";
            break;

        case '6':
            word_amount += "Sixteen";
            break;

        case '7':
            word_amount += "Seventeen";
            break;

        case '8':
            word_amount += "Eighteen";
            break;

        case '9':
            word_amount += "Ninteen";
            break;

        
        
        default:
            cout<<"Amount not known 2";
            break;
        }


    }

    //if the first digit is not 0 or 1 then it would follow the typical 
    if(word[0] != '0' && word[0] != '1'){

        //Putting the prefix for the first digit which would be 2-9
        switch (word[0])
        {
        case '2':
            word_amount += "Twenty";
            break;

        case '3':
            word_amount += "Thirty";
            break;

        case '4':
            word_amount += "Fourty";
            break;

        case '5':
            word_amount += "Fifty";
            break;

        case '6':
            word_amount += "Sixty";
            break;

        case '7':
            word_amount += "Seventy";
            break;

        case '8':
            word_amount += "Eighty";
            break;
        case '9':
            word_amount += "Ninty";
            break;
        
        default:
            cout<<"Amount not known 3";
            break;
        }

        if(forCents == true){
            word_amount += "-";
        }

        else{

            word_amount +=" ";
        }

        //Putting the prefix from 1-9 of the second digit 
        switch (word[1])
        {

        case '0':
            break;
        case '1':
            word_amount += "One";
            break;
        case '2':
            word_amount += "Two";
            break;

        case '3':
            word_amount += "Three";
            break;

        case '4':
            word_amount += "Four";
            break;

        case '5':
            word_amount += "Five";
            break;

        case '6':
            word_amount += "Six";
            break;

        case '7':
            word_amount += "Seven";
            break;

        case '8':
            word_amount += "Eight";
            break;
        case '9':
            word_amount += "Nine";
            break;
        
        default:
            cout<<"Amount not known 4";
            break;
        }//Switch statment ending 

    }//If statment ending 



return word_amount;//Returning the string 

}


string Three_Word(string dollar_word, int dollar_length){

    string dollar_word_amount;
    string hundreds;
    string hundred_word;
    string two_digits;
    string two_words;
    string dollars_results;

    int length;

    for(int i = 0; i <= dollar_length-1; i++){
            if(i==0){
                hundred_word = One_Word(dollar_word);
                hundreds = hundred_word+" Hundred";

            }

            else{
                two_digits += dollar_word[i];

            }

        }//For loop ending

        length = two_digits.length();
        two_words = Two_Word(two_digits,length,false);

        dollars_results = hundreds +" "+ two_words;

        return dollars_results;

}

/*Dollar function involves a sub function. The task of the sub-function is to determine 
what is the word amount between 00-99 dollars. How the overall function will work is that 
if the dollar amount is 238 then it will split it like 2 and 38 the 2 is in the hundreds place 
so the output will be 2 hundred the 38 would be sent to the sub-funtion. */


string Cents_To_Words(string cents_word, int cents_length){

 return Two_Word(cents_word,cents_length,true);

}



string Dollars_To_Words(string dollar_word, int dollar_length){

    string dollar_word_amount;
    string dollars_results;

    string thousand;
    string hundred;
    string word;
    string three_word;

    int length;
    int length2;


    if(dollar_length == 1 || dollar_length == 2){

       dollar_word_amount = Two_Word(dollar_word, dollar_length, false);

        return dollar_word_amount;

    }


    if(dollar_length == 3){

        dollar_word_amount = Three_Word(dollar_word, dollar_length);

        return dollar_word_amount;

    }

    else if(dollar_length == 4){

        for(int i = 0; i<=dollar_length-1; i++){

            if( i == 0){

                thousand = One_Word(dollar_word);

            }

            else{
                word += dollar_word[i];

            }

        }//For loop ending


        length  = word.length();
        dollars_results = Three_Word(word,length);

        dollar_word_amount = thousand+" Thousand "+dollars_results;

        return dollar_word_amount;

    }


    else if(dollar_length == 5){
        for(int i = 0; i<=dollar_length-1; i++){

            if(i<=1){
                word += dollar_word[i]; //will contain the first 2 numbers 
            }

            else{

                three_word += dollar_word[i];
            }

        }//For loop ending

        length = word.length();
        length2 = three_word.length();

        thousand = Two_Word(word, length,false)+" Thousand ";
        hundred = Three_Word(three_word,length2);

        dollar_word_amount = thousand+hundred;

        return dollar_word_amount;

    }

    else{

        for(int i = 0; i<=dollar_length-1; i++){

            if(i<=2){
                word += dollar_word[i]; //will contain the first 2 numbers 
            }

            else{

                three_word += dollar_word[i];
            }

        }//For loop ending

        length = word.length();
        length2 = three_word.length();

        thousand = Three_Word(word, length)+" Thousand ";
        hundred = Three_Word(three_word,length2);

        dollar_word_amount = thousand+hundred;

    return dollar_word_amount;

    }






}



}


#include "currency_conversion.h"
#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

namespace CurrencyConversion {

/*
The purpose of this function is to take in the intial input from the user and then split the dollar and cents amount
so they can easily be converted to words. After the amount has been spit it is converted to string and then spent into 
its correspoding function. This funtion will retrive th edollar word amount and cenrts word amount and then put them together 
and return it to the user.
*/
string currency_conversion(double money){

    //Inital varibales
    int dollars, cents, dollar_length, cents_length;
    string dollar_word, cents_word, dollars_result,cents_result, result;

    //Seperated the dollars and the cents 
    dollars  = floor(money);
    cents = round((money-dollars)*100);

    //Converted to strings
    dollar_word = to_string(dollars);
    cents_word  = to_string(cents);
    
    //Finding the length 
    dollar_length = dollar_word.length(); //max length of 6
    cents_length = cents_word.length(); // max length of 1 

    //Calling functions which convert dolalrs and cents to words and storing them into the variables below
    cents_result = Cents_To_Words(cents_word, cents_length);
    dollars_result = Dollars_To_Words(dollar_word, dollar_length);

    //Variables dollar and cent intialized to strings
    string dollar = "Dollar";
    string cent = "Cent";


    //The bottom two conditionals are used to determine if an "s" need to be added to the end of either dollar or cent
    if(dollars_result != "One"){
        dollar = "Dollars";
       
    }

     if(cents_result != "One"){
        cent = "Cents";
       
    }

    //In the result variable the returns of the previous funtions are retrived and the final output is assembled
    result = dollars_result+" " +dollar+ " and "+cents_result+" "+ cent;
    return result; //Returning the final output

}


/*
The purpose of this funtion is to identify the correct word for a single digit between 0-9.
*/
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

        return word_amount;//Returing the corresponding word for the digit provided  

}


/*
 The purpose of this funtion is to handle cases for 2 digit numbers to words. 
*/
string Two_Word(string word, int word_length, bool forCents){

    string word_amount;//storing the entire result in this variable

    //If the first digit is 1 then we check the second digit to handle the cases from 10-19
    if(word[0] == '1'){
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


/*
 The purpose of this funtion is to handle cases for 3 digit numbers to words. 
*/
string Three_Word(string dollar_word, int dollar_length){

    //Initial variables
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



/*
 The purpose of this funtion is to convert the number amount of cents to words. This is done by
 outsourceing the task the the Two_Word() function which can directly convert 2 digit numbers to words. 
*/
string Cents_To_Words(string cents_word, int cents_length){

    if(cents_length == 1){
        return One_Word(cents_word);
    }

    else{
        return Two_Word(cents_word,cents_length,true);
    }

}


/*
The purpose of the Dollars_To_Words() funtion is to take in the dollar number amount only and generate the dolalr word amount.
This is achived through checking the length of the number amount given and then using a combination of the 3 funtions which
handle converting the number amount to word for 1 to 3 digits. The example below showcases how this funtion utilizes
the other functions to break down larger numbers to easily convert them to words.

Example:
Dollar Amount: 3 --> One_Word()
Dollar Amount: 52 --> Two_Word()
Dollar Amount: 371 --> Three_Word()
Dollar Amount: 2853 --> One_Word() + Three_Word()
Dollar Amount: 62814 --> Two_Word() + Three_Word()
Dollar Amount: 842317 --> Three_Word() + Three_Word()
 */
string Dollars_To_Words(string dollar_word, int dollar_length){

    //Initial variables 
    string dollar_word_amount;
    string dollars_results;

    string thousand;
    string hundred;
    string word;
    string three_word;

    int length;
    int length2;


    //Handles 1 digit numbers 
    if(dollar_length == 1){

        dollar_word_amount = One_Word(dollar_word);

        return dollar_word_amount;

    }


    //Handles 2 digit numbers
    if(dollar_length == 2){

       dollar_word_amount = Two_Word(dollar_word, dollar_length, false);

        return dollar_word_amount;

    }//End of if statment

    //Handles 3 digits numbers
    if(dollar_length == 3){

        dollar_word_amount = Three_Word(dollar_word, dollar_length);

        return dollar_word_amount;

    }//End of if statment 

    //Handles 4 digit numbers
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

    }//End of Else if statment

    //Handles 5 digit numbers
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

    }//End of else if statment

    //Handles 6 digit numbers
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

    }//End of else statment

}//End of function



}//End of namespace


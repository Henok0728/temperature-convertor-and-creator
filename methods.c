#include <ctype.h>
#include <stdio.h>
#include <strings.h>
// temperature conversion program
float kelvin_and_celsius(float temperature,char degree);
float kelvin_and_farenheight(float temperature,char degree);
float farenheight_and_celsius(float temperature,char degree);
void temperature_scale_converter();
void temperature_scale_creator();
float customtemp_and_kelvin(float temperature,float high,float low, char degree);
float customtemp_and_farenheight(float temperature,float high , float low ,char degree);
float customtemp_and_celsius(float temperature,float high,float low,char degree);


// main build
int main(){
    char choose;
    printf("**********************************************************************\n");
    printf("Temperature converter and creator project by Henok Gizaw using c 2025\n");
    printf("**********************************************************************\n");
    printf("\nWhat do u want to do:\n a.Create custom temperature     b. Convert temperature\n: ");
    scanf("%c",&choose);
    if (choose == 'a'){
        temperature_scale_creator();

    }
    else if (choose == 'b'){
        temperature_scale_converter();
    }

    else{
        printf("seems I don't know what you want!\n");
    }

}
// the functions block
float kelvin_and_celsius(float temperature,char degree){
    float kelvin;
    float celsius;
    float new_temp;
    if (degree == 'C'){
        kelvin = temperature;
        celsius = kelvin - 273;
        new_temp =celsius;
    }
    else if (degree == 'K'){
        celsius = temperature;
        kelvin = celsius + 273;
        new_temp = kelvin;

    }
    return new_temp;
    }
float kelvin_and_farenheight(float temperature,char degree){
    float kelvin;
    float farenheight;
    float new_temp;
    if (degree == 'F'){
        kelvin = temperature;
        farenheight = (9/(float)5)*(kelvin-273) + 32;
        new_temp = farenheight;
    }
    else if (degree == 'K'){
        farenheight = temperature;
        kelvin = (5/(float)9)*(farenheight-32)+273;
        new_temp = kelvin;
    }
    return new_temp;
    }
float farenheight_and_celsius(float temperature,char degree){
    float new_temp ;
    float farenheight;
    float celsius;
    if (degree == 'F'){
        celsius = temperature;
        farenheight = (9/(float)5)*(celsius)+ 32;
        new_temp = farenheight;
    }
    else if (degree == 'C'){
        farenheight = temperature;
        celsius = (5/(float)9)*(farenheight-32);
        new_temp = celsius;

    }
    return new_temp;
}
float customtemp_and_kelvin(float temperature,float high,float low, char degree){
    float custom_temp;
    float kelvin;
    if (degree == 'K'){
        custom_temp = temperature;
        kelvin = (custom_temp - low)/(float)(high-low)*100 + 273;
        temperature = kelvin;
    }
    else{
        kelvin = temperature;
        custom_temp = ((high - low)/(float)100)*(kelvin - 273) + low;
        temperature = custom_temp;
    }
    return temperature;
}
float customtemp_and_celsius(float temperature,float high,float low,char degree){
    float custom_temp;
    float celsius;
    if (degree == 'C'){
        custom_temp = temperature;
        celsius = (100)/(float)(high - low)*(custom_temp - low);
        temperature = celsius;

    }
    else{
        celsius = temperature;
        custom_temp = (high - low)/(float)100*celsius + low;
        temperature = custom_temp;
    }
    return temperature;
}
float customtemp_and_farenheight(float temperature,float high , float low ,char degree){
    float custom_temp;
    float farenheight;
    if (degree == 'F'){
        custom_temp = temperature;
        farenheight = 180*(custom_temp - low)/(high-low) + 32;
        temperature = farenheight;
    }
    else{
        farenheight = temperature;
        custom_temp =  (high - low)/180 *(farenheight - 32) + low;
        temperature = custom_temp;
    }
    return temperature;


}
void temperature_scale_converter(){
    float convert_to;
    float converted;
    char degree;// sign of the degree
    char given;
    char convert;
    printf("Enter the given temperature: ");
    scanf("%f",&convert_to);
    scanf("%c",&given);
    printf("\nEnter the measured degree of the temperature:\n a. Kelvin    b. Celsius   c. Farenheit  \n: ");
    scanf("%c",&given);
    if (given == 'a'){// given in kelvin
        scanf("%c",&convert);
        printf("Enter a temperature you want to convert:\n");
        printf("    a. Celsius    b. Farenheit  \n: ");
        scanf("%c",&convert);
        if (convert == 'a'){
            degree = 'C';
            converted = kelvin_and_celsius( convert_to, degree);
        }
        else{
            degree = 'F';
            converted = kelvin_and_farenheight(convert_to, degree);
        }

    }
    else if (given == 'b'){// given in celsius
        scanf("%c",&convert);
        printf("Enter a temperature you want to convert:\n");
        printf("     a. kelvin    b. farenheight \n: ");
        scanf("%c",&convert);
        if (convert == 'a'){
            degree = 'K';
            converted = kelvin_and_celsius( convert_to, degree);

        }
        else{
            degree = 'F';
            converted = farenheight_and_celsius(convert_to, degree);

        }
    }
    else {// given is in farenheight
        scanf("%c",&convert);
        printf("Enter a temperature you want to convert\n");
        printf("     a. kelvin    b. celsius \n: ");
        scanf("%c",&convert);
        if (convert == 'a'){
            degree = 'K';
            converted = kelvin_and_farenheight( convert_to, degree);

        }
        else{
            degree = 'C';
            converted = farenheight_and_celsius(convert_to, degree);

        }
    }
    printf("The converted temperature = %.2f %c\n",converted,degree);
    printf("***************************************************************\n");
}
void temperature_scale_creator(){
    char custom_name[60];
    char custom_unit;
    float custom_high;
    float custom_low;
    printf("\n***************************************************************\n");
    printf("Custom Temperature scale creator\n");
    printf("***************************************************************\n");
    printf("Name your temperature scale: ");
    fgets(custom_name,60, stdin);
    printf("enter the custom unit of your temperature scale\n: ");
    scanf("%c",&custom_unit);
    printf("Enter the boiling point of the water in your custom temperature scale\n: ");
    scanf("%f",&custom_high);
    printf("Enter the freezing point of the water in your custom temperature scale\n: ");
    scanf("%f",&custom_low);
    printf("Your temperature is successfully created\bHere are the measurements of your custom temperature\n");
    printf("***************************************************************\n");
    printf("%s to Kelvin  => 1 %c = %.2f K\n",custom_name,custom_unit,customtemp_and_kelvin(1,custom_high,custom_low,'K'));
    printf("%s to Farenheight => 1 %c = %.2f F\n",custom_name,custom_unit,customtemp_and_farenheight(1,custom_high,custom_low,'F'));
    printf("%s to Celsius => 1 %c = %.2f C \n",custom_name,custom_unit,customtemp_and_celsius(1,custom_high,custom_low,'C'));
    printf("***************************************************************\n");

}

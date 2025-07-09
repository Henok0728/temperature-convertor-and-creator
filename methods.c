#include <stdio.h>
// temperature conversion program
float kelvin_and_celsius(float temperature,char degree);
float kelvin_and_farenheight(float temperature,char degree);
float farenheight_and_celsius(float temperature,char degree);
void temperature_converter();
// main build
int main(){
    char choose;
    printf("***************************************************************\n");
    printf("   Temperature converter and creator project by Henok Gizaw using c 2025\n");
    printf("***************************************************************\n");
    printf("\n What do u want to do:\n a.Create custom temperature     b. Convert temperature\n");
    scanf("%c",&choose);
    if (choose == 'a'){
        temperature_converter();
    }
    else{

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
void temperature_converter(){

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
        // switch(convert){
        //     case 'a':// kelvin to celsius
        //         degree = 'C';
        //
        //     case 'b':// kelvin to farenheight
        // degree = 'F';
        // converted = kelvin_and_farenheight(convert_to, degree);
        //
        // }
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
        // switch(convert){
        //     case 'a':// celsius to kelvin
        //         degree = 'K';
        //         converted = kelvin_and_celsius( convert_to, degree);
        //     case 'b':// celsius to farenheight
        //         degree = 'F';
        //         converted = farenheight_and_celsius(convert_to, degree);
        // }
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
        // switch(convert){
        //     case 'a':// farenheight to kelvin

        //     case 'b':// farenheight to celsius
        //         degree = 'C';
        //         converted = farenheight_and_celsius(convert_to, degree);
        // }
    }
    printf("The converted temperature = %.2f %c\n",converted,degree);
    printf("***************************************************************\n");
}
void temperature_creator(){
    printf("\n***************************************************************\n");
    printf("Custom Temperature creator\n");
    printf("***************************************************************\n");


}

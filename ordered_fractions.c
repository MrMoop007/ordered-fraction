#include <stdio.h>

//returns the greatest fraction less than a/b with a denominator of z
//may return an improper fraction that needs to be simplified
int fraction_less_than(float a, float b, float z){
    float numerator = 1.0;
    int previous_numerator;
    float value = a/b;
    float fraction = numerator/z;
    //we now iterate through 1/z, 2/z, etc. to find the greatest possible fraction
    while(fraction < value+1){
        if(fraction >= value){
            return previous_numerator;
        }
        else{
            previous_numerator = numerator;
            numerator++;
            fraction = numerator/z;
        }
    }
}

//we now need to vary the denominator from d, d-1, d-2... 3, 2, 1 and keep track of the smallest value as we do
int vary_fraction_denominator(int d){
    int best_numerator = fraction_less_than(3, 7, d);
    float greatest_value = best_numerator/d;
    int current_numerator;
    float current_value;
    int i;
    int denominator;
    //we start at the maximum value as the fraction is likely to have a large denominator
    for(i = d; i>0; i--){
        current_numerator = fraction_less_than(3, 7, i);
        current_value = (float)current_numerator/i;
        if(current_value > greatest_value){
            greatest_value = current_value;
            best_numerator = current_numerator;
            denominator = i;
            printf("The best guess so far of the numerator is %d\n", best_numerator);
            printf("With a denominator of %d\n", denominator);
        }
        if(i%10000==0){printf("Progress to completion: %d out of %d\n", d-i, d);}
    }
    printf("The best numerator is %d\n", best_numerator);
    printf("With a denominator of %d\n", denominator);
}

int main(){
    vary_fraction_denominator(1000000);
    return 1;
}
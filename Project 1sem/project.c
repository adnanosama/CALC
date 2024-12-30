#include <stdio.h>
#include <malloc.h>

void integrationByParts(double u_coeff, double u_power, double v_coeff, double v_power) {
    double u_final_coeff = u_coeff * u_power;
    double u_final_power = u_power - 1;

    double v_int_coeff = v_coeff / (v_power + 1);
    double v_int_power = v_power + 1;

    double uv_coeff = u_coeff * v_int_coeff;
    double uv_power = u_power + v_int_power;

    double u_final_v_coeff = u_final_coeff * v_int_coeff;
    double u_final_v_power = u_final_power + v_int_power;

    printf("u(x)v(x) = %.1lfx^%.1lf\n", uv_coeff, uv_power);
    printf("- ∫ u'(x)v(x) dx = - %.1lfx^%.1lf + C\n", u_final_v_coeff, u_final_v_power);
    printf("Final Integration is: %.1lfx^%.1lf - %.1lfx^%.1lf + C\n",uv_coeff, uv_power,u_final_v_coeff, u_final_v_power);
}

void powerRuleIntegration(double coefficient, double power) {
    if (power != -1) { 
        double newCoefficient = coefficient / (power + 1);
        double newPower = power + 1;
        printf("The integral using the Power Rule is: %.01fx^%.01f + C\n", newCoefficient, newPower);
    } else {
        printf("The integral of 1/x is ln|x| + C\n");
    }
}

void productRuleIntegration(double a, double p, double b) {

    double newCoefficient = a * b / (p + 1);
    double newPower = p + 1;
    printf("The integral using the Product Rule is: %.01fx^%.01f + C\n", newCoefficient, newPower);
}

void trigonometricIntegration(char trigFunc) {
    if (trigFunc == 's') {
        printf("The integral of sin(x) is -cos(x) + C\n");
    } else if (trigFunc == 'c') {
        printf("The integral of cos(x) is sin(x) + C\n");
    } else if (trigFunc == 't') {
        printf("The integral of tan(x) is ln|sec(x)| + C\n");
    } else if (trigFunc == 'S') {
        printf("The integral of sec(x) is ln|sec(x) + tan(x)| + C\n");
    } else if (trigFunc == 'T') {
        printf("The integral of cot(x) is ln|sin(x)| + C\n");
    } else if (trigFunc == 'C') {
        printf("The integral of cosec(x) is -ln|cosec(x) + cot(x)| + C\n");
    } else {
        printf("Invalid trigonometric function.\n");
    }
}

void powerRule(double coefficient, double power) {
    double newCoefficient = coefficient * power;
    double newPower = power - 1;
    printf("The derivative using the Power Rule is: %.01fx^%.01f\n", newCoefficient, newPower);
}

void productRule(double a, double p, double b, double q) {

    double u_final = a * p;
    double u_final_v = u_final * b;
    double u_final_v_exp = p - 1 + q;

    double v_final = b * q;
    double uv_final = v_final * a;
    double uv_final_exp = q - 1 + p;

    printf("The derivative using the Product Rule is: %.01fx^%.01f + %.01fx^%.01f\n", 
           u_final_v, u_final_v_exp, uv_final, uv_final_exp);
}

void quotientRule(double a, double p, double b, double q) {
    double u_final = a * p;
    double v_final = b * q;

    double numerator_coeff1 = u_final * b; // u'v
    double numerator_coeff2 = v_final * a; // uv'
    double numerator_exp = (p - 1) + q;

    double denominator_coeff = b * b; // v^2
    double denominator_exp = 2 * q;

    printf("The derivative using the Quotient Rule is: (%.1lfx^%.1lf - %.1lfx^%.1lf) / %.1lfx^%.1lf\n", 
           numerator_coeff1, numerator_exp, numerator_coeff2, numerator_exp, denominator_coeff, denominator_exp);
}

void trigonometricRule(char trigFunc) {
    if (trigFunc == 's') {
        printf("The derivative of sin(x) is cos(x)\n");
    } else if (trigFunc == 'c') {
        printf("The derivative of cos(x) is -sin(x)\n");
    } else if (trigFunc == 't') {
        printf("The derivative of tan(x) is sec^2(x)\n");
    } else if (trigFunc == 'T') {
        printf("The derivative of cot(x) is -csc^2(x)\n");
    } else if (trigFunc == 'S') {
        printf("The derivative of sec(x) is sec(x)tan(x)\n");
    } else if (trigFunc == 'C') {
        printf("The derivative of csc(x) is -csc(x)cot(x)\n");
    } else {
        printf("Invalid trigonometric function.\n");
    }
}

void polynomialDerivative(int n, double *coefficients, double *powers) {
    printf("The derivative of the polynomial is: ");
    for (int i = 0; i < n; i++) {
        if (powers[i] != 0) {
            double new_coeff = coefficients[i] * powers[i];
            double new_power = powers[i] - 1;

            if (i > 0 && new_coeff > 0) {
                printf("+ ");
            }

            if (new_power == 0) {
                printf("%.1lf ", new_coeff);
            } else if (new_power == 1) {
                printf("%.1lfx ", new_coeff);
            } else {
                printf("%.1lfx^%.1lf ", new_coeff, new_power);
            }
        }
    }
    printf("\n");
}

void main() {
    int choice;
    while (1) {
        printf("Choose from the options below:\n");
        printf("1. Integral\n");
        printf("2. Derivative\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            break;
        }

        switch (choice) {
        case 1: {
            int i;
            printf("Which type of integration do you want:\n");
            printf("1. Power Rule Integration\n");
            printf("2. Product Rule Integration\n");
            printf("3. Trigonometric Integration\n");
            printf("4. By Parts Integration\n");
            printf("Enter your choice: ");
            scanf("%d", &i);

            switch (i) {
            case 1: {
                double coefficient, power;
                printf("You chose Power Rule Integration.\n");
                printf("Enter coefficient and power of x (e.g., for 5x^3, enter 5 3): ");
                scanf("%lf %lf", &coefficient, &power);
                powerRuleIntegration(coefficient, power);
                break;
            }
            case 2: {
                double a, p, b;
                printf("You chose Product Rule Integration.\n");
                printf("Enter coefficient of first term, power of x, and constant multiplier (e.g., for 5x^2 * 3, enter 5 2 3): ");
                scanf("%lf %lf %lf", &a, &p, &b);
                productRuleIntegration(a, p, b);
                break;
            }
            case 3: {
                char trigFunc;
                printf("You chose Trigonometric Integration.\n");
                printf("Enter the trigonometric function (s for sin, c for cos, t for tan, S for sec, T for cot, C for cosec): ");
                scanf(" %c", &trigFunc);
                trigonometricIntegration(trigFunc);
                break;
            }
            case 4:{
                double u_coeff, u_power, v_coeff, v_power;
                printf("You chose Integration by Parts.\n");
                printf("Enter the coefficient and power of u(x) (e.g., for 5x^3, enter 5 3): ");
                scanf("%lf %lf", &u_coeff, &u_power);

                printf("Enter the coefficient and power of v'(x) (e.g., for 4x^2, enter 4 2): ");
                scanf("%lf %lf", &v_coeff, &v_power);

                integrationByParts(u_coeff, u_power, v_coeff, v_power);
                break;
            }
            default:
                printf("Invalid choice.\n");
                break;
            }
            break;
        }
        case 2: {
            int d;
            printf("Which type of derivation do you want:\n");
            printf("1. Power Rule Differentiation\n");
            printf("2. Product Rule Differentiation\n");
            printf("3. Trigonometric Differentiation\n");
            printf("4. Quotient Rule Differentiation\n");
            printf("5. Polynomial Differentiation\n");
            printf("Enter your choice: ");
            scanf("%d", &d);

            switch (d) {
            case 1: {
                double coefficient, power;
                printf("You chose Power Rule Differentiation.\n");
                printf("Enter coefficient and power of x (e.g., for 5x^3, enter 5 3): ");
                scanf("%lf %lf", &coefficient, &power);
                powerRule(coefficient, power);
                break;
            }
            case 2: {
                double a, b, p, q;
                printf("You chose Product Rule Differentiation.\n");
                printf("Enter coefficients and powers of two terms (e.g., for 5x^2 * 3x^3, enter 5 2 3 3): ");
                scanf("%lf %lf %lf %lf", &a, &p, &b, &q);
                productRule(a, p, b, q);
                break;
            }
            case 3: {
                char trigFunc;
                printf("You chose Trigonometric Differentiation.\n");
                printf("Enter the trigonometric function (s for sin, c for cos, t for tan, S for sec, T for cot, C for cosec): ");
                scanf(" %c", &trigFunc);
                trigonometricRule(trigFunc);
                break;
            }
            case 4: {
                double c, d, e, f;
                printf("You chose Quotient Rule Differentiation.\n");
                printf("Enter coefficients and powers of numerator and denominator terms (e.g., for 6x^3 / 5x^2, enter 6 3 5 2): ");
                scanf("%lf %lf %lf %lf", &c, &d, &e, &f);
                quotientRule(c, d, e, f);
                break;
            }
            case 5: {
                int n;
                printf("You chose Polynomial Differentiation.\n");
                printf("Enter the number of terms in the polynomial: ");
                scanf("%d", &n);

                if (n <= 0) {
                    printf("Invalid number of terms.\n");
                    break;
                }

                double *coefficients = (double *)malloc(n * sizeof(double));
                double *powers = (double *)malloc(n * sizeof(double));

                if (coefficients == NULL || powers == NULL) {
                    printf("Memory allocation failed.\n");
                    break;
                }

                printf("Enter the coefficients and powers of each term (e.g., for 6x^3, enter 6 3):\n");
                for (int i = 0; i < n; i++) {
                    printf("Term %d: ", i + 1);
                    scanf("%lf %lf", &coefficients[i], &powers[i]);
                }

                polynomialDerivative(n, coefficients, powers);

                free(coefficients);
                free(powers);
                break;
            }
            default:
                printf("Invalid choice.\n");
                break;
            }
            break;
        }
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
}




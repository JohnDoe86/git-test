/* ******CASE FROM STANDARD******. */

/// Noncompliant code example
#define NONCOMPLIANT_CUBE(I) (I * I * I) //#defect#CERT PRE01-C
int a = 81 / NONCOMPLIANT_CUBE(2 + 1);

/// Compliant code example
#define COMPLIANT_CUBE(I) ( (I) * (I) * (I) ) //#nodefect#CERT PRE01-C
int b = 81 / COMPLIANT_CUBE(2 + 1);

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// compile with gcc hexmodel.c -lm

int main(int argc, const char *argv[])
{
	// please pass day number query on
	// command line to run model
	// 353 Nov 20th 2020 00:00 UTC
	int u = atoi(argv[1]);

	// eth price on Dec 4th 2019 open
	double a = 142.92;
	
	// hex per eth on Dec 4th 2019 open
	double b = 47584;
	
	// multiplier to reach market equiv
	double c = 1.3;
	
	// eth price on May 14th 2020 open
	double e = 198.89;
	
	// hex per eth on May 14th 2020 open
	double f = 23905;
	
	// time between dec 4th 2019 open
	// and may 14th 2020 open in days
	double t = 162;
	
	// calculate factors for
	// finding slope. when using semi-log
	// chart, only y is log
	double r1 = log(a/(b*c));
	double r2 = log(e/(f*c));

	// calculate slope
	double s = (r1 - r2)/(t * -1);
	
	// solve for y using exp and
	// equation log(y) = log(a) + bx
	double y = exp(r1 + (s*u));

	printf("%lf\n", y);

	return 0;
}

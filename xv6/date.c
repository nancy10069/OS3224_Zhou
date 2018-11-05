#include "types.h"
#include "user.h"
#include "date.h"

int
main(int argc, char *argv[])
{
	struct rtcdate r;

	if (date(&r)) {
		printf(2, "date failed\n");
		exit();
	}

  // your code to print the time in any format you like...
	r.hour -= 5;

	if((int)r.hour < 0){
		r.day -= 1;
		r.hour += 24;
	}


	if(r.day == 0){
		r.month -= 1;
		if(r.month == 0 || r.month == 1 || r.month == 3 || r.month == 5 ||
			r.month == 7 || r.month == 8 || r.month == 10){
			r.day = 31;
			}
		else if(r.month == 4 || r.month == 6 || r.month == 9 || r.month == 11){
			r.day = 30;
		}
		else{
			if((r.year % 4 == 0 && r.year % 100 != 0) || r.year % 400 == 0) r.day = 29;
			else r.day = 28;
		}
	}

	if(r.month == 1){
		r.month += 12;
		r.year -= 1;
	}

	printf(1, "%d-%d-%d %d:%d:%d\n",
	r.year, r.month, r.day, r.hour, r.minute, r.second);

	exit();
}

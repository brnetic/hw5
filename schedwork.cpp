

#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
// add or remove necessary headers as you please
#include "schedwork.h"

using namespace std;

// a constant that can be used to indicate an INVALID 
// worker ID if that is useful to your implementation.
// Feel free to not use or delete.
static const Worker_T INVALID_ID = (unsigned int)-1;


// Add prototypes for any helper functions here

bool scheduleHelper(const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sched, int day);
bool check(const size_t maxShifts,
    DailySchedule& sched, int id);
// Add your implementation of schedule() and other helper functions here

bool schedule(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sched
)
{
    if(avail.size() == 0U){
        return false;
    }
    sched.clear();
    // Add your code below

    for(int i = 0;i<avail.size();i++){
        sched.push_back(vector<Worker_T>());
    }
    return scheduleHelper(avail,dailyNeed,maxShifts,sched,0);
    



}
bool scheduleHelper(const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sched, int day)
{
    if(day == avail.size()){
        return true;
    }
    if(sched[day].size() >= dailyNeed){
        return scheduleHelper(avail,dailyNeed,maxShifts,sched,day+1);
    }


    for(int i = 0;i<avail[day].size();i++){
        if(avail[day][i]){
            sched[day].push_back(i);
            if(check(maxShifts,sched,i)){
                if(scheduleHelper(avail,dailyNeed,maxShifts,sched,day)){
                    return true;
                }
            }
            sched[day].pop_back();

        }
    }
    return false;


}

bool check(const size_t maxShifts,
    DailySchedule& sched, int id)
{
    int br = 0;
    for(int i = 0;i<sched.size();i++){
			int br2 = 0;
        for(int j = 0;j<sched[i].size();j++){
            if(sched[i][j] == id){
                br++;
								br2++;
						}
        }
				if(br2>1){
					return false;
				}
    }
    return br <= maxShifts;
}

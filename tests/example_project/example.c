/* This C program based on code found inside the Linux kernel job scheduler version 6.1 and is
 * used as the motivating example in the SAILR paper from USENIX 2024. Compile it using:
 * 
 * gcc -fno-inline -O2 motivating_example.c -o motivating_example; strip --strip-debug motivating_example
 * 
 * This will enable O2 optimizations, which have Jump Threading, and cause the function schedule_job
 * to have at least two gotos in the output and a duplication call to refresh_jobs. 
 */ 

#include <stdio.h>


int EXTRA_RUN = 3;
int EARLY_EXIT = 4;

int next_job() {
    puts("next_job");
    return 1;
}

int refresh_jobs() {
    puts("refresh_jobs");
    return 2;
}

int fast_unlock() {
    puts("fast_unlock");
    return 4;
}

int complete_job() {
    puts("checking...");
}

void log_workers() {
    puts("log_workers");
}

int job_status(int stats) {
    puts("job_status");
    return stats;
}

int schedule_job(int needs_next, int fast_job, int mode)
{
    if (needs_next && fast_job) {
        complete_job();
        if (mode == EARLY_EXIT) 
            goto cleanup;

        next_job();
    }

    refresh_jobs();
    if (fast_job)
        fast_unlock();
    
cleanup:
    complete_job();
    log_workers();
    return job_status(fast_job);
} 

int main(int argc, char** argv)
{
    return schedule_job(argv[0][0], argv[1][0], argv[2][0]);  
}


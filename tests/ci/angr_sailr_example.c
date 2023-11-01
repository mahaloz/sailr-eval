void complete_job() {
    unsigned long long v1;  // rax

    v1 = puts("checking...");
    return;
}

void next_job() {
    unsigned long long v1;  // rax

    puts("next_job");
    v1 = 1;
    return;
}

void refresh_jobs() {
    unsigned long long v1;  // rax

    puts("refresh_jobs");
    v1 = 2;
    return;
}

void fast_unlock() {
    unsigned long long v1;  // rax

    puts("fast_unlock");
    v1 = 4;
    return;
}

void log_workers() {
    unsigned long long v1;  // rax

    v1 = puts("log_workers");
    return;
}

long long schedule_job(unsigned long a0, unsigned long long a1, unsigned long a2) {
    if (a0 && a1) {
        complete_job();
        if (EARLY_EXIT == a2)
            goto LABEL_4000eb;
        next_job();
    }
    refresh_jobs();
    if (a1 || a1)
        fast_unlock();
LABEL_4000eb:
    complete_job();
    log_workers();
    return job_status(a1);
}

long long job_status(unsigned long a0) {
    puts("job_status");
    return a0;
}

int main(unsigned long a0, struct struct_0 *a1[3]) {
    return schedule_job(a1[0]->field_0, a1[1]->field_0, a1[2]->field_0);
}


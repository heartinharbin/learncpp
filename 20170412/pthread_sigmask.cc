 ///
 /// @file    pthread_sigmask.cc
 /// @author  heartinharbin
 /// @date    2017-04-13 14:12:54
 ///
 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <iostream>
using std::cout;
using std::endl;

#define handle_error_en(en, msg) \
	do {errno = en; perror(msg); exit(EXIT_FAILURE);}  while(0)

static void *sig_thread(void *arg){
	sigset_t *set = (sigset_t *) arg;
	int ret, sig;
	for(;;){
		ret = sigwait(set, &sig);
		if(ret != 0)
			handle_error_en(ret, "sigwait");
		printf("Signal handling thread got signal %d\n", sig);
	}
}



int main(int argc, char * argv[]){
	pthread_t id;
	sigset_t set;
	int ret;

	sigemptyset(&set);
	sigaddset(&set, SIGQUIT);
	sigaddset(&set, SIGUSR1);
	ret = pthread_sigmask(SIG_BLOCK, &set, NULL);
	if(ret != 0){
		handle_error_en(ret, "pthread_sigmask");
	}

	ret = pthread_create(&id, NULL, &sig_thread, (void *) &set);
	if(ret != 0){
		handle_error_en(ret, "pthread_create");
	}
	pause();
	return 0;
}

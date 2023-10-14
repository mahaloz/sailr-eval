



















struct option
{
  const char *name;


  int has_arg;
  int *flag;
  int val;
};









       




typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;






typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;



typedef long int __quad_t;
typedef unsigned long int __u_quad_t;







typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;


typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;

typedef int __daddr_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void * __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;


typedef long int __fsword_t;

typedef long int __ssize_t;


typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;



typedef __off64_t __loff_t;
typedef char *__caddr_t;


typedef long int __intptr_t;


typedef unsigned int __socklen_t;




typedef int __sig_atomic_t;



typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;


typedef __loff_t loff_t;




typedef __ino_t ino_t;






typedef __ino64_t ino64_t;




typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;





typedef __off_t off_t;






typedef __off64_t off64_t;




typedef __pid_t pid_t;





typedef __id_t id_t;




typedef __ssize_t ssize_t;





typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;










typedef __clock_t clock_t;







typedef __clockid_t clockid_t;
typedef __time_t time_t;






typedef __timer_t timer_t;



typedef __useconds_t useconds_t;



typedef __suseconds_t suseconds_t;





typedef long unsigned int size_t;



typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;




typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;


typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;


typedef int register_t __attribute__ ((__mode__ (__word__)));
static __inline __uint16_t
__bswap_16 (__uint16_t __bsx)
{

  return __builtin_bswap16 (__bsx);



}






static __inline __uint32_t
__bswap_32 (__uint32_t __bsx)
{

  return __builtin_bswap32 (__bsx);



}
__extension__ static __inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{

  return __builtin_bswap64 (__bsx);



}
static __inline __uint16_t
__uint16_identity (__uint16_t __x)
{
  return __x;
}

static __inline __uint32_t
__uint32_identity (__uint32_t __x)
{
  return __x;
}

static __inline __uint64_t
__uint64_identity (__uint64_t __x)
{
  return __x;
}


       
       









typedef struct
{
  unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
} __sigset_t;


typedef __sigset_t sigset_t;










struct timeval
{




  __time_t tv_sec;
  __suseconds_t tv_usec;

};

struct timespec
{



  __time_t tv_sec;




  __syscall_slong_t tv_nsec;
};
typedef long int __fd_mask;
typedef struct
  {



    __fd_mask fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];





  } fd_set;






typedef __fd_mask fd_mask;











typedef __blksize_t blksize_t;






typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
typedef __blkcnt64_t blkcnt64_t;
typedef __fsblkcnt64_t fsblkcnt64_t;
typedef __fsfilcnt64_t fsfilcnt64_t;






typedef union
{
  __extension__ unsigned long long int __value64;
  struct
  {
    unsigned int __low;
    unsigned int __high;
  } __value32;
} __atomic_wide_counter;




typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;

typedef struct __pthread_internal_slist
{
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;
struct __pthread_mutex_s
{
  int __lock;
  unsigned int __count;
  int __owner;

  unsigned int __nusers;



  int __kind;

  short __spins;
  short __elision;
  __pthread_list_t __list;
};
struct __pthread_rwlock_arch_t
{
  unsigned int __readers;
  unsigned int __writers;
  unsigned int __wrphase_futex;
  unsigned int __writers_futex;
  unsigned int __pad3;
  unsigned int __pad4;

  int __cur_writer;
  int __shared;
  signed char __rwelision;




  unsigned char __pad1[7];


  unsigned long int __pad2;


  unsigned int __flags;
};




struct __pthread_cond_s
{
  __atomic_wide_counter __wseq;
  __atomic_wide_counter __g1_start;
  unsigned int __g_refs[2] ;
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
};

typedef unsigned int __tss_t;
typedef unsigned long int __thrd_t;

typedef struct
{
  int __data ;
} __once_flag;



typedef unsigned long int pthread_t;




typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;




typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;



typedef unsigned int pthread_key_t;



typedef int pthread_once_t;


union pthread_attr_t
{
  char __size[56];
  long int __align;
};

typedef union pthread_attr_t pthread_attr_t;




typedef union
{
  struct __pthread_mutex_s __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;


typedef union
{
  struct __pthread_cond_s __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;





typedef union
{
  struct __pthread_rwlock_arch_t __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;

typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;





typedef volatile int pthread_spinlock_t;




typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;





       
       


       



struct timex
{
  unsigned int modes;
  __syscall_slong_t offset;
  __syscall_slong_t freq;
  __syscall_slong_t maxerror;
  __syscall_slong_t esterror;
  int status;
  __syscall_slong_t constant;
  __syscall_slong_t precision;
  __syscall_slong_t tolerance;
  struct timeval time;
  __syscall_slong_t tick;
  __syscall_slong_t ppsfreq;
  __syscall_slong_t jitter;
  int shift;
  __syscall_slong_t stabil;
  __syscall_slong_t jitcnt;
  __syscall_slong_t calcnt;
  __syscall_slong_t errcnt;
  __syscall_slong_t stbcnt;

  int tai;


  int :32; int :32; int :32; int :32;
  int :32; int :32; int :32; int :32;
  int :32; int :32; int :32;

};
















struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;


  long int tm_gmtoff;
  const char *tm_zone;




};







struct itimerspec
  {
    struct timespec it_interval;
    struct timespec it_value;
  };
struct sigevent;
struct __locale_struct
{

  struct __locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
};

typedef struct __locale_struct *__locale_t;

typedef __locale_t locale_t;
























































































typedef long int ptrdiff_t;
typedef int wchar_t;
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
struct __time_t_must_be_integral {
  unsigned int __floating_time_t_unsupported : (time_t) 1;
};







typedef struct tm_zone *timezone_t;





















struct stat
  {



    __dev_t st_dev;




    __ino_t st_ino;







    __nlink_t st_nlink;
    __mode_t st_mode;

    __uid_t st_uid;
    __gid_t st_gid;

    int __pad0;

    __dev_t st_rdev;




    __off_t st_size;



    __blksize_t st_blksize;

    __blkcnt_t st_blocks;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
    __syscall_slong_t __glibc_reserved[3];
  };



struct stat64
  {



    __dev_t st_dev;

    __ino64_t st_ino;
    __nlink_t st_nlink;
    __mode_t st_mode;






    __uid_t st_uid;
    __gid_t st_gid;

    int __pad0;
    __dev_t st_rdev;
    __off_t st_size;





    __blksize_t st_blksize;
    __blkcnt64_t st_blocks;







    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
    __syscall_slong_t __glibc_reserved[3];




  };



















































































typedef __signed__ char __s8;
typedef unsigned char __u8;

typedef __signed__ short __s16;
typedef unsigned short __u16;

typedef __signed__ int __s32;
typedef unsigned int __u32;


__extension__ typedef __signed__ long long __s64;
__extension__ typedef unsigned long long __u64;







typedef struct {
 unsigned long fds_bits[1024 / (8 * sizeof(long))];
} __kernel_fd_set;


typedef void (*__kernel_sighandler_t)(int);


typedef int __kernel_key_t;
typedef int __kernel_mqd_t;







typedef unsigned short __kernel_old_uid_t;
typedef unsigned short __kernel_old_gid_t;


typedef unsigned long __kernel_old_dev_t;


typedef long __kernel_long_t;
typedef unsigned long __kernel_ulong_t;



typedef __kernel_ulong_t __kernel_ino_t;



typedef unsigned int __kernel_mode_t;



typedef int __kernel_pid_t;



typedef int __kernel_ipc_pid_t;



typedef unsigned int __kernel_uid_t;
typedef unsigned int __kernel_gid_t;



typedef __kernel_long_t __kernel_suseconds_t;



typedef int __kernel_daddr_t;



typedef unsigned int __kernel_uid32_t;
typedef unsigned int __kernel_gid32_t;
typedef __kernel_ulong_t __kernel_size_t;
typedef __kernel_long_t __kernel_ssize_t;
typedef __kernel_long_t __kernel_ptrdiff_t;




typedef struct {
 int val[2];
} __kernel_fsid_t;





typedef __kernel_long_t __kernel_off_t;
typedef long long __kernel_loff_t;
typedef __kernel_long_t __kernel_old_time_t;
typedef __kernel_long_t __kernel_time_t;
typedef long long __kernel_time64_t;
typedef __kernel_long_t __kernel_clock_t;
typedef int __kernel_timer_t;
typedef int __kernel_clockid_t;
typedef char * __kernel_caddr_t;
typedef unsigned short __kernel_uid16_t;
typedef unsigned short __kernel_gid16_t;
typedef __u16 __le16;
typedef __u16 __be16;
typedef __u32 __le32;
typedef __u32 __be32;
typedef __u64 __le64;
typedef __u64 __be64;

typedef __u16 __sum16;
typedef __u32 __wsum;
typedef unsigned __poll_t;
struct statx_timestamp {
 __s64 tv_sec;
 __u32 tv_nsec;
 __s32 __reserved;
};
struct statx {

 __u32 stx_mask;
 __u32 stx_blksize;
 __u64 stx_attributes;

 __u32 stx_nlink;
 __u32 stx_uid;
 __u32 stx_gid;
 __u16 stx_mode;
 __u16 __spare0[1];

 __u64 stx_ino;
 __u64 stx_size;
 __u64 stx_blocks;
 __u64 stx_attributes_mask;

 struct statx_timestamp stx_atime;
 struct statx_timestamp stx_btime;
 struct statx_timestamp stx_ctime;
 struct statx_timestamp stx_mtime;

 __u32 stx_rdev_major;
 __u32 stx_rdev_minor;
 __u32 stx_dev_major;
 __u32 stx_dev_minor;

 __u64 stx_mnt_id;
 __u64 __spare2;

 __u64 __spare3[12];

};










int statx (int __dirfd, const char *__restrict __path, int __flags,
           unsigned int __mask, struct statx *__restrict __buf)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 5)));



























       
       






       









       
       













typedef __sig_atomic_t sig_atomic_t;




union sigval
{
  int sival_int;
  void *sival_ptr;
};

typedef union sigval __sigval_t;
typedef struct
  {
    int si_signo;

    int si_errno;

    int si_code;





    int __pad0;


    union
      {
 int _pad[((128 / sizeof (int)) - 4)];


 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
   } _kill;


 struct
   {
     int si_tid;
     int si_overrun;
     __sigval_t si_sigval;
   } _timer;


 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     __sigval_t si_sigval;
   } _rt;


 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     int si_status;
     __clock_t si_utime;
     __clock_t si_stime;
   } _sigchld;


 struct
   {
     void *si_addr;
    
     short int si_addr_lsb;
     union
       {

  struct
    {
      void *_lower;
      void *_upper;
    } _addr_bnd;

  __uint32_t _pkey;
       } _bounds;
   } _sigfault;


 struct
   {
     long int si_band;
     int si_fd;
   } _sigpoll;



 struct
   {
     void *_call_addr;
     int _syscall;
     unsigned int _arch;
   } _sigsys;

      } _sifields;
  } siginfo_t ;
enum
{
  SI_ASYNCNL = -60,
  SI_DETHREAD = -7,

  SI_TKILL,
  SI_SIGIO,

  SI_ASYNCIO,
  SI_MESGQ,
  SI_TIMER,





  SI_QUEUE,
  SI_USER,
  SI_KERNEL = 0x80
};




enum
{
  ILL_ILLOPC = 1,

  ILL_ILLOPN,

  ILL_ILLADR,

  ILL_ILLTRP,

  ILL_PRVOPC,

  ILL_PRVREG,

  ILL_COPROC,

  ILL_BADSTK,

  ILL_BADIADDR

};


enum
{
  FPE_INTDIV = 1,

  FPE_INTOVF,

  FPE_FLTDIV,

  FPE_FLTOVF,

  FPE_FLTUND,

  FPE_FLTRES,

  FPE_FLTINV,

  FPE_FLTSUB,

  FPE_FLTUNK = 14,

  FPE_CONDTRAP

};


enum
{
  SEGV_MAPERR = 1,

  SEGV_ACCERR,

  SEGV_BNDERR,

  SEGV_PKUERR,

  SEGV_ACCADI,

  SEGV_ADIDERR,

  SEGV_ADIPERR,

  SEGV_MTEAERR,

  SEGV_MTESERR

};


enum
{
  BUS_ADRALN = 1,

  BUS_ADRERR,

  BUS_OBJERR,

  BUS_MCEERR_AR,

  BUS_MCEERR_AO

};




enum
{
  TRAP_BRKPT = 1,

  TRAP_TRACE,

  TRAP_BRANCH,

  TRAP_HWBKPT,

  TRAP_UNK

};




enum
{
  CLD_EXITED = 1,

  CLD_KILLED,

  CLD_DUMPED,

  CLD_TRAPPED,

  CLD_STOPPED,

  CLD_CONTINUED

};


enum
{
  POLL_IN = 1,

  POLL_OUT,

  POLL_MSG,

  POLL_ERR,

  POLL_PRI,

  POLL_HUP

};








typedef __sigval_t sigval_t;






typedef struct sigevent
  {
    __sigval_t sigev_value;
    int sigev_signo;
    int sigev_notify;

    union
      {
 int _pad[((64 / sizeof (int)) - 4)];



 __pid_t _tid;

 struct
   {
     void (*_function) (__sigval_t);
     pthread_attr_t *_attribute;
   } _sigev_thread;
      } _sigev_un;
  } sigevent_t;
enum
{
  SIGEV_SIGNAL = 0,

  SIGEV_NONE,

  SIGEV_THREAD,


  SIGEV_THREAD_ID = 4


};




typedef void (*__sighandler_t) (int);

































typedef __sighandler_t sighandler_t;




typedef __sighandler_t sig_t;
























struct sigaction
  {


    union
      {

 __sighandler_t sa_handler;

 void (*sa_sigaction) (int, siginfo_t *, void *);
      }
    __sigaction_handler;







    __sigset_t sa_mask;


    int sa_flags;


    void (*sa_restorer) (void);
  };








































struct _fpx_sw_bytes
{
  __uint32_t magic1;
  __uint32_t extended_size;
  __uint64_t xstate_bv;
  __uint32_t xstate_size;
  __uint32_t __glibc_reserved1[7];
};

struct _fpreg
{
  unsigned short significand[4];
  unsigned short exponent;
};

struct _fpxreg
{
  unsigned short significand[4];
  unsigned short exponent;
  unsigned short __glibc_reserved1[3];
};

struct _xmmreg
{
  __uint32_t element[4];
};
struct _fpstate
{

  __uint16_t cwd;
  __uint16_t swd;
  __uint16_t ftw;
  __uint16_t fop;
  __uint64_t rip;
  __uint64_t rdp;
  __uint32_t mxcsr;
  __uint32_t mxcr_mask;
  struct _fpxreg _st[8];
  struct _xmmreg _xmm[16];
  __uint32_t __glibc_reserved1[24];
};

struct sigcontext
{
  __uint64_t r8;
  __uint64_t r9;
  __uint64_t r10;
  __uint64_t r11;
  __uint64_t r12;
  __uint64_t r13;
  __uint64_t r14;
  __uint64_t r15;
  __uint64_t rdi;
  __uint64_t rsi;
  __uint64_t rbp;
  __uint64_t rbx;
  __uint64_t rdx;
  __uint64_t rax;
  __uint64_t rcx;
  __uint64_t rsp;
  __uint64_t rip;
  __uint64_t eflags;
  unsigned short cs;
  unsigned short gs;
  unsigned short fs;
  unsigned short __pad0;
  __uint64_t err;
  __uint64_t trapno;
  __uint64_t oldmask;
  __uint64_t cr2;
  __extension__ union
    {
      struct _fpstate * fpstate;
      __uint64_t __fpstate_word;
    };
  __uint64_t __reserved1 [8];
};



struct _xsave_hdr
{
  __uint64_t xstate_bv;
  __uint64_t __glibc_reserved1[2];
  __uint64_t __glibc_reserved2[5];
};

struct _ymmh_state
{
  __uint32_t ymmh_space[64];
};

struct _xstate
{
  struct _fpstate fpstate;
  struct _xsave_hdr xstate_hdr;
  struct _ymmh_state ymmh;
};











typedef struct
  {
    void *ss_sp;
    int ss_flags;
    size_t ss_size;
  } stack_t;


__extension__ typedef long long int greg_t;
typedef greg_t gregset_t[23];



enum
{
  REG_R8 = 0,

  REG_R9,

  REG_R10,

  REG_R11,

  REG_R12,

  REG_R13,

  REG_R14,

  REG_R15,

  REG_RDI,

  REG_RSI,

  REG_RBP,

  REG_RBX,

  REG_RDX,

  REG_RAX,

  REG_RCX,

  REG_RSP,

  REG_RIP,

  REG_EFL,

  REG_CSGSFS,

  REG_ERR,

  REG_TRAPNO,

  REG_OLDMASK,

  REG_CR2

};


struct _libc_fpxreg
{
  unsigned short int significand[4];
  unsigned short int exponent;
  unsigned short int __glibc_reserved1[3];
};

struct _libc_xmmreg
{
  __uint32_t element[4];
};

struct _libc_fpstate
{

  __uint16_t cwd;
  __uint16_t swd;
  __uint16_t ftw;
  __uint16_t fop;
  __uint64_t rip;
  __uint64_t rdp;
  __uint32_t mxcsr;
  __uint32_t mxcr_mask;
  struct _libc_fpxreg _st[8];
  struct _libc_xmmreg _xmm[16];
  __uint32_t __glibc_reserved1[24];
};


typedef struct _libc_fpstate *fpregset_t;


typedef struct
  {
    gregset_t gregs;

    fpregset_t fpregs;
    __extension__ unsigned long long __reserved1 [8];
} mcontext_t;


typedef struct ucontext_t
  {
    unsigned long int uc_flags;
    struct ucontext_t *uc_link;
    stack_t uc_stack;
    mcontext_t uc_mcontext;
    sigset_t uc_sigmask;
    struct _libc_fpstate __fpregs_mem;
    __extension__ unsigned long long int __ssp[4];
  } ucontext_t;








       




typedef __intptr_t intptr_t;






typedef __socklen_t socklen_t;
































































































































































enum
  {
    _PC_LINK_MAX,

    _PC_MAX_CANON,

    _PC_MAX_INPUT,

    _PC_NAME_MAX,

    _PC_PATH_MAX,

    _PC_PIPE_BUF,

    _PC_CHOWN_RESTRICTED,

    _PC_NO_TRUNC,

    _PC_VDISABLE,

    _PC_SYNC_IO,

    _PC_ASYNC_IO,

    _PC_PRIO_IO,

    _PC_SOCK_MAXBUF,

    _PC_FILESIZEBITS,

    _PC_REC_INCR_XFER_SIZE,

    _PC_REC_MAX_XFER_SIZE,

    _PC_REC_MIN_XFER_SIZE,

    _PC_REC_XFER_ALIGN,

    _PC_ALLOC_SIZE_MIN,

    _PC_SYMLINK_MAX,

    _PC_2_SYMLINKS

  };


enum
  {
    _SC_ARG_MAX,

    _SC_CHILD_MAX,

    _SC_CLK_TCK,

    _SC_NGROUPS_MAX,

    _SC_OPEN_MAX,

    _SC_STREAM_MAX,

    _SC_TZNAME_MAX,

    _SC_JOB_CONTROL,

    _SC_SAVED_IDS,

    _SC_REALTIME_SIGNALS,

    _SC_PRIORITY_SCHEDULING,

    _SC_TIMERS,

    _SC_ASYNCHRONOUS_IO,

    _SC_PRIORITIZED_IO,

    _SC_SYNCHRONIZED_IO,

    _SC_FSYNC,

    _SC_MAPPED_FILES,

    _SC_MEMLOCK,

    _SC_MEMLOCK_RANGE,

    _SC_MEMORY_PROTECTION,

    _SC_MESSAGE_PASSING,

    _SC_SEMAPHORES,

    _SC_SHARED_MEMORY_OBJECTS,

    _SC_AIO_LISTIO_MAX,

    _SC_AIO_MAX,

    _SC_AIO_PRIO_DELTA_MAX,

    _SC_DELAYTIMER_MAX,

    _SC_MQ_OPEN_MAX,

    _SC_MQ_PRIO_MAX,

    _SC_VERSION,

    _SC_PAGESIZE,


    _SC_RTSIG_MAX,

    _SC_SEM_NSEMS_MAX,

    _SC_SEM_VALUE_MAX,

    _SC_SIGQUEUE_MAX,

    _SC_TIMER_MAX,




    _SC_BC_BASE_MAX,

    _SC_BC_DIM_MAX,

    _SC_BC_SCALE_MAX,

    _SC_BC_STRING_MAX,

    _SC_COLL_WEIGHTS_MAX,

    _SC_EQUIV_CLASS_MAX,

    _SC_EXPR_NEST_MAX,

    _SC_LINE_MAX,

    _SC_RE_DUP_MAX,

    _SC_CHARCLASS_NAME_MAX,


    _SC_2_VERSION,

    _SC_2_C_BIND,

    _SC_2_C_DEV,

    _SC_2_FORT_DEV,

    _SC_2_FORT_RUN,

    _SC_2_SW_DEV,

    _SC_2_LOCALEDEF,


    _SC_PII,

    _SC_PII_XTI,

    _SC_PII_SOCKET,

    _SC_PII_INTERNET,

    _SC_PII_OSI,

    _SC_POLL,

    _SC_SELECT,

    _SC_UIO_MAXIOV,

    _SC_IOV_MAX = _SC_UIO_MAXIOV,

    _SC_PII_INTERNET_STREAM,

    _SC_PII_INTERNET_DGRAM,

    _SC_PII_OSI_COTS,

    _SC_PII_OSI_CLTS,

    _SC_PII_OSI_M,

    _SC_T_IOV_MAX,



    _SC_THREADS,

    _SC_THREAD_SAFE_FUNCTIONS,

    _SC_GETGR_R_SIZE_MAX,

    _SC_GETPW_R_SIZE_MAX,

    _SC_LOGIN_NAME_MAX,

    _SC_TTY_NAME_MAX,

    _SC_THREAD_DESTRUCTOR_ITERATIONS,

    _SC_THREAD_KEYS_MAX,

    _SC_THREAD_STACK_MIN,

    _SC_THREAD_THREADS_MAX,

    _SC_THREAD_ATTR_STACKADDR,

    _SC_THREAD_ATTR_STACKSIZE,

    _SC_THREAD_PRIORITY_SCHEDULING,

    _SC_THREAD_PRIO_INHERIT,

    _SC_THREAD_PRIO_PROTECT,

    _SC_THREAD_PROCESS_SHARED,


    _SC_NPROCESSORS_CONF,

    _SC_NPROCESSORS_ONLN,

    _SC_PHYS_PAGES,

    _SC_AVPHYS_PAGES,

    _SC_ATEXIT_MAX,

    _SC_PASS_MAX,


    _SC_XOPEN_VERSION,

    _SC_XOPEN_XCU_VERSION,

    _SC_XOPEN_UNIX,

    _SC_XOPEN_CRYPT,

    _SC_XOPEN_ENH_I18N,

    _SC_XOPEN_SHM,


    _SC_2_CHAR_TERM,

    _SC_2_C_VERSION,

    _SC_2_UPE,


    _SC_XOPEN_XPG2,

    _SC_XOPEN_XPG3,

    _SC_XOPEN_XPG4,


    _SC_CHAR_BIT,

    _SC_CHAR_MAX,

    _SC_CHAR_MIN,

    _SC_INT_MAX,

    _SC_INT_MIN,

    _SC_LONG_BIT,

    _SC_WORD_BIT,

    _SC_MB_LEN_MAX,

    _SC_NZERO,

    _SC_SSIZE_MAX,

    _SC_SCHAR_MAX,

    _SC_SCHAR_MIN,

    _SC_SHRT_MAX,

    _SC_SHRT_MIN,

    _SC_UCHAR_MAX,

    _SC_UINT_MAX,

    _SC_ULONG_MAX,

    _SC_USHRT_MAX,


    _SC_NL_ARGMAX,

    _SC_NL_LANGMAX,

    _SC_NL_MSGMAX,

    _SC_NL_NMAX,

    _SC_NL_SETMAX,

    _SC_NL_TEXTMAX,


    _SC_XBS5_ILP32_OFF32,

    _SC_XBS5_ILP32_OFFBIG,

    _SC_XBS5_LP64_OFF64,

    _SC_XBS5_LPBIG_OFFBIG,


    _SC_XOPEN_LEGACY,

    _SC_XOPEN_REALTIME,

    _SC_XOPEN_REALTIME_THREADS,


    _SC_ADVISORY_INFO,

    _SC_BARRIERS,

    _SC_BASE,

    _SC_C_LANG_SUPPORT,

    _SC_C_LANG_SUPPORT_R,

    _SC_CLOCK_SELECTION,

    _SC_CPUTIME,

    _SC_THREAD_CPUTIME,

    _SC_DEVICE_IO,

    _SC_DEVICE_SPECIFIC,

    _SC_DEVICE_SPECIFIC_R,

    _SC_FD_MGMT,

    _SC_FIFO,

    _SC_PIPE,

    _SC_FILE_ATTRIBUTES,

    _SC_FILE_LOCKING,

    _SC_FILE_SYSTEM,

    _SC_MONOTONIC_CLOCK,

    _SC_MULTI_PROCESS,

    _SC_SINGLE_PROCESS,

    _SC_NETWORKING,

    _SC_READER_WRITER_LOCKS,

    _SC_SPIN_LOCKS,

    _SC_REGEXP,

    _SC_REGEX_VERSION,

    _SC_SHELL,

    _SC_SIGNALS,

    _SC_SPAWN,

    _SC_SPORADIC_SERVER,

    _SC_THREAD_SPORADIC_SERVER,

    _SC_SYSTEM_DATABASE,

    _SC_SYSTEM_DATABASE_R,

    _SC_TIMEOUTS,

    _SC_TYPED_MEMORY_OBJECTS,

    _SC_USER_GROUPS,

    _SC_USER_GROUPS_R,

    _SC_2_PBS,

    _SC_2_PBS_ACCOUNTING,

    _SC_2_PBS_LOCATE,

    _SC_2_PBS_MESSAGE,

    _SC_2_PBS_TRACK,

    _SC_SYMLOOP_MAX,

    _SC_STREAMS,

    _SC_2_PBS_CHECKPOINT,


    _SC_V6_ILP32_OFF32,

    _SC_V6_ILP32_OFFBIG,

    _SC_V6_LP64_OFF64,

    _SC_V6_LPBIG_OFFBIG,


    _SC_HOST_NAME_MAX,

    _SC_TRACE,

    _SC_TRACE_EVENT_FILTER,

    _SC_TRACE_INHERIT,

    _SC_TRACE_LOG,


    _SC_LEVEL1_ICACHE_SIZE,

    _SC_LEVEL1_ICACHE_ASSOC,

    _SC_LEVEL1_ICACHE_LINESIZE,

    _SC_LEVEL1_DCACHE_SIZE,

    _SC_LEVEL1_DCACHE_ASSOC,

    _SC_LEVEL1_DCACHE_LINESIZE,

    _SC_LEVEL2_CACHE_SIZE,

    _SC_LEVEL2_CACHE_ASSOC,

    _SC_LEVEL2_CACHE_LINESIZE,

    _SC_LEVEL3_CACHE_SIZE,

    _SC_LEVEL3_CACHE_ASSOC,

    _SC_LEVEL3_CACHE_LINESIZE,

    _SC_LEVEL4_CACHE_SIZE,

    _SC_LEVEL4_CACHE_ASSOC,

    _SC_LEVEL4_CACHE_LINESIZE,



    _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50,

    _SC_RAW_SOCKETS,


    _SC_V7_ILP32_OFF32,

    _SC_V7_ILP32_OFFBIG,

    _SC_V7_LP64_OFF64,

    _SC_V7_LPBIG_OFFBIG,


    _SC_SS_REPL_MAX,


    _SC_TRACE_EVENT_NAME_MAX,

    _SC_TRACE_NAME_MAX,

    _SC_TRACE_SYS_MAX,

    _SC_TRACE_USER_EVENT_MAX,


    _SC_XOPEN_STREAMS,


    _SC_THREAD_ROBUST_PRIO_INHERIT,

    _SC_THREAD_ROBUST_PRIO_PROTECT,


    _SC_MINSIGSTKSZ,


    _SC_SIGSTKSZ

  };


enum
  {
    _CS_PATH,


    _CS_V6_WIDTH_RESTRICTED_ENVS,



    _CS_GNU_LIBC_VERSION,

    _CS_GNU_LIBPTHREAD_VERSION,


    _CS_V5_WIDTH_RESTRICTED_ENVS,



    _CS_V7_WIDTH_RESTRICTED_ENVS,



    _CS_LFS_CFLAGS = 1000,

    _CS_LFS_LDFLAGS,

    _CS_LFS_LIBS,

    _CS_LFS_LINTFLAGS,

    _CS_LFS64_CFLAGS,

    _CS_LFS64_LDFLAGS,

    _CS_LFS64_LIBS,

    _CS_LFS64_LINTFLAGS,


    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,

    _CS_XBS5_ILP32_OFF32_LDFLAGS,

    _CS_XBS5_ILP32_OFF32_LIBS,

    _CS_XBS5_ILP32_OFF32_LINTFLAGS,

    _CS_XBS5_ILP32_OFFBIG_CFLAGS,

    _CS_XBS5_ILP32_OFFBIG_LDFLAGS,

    _CS_XBS5_ILP32_OFFBIG_LIBS,

    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,

    _CS_XBS5_LP64_OFF64_CFLAGS,

    _CS_XBS5_LP64_OFF64_LDFLAGS,

    _CS_XBS5_LP64_OFF64_LIBS,

    _CS_XBS5_LP64_OFF64_LINTFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_CFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_LIBS,

    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,


    _CS_POSIX_V6_ILP32_OFF32_CFLAGS,

    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,

    _CS_POSIX_V6_ILP32_OFF32_LIBS,

    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_LIBS,

    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,

    _CS_POSIX_V6_LP64_OFF64_CFLAGS,

    _CS_POSIX_V6_LP64_OFF64_LDFLAGS,

    _CS_POSIX_V6_LP64_OFF64_LIBS,

    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,


    _CS_POSIX_V7_ILP32_OFF32_CFLAGS,

    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS,

    _CS_POSIX_V7_ILP32_OFF32_LIBS,

    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS,

    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS,

    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS,

    _CS_POSIX_V7_ILP32_OFFBIG_LIBS,

    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS,

    _CS_POSIX_V7_LP64_OFF64_CFLAGS,

    _CS_POSIX_V7_LP64_OFF64_LDFLAGS,

    _CS_POSIX_V7_LP64_OFF64_LIBS,

    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS,

    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS,

    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS,

    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS,

    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS,


    _CS_V6_ENV,

    _CS_V7_ENV

  };























































































































































































































































































ssize_t copy_file_range (int __infd, __off64_t *__pinoff,
    int __outfd, __off64_t *__poutoff,
    size_t __length, unsigned int __flags);












int getentropy (void *__buffer, size_t __length) __attribute__ ((__warn_unused_result__))
    __attribute__ ((__access__ (__write_only__, 1, 2)));





}




}
}





}




}



}



  return __getwd_warn (__buf);
}



}



}



}




}





}





}








       
















































enum
{
  SS_ONSTACK = 1,

  SS_DISABLE

};







struct sigstack
  {
    void *ss_sp;
    int ss_onstack;
  };




























































typedef void (*_gl_function_taking_int_returning_void_t) (int);












       

       





       
       


struct timezone
  {
    int tz_minuteswest;
    int tz_dsttime;
  };





enum __itimer_which
  {

    ITIMER_REAL = 0,


    ITIMER_VIRTUAL = 1,



    ITIMER_PROF = 2

  };



struct itimerval
  {

    struct timeval it_interval;

    struct timeval it_value;
  };




typedef enum __itimer_which __itimer_which_t;



















       










       
































































































































__extension__ 





















}

}




































}

}


}
}




void __explicit_bzero_chk (void *__dest, size_t __len, size_t __destlen)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__access__ (__write_only__, 1, 2)));

}


}


}



}



}
}


}





















































typedef int error_t;




       














typedef struct
  {
    int quot;
    int rem;
  } div_t;



typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;





__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;








__extension__ 






















__extension__

__extension__




__extension__

__extension__




















__extension__

__extension__





















       























struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };































struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;

  };
















































































































typedef int (*__compar_fn_t) (const void *, const void *);


typedef __compar_fn_t comparison_fn_t;



typedef int (*__compar_d_fn_t) (const void *, const void *, void *);


















__extension__ 



















































































  if (sz == (size_t) -1)
    return __realpath_alias (__name, __resolved);


  if ((((__typeof (4096)) 0 < (__typeof (4096)) -1 || (__builtin_constant_p (4096) && (4096) > 0)) && __builtin_constant_p ((((long unsigned int) (4096)) <= (sz) / (sizeof (char)))) && !(((long unsigned int) (4096)) <= (sz) / (sizeof (char)))))
    return __realpath_chk_warn (__name, __resolved, sz);

  return __realpath_chk (__name, __resolved, sz);
}



}



  return __wctomb_alias (__s, __wchar);
}



}



}




























































enum
{
  EXIT_TIMEDOUT = 124,
  EXIT_CANCELED = 125,
  EXIT_CANNOT_INVOKE = 126,
  EXIT_ENOENT = 127
};



static inline void
initialize_exit_failure (int status)
{
  if (status != 
               1
                           )
    exit_failure = status;
}

       
       








struct flock
  {
    short int l_type;
    short int l_whence;

    __off_t l_start;
    __off_t l_len;




    __pid_t l_pid;
  };


struct flock64
  {
    short int l_type;
    short int l_whence;
    __off64_t l_start;
    __off64_t l_len;
    __pid_t l_pid;
  };





struct iovec
  {
    void *iov_base;
    size_t iov_len;
  };
enum __pid_type
  {
    F_OWNER_TID = 0,
    F_OWNER_PID,
    F_OWNER_PGRP,
    F_OWNER_GID = F_OWNER_PGRP
  };


struct f_owner_ex
  {
    enum __pid_type type;
    __pid_t pid;
  };



struct file_handle
{
  unsigned int handle_bytes;
  int handle_type;

  unsigned char f_handle[0];
};





























































  if (__builtin_constant_p (__oflag))
    {
      if ((((__oflag) & 0100) != 0 || ((__oflag) & (020000000 | 0200000)) == (020000000 | 0200000)) && __builtin_va_arg_pack_len () < 1)
 {
   __open_missing_mode ();
   return __open_2 (__path, __oflag);
 }
      return __open_alias (__path, __oflag, __builtin_va_arg_pack ());
    }

  if (__builtin_va_arg_pack_len () < 1)
    return __open_2 (__path, __oflag);

  return __open_alias (__path, __oflag, __builtin_va_arg_pack ());
}





  if (__builtin_constant_p (__oflag))
    {
      if ((((__oflag) & 0100) != 0 || ((__oflag) & (020000000 | 0200000)) == (020000000 | 0200000)) && __builtin_va_arg_pack_len () < 1)
 {
   __open64_missing_mode ();
   return __open64_2 (__path, __oflag);
 }
      return __open64_alias (__path, __oflag, __builtin_va_arg_pack ());
    }

  if (__builtin_va_arg_pack_len () < 1)
    return __open64_2 (__path, __oflag);

  return __open64_alias (__path, __oflag, __builtin_va_arg_pack ());
}







  if (__builtin_constant_p (__oflag))
    {
      if ((((__oflag) & 0100) != 0 || ((__oflag) & (020000000 | 0200000)) == (020000000 | 0200000)) && __builtin_va_arg_pack_len () < 1)
 {
   __openat_missing_mode ();
   return __openat_2 (__fd, __path, __oflag);
 }
      return __openat_alias (__fd, __path, __oflag, __builtin_va_arg_pack ());
    }

  if (__builtin_va_arg_pack_len () < 1)
    return __openat_2 (__fd, __path, __oflag);

  return __openat_alias (__fd, __path, __oflag, __builtin_va_arg_pack ());
}





  if (__builtin_constant_p (__oflag))
    {
      if ((((__oflag) & 0100) != 0 || ((__oflag) & (020000000 | 0200000)) == (020000000 | 0200000)) && __builtin_va_arg_pack_len () < 1)
 {
   __openat64_missing_mode ();
   return __openat64_2 (__fd, __path, __oflag);
 }
      return __openat64_alias (__fd, __path, __oflag, __builtin_va_arg_pack ());
    }

  if (__builtin_va_arg_pack_len () < 1)
    return __openat64_2 (__fd, __path, __oflag);

  return __openat64_alias (__fd, __path, __oflag, __builtin_va_arg_pack ());
}











enum { O_PATHSEARCH = 
                     010000000 
                            };




       







struct dirent
  {

    __ino_t d_ino;
    __off_t d_off;




    unsigned short int d_reclen;
    unsigned char d_type;
    char d_name[256];
  };


struct dirent64
  {
    __ino64_t d_ino;
    __off64_t d_off;
    unsigned short int d_reclen;
    unsigned char d_type;
    char d_name[256];
  };
enum
  {
    DT_UNKNOWN = 0,

    DT_FIFO = 1,

    DT_CHR = 2,

    DT_DIR = 4,

    DT_BLK = 6,

    DT_REG = 8,

    DT_LNK = 10,

    DT_SOCK = 12,

    DT_WHT = 14

  };
typedef struct __dirstream DIR;

































































       











enum
{
  NOT_AN_INODE_NUMBER = 0
};
       









typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;





typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;


typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;





typedef signed char int_fast8_t;

typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;

typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef unsigned long int uintptr_t;
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;






typedef int __gwchar_t;





typedef struct
  {
    long int quot;
    long int rem;
  } imaxdiv_t;












       



       










enum { TIMESPEC_HZ = 1000000000 };
enum { LOG10_TIMESPEC_HZ = 9 };




enum { TIMESPEC_RESOLUTION = TIMESPEC_HZ };
enum { LOG10_TIMESPEC_RESOLUTION = LOG10_TIMESPEC_HZ };



inline struct timespec
make_timespec (time_t s, long int ns)
{
  struct timespec r;
  r.tv_sec = s;
  r.tv_nsec = ns;
  return r;
}



inline int __attribute__ ((__pure__))
timespec_cmp (struct timespec a, struct timespec b)
{
  return 2 * (((a.tv_sec) > (b.tv_sec)) - ((a.tv_sec) < (b.tv_sec))) + (((a.tv_nsec) > (b.tv_nsec)) - ((a.tv_nsec) < (b.tv_nsec)));
}



inline int __attribute__ ((__pure__))
timespec_sign (struct timespec a)
{
  return (((a.tv_sec) > (0)) - ((a.tv_sec) < (0))) + (!a.tv_sec & !!a.tv_nsec);
}

struct timespec timespec_add (struct timespec, struct timespec)
  __attribute__ ((__const__));
struct timespec timespec_sub (struct timespec, struct timespec)
  __attribute__ ((__const__));
struct timespec dtotimespec (double)
  __attribute__ ((__const__));


inline double
timespectod (struct timespec a)
{
  return a.tv_sec + a.tv_nsec / 1e9;
}

long int gettime_res (void);
struct timespec current_timespec (void);
void gettime (struct timespec *) 
                                __attribute__ ((__nonnull__ 
                                (1)
                                ))
                                                     ;
int settime (struct timespec const *) 
                                     __attribute__ ((__nonnull__ 
                                     (1)
                                     ))
                                                          ;







       







enum
{
  _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
  _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
  _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
  _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
  _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
  _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
  _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
  _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
  _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
  _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
  _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
  _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
};

































static inline unsigned char to_uchar (char ch) { return ch; }


static inline 
             _Bool

field_sep (unsigned char ch)
{
  return 
        ((*__ctype_b_loc ())[(int) ((
        ch
        ))] & (unsigned short int) _ISblank) 
                     || ch == '\n';
}

       



struct lconv
{


  char *decimal_point;
  char *thousands_sep;





  char *grouping;





  char *int_curr_symbol;
  char *currency_symbol;
  char *mon_decimal_point;
  char *mon_thousands_sep;
  char *mon_grouping;
  char *positive_sign;
  char *negative_sign;
  char int_frac_digits;
  char frac_digits;

  char p_cs_precedes;

  char p_sep_by_space;

  char n_cs_precedes;

  char n_sep_by_space;






  char p_sign_posn;
  char n_sign_posn;


  char int_p_cs_precedes;

  char int_p_sep_by_space;

  char int_n_cs_precedes;

  char int_n_sep_by_space;






  char int_p_sign_posn;
  char int_n_sign_posn;
};











































































       


__inline





static const char *
pgettext_aux (const char *domain,
              const char *msg_ctxt_id, const char *msgid,
              int category)
{
  const char *translation = dcgettext (domain, msg_ctxt_id, category);
  if (translation == msg_ctxt_id)
    return msgid;
  else
    return translation;
}


__inline





static const char *
npgettext_aux (const char *domain,
               const char *msg_ctxt_id, const char *msgid,
               const char *msgid_plural, unsigned long int n,
               int category)
{
  const char *translation =
    dcngettext (domain, msg_ctxt_id, msgid_plural, n, category);
  if (translation == msg_ctxt_id || translation == msgid_plural)
    return (n == 1 ? msgid : msgid_plural);
  else
    return translation;
}





       
       
__inline





static const char *
dcpgettext_expr (const char *domain,
                 const char *msgctxt, const char *msgid,
                 int category)
{
  size_t msgctxt_len = strlen (msgctxt) + 1;
  size_t msgid_len = strlen (msgid) + 1;
  const char *translation;



  char buf[1024];
  char *msg_ctxt_id =
    (msgctxt_len + msgid_len <= sizeof (buf)
     ? buf
     : (char *) malloc (msgctxt_len + msgid_len));
  if (msg_ctxt_id != 
                    ((void *)0)
                        )

    {
      int found_translation;
      memcpy (msg_ctxt_id, msgctxt, msgctxt_len - 1);
      msg_ctxt_id[msgctxt_len - 1] = '\004';
      memcpy (msg_ctxt_id + msgctxt_len, msgid, msgid_len);
      translation = dcgettext (domain, msg_ctxt_id, category);
      found_translation = (translation != msg_ctxt_id);

      if (msg_ctxt_id != buf)
        free (msg_ctxt_id);

      if (found_translation)
        return translation;
    }
  return msgid;
}







__inline





static const char *
dcnpgettext_expr (const char *domain,
                  const char *msgctxt, const char *msgid,
                  const char *msgid_plural, unsigned long int n,
                  int category)
{
  size_t msgctxt_len = strlen (msgctxt) + 1;
  size_t msgid_len = strlen (msgid) + 1;
  const char *translation;



  char buf[1024];
  char *msg_ctxt_id =
    (msgctxt_len + msgid_len <= sizeof (buf)
     ? buf
     : (char *) malloc (msgctxt_len + msgid_len));
  if (msg_ctxt_id != 
                    ((void *)0)
                        )

    {
      int found_translation;
      memcpy (msg_ctxt_id, msgctxt, msgctxt_len - 1);
      msg_ctxt_id[msgctxt_len - 1] = '\004';
      memcpy (msg_ctxt_id + msgctxt_len, msgid, msgid_len);
      translation = dcngettext (domain, msg_ctxt_id, msgid_plural, n, category);
      found_translation = !(translation == msg_ctxt_id || translation == msgid_plural);

      if (msg_ctxt_id != buf)
        free (msg_ctxt_id);

      if (found_translation)
        return translation;
    }
  return (n == 1 ? msgid : msgid_plural);
}
static inline unsigned long int
select_plural (uintmax_t n)
{


  enum { PLURAL_REDUCER = 1000000 };
  return (n <= 
              (0x7fffffffffffffffL * 2UL + 1UL) 
                        ? n : n % PLURAL_REDUCER + PLURAL_REDUCER);
}
       



typedef ptrdiff_t idx_t;
       






           _Noreturn void xalloc_die (void);





void *xmalloc (size_t s)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__alloc_size__ (1))) __attribute__ ((__returns_nonnull__));
void *ximalloc (idx_t s)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__alloc_size__ (1))) __attribute__ ((__returns_nonnull__));
void *xinmalloc (idx_t n, idx_t s)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__alloc_size__ (1, 2))) __attribute__ ((__returns_nonnull__));
void *xzalloc (size_t s)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__alloc_size__ (1))) __attribute__ ((__returns_nonnull__));
void *xizalloc (idx_t s)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__alloc_size__ (1))) __attribute__ ((__returns_nonnull__));
void *xcalloc (size_t n, size_t s)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__alloc_size__ (1, 2))) __attribute__ ((__returns_nonnull__));
void *xicalloc (idx_t n, idx_t s)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__alloc_size__ (1, 2))) __attribute__ ((__returns_nonnull__));
void *xrealloc (void *p, size_t s)
  __attribute__ ((__alloc_size__ (2)));
void *xirealloc (void *p, idx_t s)
  __attribute__ ((__alloc_size__ (2))) __attribute__ ((__returns_nonnull__));
void *xreallocarray (void *p, size_t n, size_t s)
  __attribute__ ((__alloc_size__ (2, 3)));
void *xireallocarray (void *p, idx_t n, idx_t s)
  __attribute__ ((__alloc_size__ (2, 3))) __attribute__ ((__returns_nonnull__));
void *x2realloc (void *p, size_t *ps)
  __attribute__ ((__returns_nonnull__));
void *x2nrealloc (void *p, size_t *pn, size_t s)
  __attribute__ ((__returns_nonnull__));
void *xpalloc (void *pa, idx_t *pn, idx_t n_incr_min, ptrdiff_t n_max, idx_t s)
  __attribute__ ((__returns_nonnull__));
void *xmemdup (void const *p, size_t s)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__alloc_size__ (2))) __attribute__ ((__returns_nonnull__));
void *ximemdup (void const *p, idx_t s)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__alloc_size__ (2))) __attribute__ ((__returns_nonnull__));
char *ximemdup0 (void const *p, idx_t s)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__returns_nonnull__));
char *xstrdup (char const *str)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__returns_nonnull__));
void *xnmalloc (size_t n, size_t s)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__alloc_size__ (1, 2))) __attribute__ ((__returns_nonnull__));





inline void *xnrealloc (void *p, size_t n, size_t s)
  __attribute__ ((__alloc_size__ (2, 3)));
inline void *
xnrealloc (void *p, size_t n, size_t s)
{
  return xreallocarray (p, n, s);
}




char *xcharalloc (size_t n)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__alloc_size__ (1))) __attribute__ ((__returns_nonnull__));

       








typedef __builtin_va_list __gnuc_va_list;






typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;




typedef struct _G_fpos_t
{
  __off_t __pos;
  __mbstate_t __state;
} __fpos_t;
typedef struct _G_fpos64_t
{
  __off64_t __pos;
  __mbstate_t __state;
} __fpos64_t;



struct _IO_FILE;
typedef struct _IO_FILE __FILE;



struct _IO_FILE;


typedef struct _IO_FILE FILE;
struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;




typedef void _IO_lock_t;





struct _IO_FILE
{
  int _flags;


  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;


  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;
  int _flags2;
  __off_t _old_offset;


  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];

  _IO_lock_t *_lock;







  __off64_t _offset;

  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  size_t __pad5;
  int _mode;

  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};


typedef __ssize_t cookie_read_function_t (void *__cookie, char *__buf,
                                          size_t __nbytes);







typedef __ssize_t cookie_write_function_t (void *__cookie, const char *__buf,
                                           size_t __nbytes);







typedef int cookie_seek_function_t (void *__cookie, __off64_t *__pos, int __w);


typedef int cookie_close_function_t (void *__cookie);






typedef struct _IO_cookie_io_functions_t
{
  cookie_read_function_t *read;
  cookie_write_function_t *write;
  cookie_seek_function_t *seek;
  cookie_close_function_t *close;
} cookie_io_functions_t;





typedef __gnuc_va_list va_list;
typedef __fpos_t fpos_t;




typedef __fpos64_t fpos64_t;

































































































































































































































































struct obstack;























}






}





}






}







}

}








}

}




}





}






}

}

}
}

}

  if ((((__typeof (__n)) 0 < (__typeof (__n)) -1 || (__builtin_constant_p (__n) && (__n) > 0)) && __builtin_constant_p ((((long unsigned int) (__n)) <= (sz) / (sizeof (char)))) && (((long unsigned int) (__n)) <= (sz) / (sizeof (char)))))
    return __fgets_alias (__s, __n, __stream);
  if ((((__typeof (__n)) 0 < (__typeof (__n)) -1 || (__builtin_constant_p (__n) && (__n) > 0)) && __builtin_constant_p ((((long unsigned int) (__n)) <= (sz) / (sizeof (char)))) && !(((long unsigned int) (__n)) <= (sz) / (sizeof (char)))))
    return __fgets_chk_warn (__s, sz, __n, __stream);
  return __fgets_chk (__s, sz, __n, __stream);
}


  if ((((__typeof (__n)) 0 < (__typeof (__n)) -1 || (__builtin_constant_p (__n) && (__n) > 0)) && __builtin_constant_p ((((long unsigned int) (__n)) <= (sz) / (__size))) && (((long unsigned int) (__n)) <= (sz) / (__size))))
    return __fread_alias (__ptr, __size, __n, __stream);
  if ((((__typeof (__n)) 0 < (__typeof (__n)) -1 || (__builtin_constant_p (__n) && (__n) > 0)) && __builtin_constant_p ((((long unsigned int) (__n)) <= (sz) / (__size))) && !(((long unsigned int) (__n)) <= (sz) / (__size))))
    return __fread_chk_warn (__ptr, sz, __size, __n, __stream);
  return __fread_chk (__ptr, sz, __size, __n, __stream);
}



  if ((((__typeof (__n)) 0 < (__typeof (__n)) -1 || (__builtin_constant_p (__n) && (__n) > 0)) && __builtin_constant_p ((((long unsigned int) (__n)) <= (sz) / (sizeof (char)))) && (((long unsigned int) (__n)) <= (sz) / (sizeof (char)))))
    return __fgets_unlocked_alias (__s, __n, __stream);
  if ((((__typeof (__n)) 0 < (__typeof (__n)) -1 || (__builtin_constant_p (__n) && (__n) > 0)) && __builtin_constant_p ((((long unsigned int) (__n)) <= (sz) / (sizeof (char)))) && !(((long unsigned int) (__n)) <= (sz) / (sizeof (char)))))
    return __fgets_unlocked_chk_warn (__s, sz, __n, __stream);
  return __fgets_unlocked_chk (__s, sz, __n, __stream);
}





  if ((((__typeof (__n)) 0 < (__typeof (__n)) -1 || (__builtin_constant_p (__n) && (__n) > 0)) && __builtin_constant_p ((((long unsigned int) (__n)) <= (sz) / (__size))) && (((long unsigned int) (__n)) <= (sz) / (__size))))
    {
      return __fread_unlocked_alias (__ptr, __size, __n, __stream);
    }
  if ((((__typeof (__n)) 0 < (__typeof (__n)) -1 || (__builtin_constant_p (__n) && (__n) > 0)) && __builtin_constant_p ((((long unsigned int) (__n)) <= (sz) / (__size))) && !(((long unsigned int) (__n)) <= (sz) / (__size))))
    return __fread_unlocked_chk_warn (__ptr, sz, __size, __n, __stream);
  return __fread_unlocked_chk (__ptr, sz, __size, __n, __stream);

}




















       






























































































       

       
       





char *base_name (char const *file)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__returns_nonnull__));
char *dir_name (char const *file)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__returns_nonnull__));


char *mdir_name (char const *file)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)));
size_t dir_len (char const *file) __attribute__ ((__pure__));


_Bool 
    strip_trailing_slashes (char *file);
       

       
       







_Noreturn void openat_restore_fail (int);
_Noreturn void openat_save_fail (int);
inline int
chownat (int fd, char const *file, uid_t owner, gid_t group)
{
  return fchownat (fd, file, owner, group, 0);
}

inline int
lchownat (int fd, char const *file, uid_t owner, gid_t group)
{
  return fchownat (fd, file, owner, group, 
                                          0x100
                                                             );
}
inline int
chmodat (int fd, char const *file, mode_t mode)
{
  return fchmodat (fd, file, mode, 0);
}

inline int
lchmodat (int fd, char const *file, mode_t mode)
{
  return fchmodat (fd, file, mode, 
                                  0x100
                                                     );
}


static inline 
             _Bool

dot_or_dotdot (char const *file_name)
{
  if (file_name[0] == '.')
    {
      char sep = file_name[(file_name[1] == '.') + 1];
      return (! sep || ((sep) == '/'));
    }
  else
    return 
          0
               ;
}


static inline struct dirent const *
readdir_ignoring_dot_and_dotdot (DIR *dirp)
{
  while (
        1
            )
    {
      struct dirent const *dp = readdir (dirp);
      if (dp == 
               ((void *)0) 
                    || ! dot_or_dotdot (dp->d_name))
        return dp;
    }
}




static inline 
             _Bool

is_empty_dir (int fd_cwd, char const *dir)
{
  DIR *dirp;
  struct dirent const *dp;
  int saved_errno;
  int fd = openat (fd_cwd, dir,
                   (
                   00 
                            | 
                              0200000
                    
                   | 
                     0400 
                              | 
                                0400000 
                                           | 
                                             04000
                                                       ));

  if (fd < 0)
    return 
          0
               ;

  dirp = fdopendir (fd);
  if (dirp == 
             ((void *)0)
                 )
    {
      close (fd);
      return 
            0
                 ;
    }

  
 (*__errno_location ()) 
       = 0;
  dp = readdir_ignoring_dot_and_dotdot (dirp);
  saved_errno = 
               (*__errno_location ())
                    ;
  closedir (dirp);
  
 (*__errno_location ()) 
       = saved_errno;
  if (dp != 
           ((void *)0)
               )
    return 
          0
               ;
  return saved_errno == 0 ? 
                           1 
                                : 
                                  0
                                       ;
}






enum
{
  GETOPT_HELP_CHAR = (
                     (-0x7f - 1) 
                              - 2),
  GETOPT_VERSION_CHAR = (
                        (-0x7f - 1) 
                                 - 3)
};
void close_stdin_set_file_name (const char *file);
void close_stdin (void);
void close_stdout_set_file_name (const char *file);
void close_stdout_set_ignore_EPIPE (
                                   _Bool 
                                        ignore);
void close_stdout (void);


       

































__attribute__ ((__const__))
static inline size_t
gcd (size_t u, size_t v)
{
  do
    {
      size_t t = u % v;
      u = v;
      v = t;
    }
  while (v);

  return u;
}





__attribute__ ((__const__))
static inline size_t
lcm (size_t u, size_t v)
{
  return u * (v / gcd (u, v));
}






static inline void *
ptr_align (void const *ptr, size_t alignment)
{
  char const *p0 = ptr;
  char const *p1 = p0 + alignment - 1;
  return (void *) (p1 - (size_t) p1 % alignment);
}




__attribute__ ((__pure__))
static inline 
             _Bool

is_nul (void const *buf, size_t length)
{
  const unsigned char *p = buf;
  unsigned char word;


  if (! length)
      return 
            1
                ;


  while (__builtin_expect ((length & (sizeof word - 1)), 0))
    {
      if (*p)
        return 
              0
                   ;
      p++;
      length--;
      if (! length)
        return 
              1
                  ;
   }


  for (;;)
    {
      memcpy (&word, p, sizeof word);
      if (word)
        return 
              0
                   ;
      p += sizeof word;
      length -= sizeof word;
      if (! length)
        return 
              1
                  ;
      if (__builtin_expect ((length & 15), 0) == 0)
        break;
   }


   return memcmp (buf, p, length) == 0;
}
static inline void
emit_stdin_note (void)
{
  fputs_unlocked (
 dcgettext (((void *)0), 
 "\nWith no FILE, or when FILE is -, read standard input.\n"
 , 5)
 ,
 stdout
 )

           ;
}
static inline void
emit_mandatory_arg_note (void)
{
  fputs_unlocked (
 dcgettext (((void *)0), 
 "\nMandatory arguments to long options are mandatory for short options too.\n"
 , 5)
 ,
 stdout
 )

           ;
}

static inline void
emit_size_note (void)
{
  fputs_unlocked (
 dcgettext (((void *)0), 
 "\nThe SIZE argument is an integer and optional unit (example: 10K is 10*1024).\nUnits are K,M,G,T,P,E,Z,Y (powers of 1024) or KB,MB,... (powers of 1000).\nBinary prefixes can be used, too: KiB=K, MiB=M, and so on.\n"
 , 5)
 ,
 stdout
 )



           ;
}

static inline void
emit_blocksize_note (char const *program)
{
  printf (
         dcgettext (((void *)0), 
         "\nDisplay values are in units of the first available SIZE from --block-size,\nand the %s_BLOCK_SIZE, BLOCK_SIZE and BLOCKSIZE environment variables.\nOtherwise, units default to 1024 bytes (or 512 if POSIXLY_CORRECT is set).\n"
         , 5)



  
 , program);
}

static inline void
emit_backup_suffix_note (void)
{
  fputs_unlocked (
 dcgettext (((void *)0), 
 "\nThe backup suffix is '~', unless set with --suffix or SIMPLE_BACKUP_SUFFIX.\nThe version control method may be selected via the --backup option or through\nthe VERSION_CONTROL environment variable.  Here are the values:\n\n"
 , 5)
 ,
 stdout
 )





           ;
  fputs_unlocked (
 dcgettext (((void *)0), 
 "  none, off       never make backups (even if --backup is given)\n  numbered, t     make numbered backups\n  existing, nil   numbered if numbered backups exist, simple otherwise\n  simple, never   always make simple backups\n"
 , 5)
 ,
 stdout
 )




           ;
}

static inline void
emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { 
     ((void *)0)
         , 
           ((void *)0) 
                }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! (strcmp (program, map_prog->program) == 0))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (
         dcgettext (((void *)0), 
         "\n%s online help: <%s>\n"
         , 5)
                                      , "GNU coreutils", "https://www.gnu.org/software/coreutils/");



  char const *lc_messages = setlocale (
                                      5
                                                 , 
                                                   ((void *)0)
                                                       );
  if (lc_messages && strncmp (lc_messages, "" "en_" "", sizeof ("en_") - 1))
    {




      fputs_unlocked (
     dcgettext (((void *)0), 
     "Report any translation bugs to " "<https://translationproject.org/team/>\n"
     , 5)
     ,
     stdout
     )
                                                                   ;
    }



  char const *url_program = (strcmp (program, "[") == 0) ? "test" : program;
  printf (
         dcgettext (((void *)0), 
         "Full documentation <%s%s>\n"
         , 5)
                                         ,
          "https://www.gnu.org/software/coreutils/", url_program);
  printf (
         dcgettext (((void *)0), 
         "or available locally via: info '(coreutils) %s%s'\n"
         , 5)
                                                                 ,
          node, node == program ? " invocation" : "");
}
       



[[__nodiscard__]] char *imaxtostr (intmax_t, char *);
[[__nodiscard__]] char *inttostr (int, char *);
[[__nodiscard__]] char *offtostr (off_t, char *);
[[__nodiscard__]] char *uinttostr (unsigned int, char *);
[[__nodiscard__]] char *umaxtostr (uintmax_t, char *);

static inline char *
timetostr (time_t t, char *buf)
{
  return ((! ((time_t) 0 < (time_t) -1))
          ? imaxtostr (t, buf)
          : umaxtostr (t, buf));
}

static inline char *
bad_cast (char const *s)
{
  return (char *) s;
}


static inline 
             _Bool

usable_st_size (struct stat const *sb)
{
  return (
         ((((
         sb->st_mode
         )) & 0170000) == (0100000)) 
                               || 
                                  ((((
                                  sb->st_mode
                                  )) & 0170000) == (0120000))
          
         || 
            ((
            sb
            )->st_mode - (
            sb
            )->st_mode) 
                             || 
                                0
                                                );
}

_Noreturn void usage (int status);
static inline char *
stzncpy (char *__restrict__ dest, char const *__restrict__ src, size_t len)
{
  char const *src_end = src + len;
  while (src < src_end && *src)
    *dest++ = *src++;
  *dest = 0;
  return dest;
}
static inline 
             _Bool

is_ENOTSUP (int err)
{
  return err == 
               95 
                          || (
                              95 
                                      != 
                                         95 
                                                    && err == 
                                                              95
                                                                     );
}




       







enum quoting_style
  {
    literal_quoting_style,
    shell_quoting_style,
    shell_always_quoting_style,
    shell_escape_quoting_style,
    shell_escape_always_quoting_style,
    c_quoting_style,
    c_maybe_quoting_style,
    escape_quoting_style,
    locale_quoting_style,
    clocale_quoting_style,
    custom_quoting_style
  };


enum quoting_flags
  {



    QA_ELIDE_NULL_BYTES = 0x01,




    QA_ELIDE_OUTER_QUOTES = 0x02,





    QA_SPLIT_TRIGRAPHS = 0x04
  };








struct quoting_options;







struct quoting_options *clone_quoting_options (struct quoting_options *o)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__returns_nonnull__));


enum quoting_style get_quoting_style (struct quoting_options const *o);



void set_quoting_style (struct quoting_options *o, enum quoting_style s);
int set_char_quoting (struct quoting_options *o, char c, int i);





int set_quoting_flags (struct quoting_options *o, int i);
void set_custom_quoting (struct quoting_options *o,
                         char const *left_quote,
                         char const *right_quote);
size_t quotearg_buffer (char *__restrict__ buffer, size_t buffersize,
                        char const *arg, size_t argsize,
                        struct quoting_options const *o);




char *quotearg_alloc (char const *arg, size_t argsize,
                      struct quoting_options const *o)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__returns_nonnull__));







char *quotearg_alloc_mem (char const *arg, size_t argsize,
                          size_t *size, struct quoting_options const *o)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (free, 1)))
  __attribute__ ((__returns_nonnull__));
char *quotearg_n (int n, char const *arg);


char *quotearg (char const *arg);




char *quotearg_n_mem (int n, char const *arg, size_t argsize);


char *quotearg_mem (char const *arg, size_t argsize);




char *quotearg_n_style (int n, enum quoting_style s, char const *arg);




char *quotearg_n_style_mem (int n, enum quoting_style s,
                            char const *arg, size_t argsize);


char *quotearg_style (enum quoting_style s, char const *arg);


char *quotearg_style_mem (enum quoting_style s,
                          char const *arg, size_t argsize);



char *quotearg_char (char const *arg, char ch);


char *quotearg_char_mem (char const *arg, size_t argsize, char ch);


char *quotearg_colon (char const *arg);


char *quotearg_colon_mem (char const *arg, size_t argsize);


char *quotearg_n_style_colon (int n, enum quoting_style s, char const *arg);





char *quotearg_n_custom (int n, char const *left_quote,
                         char const *right_quote, char const *arg);



char *quotearg_n_custom_mem (int n, char const *left_quote,
                             char const *right_quote,
                             char const *arg, size_t argsize);


char *quotearg_custom (char const *left_quote, char const *right_quote,
                       char const *arg);



char *quotearg_custom_mem (char const *left_quote,
                           char const *right_quote,
                           char const *arg, size_t argsize);


void quotearg_free (void);
       










       
typedef unsigned int __re_size_t;
typedef unsigned long int __re_long_size_t;







typedef long int s_reg_t;
typedef unsigned long int active_reg_t;






typedef unsigned long int reg_syntax_t;
typedef enum
{
  _REG_ENOSYS = -1,
  _REG_NOERROR = 0,
  _REG_NOMATCH,



  _REG_BADPAT,
  _REG_ECOLLATE,
  _REG_ECTYPE,
  _REG_EESCAPE,
  _REG_ESUBREG,
  _REG_EBRACK,
  _REG_EPAREN,
  _REG_EBRACE,
  _REG_BADBR,
  _REG_ERANGE,
  _REG_ESPACE,
  _REG_BADRPT,


  _REG_EEND,
  _REG_ESIZE,
  _REG_ERPAREN
} reg_errcode_t;
struct re_pattern_buffer
{


  struct re_dfa_t *buffer;


  __re_long_size_t allocated;


  __re_long_size_t used;


  reg_syntax_t syntax;




  char *fastmap;





  unsigned char * translate;


  size_t re_nsub;





  unsigned can_be_null : 1;
  unsigned regs_allocated : 2;



  unsigned fastmap_accurate : 1;



  unsigned no_sub : 1;



  unsigned not_bol : 1;


  unsigned not_eol : 1;


  unsigned newline_anchor : 1;
};

typedef struct re_pattern_buffer regex_t;
typedef int regoff_t;






struct re_registers
{
  __re_size_t num_regs;
  regoff_t *start;
  regoff_t *end;
};
typedef struct
{
  regoff_t rm_so;
  regoff_t rm_eo;
} regmatch_t;




























       

       
       









char const *quote_n_mem (int n, char const *arg, size_t argsize);




char const *quote_mem (char const *arg, size_t argsize);



char const *quote_n (int n, char const *arg);



char const *quote (char const *arg);
ptrdiff_t argmatch (char const *arg, char const *const *arglist,
                    void const *vallist, size_t valsize) __attribute__ ((__pure__));

ptrdiff_t argmatch_exact (char const *arg, char const *const *arglist)
  __attribute__ ((__pure__));
typedef void (*argmatch_exit_fn) (void);



void argmatch_invalid (char const *context, char const *value,
                       ptrdiff_t problem);
void argmatch_valid (char const *const *arglist,
                     void const *vallist, size_t valsize);
ptrdiff_t __xargmatch_internal (char const *context,
                                char const *arg, char const *const *arglist,
                                void const *vallist, size_t valsize,
                                argmatch_exit_fn exit_fn,
                                
                               _Bool 
                                    allow_abbreviation);
char const *argmatch_to_argument (void const *value,
                                  char const *const *arglist,
                                  void const *vallist, size_t valsize)
  __attribute__ ((__pure__));

       
       
       
typedef enum {
  FADVISE_NORMAL = 
                      0
                                       ,
  FADVISE_SEQUENTIAL = 
                      2
                                           ,
  FADVISE_NOREUSE = 
                      5
                                        ,
  FADVISE_DONTNEED = 
                      4
                                         ,
  FADVISE_WILLNEED = 
                      3
                                         ,
  FADVISE_RANDOM = 
                      1

} fadvice_t;
void fdadvise (int fd, off_t offset, off_t len, fadvice_t advice);
void fadvise (FILE *fp, fadvice_t advice);
       


       








       
       


FILE *fopen_safer (char const *, char const *)
  
 __attribute__ ((__nonnull__ 
 (1, 2)
 )) 
                          __attribute__ ((__malloc__ (
                          rpl_fclose
                          , 1)));



FILE *freopen_safer (char const *, char const *, FILE *)
  
 __attribute__ ((__nonnull__ 
 (2, 3)
 ))
                         ;
enum strtol_error
  {
    LONGINT_OK = 0,



    LONGINT_OVERFLOW = 1,
    LONGINT_INVALID_SUFFIX_CHAR = 2,

    LONGINT_INVALID_SUFFIX_CHAR_WITH_OVERFLOW = (LONGINT_INVALID_SUFFIX_CHAR
                                                 | LONGINT_OVERFLOW),
    LONGINT_INVALID = 4
  };
typedef enum strtol_error strtol_error;




strtol_error xstrtol (const char *, char **, int, long int *, const char *);
strtol_error xstrtoul (const char *, char **, int, unsigned long int *, const char *);
strtol_error xstrtoll (const char *, char **, int, long long int *, const char *);
strtol_error xstrtoull (const char *, char **, int, unsigned long long int *, const char *);
strtol_error xstrtoimax (const char *, char **, int, intmax_t *, const char *);
strtol_error xstrtoumax (const char *, char **, int, uintmax_t *, const char *);
enum Format
{
  UNKNOWN_FORMAT,
  DUMB_FORMAT,
  ROFF_FORMAT,
  TEX_FORMAT
};

static 
      _Bool 
           gnu_extensions = 
                            1
                                ;
static 
      _Bool 
           auto_reference = 
                            0
                                 ;
static 
      _Bool 
           input_reference = 
                             0
                                  ;
static 
      _Bool 
           right_reference = 
                             0
                                  ;
static ptrdiff_t line_width = 72;
static ptrdiff_t gap_size = 3;
static char const *truncation_string = "/";

static char const *macro_name = "xx";
static enum Format output_format = UNKNOWN_FORMAT;


static 
      _Bool 
           ignore_case = 
                         0
                              ;
static char const *break_file = 
                               ((void *)0)
                                   ;
static char const *only_file = 
                              ((void *)0)
                                  ;
static char const *ignore_file = 
                                ((void *)0)
                                    ;


struct regex_data
{

  char const *string;


  struct re_pattern_buffer pattern;
  char fastmap[
              (0x7f * 2 + 1) 
                        + 1];
};

static struct regex_data context_regex;
static struct regex_data word_regex;





typedef struct
  {
    char *start;
    char *end;
  }
BLOCK;

typedef struct
  {
    char *start;
    ptrdiff_t size;
  }
WORD;

typedef struct
  {
    WORD *start;
    size_t alloc;
    ptrdiff_t length;
  }
WORD_TABLE;




static unsigned char folded_chars[256];


static struct re_registers context_regs;


static struct re_registers word_regs;






static char word_fastmap[256];


static ptrdiff_t maximum_word_length;


static ptrdiff_t reference_max_width;



static WORD_TABLE ignore_table;
static WORD_TABLE only_table;



static int number_input_files;
static intmax_t total_line_count;
static char const **input_file_name;
static intmax_t *file_line_count;

static BLOCK *text_buffers;
typedef struct
  {
    WORD key;
    ptrdiff_t left;
    ptrdiff_t right;
    intmax_t reference;
    int file_index;
  }
OCCURS;




static OCCURS *occurs_table[1];
static size_t occurs_alloc[1];
static ptrdiff_t number_of_occurs[1];





static char edited_flag[256];


static ptrdiff_t half_line_width;


static ptrdiff_t before_max_width;


static ptrdiff_t keyafter_max_width;


static ptrdiff_t truncation_string_length;







static BLOCK tail;
static 
      _Bool 
           tail_truncation;

static BLOCK before;
static 
      _Bool 
           before_truncation;

static BLOCK keyafter;
static 
      _Bool 
           keyafter_truncation;

static BLOCK head;
static 
      _Bool 
           head_truncation;

static BLOCK reference;





static void
matcher_error (void)
{
  ((!!sizeof (struct { _Static_assert (
 1
 , "verify_expr (" "1" ", " "(error (1, (*__errno_location ()), dcgettext (((void *)0), \"error in regular expression matcher\", 5)), assume (false))" ")"); int _gl_dummy; })) ? ((error (
 1
 , 
 (*__errno_location ())
 , 
 dcgettext (((void *)0), 
 "error in regular expression matcher"
 , 5)
 ), ((
 0
 ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
 1
 , 
 (*__errno_location ())
 , 
 dcgettext (((void *)0), 
 "error in regular expression matcher"
 , 5)
 ), ((
 0
 ) ? (void) 0 : __builtin_unreachable ()))));
}



static void
unescape_string (char *string)
{
  char *cursor;
  int value;
  int length;

  cursor = string;

  while (*string)
    {
      if (*string == '\\')
        {
          string++;
          switch (*string)
            {
            case 'x':
              value = 0;
              for (length = 0, string++;
                   length < 3 && 
                                ((*__ctype_b_loc ())[(int) ((
                                to_uchar (*string)
                                ))] & (unsigned short int) _ISxdigit)
                                                             ;
                   length++, string++)
                value = value * 16 + ((*string) >= 'a' && (*string) <= 'f' ? (*string)-'a'+10 : (*string) >= 'A' && (*string) <= 'F' ? (*string)-'A'+10 : (*string)-'0');
              if (length == 0)
                {
                  *cursor++ = '\\';
                  *cursor++ = 'x';
                }
              else
                *cursor++ = value;
              break;

            case '0':
              value = 0;
              for (length = 0, string++;
                   length < 3 && ((*string) >= '0' && (*string) <= '7');
                   length++, string++)
                value = value * 8 + ((*string) - '0');
              *cursor++ = value;
              break;

            case 'a':

              *cursor++ = '\a';



              string++;
              break;

            case 'b':
              *cursor++ = '\b';
              string++;
              break;

            case 'c':
              while (*string)
                string++;
              break;

            case 'f':
              *cursor++ = '\f';
              string++;
              break;

            case 'n':
              *cursor++ = '\n';
              string++;
              break;

            case 'r':
              *cursor++ = '\r';
              string++;
              break;

            case 't':
              *cursor++ = '\t';
              string++;
              break;

            case 'v':

              *cursor++ = '\v';



              string++;
              break;

            case '\0':

              break;

            default:
              *cursor++ = '\\';
              *cursor++ = *string++;
              break;
            }
        }
      else
        *cursor++ = *string++;
    }

  *cursor = '\0';
}





static void
compile_regex (struct regex_data *regex)
{
  struct re_pattern_buffer *pattern = &regex->pattern;
  char const *string = regex->string;
  char const *message;

  pattern->buffer = 
                   ((void *)0)
                       ;
  pattern->allocated = 0;
  pattern->fastmap = regex->fastmap;
  pattern->translate = ignore_case ? folded_chars : 
                                                   ((void *)0)
                                                       ;

  message = re_compile_pattern (string, strlen (string), pattern);
  if (message)
    ((!!sizeof (struct { _Static_assert (
   1
   , "verify_expr (" "1" ", " "(error (1, 0, dcgettext (((void *)0), \"%s (for regexp %s)\", 5), message, quote (string)), assume (false))" ")"); int _gl_dummy; })) ? ((error (
   1
   , 0, 
   dcgettext (((void *)0), 
   "%s (for regexp %s)"
   , 5)
   , message, quote (string)), ((
   0
   ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
   1
   , 0, 
   dcgettext (((void *)0), 
   "%s (for regexp %s)"
   , 5)
   , message, quote (string)), ((
   0
   ) ? (void) 0 : __builtin_unreachable ()))));





  re_compile_fastmap (pattern);
}






static void
initialize_regex (void)
{
  int character;



  if (ignore_case)
    for (character = 0; character < 256; character++)
      folded_chars[character] = 
                               (__extension__ ({ int __res; if (sizeof (
                               character
                               ) > 1) { if (__builtin_constant_p (
                               character
                               )) { int __c = (
                               character
                               ); __res = __c < -128 || __c > 255 ? __c : (*__ctype_toupper_loc ())[__c]; } else __res = toupper (
                               character
                               ); } else __res = (*__ctype_toupper_loc ())[(int) (
                               character
                               )]; __res; }))
                                                  ;
  if (context_regex.string)
    {
      if (!*context_regex.string)
        context_regex.string = 
                              ((void *)0)
                                  ;
    }
  else if (gnu_extensions && !input_reference)
    context_regex.string = "[.?!][]\"')}]*\\($\\|\t\\|  \\)[ \t\n]*";
  else
    context_regex.string = "\n";

  if (context_regex.string)
    compile_regex (&context_regex);
  if (word_regex.string)
    compile_regex (&word_regex);
  else if (!break_file)
    {
      if (gnu_extensions)
        {



          for (character = 0; character < 256; character++)
            word_fastmap[character] = !! 
                                        ((*__ctype_b_loc ())[(int) ((
                                        character
                                        ))] & (unsigned short int) _ISalpha)
                                                           ;
        }
      else
        {



          memset (word_fastmap, 1, 256);
          word_fastmap[' '] = 0;
          word_fastmap['\t'] = 0;
          word_fastmap['\n'] = 0;
        }
    }
}
static void
swallow_file_in_memory (char const *file_name, BLOCK *block)
{
  size_t used_length;




  
 _Bool 
      using_stdin = !file_name || !*file_name || (strcmp (file_name, "-") == 0);
  if (using_stdin)
    block->start = fread_file (
                              stdin
                                   , 0, &used_length);
  else
    block->start = read_file (file_name, 0, &used_length);

  if (!block->start)
    ((!!sizeof (struct { _Static_assert (
   1
   , "verify_expr (" "1" ", " "(error (1, (*__errno_location ()), \"%s\", quotearg_n_style_colon (0, shell_escape_quoting_style, using_stdin ? \"-\" : file_name)), assume (false))" ")"); int _gl_dummy; })) ? ((error (
   1
   , 
   (*__errno_location ())
   , "%s", quotearg_n_style_colon (0, shell_escape_quoting_style, using_stdin ? "-" : file_name)), ((
   0
   ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
   1
   , 
   (*__errno_location ())
   , "%s", quotearg_n_style_colon (0, shell_escape_quoting_style, using_stdin ? "-" : file_name)), ((
   0
   ) ? (void) 0 : __builtin_unreachable ()))));

  if (using_stdin)
    clearerr_unlocked (
   stdin
   );

  block->end = block->start + used_length;
}
static int
compare_words (const void *void_first, const void *void_second)
{


  ptrdiff_t length;
  ptrdiff_t counter;
  int value;

  length = ((const WORD *) void_first)->size < ((const WORD *) void_second)->size ? ((const WORD *) void_first)->size : ((const WORD *) void_second)->size;

  if (ignore_case)
    {
      for (counter = 0; counter < length; counter++)
        {
          value = (folded_chars [to_uchar (((const WORD *) void_first)->start[counter])]
                   - folded_chars [to_uchar (((const WORD *) void_second)->start[counter])]);
          if (value != 0)
            return value;
        }
    }
  else
    {
      for (counter = 0; counter < length; counter++)
        {
          value = (to_uchar (((const WORD *) void_first)->start[counter])
                   - to_uchar (((const WORD *) void_second)->start[counter]));
          if (value != 0)
            return value;
        }
    }

  return ((const WORD *) void_first)->size < ((const WORD *) void_second)->size ? -1 : ((const WORD *) void_first)->size > ((const WORD *) void_second)->size;


}







static int
compare_occurs (const void *void_first, const void *void_second)
{


  int value;

  value = compare_words (&((const OCCURS *) void_first)->key, &((const OCCURS *) void_second)->key);
  return (value ? value
          : ((const OCCURS *) void_first)->key.start < ((const OCCURS *) void_second)->key.start ? -1
          : ((const OCCURS *) void_first)->key.start > ((const OCCURS *) void_second)->key.start);


}



__attribute__ ((__pure__))
static 
      _Bool

search_table (WORD *word, WORD_TABLE *table)
{
  ptrdiff_t lowest;
  ptrdiff_t highest;
  ptrdiff_t middle;
  int value;

  lowest = 0;
  highest = table->length - 1;
  while (lowest <= highest)
    {
      middle = (lowest + highest) / 2;
      value = compare_words (word, table->start + middle);
      if (value < 0)
        highest = middle - 1;
      else if (value > 0)
        lowest = middle + 1;
      else
        return 
              1
                  ;
    }
  return 
        0
             ;
}







static void
sort_found_occurs (void)
{


  if (number_of_occurs[0])
    qsort (occurs_table[0], number_of_occurs[0], sizeof **occurs_table,
           compare_occurs);
}
static void
digest_break_file (char const *file_name)
{
  BLOCK file_contents;
  char *cursor;

  swallow_file_in_memory (file_name, &file_contents);



  memset (word_fastmap, 1, 256);
  for (cursor = file_contents.start; cursor < file_contents.end; cursor++)
    word_fastmap[to_uchar (*cursor)] = 0;

  if (!gnu_extensions)
    {







      word_fastmap[' '] = 0;
      word_fastmap['\t'] = 0;
      word_fastmap['\n'] = 0;
    }



  free (file_contents.start);
}
static void
digest_word_file (char const *file_name, WORD_TABLE *table)
{
  BLOCK file_contents;
  char *cursor;
  char *word_start;

  swallow_file_in_memory (file_name, &file_contents);

  table->start = 
                ((void *)0)
                    ;
  table->alloc = 0;
  table->length = 0;



  cursor = file_contents.start;
  while (cursor < file_contents.end)
    {



      word_start = cursor;
      while (cursor < file_contents.end && *cursor != '\n')
        cursor++;



      if (cursor > word_start)
        {
          if (table->length == table->alloc)
            table->start = x2nrealloc (table->start, &table->alloc,
                                       sizeof *table->start);
          table->start[table->length].start = word_start;
          table->start[table->length].size = cursor - word_start;
          table->length++;
        }



      if (cursor < file_contents.end)
        cursor++;
    }



  qsort (table->start, table->length, sizeof table->start[0], compare_words);
}







static void
find_occurs_in_text (int file_index)
{
  char *cursor;
  char *scan;
  char *line_start;
  char *line_scan;
  ptrdiff_t reference_length;
  WORD possible_key;
  OCCURS *occurs_cursor;

  char *context_start;
  char *context_end;
  char *word_start;
  char *word_end;
  char *next_context_start;

  const BLOCK *text_buffer = &text_buffers[file_index];





  reference_length = 0;
  line_start = text_buffer->start;
  line_scan = line_start;
  if (input_reference)
    {
      while (line_scan < text_buffer->end && ! 
     ((*__ctype_b_loc ())[(int) ((
     to_uchar (*line_scan)
     ))] & (unsigned short int) _ISspace)
     ) line_scan++;
      reference_length = line_scan - line_start;
      while (line_scan < text_buffer->end && 
     ((*__ctype_b_loc ())[(int) ((
     to_uchar (*line_scan)
     ))] & (unsigned short int) _ISspace)
     ) line_scan++;
    }



  for (cursor = text_buffer->start;
       cursor < text_buffer->end;
       cursor = next_context_start)
    {





      context_start = cursor;
      next_context_start = text_buffer->end;
      if (context_regex.string)
        switch (re_search (&context_regex.pattern, cursor,
                           text_buffer->end - cursor,
                           0, text_buffer->end - cursor, &context_regs))
          {
          case -2:
            matcher_error ();

          case -1:
            break;

          case 0:
            ((!!sizeof (struct { _Static_assert (
           1
           , "verify_expr (" "1" ", " "(error (1, 0, dcgettext (((void *)0), \"error: regular expression has a match of length zero: %s\", 5), quote (context_regex.string)), assume (false))" ")"); int _gl_dummy; })) ? ((error (
           1
           , 0, 
           dcgettext (((void *)0), 
           "error: regular expression has a match of length zero: %s"
           , 5)
           , quote (context_regex.string)), ((
           0
           ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
           1
           , 0, 
           dcgettext (((void *)0), 
           "error: regular expression has a match of length zero: %s"
           , 5)
           , quote (context_regex.string)), ((
           0
           ) ? (void) 0 : __builtin_unreachable ()))))

                                              ;

          default:
            next_context_start = cursor + context_regs.end[0];
            break;
          }





      context_end = next_context_start;
      while (context_end > context_start && 
     ((*__ctype_b_loc ())[(int) ((
     to_uchar (context_end[-1])
     ))] & (unsigned short int) _ISspace)
     ) context_end--;




      while (
            1
                )
        {
          if (word_regex.string)





            {
              regoff_t r = re_search (&word_regex.pattern, cursor,
                                      context_end - cursor,
                                      0, context_end - cursor, &word_regs);
              if (r == -2)
                matcher_error ();
              if (r == -1)
                break;
              word_start = cursor + word_regs.start[0];
              word_end = cursor + word_regs.end[0];
            }
          else





            {
              scan = cursor;
              while (scan < context_end
                     && !word_fastmap[to_uchar (*scan)])
                scan++;

              if (scan == context_end)
                break;

              word_start = scan;

              while (scan < context_end
                     && word_fastmap[to_uchar (*scan)])
                scan++;

              word_end = scan;
            }



          cursor = word_start;




          if (word_end == word_start)
            {
              cursor++;
              continue;
            }
          possible_key.start = cursor;
          possible_key.size = word_end - word_start;
          cursor += possible_key.size;

          if (possible_key.size > maximum_word_length)
            maximum_word_length = possible_key.size;






          if (input_reference)
            {
              while (line_scan < possible_key.start)
                if (*line_scan == '\n')
                  {
                    total_line_count++;
                    line_scan++;
                    line_start = line_scan;
                    while (line_scan < text_buffer->end && ! 
                   ((*__ctype_b_loc ())[(int) ((
                   to_uchar (*line_scan)
                   ))] & (unsigned short int) _ISspace)
                   ) line_scan++;
                    reference_length = line_scan - line_start;
                  }
                else
                  line_scan++;
              if (line_scan > possible_key.start)
                continue;
            }
          if (ignore_file && search_table (&possible_key, &ignore_table))
            continue;
          if (only_file && !search_table (&possible_key, &only_table))
            continue;





          if (number_of_occurs[0] == occurs_alloc[0])
            occurs_table[0] = x2nrealloc (occurs_table[0],
                                          &occurs_alloc[0],
                                          sizeof *occurs_table[0]);
          occurs_cursor = occurs_table[0] + number_of_occurs[0];



          if (auto_reference)
            {







              while (line_scan < possible_key.start)
                if (*line_scan == '\n')
                  {
                    total_line_count++;
                    line_scan++;
                    line_start = line_scan;
                    while (line_scan < text_buffer->end && ! 
                   ((*__ctype_b_loc ())[(int) ((
                   to_uchar (*line_scan)
                   ))] & (unsigned short int) _ISspace)
                   ) line_scan++;
                  }
                else
                  line_scan++;

              occurs_cursor->reference = total_line_count;
            }
          else if (input_reference)
            {






              occurs_cursor->reference = line_start - possible_key.start;
              if (reference_length > reference_max_width)
                reference_max_width = reference_length;
            }



          if (input_reference && line_start == context_start)
            {
              while (context_start < context_end && ! 
             ((*__ctype_b_loc ())[(int) ((
             to_uchar (*context_start)
             ))] & (unsigned short int) _ISspace)
             ) context_start++;
              while (context_start < context_end && 
             ((*__ctype_b_loc ())[(int) ((
             to_uchar (*context_start)
             ))] & (unsigned short int) _ISspace)
             ) context_start++;
            }



          occurs_cursor->key = possible_key;
          occurs_cursor->left = context_start - possible_key.start;
          occurs_cursor->right = context_end - possible_key.start;
          occurs_cursor->file_index = file_index;

          number_of_occurs[0]++;
        }
    }
}







static void
print_spaces (ptrdiff_t number)
{
  for (ptrdiff_t counter = number; counter > 0; counter--)
    putchar_unlocked (' ');
}





static void
print_field (BLOCK field)
{
  char *cursor;




  for (cursor = field.start; cursor < field.end; cursor++)
    {
      unsigned char character = *cursor;
      if (edited_flag[character])
        {




          switch (character)
            {
            case '"':

              putchar_unlocked ('"');
              putchar_unlocked ('"');
              break;

            case '$':
            case '%':
            case '&':
            case '_':

              putchar_unlocked ('\\');
              putchar_unlocked (character);
              break;

            case '{':
            case '}':


              printf ("$\\%c$", character);
              break;

            case '\\':

              fputs_unlocked ("\\backslash{}",
             stdout
             );
              break;

            default:

              putchar_unlocked (' ');
            }
        }
      else
        putchar_unlocked (*cursor);
    }
}
static void
fix_output_parameters (void)
{
  size_t file_index;
  intmax_t line_ordinal;
  ptrdiff_t reference_width;
  int character;
  char const *cursor;





  if (auto_reference)
    {
      reference_max_width = 0;
      for (file_index = 0; file_index < number_input_files; file_index++)
        {
          line_ordinal = file_line_count[file_index] + 1;
          if (file_index > 0)
            line_ordinal -= file_line_count[file_index - 1];
          char ordinal_string[((((((sizeof (intmax_t) * 8) - (! ((__typeof__ (intmax_t)) 0 < (__typeof__ (intmax_t)) -1))) * 146 + 484) / 485) + (! ((__typeof__ (intmax_t)) 0 < (__typeof__ (intmax_t)) -1))) + 1)];
          reference_width = sprintf (ordinal_string, "%"
                                                       "l" "d"
                                                              , line_ordinal);
          if (input_file_name[file_index])
            reference_width += strlen (input_file_name[file_index]);
          if (reference_width > reference_max_width)
            reference_max_width = reference_width;
        }
      reference_max_width++;
      reference.start = xmalloc (reference_max_width + 1);
    }




  if ((auto_reference || input_reference) && !right_reference)
    line_width -= reference_max_width + gap_size;
  if (line_width < 0)
    line_width = 0;
  half_line_width = line_width / 2;
  before_max_width = half_line_width - gap_size;
  keyafter_max_width = half_line_width;





  if (truncation_string && *truncation_string)
    truncation_string_length = strlen (truncation_string);
  else
    truncation_string = 
                       ((void *)0)
                           ;

  if (gnu_extensions)
    {
      before_max_width -= 2 * truncation_string_length;
      if (before_max_width < 0)
        before_max_width = 0;
      keyafter_max_width -= 2 * truncation_string_length;
    }
  else
    {







      keyafter_max_width -= 2 * truncation_string_length + 1;
    }





  for (character = 0; character < 256; character++)
    edited_flag[character] = !! 
                               ((*__ctype_b_loc ())[(int) ((
                               character
                               ))] & (unsigned short int) _ISspace)
                                                  ;
  edited_flag['\f'] = 1;




  switch (output_format)
    {
    case UNKNOWN_FORMAT:


    case DUMB_FORMAT:
      break;

    case ROFF_FORMAT:



      edited_flag['"'] = 1;
      break;

    case TEX_FORMAT:



        edited_flag[to_uchar (*cursor)] = 1;

      break;
    }
}






static void
define_all_fields (OCCURS *occurs)
{
  ptrdiff_t tail_max_width;
  ptrdiff_t head_max_width;
  char *cursor;
  char *left_context_start;
  char *right_context_end;
  char *left_field_start;
  char const *file_name;
  intmax_t line_ordinal;
  char const *buffer_start;
  char const *buffer_end;







  keyafter.start = occurs->key.start;
  keyafter.end = keyafter.start + occurs->key.size;
  left_context_start = keyafter.start + occurs->left;
  right_context_end = keyafter.start + occurs->right;

  buffer_start = text_buffers[occurs->file_index].start;
  buffer_end = text_buffers[occurs->file_index].end;

  cursor = keyafter.end;
  while (cursor < right_context_end
         && cursor <= keyafter.start + keyafter_max_width)
    {
      keyafter.end = cursor;
      if (word_regex.string) { regoff_t count; count = re_match (&word_regex.pattern, cursor, right_context_end - cursor, 0, 
     ((void *)0)
     ); if (count == -2) matcher_error (); cursor += count == -1 ? 1 : count; } else if (word_fastmap[to_uchar (*cursor)]) while (cursor < right_context_end && word_fastmap[to_uchar (*cursor)]) cursor++; else cursor++;
    }
  if (cursor <= keyafter.start + keyafter_max_width)
    keyafter.end = cursor;

  keyafter_truncation = truncation_string && keyafter.end < right_context_end;

  while (keyafter.end > keyafter.start && 
 ((*__ctype_b_loc ())[(int) ((
 to_uchar (keyafter.end[-1])
 ))] & (unsigned short int) _ISspace)
 ) keyafter.end--;
  if (-occurs->left > half_line_width + maximum_word_length)
    {
      left_field_start
        = keyafter.start - (half_line_width + maximum_word_length);
      if (word_regex.string) { regoff_t count; count = re_match (&word_regex.pattern, left_field_start, keyafter.start - left_field_start, 0, 
     ((void *)0)
     ); if (count == -2) matcher_error (); left_field_start += count == -1 ? 1 : count; } else if (word_fastmap[to_uchar (*left_field_start)]) while (left_field_start < keyafter.start && word_fastmap[to_uchar (*left_field_start)]) left_field_start++; else left_field_start++;
    }
  else
    left_field_start = keyafter.start + occurs->left;







  before.start = left_field_start;
  before.end = keyafter.start;
  while (before.end > before.start && 
 ((*__ctype_b_loc ())[(int) ((
 to_uchar (before.end[-1])
 ))] & (unsigned short int) _ISspace)
 ) before.end--;

  while (before.start + before_max_width < before.end)
    if (word_regex.string) { regoff_t count; count = re_match (&word_regex.pattern, before.start, before.end - before.start, 0, 
   ((void *)0)
   ); if (count == -2) matcher_error (); before.start += count == -1 ? 1 : count; } else if (word_fastmap[to_uchar (*before.start)]) while (before.start < before.end && word_fastmap[to_uchar (*before.start)]) before.start++; else before.start++;

  if (truncation_string)
    {
      cursor = before.start;
      while (cursor > buffer_start && 
     ((*__ctype_b_loc ())[(int) ((
     to_uchar (cursor[-1])
     ))] & (unsigned short int) _ISspace)
     ) cursor--;
      before_truncation = cursor > left_context_start;
    }
  else
    before_truncation = 
                       0
                            ;

  while (before.start < buffer_end && 
 ((*__ctype_b_loc ())[(int) ((
 to_uchar (*before.start)
 ))] & (unsigned short int) _ISspace)
 ) before.start++;
  tail_max_width
    = before_max_width - (before.end - before.start) - gap_size;

  if (tail_max_width > 0)
    {
      tail.start = keyafter.end;
      while (tail.start < buffer_end && 
     ((*__ctype_b_loc ())[(int) ((
     to_uchar (*tail.start)
     ))] & (unsigned short int) _ISspace)
     ) tail.start++;

      tail.end = tail.start;
      cursor = tail.end;
      while (cursor < right_context_end
             && cursor < tail.start + tail_max_width)
        {
          tail.end = cursor;
          if (word_regex.string) { regoff_t count; count = re_match (&word_regex.pattern, cursor, right_context_end - cursor, 0, 
         ((void *)0)
         ); if (count == -2) matcher_error (); cursor += count == -1 ? 1 : count; } else if (word_fastmap[to_uchar (*cursor)]) while (cursor < right_context_end && word_fastmap[to_uchar (*cursor)]) cursor++; else cursor++;
        }

      if (cursor < tail.start + tail_max_width)
        tail.end = cursor;

      if (tail.end > tail.start)
        {
          keyafter_truncation = 
                               0
                                    ;
          tail_truncation = truncation_string && tail.end < right_context_end;
        }
      else
        tail_truncation = 
                         0
                              ;

      while (tail.end > tail.start && 
     ((*__ctype_b_loc ())[(int) ((
     to_uchar (tail.end[-1])
     ))] & (unsigned short int) _ISspace)
     ) tail.end--;
    }
  else
    {



      tail.start = 
                  ((void *)0)
                      ;
      tail.end = 
                ((void *)0)
                    ;
      tail_truncation = 
                       0
                            ;
    }







  head_max_width
    = keyafter_max_width - (keyafter.end - keyafter.start) - gap_size;

  if (head_max_width > 0)
    {
      head.end = before.start;
      while (head.end > buffer_start && 
     ((*__ctype_b_loc ())[(int) ((
     to_uchar (head.end[-1])
     ))] & (unsigned short int) _ISspace)
     ) head.end--;

      head.start = left_field_start;
      while (head.start + head_max_width < head.end)
        if (word_regex.string) { regoff_t count; count = re_match (&word_regex.pattern, head.start, head.end - head.start, 0, 
       ((void *)0)
       ); if (count == -2) matcher_error (); head.start += count == -1 ? 1 : count; } else if (word_fastmap[to_uchar (*head.start)]) while (head.start < head.end && word_fastmap[to_uchar (*head.start)]) head.start++; else head.start++;

      if (head.end > head.start)
        {
          before_truncation = 
                             0
                                  ;
          head_truncation = (truncation_string
                             && head.start > left_context_start);
        }
      else
        head_truncation = 
                         0
                              ;

      while (head.start < head.end && 
     ((*__ctype_b_loc ())[(int) ((
     to_uchar (*head.start)
     ))] & (unsigned short int) _ISspace)
     ) head.start++;
    }
  else
    {



      head.start = 
                  ((void *)0)
                      ;
      head.end = 
                ((void *)0)
                    ;
      head_truncation = 
                       0
                            ;
    }

  if (auto_reference)
    {





      file_name = input_file_name[occurs->file_index];
      if (!file_name)
        file_name = "";

      line_ordinal = occurs->reference + 1;
      if (occurs->file_index > 0)
        line_ordinal -= file_line_count[occurs->file_index - 1];

      char *file_end = stpcpy (reference.start, file_name);
      reference.end = file_end + sprintf (file_end, ":%"
                                                       "l" "d"
                                                              , line_ordinal);
    }
  else if (input_reference)
    {




      reference.start = keyafter.start + occurs->reference;
      reference.end = reference.start;
      while (reference.end < right_context_end && ! 
     ((*__ctype_b_loc ())[(int) ((
     to_uchar (*reference.end)
     ))] & (unsigned short int) _ISspace)
     ) reference.end++;
    }
}







static void
output_one_roff_line (void)
{


  printf (".%s \"", macro_name);
  print_field (tail);
  if (tail_truncation)
    fputs_unlocked (truncation_string,
   stdout
   );
  putchar_unlocked ('"');



  fputs_unlocked (" \"",
 stdout
 );
  if (before_truncation)
    fputs_unlocked (truncation_string,
   stdout
   );
  print_field (before);
  putchar_unlocked ('"');



  fputs_unlocked (" \"",
 stdout
 );
  print_field (keyafter);
  if (keyafter_truncation)
    fputs_unlocked (truncation_string,
   stdout
   );
  putchar_unlocked ('"');



  fputs_unlocked (" \"",
 stdout
 );
  if (head_truncation)
    fputs_unlocked (truncation_string,
   stdout
   );
  print_field (head);
  putchar_unlocked ('"');



  if (auto_reference || input_reference)
    {
      fputs_unlocked (" \"",
     stdout
     );
      print_field (reference);
      putchar_unlocked ('"');
    }

  putchar_unlocked ('\n');
}





static void
output_one_tex_line (void)
{
  BLOCK key;
  BLOCK after;
  char *cursor;

  printf ("\\%s ", macro_name);
  putchar_unlocked ('{');
  print_field (tail);
  fputs_unlocked ("}{",
 stdout
 );
  print_field (before);
  fputs_unlocked ("}{",
 stdout
 );
  key.start = keyafter.start;
  after.end = keyafter.end;
  cursor = keyafter.start;
  if (word_regex.string) { regoff_t count; count = re_match (&word_regex.pattern, cursor, keyafter.end - cursor, 0, 
 ((void *)0)
 ); if (count == -2) matcher_error (); cursor += count == -1 ? 1 : count; } else if (word_fastmap[to_uchar (*cursor)]) while (cursor < keyafter.end && word_fastmap[to_uchar (*cursor)]) cursor++; else cursor++;
  key.end = cursor;
  after.start = cursor;
  print_field (key);
  fputs_unlocked ("}{",
 stdout
 );
  print_field (after);
  fputs_unlocked ("}{",
 stdout
 );
  print_field (head);
  putchar_unlocked ('}');
  if (auto_reference || input_reference)
    {
      putchar_unlocked ('{');
      print_field (reference);
      putchar_unlocked ('}');
    }
  putchar_unlocked ('\n');
}





static void
output_one_dumb_line (void)
{
  if (!right_reference)
    {
      if (auto_reference)
        {





          print_field (reference);
          putchar_unlocked (':');
          print_spaces (reference_max_width
                        + gap_size
                        - (reference.end - reference.start)
                        - 1);
        }
      else
        {



          print_field (reference);
          print_spaces (reference_max_width
                        + gap_size
                        - (reference.end - reference.start));
        }
    }

  if (tail.start < tail.end)
    {


      print_field (tail);
      if (tail_truncation)
        fputs_unlocked (truncation_string,
       stdout
       );

      print_spaces (half_line_width - gap_size
                    - (before.end - before.start)
                    - (before_truncation ? truncation_string_length : 0)
                    - (tail.end - tail.start)
                    - (tail_truncation ? truncation_string_length : 0));
    }
  else
    print_spaces (half_line_width - gap_size
                  - (before.end - before.start)
                  - (before_truncation ? truncation_string_length : 0));



  if (before_truncation)
    fputs_unlocked (truncation_string,
   stdout
   );
  print_field (before);

  print_spaces (gap_size);



  print_field (keyafter);
  if (keyafter_truncation)
    fputs_unlocked (truncation_string,
   stdout
   );

  if (head.start < head.end)
    {


      print_spaces (half_line_width
                    - (keyafter.end - keyafter.start)
                    - (keyafter_truncation ? truncation_string_length : 0)
                    - (head.end - head.start)
                    - (head_truncation ? truncation_string_length : 0));
      if (head_truncation)
        fputs_unlocked (truncation_string,
       stdout
       );
      print_field (head);
    }
  else

    if ((auto_reference || input_reference) && right_reference)
      print_spaces (half_line_width
                    - (keyafter.end - keyafter.start)
                    - (keyafter_truncation ? truncation_string_length : 0));

  if ((auto_reference || input_reference) && right_reference)
    {


      print_spaces (gap_size);
      print_field (reference);
    }

  putchar_unlocked ('\n');
}






static void
generate_all_output (void)
{
  ptrdiff_t occurs_index;
  OCCURS *occurs_cursor;





  tail.start = 
              ((void *)0)
                  ;
  tail.end = 
            ((void *)0)
                ;
  tail_truncation = 
                   0
                        ;

  head.start = 
              ((void *)0)
                  ;
  head.end = 
            ((void *)0)
                ;
  head_truncation = 
                   0
                        ;



  occurs_cursor = occurs_table[0];

  for (occurs_index = 0; occurs_index < number_of_occurs[0]; occurs_index++)
    {



      define_all_fields (occurs_cursor);



      switch (output_format)
        {
        case UNKNOWN_FORMAT:


        case DUMB_FORMAT:
          output_one_dumb_line ();
          break;

        case ROFF_FORMAT:
          output_one_roff_line ();
          break;

        case TEX_FORMAT:
          output_one_tex_line ();
          break;
        }



      occurs_cursor++;
    }
}







void
usage (int status)
{
  if (status != 
               0
                           )
    do { fprintf (
   stderr
   , 
   dcgettext (((void *)0), 
   "Try '%s --help' for more information.\n"
   , 5)
   , program_name); } while (0);
  else
    {
      printf (
             dcgettext (((void *)0), 
             "Usage: %s [OPTION]... [INPUT]...   (without -G)\n  or:  %s -G [OPTION]... [INPUT [OUTPUT]]\n"
             , 5)

                                             
                                            ,
              program_name, program_name);
      fputs_unlocked (
     dcgettext (((void *)0), 
     "Output a permuted index, including context, of the words in the input files.\n"
     , 5)
     ,
     stdout
     )

           ;

      emit_stdin_note ();
      emit_mandatory_arg_note ();

      fputs_unlocked (
     dcgettext (((void *)0), 
     "  -A, --auto-reference           output automatically generated references\n  -G, --traditional              behave more like System V 'ptx'\n"
     , 5)
     ,
     stdout
     )


           ;
      fputs_unlocked (
     dcgettext (((void *)0), 
     "  -F, --flag-truncation=STRING   use STRING for flagging line truncations.\n                                 The default is '/'\n"
     , 5)
     ,
     stdout
     )


           ;
      fputs_unlocked (
     dcgettext (((void *)0), 
     "  -M, --macro-name=STRING        macro name to use instead of 'xx'\n  -O, --format=roff              generate output as roff directives\n  -R, --right-side-refs          put references at right, not counted in -w\n  -S, --sentence-regexp=REGEXP   for end of lines or end of sentences\n  -T, --format=tex               generate output as TeX directives\n"
     , 5)
     ,
     stdout
     )





           ;
      fputs_unlocked (
     dcgettext (((void *)0), 
     "  -W, --word-regexp=REGEXP       use REGEXP to match each keyword\n  -b, --break-file=FILE          word break characters in this FILE\n  -f, --ignore-case              fold lower case to upper case for sorting\n  -g, --gap-size=NUMBER          gap size in columns between output fields\n  -i, --ignore-file=FILE         read ignore word list from FILE\n  -o, --only-file=FILE           read only word list from this FILE\n"
     , 5)
     ,
     stdout
     )






           ;
      fputs_unlocked (
     dcgettext (((void *)0), 
     "  -r, --references               first field of each line is a reference\n  -t, --typeset-mode               - not implemented -\n  -w, --width=NUMBER             output width in columns, reference excluded\n"
     , 5)
     ,
     stdout
     )



           ;
      fputs_unlocked (
     dcgettext (((void *)0), 
     "      --help        display this help and exit\n"
     , 5)
     ,
     stdout
     );
      fputs_unlocked (
     dcgettext (((void *)0), 
     "      --version     output version information and exit\n"
     , 5)
     ,
     stdout
     );
      emit_ancillary_info ("ptx");
    }
  exit (status);
}







static struct option const long_options[] =
{
  {"auto-reference", 
                    0
                               , 
                                 ((void *)0)
                                     , 'A'},
  {"break-file", 
                1
                                 , 
                                   ((void *)0)
                                       , 'b'},
  {"flag-truncation", 
                     1
                                      , 
                                        ((void *)0)
                                            , 'F'},
  {"ignore-case", 
                 0
                            , 
                              ((void *)0)
                                  , 'f'},
  {"gap-size", 
              1
                               , 
                                 ((void *)0)
                                     , 'g'},
  {"ignore-file", 
                 1
                                  , 
                                    ((void *)0)
                                        , 'i'},
  {"macro-name", 
                1
                                 , 
                                   ((void *)0)
                                       , 'M'},
  {"only-file", 
               1
                                , 
                                  ((void *)0)
                                      , 'o'},
  {"references", 
                0
                           , 
                             ((void *)0)
                                 , 'r'},
  {"right-side-refs", 
                     0
                                , 
                                  ((void *)0)
                                      , 'R'},
  {"format", 
            1
                             , 
                               ((void *)0)
                                   , 10},
  {"sentence-regexp", 
                     1
                                      , 
                                        ((void *)0)
                                            , 'S'},
  {"traditional", 
                 0
                            , 
                              ((void *)0)
                                  , 'G'},
  {"typeset-mode", 
                  0
                             , 
                               ((void *)0)
                                   , 't'},
  {"width", 
           1
                            , 
                              ((void *)0)
                                  , 'w'},
  {"word-regexp", 
                 1
                                  , 
                                    ((void *)0)
                                        , 'W'},
  {"help", 
  0
  , 
  ((void *)0)
  , GETOPT_HELP_CHAR},
  {"version", 
  0
  , 
  ((void *)0)
  , GETOPT_VERSION_CHAR},
  {
  ((void *)0)
      , 0, 
           ((void *)0)
               , 0},
};

static char const *const format_args[] =
{
  "roff", "tex", 
                ((void *)0)

};

static enum Format const format_vals[] =
{
  ROFF_FORMAT, TEX_FORMAT
};

int
main (int argc, char **argv)
{
  int optchar;
  int file_index;



  ;
  set_program_name (argv[0]);
  setlocale (
            6
                  , "");
  bindtextdomain ("coreutils", "/usr/local/share/locale");
  textdomain ("coreutils");

  atexit (close_stdout);





  while (optchar = getopt_long (argc, argv, "AF:GM:ORS:TW:b:i:fg:o:trw:",
                                long_options, 
                                             ((void *)0)
                                                 ),
         optchar != 
                   (-1)
                      )
    {
      switch (optchar)
        {
        default:
          usage (
                1
                            );

        case 'G':
          gnu_extensions = 
                          0
                               ;
          break;

        case 'b':
          break_file = optarg;
          break;

        case 'f':
          ignore_case = 
                       1
                           ;
          break;

        case 'g':
          {
            intmax_t tmp;
            if (! (xstrtoimax (optarg, 
                                      ((void *)0)
                                          , 0, &tmp, "") == LONGINT_OK
                   && 0 < tmp && tmp <= 
                                       (9223372036854775807L)
                                                  ))
              ((!!sizeof (struct { _Static_assert (
             1
             , "verify_expr (" "1" ", " "(error (1, 0, dcgettext (((void *)0), \"invalid gap width: %s\", 5), quote (optarg)), assume (false))" ")"); int _gl_dummy; })) ? ((error (
             1
             , 0, 
             dcgettext (((void *)0), 
             "invalid gap width: %s"
             , 5)
             , quote (optarg)), ((
             0
             ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
             1
             , 0, 
             dcgettext (((void *)0), 
             "invalid gap width: %s"
             , 5)
             , quote (optarg)), ((
             0
             ) ? (void) 0 : __builtin_unreachable ()))))
                                  ;
            gap_size = tmp;
            break;
          }

        case 'i':
          ignore_file = optarg;
          break;

        case 'o':
          only_file = optarg;
          break;

        case 'r':
          input_reference = 
                           1
                               ;
          break;

        case 't':

          break;

        case 'w':
          {
            intmax_t tmp;
            if (! (xstrtoimax (optarg, 
                                      ((void *)0)
                                          , 0, &tmp, "") == LONGINT_OK
                   && 0 < tmp && tmp <= 
                                       (9223372036854775807L)
                                                  ))
              ((!!sizeof (struct { _Static_assert (
             1
             , "verify_expr (" "1" ", " "(error (1, 0, dcgettext (((void *)0), \"invalid line width: %s\", 5), quote (optarg)), assume (false))" ")"); int _gl_dummy; })) ? ((error (
             1
             , 0, 
             dcgettext (((void *)0), 
             "invalid line width: %s"
             , 5)
             , quote (optarg)), ((
             0
             ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
             1
             , 0, 
             dcgettext (((void *)0), 
             "invalid line width: %s"
             , 5)
             , quote (optarg)), ((
             0
             ) ? (void) 0 : __builtin_unreachable ()))))
                                  ;
            line_width = tmp;
            break;
          }

        case 'A':
          auto_reference = 
                          1
                              ;
          break;

        case 'F':
          truncation_string = optarg;
          unescape_string (optarg);
          break;

        case 'M':
          macro_name = optarg;
          break;

        case 'O':
          output_format = ROFF_FORMAT;
          break;

        case 'R':
          right_reference = 
                           1
                               ;
          break;

        case 'S':
          context_regex.string = optarg;
          unescape_string (optarg);
          break;

        case 'T':
          output_format = TEX_FORMAT;
          break;

        case 'W':
          word_regex.string = optarg;
          unescape_string (optarg);
          if (!*word_regex.string)
            word_regex.string = 
                               ((void *)0)
                                   ;
          break;

        case 10:
          output_format = ((format_vals) [__xargmatch_internal ("--format", optarg, format_args, (void const *) (format_vals), sizeof *(format_vals), argmatch_die, 
                         1
                         )])
                                                              ;
          break;

        case GETOPT_HELP_CHAR: usage (
       0
       ); break;;

        case GETOPT_VERSION_CHAR: version_etc (
       stdout
       , "ptx", "GNU coreutils", Version, proper_name_utf8 ("F. Pinard", "Fran\xc3\xa7ois Pinard"), (char *) 
       ((void *)0)
       ); exit (
       0
       ); break;;
        }
    }





  if (optind == argc)
    {



      input_file_name = xmalloc (sizeof *input_file_name);
      file_line_count = xmalloc (sizeof *file_line_count);
      text_buffers = xmalloc (sizeof *text_buffers);
      number_input_files = 1;
      input_file_name[0] = 
                          ((void *)0)
                              ;
    }
  else if (gnu_extensions)
    {
      number_input_files = argc - optind;
      input_file_name = xnmalloc (number_input_files, sizeof *input_file_name);
      file_line_count = xnmalloc (number_input_files, sizeof *file_line_count);
      text_buffers = xnmalloc (number_input_files, sizeof *text_buffers);

      for (file_index = 0; file_index < number_input_files; file_index++)
        {
          if (!*argv[optind] || (strcmp (argv[optind], "-") == 0))
            input_file_name[file_index] = 
                                         ((void *)0)
                                             ;
          else
            input_file_name[file_index] = argv[optind];
          optind++;
        }
    }
  else
    {



      number_input_files = 1;
      input_file_name = xmalloc (sizeof *input_file_name);
      file_line_count = xmalloc (sizeof *file_line_count);
      text_buffers = xmalloc (sizeof *text_buffers);
      if (!*argv[optind] || (strcmp (argv[optind], "-") == 0))
        input_file_name[0] = 
                            ((void *)0)
                                ;
      else
        input_file_name[0] = argv[optind];
      optind++;



      if (optind < argc)
        {
          if (! freopen_safer (argv[optind], "w", 
                                           stdout
                                                 ))
            ((!!sizeof (struct { _Static_assert (
           1
           , "verify_expr (" "1" ", " "(error (1, (*__errno_location ()), \"%s\", quotearg_n_style_colon (0, shell_escape_quoting_style, argv[optind])), assume (false))" ")"); int _gl_dummy; })) ? ((error (
           1
           , 
           (*__errno_location ())
           , "%s", quotearg_n_style_colon (0, shell_escape_quoting_style, argv[optind])), ((
           0
           ) ? (void) 0 : __builtin_unreachable ()))) : ((error (
           1
           , 
           (*__errno_location ())
           , "%s", quotearg_n_style_colon (0, shell_escape_quoting_style, argv[optind])), ((
           0
           ) ? (void) 0 : __builtin_unreachable ()))));
          optind++;
        }



      if (optind < argc)
        {
          error (0, 0, 
                      dcgettext (((void *)0), 
                      "extra operand %s"
                      , 5)
                                           , quote (argv[optind]));
          usage (
                1
                            );
        }
    }




  if (output_format == UNKNOWN_FORMAT)
    output_format = gnu_extensions ? DUMB_FORMAT : ROFF_FORMAT;



  initialize_regex ();



  if (break_file)
    digest_break_file (break_file);





  if (ignore_file)
    {
      digest_word_file (ignore_file, &ignore_table);
      if (ignore_table.length == 0)
        ignore_file = 
                     ((void *)0)
                         ;
    }

  if (only_file)
    {
      digest_word_file (only_file, &only_table);
      if (only_table.length == 0)
        only_file = 
                   ((void *)0)
                       ;
    }



  number_of_occurs[0] = 0;
  total_line_count = 0;
  maximum_word_length = 0;
  reference_max_width = 0;

  for (file_index = 0; file_index < number_input_files; file_index++)
    {
      BLOCK *text_buffer = text_buffers + file_index;



      swallow_file_in_memory (input_file_name[file_index], text_buffer);
      find_occurs_in_text (file_index);





      total_line_count++;
      file_line_count[file_index] = total_line_count;
    }



  sort_found_occurs ();
  fix_output_parameters ();
  generate_all_output ();



  return 
        0
                    ;
}


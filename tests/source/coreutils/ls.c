

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
typedef struct {
  int __val[2];
} __fsid_t;
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

typedef void *__timer_t;

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

typedef int register_t __attribute__((__mode__(__word__)));
static __inline __uint16_t __bswap_16(__uint16_t __bsx) {

  return __builtin_bswap16(__bsx);
}

static __inline __uint32_t __bswap_32(__uint32_t __bsx) {

  return __builtin_bswap32(__bsx);
}
__extension__ static __inline __uint64_t __bswap_64(__uint64_t __bsx) {

  return __builtin_bswap64(__bsx);
}
static __inline __uint16_t __uint16_identity(__uint16_t __x) { return __x; }

static __inline __uint32_t __uint32_identity(__uint32_t __x) { return __x; }

static __inline __uint64_t __uint64_identity(__uint64_t __x) { return __x; }

typedef struct {
  unsigned long int __val[(1024 / (8 * sizeof(unsigned long int)))];
} __sigset_t;

typedef __sigset_t sigset_t;

struct timeval {

  __time_t tv_sec;
  __suseconds_t tv_usec;
};

struct timespec {

  __time_t tv_sec;

  __syscall_slong_t tv_nsec;
};
typedef long int __fd_mask;
typedef struct {

  __fd_mask fds_bits[1024 / (8 * (int)sizeof(__fd_mask))];

} fd_set;

typedef __fd_mask fd_mask;

extern int select(int __nfds, fd_set *__restrict __readfds,
                  fd_set *__restrict __writefds, fd_set *__restrict __exceptfds,
                  struct timeval *__restrict __timeout);
extern int pselect(int __nfds, fd_set *__restrict __readfds,
                   fd_set *__restrict __writefds,
                   fd_set *__restrict __exceptfds,
                   const struct timespec *__restrict __timeout,
                   const __sigset_t *__restrict __sigmask);
extern long int __fdelt_chk(long int __d);
extern long int __fdelt_warn(long int __d)
    __attribute__((__warning__("bit outside of fd_set selected")));

extern int _gl_cxxalias_dummy

    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

    ;

extern int _gl_cxxalias_dummy;

typedef __blksize_t blksize_t;

typedef __blkcnt_t blkcnt_t;

typedef __fsblkcnt_t fsblkcnt_t;

typedef __fsfilcnt_t fsfilcnt_t;
typedef __blkcnt64_t blkcnt64_t;
typedef __fsblkcnt64_t fsblkcnt64_t;
typedef __fsfilcnt64_t fsfilcnt64_t;

typedef union {
  __extension__ unsigned long long int __value64;
  struct {
    unsigned int __low;
    unsigned int __high;
  } __value32;
} __atomic_wide_counter;

typedef struct __pthread_internal_list {
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;

typedef struct __pthread_internal_slist {
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;
struct __pthread_mutex_s {
  int __lock;
  unsigned int __count;
  int __owner;

  unsigned int __nusers;

  int __kind;

  short __spins;
  short __elision;
  __pthread_list_t __list;
};
struct __pthread_rwlock_arch_t {
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

struct __pthread_cond_s {
  __atomic_wide_counter __wseq;
  __atomic_wide_counter __g1_start;
  unsigned int __g_refs[2];
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
};

typedef unsigned int __tss_t;
typedef unsigned long int __thrd_t;

typedef struct {
  int __data;
} __once_flag;

typedef unsigned long int pthread_t;

typedef union {
  char __size[4];
  int __align;
} pthread_mutexattr_t;

typedef union {
  char __size[4];
  int __align;
} pthread_condattr_t;

typedef unsigned int pthread_key_t;

typedef int pthread_once_t;

union pthread_attr_t {
  char __size[56];
  long int __align;
};

typedef union pthread_attr_t pthread_attr_t;

typedef union {
  struct __pthread_mutex_s __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;

typedef union {
  struct __pthread_cond_s __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;

typedef union {
  struct __pthread_rwlock_arch_t __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;

typedef union {
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;

typedef volatile int pthread_spinlock_t;

typedef union {
  char __size[32];
  long int __align;
} pthread_barrier_t;

typedef union {
  char __size[4];
  int __align;
} pthread_barrierattr_t;

typedef unsigned char cc_t;
typedef unsigned int speed_t;
typedef unsigned int tcflag_t;

struct termios {
  tcflag_t c_iflag;
  tcflag_t c_oflag;
  tcflag_t c_cflag;
  tcflag_t c_lflag;
  cc_t c_line;
  cc_t c_cc[32];
  speed_t c_ispeed;
  speed_t c_ospeed;
};

extern speed_t cfgetospeed(const struct termios *__termios_p)
    __attribute__((__nothrow__, __leaf__));

extern speed_t cfgetispeed(const struct termios *__termios_p)
    __attribute__((__nothrow__, __leaf__));

extern int cfsetospeed(struct termios *__termios_p, speed_t __speed)
    __attribute__((__nothrow__, __leaf__));

extern int cfsetispeed(struct termios *__termios_p, speed_t __speed)
    __attribute__((__nothrow__, __leaf__));

extern int cfsetspeed(struct termios *__termios_p, speed_t __speed)
    __attribute__((__nothrow__, __leaf__));

extern int tcgetattr(int __fd, struct termios *__termios_p)
    __attribute__((__nothrow__, __leaf__));

extern int tcsetattr(int __fd, int __optional_actions,
                     const struct termios *__termios_p)
    __attribute__((__nothrow__, __leaf__));

extern void cfmakeraw(struct termios *__termios_p)
    __attribute__((__nothrow__, __leaf__));

extern int tcsendbreak(int __fd, int __duration)
    __attribute__((__nothrow__, __leaf__));

extern int tcdrain(int __fd);

extern int tcflush(int __fd, int __queue_selector)
    __attribute__((__nothrow__, __leaf__));

extern int tcflow(int __fd, int __action)
    __attribute__((__nothrow__, __leaf__));

extern __pid_t tcgetsid(int __fd) __attribute__((__nothrow__, __leaf__));

struct winsize {
  unsigned short int ws_row;
  unsigned short int ws_col;
  unsigned short int ws_xpixel;
  unsigned short int ws_ypixel;
};

struct termio {
  unsigned short int c_iflag;
  unsigned short int c_oflag;
  unsigned short int c_cflag;
  unsigned short int c_lflag;
  unsigned char c_line;
  unsigned char c_cc[8];
};

extern int ioctl(int __fd, unsigned long int __request, ...)
    __attribute__((__nothrow__, __leaf__));

typedef __builtin_va_list __gnuc_va_list;

typedef struct {
  int __count;
  union {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;

typedef struct _G_fpos_t {
  __off_t __pos;
  __mbstate_t __state;
} __fpos_t;
typedef struct _G_fpos64_t {
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

struct _IO_FILE {
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

  char _unused2[15 * sizeof(int) - 4 * sizeof(void *) - sizeof(size_t)];
};

typedef __ssize_t cookie_read_function_t(void *__cookie, char *__buf,
                                         size_t __nbytes);

typedef __ssize_t cookie_write_function_t(void *__cookie, const char *__buf,
                                          size_t __nbytes);

typedef int cookie_seek_function_t(void *__cookie, __off64_t *__pos, int __w);

typedef int cookie_close_function_t(void *__cookie);

typedef struct _IO_cookie_io_functions_t {
  cookie_read_function_t *read;
  cookie_write_function_t *write;
  cookie_seek_function_t *seek;
  cookie_close_function_t *close;
} cookie_io_functions_t;

typedef __gnuc_va_list va_list;
typedef __fpos_t fpos_t;

typedef __fpos64_t fpos64_t;
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

extern int remove(const char *__filename)
    __attribute__((__nothrow__, __leaf__));

extern int rename(const char *__old, const char *__new)
    __attribute__((__nothrow__, __leaf__));

extern int renameat(int __oldfd, const char *__old, int __newfd,
                    const char *__new) __attribute__((__nothrow__, __leaf__));
extern int renameat2(int __oldfd, const char *__old, int __newfd,
                     const char *__new, unsigned int __flags)
    __attribute__((__nothrow__, __leaf__));

extern int fclose(FILE *__stream);
extern FILE *tmpfile(void) __attribute__((__malloc__))
__attribute__((__malloc__(fclose, 1))) __attribute__((__warn_unused_result__));
extern FILE *tmpfile64(void) __attribute__((__malloc__))
__attribute__((__malloc__(fclose, 1))) __attribute__((__warn_unused_result__));

extern char *tmpnam(char[20]) __attribute__((__nothrow__, __leaf__))
__attribute__((__warn_unused_result__));

extern char *tmpnam_r(char __s[20]) __attribute__((__nothrow__, __leaf__))
__attribute__((__warn_unused_result__));
extern char *tempnam(const char *__dir, const char *__pfx)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__warn_unused_result__))
    __attribute__((__malloc__(__builtin_free, 1)));

extern int fflush(FILE *__stream);
extern int fflush_unlocked(FILE *__stream);
extern int fcloseall(void);
extern FILE *fopen(const char *__restrict __filename,
                   const char *__restrict __modes) __attribute__((__malloc__))
__attribute__((__malloc__(fclose, 1))) __attribute__((__warn_unused_result__));

extern FILE *freopen(const char *__restrict __filename,
                     const char *__restrict __modes, FILE *__restrict __stream)
    __attribute__((__warn_unused_result__));
extern FILE *fopen64(const char *__restrict __filename,
                     const char *__restrict __modes) __attribute__((__malloc__))
__attribute__((__malloc__(fclose, 1))) __attribute__((__warn_unused_result__));
extern FILE *freopen64(const char *__restrict __filename,
                       const char *__restrict __modes,
                       FILE *__restrict __stream)
    __attribute__((__warn_unused_result__));

extern FILE *fdopen(int __fd, const char *__modes)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__malloc__(fclose, 1)))
    __attribute__((__warn_unused_result__));

extern FILE *fopencookie(void *__restrict __magic_cookie,
                         const char *__restrict __modes,
                         cookie_io_functions_t __io_funcs)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__malloc__(fclose, 1)))
    __attribute__((__warn_unused_result__));

extern FILE *fmemopen(void *__s, size_t __len, const char *__modes)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__malloc__(fclose, 1)))
    __attribute__((__warn_unused_result__));

extern FILE *open_memstream(char **__bufloc, size_t *__sizeloc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__malloc__(fclose, 1)))
    __attribute__((__warn_unused_result__));
extern void setbuf(FILE *__restrict __stream, char *__restrict __buf)
    __attribute__((__nothrow__, __leaf__));

extern int setvbuf(FILE *__restrict __stream, char *__restrict __buf,
                   int __modes, size_t __n)
    __attribute__((__nothrow__, __leaf__));

extern void setbuffer(FILE *__restrict __stream, char *__restrict __buf,
                      size_t __size) __attribute__((__nothrow__, __leaf__));

extern void setlinebuf(FILE *__stream) __attribute__((__nothrow__, __leaf__));

extern int fprintf(FILE *__restrict __stream, const char *__restrict __format,
                   ...);

extern int printf(const char *__restrict __format, ...);

extern int sprintf(char *__restrict __s, const char *__restrict __format, ...)
    __attribute__((__nothrow__));

extern int vfprintf(FILE *__restrict __s, const char *__restrict __format,
                    __gnuc_va_list __arg);

extern int vprintf(const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf(char *__restrict __s, const char *__restrict __format,
                    __gnuc_va_list __arg) __attribute__((__nothrow__));

extern int snprintf(char *__restrict __s, size_t __maxlen,
                    const char *__restrict __format, ...)
    __attribute__((__nothrow__)) __attribute__((__format__(__printf__, 3, 4)));

extern int vsnprintf(char *__restrict __s, size_t __maxlen,
                     const char *__restrict __format, __gnuc_va_list __arg)
    __attribute__((__nothrow__)) __attribute__((__format__(__printf__, 3, 0)));

extern int vasprintf(char **__restrict __ptr, const char *__restrict __f,
                     __gnuc_va_list __arg) __attribute__((__nothrow__))
__attribute__((__format__(__printf__, 2, 0)))
__attribute__((__warn_unused_result__));
extern int __asprintf(char **__restrict __ptr, const char *__restrict __fmt,
                      ...) __attribute__((__nothrow__))
__attribute__((__format__(__printf__, 2, 3)))
__attribute__((__warn_unused_result__));
extern int asprintf(char **__restrict __ptr, const char *__restrict __fmt, ...)
    __attribute__((__nothrow__)) __attribute__((__format__(__printf__, 2, 3)))
    __attribute__((__warn_unused_result__));

extern int vdprintf(int __fd, const char *__restrict __fmt,
                    __gnuc_va_list __arg)
    __attribute__((__format__(__printf__, 2, 0)));
extern int dprintf(int __fd, const char *__restrict __fmt, ...)
    __attribute__((__format__(__printf__, 2, 3)));

extern int fscanf(FILE *__restrict __stream, const char *__restrict __format,
                  ...) __attribute__((__warn_unused_result__));

extern int scanf(const char *__restrict __format, ...)
    __attribute__((__warn_unused_result__));

extern int sscanf(const char *__restrict __s, const char *__restrict __format,
                  ...) __attribute__((__nothrow__, __leaf__));

extern int fscanf(FILE *__restrict __stream, const char *__restrict __format,
                  ...) __asm__(""
                               "__isoc99_fscanf")

    __attribute__((__warn_unused_result__));
extern int scanf(const char *__restrict __format, ...) __asm__(""
                                                               "__isoc99_scanf")
    __attribute__((__warn_unused_result__));
extern int sscanf(const char *__restrict __s, const char *__restrict __format,
                  ...) __asm__(""
                               "__isoc99_sscanf")
    __attribute__((__nothrow__, __leaf__))

    ;
extern int vfscanf(FILE *__restrict __s, const char *__restrict __format,
                   __gnuc_va_list __arg)
    __attribute__((__format__(__scanf__, 2, 0)))
    __attribute__((__warn_unused_result__));

extern int vscanf(const char *__restrict __format, __gnuc_va_list __arg)
    __attribute__((__format__(__scanf__, 1, 0)))
    __attribute__((__warn_unused_result__));

extern int vsscanf(const char *__restrict __s, const char *__restrict __format,
                   __gnuc_va_list __arg) __attribute__((__nothrow__, __leaf__))
__attribute__((__format__(__scanf__, 2, 0)));

extern int vfscanf(FILE *__restrict __s, const char *__restrict __format,
                   __gnuc_va_list __arg) __asm__(""
                                                 "__isoc99_vfscanf")

    __attribute__((__format__(__scanf__, 2, 0)))
    __attribute__((__warn_unused_result__));
extern int vscanf(const char *__restrict __format,
                  __gnuc_va_list __arg) __asm__(""
                                                "__isoc99_vscanf")

    __attribute__((__format__(__scanf__, 1, 0)))
    __attribute__((__warn_unused_result__));
extern int vsscanf(const char *__restrict __s, const char *__restrict __format,
                   __gnuc_va_list __arg) __asm__(""
                                                 "__isoc99_vsscanf")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__format__(__scanf__, 2, 0)));
extern int fgetc(FILE *__stream);
extern int getc(FILE *__stream);

extern int getchar(void);

extern int getc_unlocked(FILE *__stream);
extern int getchar_unlocked(void);
extern int fgetc_unlocked(FILE *__stream);
extern int fputc(int __c, FILE *__stream);
extern int putc(int __c, FILE *__stream);

extern int putchar(int __c);
extern int fputc_unlocked(int __c, FILE *__stream);

extern int putc_unlocked(int __c, FILE *__stream);
extern int putchar_unlocked(int __c);

extern int getw(FILE *__stream);

extern int putw(int __w, FILE *__stream);

extern char *fgets(char *__restrict __s, int __n, FILE *__restrict __stream)
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 1, 2)));
extern char *fgets_unlocked(char *__restrict __s, int __n,
                            FILE *__restrict __stream)
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 1, 2)));
extern __ssize_t __getdelim(char **__restrict __lineptr, size_t *__restrict __n,
                            int __delimiter, FILE *__restrict __stream)
    __attribute__((__warn_unused_result__));
extern __ssize_t getdelim(char **__restrict __lineptr, size_t *__restrict __n,
                          int __delimiter, FILE *__restrict __stream)
    __attribute__((__warn_unused_result__));

extern __ssize_t getline(char **__restrict __lineptr, size_t *__restrict __n,
                         FILE *__restrict __stream)
    __attribute__((__warn_unused_result__));

extern int fputs(const char *__restrict __s, FILE *__restrict __stream);

extern int puts(const char *__s);

extern int ungetc(int __c, FILE *__stream);

extern size_t fread(void *__restrict __ptr, size_t __size, size_t __n,
                    FILE *__restrict __stream)
    __attribute__((__warn_unused_result__));

extern size_t fwrite(const void *__restrict __ptr, size_t __size, size_t __n,
                     FILE *__restrict __s);
extern int fputs_unlocked(const char *__restrict __s,
                          FILE *__restrict __stream);
extern size_t fread_unlocked(void *__restrict __ptr, size_t __size, size_t __n,
                             FILE *__restrict __stream)
    __attribute__((__warn_unused_result__));
extern size_t fwrite_unlocked(const void *__restrict __ptr, size_t __size,
                              size_t __n, FILE *__restrict __stream);

extern int fseek(FILE *__stream, long int __off, int __whence);

extern long int ftell(FILE *__stream) __attribute__((__warn_unused_result__));

extern void rewind(FILE *__stream);
extern int fseeko(FILE *__stream, __off_t __off, int __whence);

extern __off_t ftello(FILE *__stream) __attribute__((__warn_unused_result__));
extern int fgetpos(FILE *__restrict __stream, fpos_t *__restrict __pos);

extern int fsetpos(FILE *__stream, const fpos_t *__pos);
extern int fseeko64(FILE *__stream, __off64_t __off, int __whence);
extern __off64_t ftello64(FILE *__stream)
    __attribute__((__warn_unused_result__));
extern int fgetpos64(FILE *__restrict __stream, fpos64_t *__restrict __pos);
extern int fsetpos64(FILE *__stream, const fpos64_t *__pos);

extern void clearerr(FILE *__stream) __attribute__((__nothrow__, __leaf__));

extern int feof(FILE *__stream) __attribute__((__nothrow__, __leaf__))
__attribute__((__warn_unused_result__));

extern int ferror(FILE *__stream) __attribute__((__nothrow__, __leaf__))
__attribute__((__warn_unused_result__));

extern void clearerr_unlocked(FILE *__stream)
    __attribute__((__nothrow__, __leaf__));
extern int feof_unlocked(FILE *__stream) __attribute__((__nothrow__, __leaf__))
__attribute__((__warn_unused_result__));
extern int ferror_unlocked(FILE *__stream)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__));

extern void perror(const char *__s);

extern int fileno(FILE *__stream) __attribute__((__nothrow__, __leaf__))
__attribute__((__warn_unused_result__));

extern int fileno_unlocked(FILE *__stream)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__));
extern int pclose(FILE *__stream);

extern FILE *popen(const char *__command, const char *__modes)
    __attribute__((__malloc__)) __attribute__((__malloc__(pclose, 1)))
    __attribute__((__warn_unused_result__));

extern char *ctermid(char *__s) __attribute__((__nothrow__, __leaf__))
__attribute__((__access__(__write_only__, 1)));

extern char *cuserid(char *__s) __attribute__((__access__(__write_only__, 1)));

struct obstack;

extern int obstack_printf(struct obstack *__restrict __obstack,
                          const char *__restrict __format, ...)
    __attribute__((__nothrow__)) __attribute__((__format__(__printf__, 2, 3)));
extern int obstack_vprintf(struct obstack *__restrict __obstack,
                           const char *__restrict __format,
                           __gnuc_va_list __args) __attribute__((__nothrow__))
__attribute__((__format__(__printf__, 2, 0)));

extern void flockfile(FILE *__stream) __attribute__((__nothrow__, __leaf__));

extern int ftrylockfile(FILE *__stream) __attribute__((__nothrow__, __leaf__))
__attribute__((__warn_unused_result__));

extern void funlockfile(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern int __uflow(FILE *);
extern int __overflow(FILE *, int);

extern int __sprintf_chk(char *__restrict __s, int __flag, size_t __slen,
                         const char *__restrict __format, ...)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__access__(__write_only__, 1, 3)));
extern int __vsprintf_chk(char *__restrict __s, int __flag, size_t __slen,
                          const char *__restrict __format, __gnuc_va_list __ap)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__access__(__write_only__, 1, 3)));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
    __attribute__((__nothrow__, __leaf__))
    sprintf(char *__restrict __s, const char *__restrict __fmt, ...) {
  return __builtin___sprintf_chk(__s, 2 - 1, __builtin_object_size(__s, 2 > 1),
                                 __fmt, __builtin_va_arg_pack());
}

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
    __attribute__((__nothrow__, __leaf__))
    vsprintf(char *__restrict __s, const char *__restrict __fmt,
             __gnuc_va_list __ap)

{
  return __builtin___vsprintf_chk(__s, 2 - 1, __builtin_object_size(__s, 2 > 1),
                                  __fmt, __ap);
}

extern int __snprintf_chk(char *__restrict __s, size_t __n, int __flag,
                          size_t __slen, const char *__restrict __format, ...)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__access__(__write_only__, 1, 2)));
extern int __vsnprintf_chk(char *__restrict __s, size_t __n, int __flag,
                           size_t __slen, const char *__restrict __format,
                           __gnuc_va_list __ap)
    __attribute__((__nothrow__, __leaf__));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__))
__attribute__((__artificial__)) int __attribute__((__nothrow__, __leaf__))
snprintf(char *__restrict __s, size_t __n, const char *__restrict __fmt, ...)

{
  return __builtin___snprintf_chk(__s, __n, 2 - 1,
                                  __builtin_object_size(__s, 2 > 1), __fmt,
                                  __builtin_va_arg_pack());
}

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
    __attribute__((__nothrow__, __leaf__))
    vsnprintf(char *__restrict __s, size_t __n, const char *__restrict __fmt,
              __gnuc_va_list __ap)

{
  return __builtin___vsnprintf_chk(
      __s, __n, 2 - 1, __builtin_object_size(__s, 2 > 1), __fmt, __ap);
}

extern int __fprintf_chk(FILE *__restrict __stream, int __flag,
                         const char *__restrict __format, ...);
extern int __printf_chk(int __flag, const char *__restrict __format, ...);
extern int __vfprintf_chk(FILE *__restrict __stream, int __flag,
                          const char *__restrict __format, __gnuc_va_list __ap);
extern int __vprintf_chk(int __flag, const char *__restrict __format,
                         __gnuc_va_list __ap);

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
fprintf(FILE *__restrict __stream, const char *__restrict __fmt, ...) {
  return __fprintf_chk(__stream, 2 - 1, __fmt, __builtin_va_arg_pack());
}

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
printf(const char *__restrict __fmt, ...) {
  return __printf_chk(2 - 1, __fmt, __builtin_va_arg_pack());
}

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
vprintf(const char *__restrict __fmt, __gnuc_va_list __ap) {

  return __vprintf_chk(2 - 1, __fmt, __ap);
}

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
vfprintf(FILE *__restrict __stream, const char *__restrict __fmt,
         __gnuc_va_list __ap) {
  return __vfprintf_chk(__stream, 2 - 1, __fmt, __ap);
}

extern int __dprintf_chk(int __fd, int __flag, const char *__restrict __fmt,
                         ...) __attribute__((__format__(__printf__, 3, 4)));
extern int __vdprintf_chk(int __fd, int __flag, const char *__restrict __fmt,
                          __gnuc_va_list __arg)
    __attribute__((__format__(__printf__, 3, 0)));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
dprintf(int __fd, const char *__restrict __fmt, ...) {
  return __dprintf_chk(__fd, 2 - 1, __fmt, __builtin_va_arg_pack());
}

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
vdprintf(int __fd, const char *__restrict __fmt, __gnuc_va_list __ap) {
  return __vdprintf_chk(__fd, 2 - 1, __fmt, __ap);
}

extern int __asprintf_chk(char **__restrict __ptr, int __flag,
                          const char *__restrict __fmt, ...)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__format__(__printf__, 3, 4)))
    __attribute__((__warn_unused_result__));
extern int __vasprintf_chk(char **__restrict __ptr, int __flag,
                           const char *__restrict __fmt, __gnuc_va_list __arg)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__format__(__printf__, 3, 0)))
    __attribute__((__warn_unused_result__));
extern int __obstack_printf_chk(struct obstack *__restrict __obstack,
                                int __flag, const char *__restrict __format,
                                ...) __attribute__((__nothrow__, __leaf__))
__attribute__((__format__(__printf__, 3, 4)));
extern int __obstack_vprintf_chk(struct obstack *__restrict __obstack,
                                 int __flag, const char *__restrict __format,
                                 __gnuc_va_list __args)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__format__(__printf__, 3, 0)));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
    __attribute__((__nothrow__, __leaf__))
    asprintf(char **__restrict __ptr, const char *__restrict __fmt, ...) {
  return __asprintf_chk(__ptr, 2 - 1, __fmt, __builtin_va_arg_pack());
}

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
    __attribute__((__nothrow__, __leaf__))
    __asprintf(char **__restrict __ptr, const char *__restrict __fmt, ...)

{
  return __asprintf_chk(__ptr, 2 - 1, __fmt, __builtin_va_arg_pack());
}

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
    __attribute__((__nothrow__, __leaf__))
    obstack_printf(struct obstack *__restrict __obstack,
                   const char *__restrict __fmt, ...)

{
  return __obstack_printf_chk(__obstack, 2 - 1, __fmt, __builtin_va_arg_pack());
}
extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
    __attribute__((__nothrow__, __leaf__))
    vasprintf(char **__restrict __ptr, const char *__restrict __fmt,
              __gnuc_va_list __ap)

{
  return __vasprintf_chk(__ptr, 2 - 1, __fmt, __ap);
}

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
    __attribute__((__nothrow__, __leaf__))
    obstack_vprintf(struct obstack *__restrict __obstack,
                    const char *__restrict __fmt, __gnuc_va_list __ap)

{
  return __obstack_vprintf_chk(__obstack, 2 - 1, __fmt, __ap);
}
extern char *__fgets_chk(char *__restrict __s, size_t __size, int __n,
                         FILE *__restrict __stream)
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 1, 3)));
extern char *__fgets_alias(char *__restrict __s, int __n,
                           FILE *__restrict __stream) __asm__(""
                                                              "fgets")

    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 1, 2)));
extern char *__fgets_chk_warn(char *__restrict __s, size_t __size, int __n,
                              FILE *__restrict __stream) __asm__(""
                                                                 "__fgets_chk")

    __attribute__((__warn_unused_result__))
    __attribute__((__warning__("fgets called with bigger size than length "
                               "of destination buffer")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
__attribute__((__warn_unused_result__))
__attribute__((__access__(__write_only__, 1, 2))) char *
fgets(char *__restrict __s, int __n, FILE *__restrict __stream) {
  size_t sz = __builtin_object_size(__s, 2 > 1);
  if ((((__typeof(__n))0 < (__typeof(__n))-1 ||
        (__builtin_constant_p(__n) && (__n) > 0)) &&
       __builtin_constant_p(
           (((long unsigned int)(__n)) <= (sz) / (sizeof(char)))) &&
       (((long unsigned int)(__n)) <= (sz) / (sizeof(char)))))
    return __fgets_alias(__s, __n, __stream);
  if ((((__typeof(__n))0 < (__typeof(__n))-1 ||
        (__builtin_constant_p(__n) && (__n) > 0)) &&
       __builtin_constant_p(
           (((long unsigned int)(__n)) <= (sz) / (sizeof(char)))) &&
       !(((long unsigned int)(__n)) <= (sz) / (sizeof(char)))))
    return __fgets_chk_warn(__s, sz, __n, __stream);
  return __fgets_chk(__s, sz, __n, __stream);
}

extern size_t __fread_chk(void *__restrict __ptr, size_t __ptrlen,
                          size_t __size, size_t __n, FILE *__restrict __stream)
    __attribute__((__warn_unused_result__));
extern size_t __fread_alias(void *__restrict __ptr, size_t __size, size_t __n,
                            FILE *__restrict __stream) __asm__(""
                                                               "fread")

    __attribute__((__warn_unused_result__));
extern size_t __fread_chk_warn(void *__restrict __ptr, size_t __ptrlen,
                               size_t __size, size_t __n,
                               FILE *__restrict __stream) __asm__(""
                                                                  "__fread_chk")

    __attribute__((__warn_unused_result__)) __attribute__((
        __warning__("fread called with bigger size * nmemb than length "
                    "of destination buffer")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
__attribute__((__warn_unused_result__)) size_t
fread(void *__restrict __ptr, size_t __size, size_t __n,
      FILE *__restrict __stream) {
  size_t sz = __builtin_object_size(__ptr, 0);
  if ((((__typeof(__n))0 < (__typeof(__n))-1 ||
        (__builtin_constant_p(__n) && (__n) > 0)) &&
       __builtin_constant_p((((long unsigned int)(__n)) <= (sz) / (__size))) &&
       (((long unsigned int)(__n)) <= (sz) / (__size))))
    return __fread_alias(__ptr, __size, __n, __stream);
  if ((((__typeof(__n))0 < (__typeof(__n))-1 ||
        (__builtin_constant_p(__n) && (__n) > 0)) &&
       __builtin_constant_p((((long unsigned int)(__n)) <= (sz) / (__size))) &&
       !(((long unsigned int)(__n)) <= (sz) / (__size))))
    return __fread_chk_warn(__ptr, sz, __size, __n, __stream);
  return __fread_chk(__ptr, sz, __size, __n, __stream);
}

extern char *__fgets_unlocked_chk(char *__restrict __s, size_t __size, int __n,
                                  FILE *__restrict __stream)
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 1, 3)));
extern char *
__fgets_unlocked_alias(char *__restrict __s, int __n,
                       FILE *__restrict __stream) __asm__(""
                                                          "fgets_unlocked")

    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 1, 2)));
extern char *__fgets_unlocked_chk_warn(
    char *__restrict __s, size_t __size, int __n,
    FILE *__restrict __stream) __asm__(""
                                       "__fgets_unlocked_chk")

    __attribute__((__warn_unused_result__)) __attribute__((
        __warning__("fgets_unlocked called with bigger size than length "
                    "of destination buffer")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
__attribute__((__warn_unused_result__))
__attribute__((__access__(__write_only__, 1, 2))) char *
fgets_unlocked(char *__restrict __s, int __n, FILE *__restrict __stream) {
  size_t sz = __builtin_object_size(__s, 2 > 1);
  if ((((__typeof(__n))0 < (__typeof(__n))-1 ||
        (__builtin_constant_p(__n) && (__n) > 0)) &&
       __builtin_constant_p(
           (((long unsigned int)(__n)) <= (sz) / (sizeof(char)))) &&
       (((long unsigned int)(__n)) <= (sz) / (sizeof(char)))))
    return __fgets_unlocked_alias(__s, __n, __stream);
  if ((((__typeof(__n))0 < (__typeof(__n))-1 ||
        (__builtin_constant_p(__n) && (__n) > 0)) &&
       __builtin_constant_p(
           (((long unsigned int)(__n)) <= (sz) / (sizeof(char)))) &&
       !(((long unsigned int)(__n)) <= (sz) / (sizeof(char)))))
    return __fgets_unlocked_chk_warn(__s, sz, __n, __stream);
  return __fgets_unlocked_chk(__s, sz, __n, __stream);
}

extern size_t __fread_unlocked_chk(void *__restrict __ptr, size_t __ptrlen,
                                   size_t __size, size_t __n,
                                   FILE *__restrict __stream)
    __attribute__((__warn_unused_result__));
extern size_t
__fread_unlocked_alias(void *__restrict __ptr, size_t __size, size_t __n,
                       FILE *__restrict __stream) __asm__(""
                                                          "fread_unlocked")

    __attribute__((__warn_unused_result__));
extern size_t __fread_unlocked_chk_warn(
    void *__restrict __ptr, size_t __ptrlen, size_t __size, size_t __n,
    FILE *__restrict __stream) __asm__(""
                                       "__fread_unlocked_chk")

    __attribute__((__warn_unused_result__)) __attribute__((
        __warning__("fread_unlocked called with bigger size * nmemb than "
                    "length of destination buffer")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
__attribute__((__warn_unused_result__)) size_t
fread_unlocked(void *__restrict __ptr, size_t __size, size_t __n,
               FILE *__restrict __stream) {
  size_t sz = __builtin_object_size(__ptr, 0);
  if ((((__typeof(__n))0 < (__typeof(__n))-1 ||
        (__builtin_constant_p(__n) && (__n) > 0)) &&
       __builtin_constant_p((((long unsigned int)(__n)) <= (sz) / (__size))) &&
       (((long unsigned int)(__n)) <= (sz) / (__size)))) {
    return __fread_unlocked_alias(__ptr, __size, __n, __stream);
  }
  if ((((__typeof(__n))0 < (__typeof(__n))-1 ||
        (__builtin_constant_p(__n) && (__n) > 0)) &&
       __builtin_constant_p((((long unsigned int)(__n)) <= (sz) / (__size))) &&
       !(((long unsigned int)(__n)) <= (sz) / (__size))))
    return __fread_unlocked_chk_warn(__ptr, sz, __size, __n, __stream);
  return __fread_unlocked_chk(__ptr, sz, __size, __n, __stream);
}

typedef long int ptrdiff_t;
typedef int wchar_t;
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld
      __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;

extern int rpl_fclose(FILE *stream) __attribute__((__nonnull__(1)));
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern FILE *fdopen(int fd, const char *mode) __attribute__((__nonnull__(2)))
__attribute__((__malloc__(rpl_fclose, 1)))

;

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int rpl_fflush(FILE *gl_stream);
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern FILE *fopen(const char *__restrict__ filename,
                   const char *__restrict__ mode)
    __attribute__((__nonnull__(1, 2)))
    __attribute__((__malloc__(rpl_fclose, 1)))

    ;

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int fpurge(FILE *gl_stream) __attribute__((__nonnull__(1)));

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int rpl_fseek(FILE *fp, long offset, int whence)
    __attribute__((__nonnull__(1)));
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int rpl_fseeko(FILE *fp, off_t offset, int whence)
    __attribute__((__nonnull__(1)));
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

    ;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern FILE *tmpfile(void) __attribute__((__malloc__(rpl_fclose, 1)))

;
extern int rpl_asprintf(char **result, const char *format, ...)
    __attribute__((__format__(__gnu_printf__, 2, 3)))
    __attribute__((__nonnull__(1, 2)))

    ;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int rpl_vasprintf(char **result, const char *format, va_list args)
    __attribute__((__format__(__gnu_printf__, 2, 0)))
    __attribute__((__nonnull__(1, 2)))

    ;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int rpl_vfprintf(FILE *__restrict__ fp, const char *__restrict__ format,
                        va_list args)
    __attribute__((__format__(__gnu_printf__, 2, 0)))
    __attribute__((__nonnull__(1, 2)))

    ;

extern int _gl_cxxalias_dummy

    ;
extern int _gl_cxxalias_dummy;
extern int rpl_vprintf(const char *__restrict__ format, va_list args)
    __attribute__((__format__(__gnu_printf__, 1, 0)))
    __attribute__((__nonnull__(1)))

    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern void __assert_fail(const char *__assertion, const char *__file,
                          unsigned int __line, const char *__function)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

extern void __assert_perror_fail(int __errnum, const char *__file,
                                 unsigned int __line, const char *__function)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

extern void __assert(const char *__assertion, const char *__file, int __line)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

typedef long int __jmp_buf[8];
struct __jmp_buf_tag {

  __jmp_buf __jmpbuf;
  int __mask_was_saved;
  __sigset_t __saved_mask;
};

typedef struct __jmp_buf_tag jmp_buf[1];

extern int setjmp(jmp_buf __env) __attribute__((__nothrow__));

extern int __sigsetjmp(struct __jmp_buf_tag __env[1], int __savemask)
    __attribute__((__nothrow__));

extern int _setjmp(struct __jmp_buf_tag __env[1]) __attribute__((__nothrow__));
extern void longjmp(struct __jmp_buf_tag __env[1], int __val)
    __attribute__((__nothrow__)) __attribute__((__noreturn__));

extern void _longjmp(struct __jmp_buf_tag __env[1], int __val)
    __attribute__((__nothrow__)) __attribute__((__noreturn__));

typedef struct __jmp_buf_tag sigjmp_buf[1];
extern void siglongjmp(sigjmp_buf __env, int __val) __attribute__((__nothrow__))
__attribute__((__noreturn__));

extern void longjmp(struct __jmp_buf_tag __env[1],
                    int __val) __asm__(""
                                       "__longjmp_chk")
    __attribute__((__nothrow__))

    __attribute__((__noreturn__));
extern void _longjmp(struct __jmp_buf_tag __env[1],
                     int __val) __asm__(""
                                        "__longjmp_chk")
    __attribute__((__nothrow__))

    __attribute__((__noreturn__));
extern void siglongjmp(struct __jmp_buf_tag __env[1],
                       int __val) __asm__(""
                                          "__longjmp_chk")
    __attribute__((__nothrow__))

    __attribute__((__noreturn__));

struct passwd {
  char *pw_name;
  char *pw_passwd;

  __uid_t pw_uid;
  __gid_t pw_gid;
  char *pw_gecos;
  char *pw_dir;
  char *pw_shell;
};
extern void setpwent(void);

extern void endpwent(void);

extern struct passwd *getpwent(void);
extern struct passwd *fgetpwent(FILE *__stream) __attribute__((__nonnull__(1)));

extern int putpwent(const struct passwd *__restrict __p, FILE *__restrict __f);

extern struct passwd *getpwuid(__uid_t __uid);

extern struct passwd *getpwnam(const char *__name)
    __attribute__((__nonnull__(1)));
extern int getpwent_r(struct passwd *__restrict __resultbuf,
                      char *__restrict __buffer, size_t __buflen,
                      struct passwd **__restrict __result)
    __attribute__((__nonnull__(1, 2, 4)))
    __attribute__((__access__(__write_only__, 2, 3)));

extern int getpwuid_r(__uid_t __uid, struct passwd *__restrict __resultbuf,
                      char *__restrict __buffer, size_t __buflen,
                      struct passwd **__restrict __result)
    __attribute__((__nonnull__(2, 3, 5)))
    __attribute__((__access__(__write_only__, 3, 4)));

extern int getpwnam_r(const char *__restrict __name,
                      struct passwd *__restrict __resultbuf,
                      char *__restrict __buffer, size_t __buflen,
                      struct passwd **__restrict __result)
    __attribute__((__nonnull__(1, 2, 3, 5)))
    __attribute__((__access__(__write_only__, 3, 4)));
extern int fgetpwent_r(FILE *__restrict __stream,
                       struct passwd *__restrict __resultbuf,
                       char *__restrict __buffer, size_t __buflen,
                       struct passwd **__restrict __result)
    __attribute__((__nonnull__(1, 2, 3, 5)))
    __attribute__((__access__(__write_only__, 3, 4)));
extern int getpw(__uid_t __uid, char *__buffer);

extern char *optarg;
extern int optind;

extern int opterr;

extern int optopt;
extern int getopt(int ___argc, char *const *___argv, const char *__shortopts)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));

struct option {
  const char *name;

  int has_arg;
  int *flag;
  int val;
};

extern int getopt_long(int ___argc, char *const *___argv,
                       const char *__shortopts, const struct option *__longopts,
                       int *__longind) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2, 3)));
extern int getopt_long_only(int ___argc, char *const *___argv,
                            const char *__shortopts,
                            const struct option *__longopts, int *__longind)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));

typedef __sig_atomic_t sig_atomic_t;

union sigval {
  int sival_int;
  void *sival_ptr;
};

typedef union sigval __sigval_t;
typedef struct {
  int si_signo;

  int si_errno;

  int si_code;

  int __pad0;

  union {
    int _pad[((128 / sizeof(int)) - 4)];

    struct {
      __pid_t si_pid;
      __uid_t si_uid;
    } _kill;

    struct {
      int si_tid;
      int si_overrun;
      __sigval_t si_sigval;
    } _timer;

    struct {
      __pid_t si_pid;
      __uid_t si_uid;
      __sigval_t si_sigval;
    } _rt;

    struct {
      __pid_t si_pid;
      __uid_t si_uid;
      int si_status;
      __clock_t si_utime;
      __clock_t si_stime;
    } _sigchld;

    struct {
      void *si_addr;

      short int si_addr_lsb;
      union {

        struct {
          void *_lower;
          void *_upper;
        } _addr_bnd;

        __uint32_t _pkey;
      } _bounds;
    } _sigfault;

    struct {
      long int si_band;
      int si_fd;
    } _sigpoll;

    struct {
      void *_call_addr;
      int _syscall;
      unsigned int _arch;
    } _sigsys;

  } _sifields;
} siginfo_t;
enum {
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

enum {
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

enum {
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

enum {
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

enum {
  BUS_ADRALN = 1,

  BUS_ADRERR,

  BUS_OBJERR,

  BUS_MCEERR_AR,

  BUS_MCEERR_AO

};

enum {
  TRAP_BRKPT = 1,

  TRAP_TRACE,

  TRAP_BRANCH,

  TRAP_HWBKPT,

  TRAP_UNK

};

enum {
  CLD_EXITED = 1,

  CLD_KILLED,

  CLD_DUMPED,

  CLD_TRAPPED,

  CLD_STOPPED,

  CLD_CONTINUED

};

enum {
  POLL_IN = 1,

  POLL_OUT,

  POLL_MSG,

  POLL_ERR,

  POLL_PRI,

  POLL_HUP

};

typedef __sigval_t sigval_t;

typedef struct sigevent {
  __sigval_t sigev_value;
  int sigev_signo;
  int sigev_notify;

  union {
    int _pad[((64 / sizeof(int)) - 4)];

    __pid_t _tid;

    struct {
      void (*_function)(__sigval_t);
      pthread_attr_t *_attribute;
    } _sigev_thread;
  } _sigev_un;
} sigevent_t;
enum {
  SIGEV_SIGNAL = 0,

  SIGEV_NONE,

  SIGEV_THREAD,

  SIGEV_THREAD_ID = 4

};

typedef void (*__sighandler_t)(int);

extern __sighandler_t __sysv_signal(int __sig, __sighandler_t __handler)
    __attribute__((__nothrow__, __leaf__));

extern __sighandler_t sysv_signal(int __sig, __sighandler_t __handler)
    __attribute__((__nothrow__, __leaf__));

extern __sighandler_t signal(int __sig, __sighandler_t __handler)
    __attribute__((__nothrow__, __leaf__));
extern int kill(__pid_t __pid, int __sig)
    __attribute__((__nothrow__, __leaf__));

extern int killpg(__pid_t __pgrp, int __sig)
    __attribute__((__nothrow__, __leaf__));

extern int raise(int __sig) __attribute__((__nothrow__, __leaf__));

extern __sighandler_t ssignal(int __sig, __sighandler_t __handler)
    __attribute__((__nothrow__, __leaf__));
extern int gsignal(int __sig) __attribute__((__nothrow__, __leaf__));

extern void psignal(int __sig, const char *__s);

extern void psiginfo(const siginfo_t *__pinfo, const char *__s);
extern int sigpause(int __sig) __asm__("__xpg_sigpause")
    __attribute__((__deprecated__("Use the sigsuspend function instead")));
extern int sigblock(int __mask) __attribute__((__nothrow__, __leaf__))
__attribute__((__deprecated__));

extern int sigsetmask(int __mask) __attribute__((__nothrow__, __leaf__))
__attribute__((__deprecated__));

extern int siggetmask(void) __attribute__((__nothrow__, __leaf__))
__attribute__((__deprecated__));
typedef __sighandler_t sighandler_t;

typedef __sighandler_t sig_t;

extern int sigemptyset(sigset_t *__set) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

extern int sigfillset(sigset_t *__set) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

extern int sigaddset(sigset_t *__set, int __signo)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern int sigdelset(sigset_t *__set, int __signo)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern int sigismember(const sigset_t *__set, int __signo)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern int sigisemptyset(const sigset_t *__set)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern int sigandset(sigset_t *__set, const sigset_t *__left,
                     const sigset_t *__right)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__nonnull__(1, 2, 3)));

extern int sigorset(sigset_t *__set, const sigset_t *__left,
                    const sigset_t *__right)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__nonnull__(1, 2, 3)));

struct sigaction {

  union {

    __sighandler_t sa_handler;

    void (*sa_sigaction)(int, siginfo_t *, void *);
  } __sigaction_handler;

  __sigset_t sa_mask;

  int sa_flags;

  void (*sa_restorer)(void);
};

extern int sigprocmask(int __how, const sigset_t *__restrict __set,
                       sigset_t *__restrict __oset)
    __attribute__((__nothrow__, __leaf__));

extern int sigsuspend(const sigset_t *__set) __attribute__((__nonnull__(1)));

extern int sigaction(int __sig, const struct sigaction *__restrict __act,
                     struct sigaction *__restrict __oact)
    __attribute__((__nothrow__, __leaf__));

extern int sigpending(sigset_t *__set) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

extern int sigwait(const sigset_t *__restrict __set, int *__restrict __sig)
    __attribute__((__nonnull__(1, 2)));

extern int sigwaitinfo(const sigset_t *__restrict __set,
                       siginfo_t *__restrict __info)
    __attribute__((__nonnull__(1)));

extern int sigtimedwait(const sigset_t *__restrict __set,
                        siginfo_t *__restrict __info,
                        const struct timespec *__restrict __timeout)
    __attribute__((__nonnull__(1)));
extern int sigqueue(__pid_t __pid, int __sig, const union sigval __val)
    __attribute__((__nothrow__, __leaf__));

struct _fpx_sw_bytes {
  __uint32_t magic1;
  __uint32_t extended_size;
  __uint64_t xstate_bv;
  __uint32_t xstate_size;
  __uint32_t __glibc_reserved1[7];
};

struct _fpreg {
  unsigned short significand[4];
  unsigned short exponent;
};

struct _fpxreg {
  unsigned short significand[4];
  unsigned short exponent;
  unsigned short __glibc_reserved1[3];
};

struct _xmmreg {
  __uint32_t element[4];
};
struct _fpstate {

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

struct sigcontext {
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
  __extension__ union {
    struct _fpstate *fpstate;
    __uint64_t __fpstate_word;
  };
  __uint64_t __reserved1[8];
};

struct _xsave_hdr {
  __uint64_t xstate_bv;
  __uint64_t __glibc_reserved1[2];
  __uint64_t __glibc_reserved2[5];
};

struct _ymmh_state {
  __uint32_t ymmh_space[64];
};

struct _xstate {
  struct _fpstate fpstate;
  struct _xsave_hdr xstate_hdr;
  struct _ymmh_state ymmh;
};

extern int sigreturn(struct sigcontext *__scp)
    __attribute__((__nothrow__, __leaf__));

typedef struct {
  void *ss_sp;
  int ss_flags;
  size_t ss_size;
} stack_t;

__extension__ typedef long long int greg_t;
typedef greg_t gregset_t[23];

enum {
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

struct _libc_fpxreg {
  unsigned short int significand[4];
  unsigned short int exponent;
  unsigned short int __glibc_reserved1[3];
};

struct _libc_xmmreg {
  __uint32_t element[4];
};

struct _libc_fpstate {

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

typedef struct {
  gregset_t gregs;

  fpregset_t fpregs;
  __extension__ unsigned long long __reserved1[8];
} mcontext_t;

typedef struct ucontext_t {
  unsigned long int uc_flags;
  struct ucontext_t *uc_link;
  stack_t uc_stack;
  mcontext_t uc_mcontext;
  sigset_t uc_sigmask;
  struct _libc_fpstate __fpregs_mem;
  __extension__ unsigned long long int __ssp[4];
} ucontext_t;

extern int siginterrupt(int __sig, int __interrupt)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__deprecated__("Use sigaction with SA_RESTART instead")));

typedef __intptr_t intptr_t;

typedef __socklen_t socklen_t;
extern int access(const char *__name, int __type)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern int euidaccess(const char *__name, int __type)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern int eaccess(const char *__name, int __type)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern int execveat(int __fd, const char *__path, char *const __argv[],
                    char *const __envp[], int __flags)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));

extern int faccessat(int __fd, const char *__file, int __type, int __flag)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)))
    __attribute__((__warn_unused_result__));
extern __off_t lseek(int __fd, __off_t __offset, int __whence)
    __attribute__((__nothrow__, __leaf__));
extern __off64_t lseek64(int __fd, __off64_t __offset, int __whence)
    __attribute__((__nothrow__, __leaf__));

extern int close(int __fd);

extern void closefrom(int __lowfd) __attribute__((__nothrow__, __leaf__));

extern ssize_t read(int __fd, void *__buf, size_t __nbytes)
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 2, 3)));

extern ssize_t write(int __fd, const void *__buf, size_t __n)
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__read_only__, 2, 3)));
extern ssize_t pread(int __fd, void *__buf, size_t __nbytes, __off_t __offset)
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 2, 3)));

extern ssize_t pwrite(int __fd, const void *__buf, size_t __n, __off_t __offset)
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__read_only__, 2, 3)));
extern ssize_t pread64(int __fd, void *__buf, size_t __nbytes,
                       __off64_t __offset)
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 2, 3)));

extern ssize_t pwrite64(int __fd, const void *__buf, size_t __n,
                        __off64_t __offset)
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__read_only__, 2, 3)));

extern int pipe(int __pipedes[2]) __attribute__((__nothrow__, __leaf__))
__attribute__((__warn_unused_result__));

extern int pipe2(int __pipedes[2], int __flags)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__));
extern unsigned int alarm(unsigned int __seconds)
    __attribute__((__nothrow__, __leaf__));
extern unsigned int sleep(unsigned int __seconds);

extern __useconds_t ualarm(__useconds_t __value, __useconds_t __interval)
    __attribute__((__nothrow__, __leaf__));

extern int usleep(__useconds_t __useconds);
extern int pause(void);

extern int chown(const char *__file, __uid_t __owner, __gid_t __group)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__warn_unused_result__));

extern int fchown(int __fd, __uid_t __owner, __gid_t __group)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__));

extern int lchown(const char *__file, __uid_t __owner, __gid_t __group)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__warn_unused_result__));

extern int fchownat(int __fd, const char *__file, __uid_t __owner,
                    __gid_t __group, int __flag)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)))
    __attribute__((__warn_unused_result__));

extern int chdir(const char *__path) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));

extern int fchdir(int __fd) __attribute__((__nothrow__, __leaf__))
__attribute__((__warn_unused_result__));
extern char *getcwd(char *__buf, size_t __size)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__));

extern char *get_current_dir_name(void) __attribute__((__nothrow__, __leaf__));

extern char *getwd(char *__buf) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1))) __attribute__((__deprecated__))
__attribute__((__warn_unused_result__))
__attribute__((__access__(__write_only__, 1)));

extern int dup(int __fd) __attribute__((__nothrow__, __leaf__))
__attribute__((__warn_unused_result__));

extern int dup2(int __fd, int __fd2) __attribute__((__nothrow__, __leaf__));

extern int dup3(int __fd, int __fd2, int __flags)
    __attribute__((__nothrow__, __leaf__));

extern char **__environ;

extern char **environ;

extern int execve(const char *__path, char *const __argv[],
                  char *const __envp[]) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));

extern int fexecve(int __fd, char *const __argv[], char *const __envp[])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));

extern int execv(const char *__path, char *const __argv[])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern int execle(const char *__path, const char *__arg, ...)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern int execl(const char *__path, const char *__arg, ...)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern int execvp(const char *__file, char *const __argv[])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern int execlp(const char *__file, const char *__arg, ...)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern int execvpe(const char *__file, char *const __argv[],
                   char *const __envp[]) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));

extern int nice(int __inc) __attribute__((__nothrow__, __leaf__))
__attribute__((__warn_unused_result__));

extern void _exit(int __status) __attribute__((__noreturn__));

enum {
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

enum {
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

enum {
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

extern long int pathconf(const char *__path, int __name)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern long int fpathconf(int __fd, int __name)
    __attribute__((__nothrow__, __leaf__));

extern long int sysconf(int __name) __attribute__((__nothrow__, __leaf__));

extern size_t confstr(int __name, char *__buf, size_t __len)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__access__(__write_only__, 2, 3)));

extern __pid_t getpid(void) __attribute__((__nothrow__, __leaf__));

extern __pid_t getppid(void) __attribute__((__nothrow__, __leaf__));

extern __pid_t getpgrp(void) __attribute__((__nothrow__, __leaf__));

extern __pid_t __getpgid(__pid_t __pid) __attribute__((__nothrow__, __leaf__));

extern __pid_t getpgid(__pid_t __pid) __attribute__((__nothrow__, __leaf__));

extern int setpgid(__pid_t __pid, __pid_t __pgid)
    __attribute__((__nothrow__, __leaf__));
extern int setpgrp(void) __attribute__((__nothrow__, __leaf__));

extern __pid_t setsid(void) __attribute__((__nothrow__, __leaf__));

extern __pid_t getsid(__pid_t __pid) __attribute__((__nothrow__, __leaf__));

extern __uid_t getuid(void) __attribute__((__nothrow__, __leaf__));

extern __uid_t geteuid(void) __attribute__((__nothrow__, __leaf__));

extern __gid_t getgid(void) __attribute__((__nothrow__, __leaf__));

extern __gid_t getegid(void) __attribute__((__nothrow__, __leaf__));

extern int getgroups(int __size, __gid_t __list[])
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 2, 1)));

extern int group_member(__gid_t __gid) __attribute__((__nothrow__, __leaf__));

extern int setuid(__uid_t __uid) __attribute__((__nothrow__, __leaf__))
__attribute__((__warn_unused_result__));

extern int setreuid(__uid_t __ruid, __uid_t __euid)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__));

extern int seteuid(__uid_t __uid) __attribute__((__nothrow__, __leaf__))
__attribute__((__warn_unused_result__));

extern int setgid(__gid_t __gid) __attribute__((__nothrow__, __leaf__))
__attribute__((__warn_unused_result__));

extern int setregid(__gid_t __rgid, __gid_t __egid)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__));

extern int setegid(__gid_t __gid) __attribute__((__nothrow__, __leaf__))
__attribute__((__warn_unused_result__));

extern int getresuid(__uid_t *__ruid, __uid_t *__euid, __uid_t *__suid)
    __attribute__((__nothrow__, __leaf__));

extern int getresgid(__gid_t *__rgid, __gid_t *__egid, __gid_t *__sgid)
    __attribute__((__nothrow__, __leaf__));

extern int setresuid(__uid_t __ruid, __uid_t __euid, __uid_t __suid)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__));

extern int setresgid(__gid_t __rgid, __gid_t __egid, __gid_t __sgid)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__));

extern __pid_t fork(void) __attribute__((__nothrow__));

extern __pid_t vfork(void) __attribute__((__nothrow__, __leaf__));

extern __pid_t _Fork(void) __attribute__((__nothrow__, __leaf__));

extern char *ttyname(int __fd) __attribute__((__nothrow__, __leaf__));

extern int ttyname_r(int __fd, char *__buf, size_t __buflen)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)))
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 2, 3)));

extern int isatty(int __fd) __attribute__((__nothrow__, __leaf__));

extern int ttyslot(void) __attribute__((__nothrow__, __leaf__));

extern int link(const char *__from, const char *__to)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)))
    __attribute__((__warn_unused_result__));

extern int linkat(int __fromfd, const char *__from, int __tofd,
                  const char *__to, int __flags)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 4)))
    __attribute__((__warn_unused_result__));

extern int symlink(const char *__from, const char *__to)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)))
    __attribute__((__warn_unused_result__));

extern ssize_t readlink(const char *__restrict __path, char *__restrict __buf,
                        size_t __len) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2))) __attribute__((__warn_unused_result__))
__attribute__((__access__(__write_only__, 2, 3)));

extern int symlinkat(const char *__from, int __tofd, const char *__to)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)))
    __attribute__((__warn_unused_result__));

extern ssize_t readlinkat(int __fd, const char *__restrict __path,
                          char *__restrict __buf, size_t __len)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)))
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 3, 4)));

extern int unlink(const char *__name) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

extern int unlinkat(int __fd, const char *__name, int __flag)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));

extern int rmdir(const char *__path) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

extern __pid_t tcgetpgrp(int __fd) __attribute__((__nothrow__, __leaf__));

extern int tcsetpgrp(int __fd, __pid_t __pgrp_id)
    __attribute__((__nothrow__, __leaf__));

extern char *getlogin(void);

extern int getlogin_r(char *__name, size_t __name_len)
    __attribute__((__nonnull__(1)))
    __attribute__((__access__(__write_only__, 1, 2)));

extern int setlogin(const char *__name) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

extern int gethostname(char *__name, size_t __len)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__access__(__write_only__, 1, 2)));

extern int sethostname(const char *__name, size_t __len)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__read_only__, 1, 2)));

extern int sethostid(long int __id) __attribute__((__nothrow__, __leaf__))
__attribute__((__warn_unused_result__));

extern int getdomainname(char *__name, size_t __len)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 1, 2)));
extern int setdomainname(const char *__name, size_t __len)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__read_only__, 1, 2)));

extern int vhangup(void) __attribute__((__nothrow__, __leaf__));

extern int revoke(const char *__file) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));

extern int profil(unsigned short int *__sample_buffer, size_t __size,
                  size_t __offset, unsigned int __scale)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern int acct(const char *__name) __attribute__((__nothrow__, __leaf__));

extern char *getusershell(void) __attribute__((__nothrow__, __leaf__));
extern void endusershell(void) __attribute__((__nothrow__, __leaf__));
extern void setusershell(void) __attribute__((__nothrow__, __leaf__));

extern int daemon(int __nochdir, int __noclose)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__));

extern int chroot(const char *__path) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));

extern char *getpass(const char *__prompt) __attribute__((__nonnull__(1)));

extern int fsync(int __fd);

extern int syncfs(int __fd) __attribute__((__nothrow__, __leaf__));

extern long int gethostid(void);

extern void sync(void) __attribute__((__nothrow__, __leaf__));

extern int getpagesize(void) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));

extern int getdtablesize(void) __attribute__((__nothrow__, __leaf__));
extern int truncate(const char *__file, __off_t __length)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__warn_unused_result__));
extern int truncate64(const char *__file, __off64_t __length)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__warn_unused_result__));
extern int ftruncate(int __fd, __off_t __length)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__));
extern int ftruncate64(int __fd, __off64_t __length)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__));
extern int brk(void *__addr) __attribute__((__nothrow__, __leaf__))
__attribute__((__warn_unused_result__));

extern void *sbrk(intptr_t __delta) __attribute__((__nothrow__, __leaf__));
extern long int syscall(long int __sysno, ...)
    __attribute__((__nothrow__, __leaf__));
extern int lockf(int __fd, int __cmd, __off_t __len)
    __attribute__((__warn_unused_result__));
extern int lockf64(int __fd, int __cmd, __off64_t __len)
    __attribute__((__warn_unused_result__));
ssize_t copy_file_range(int __infd, __off64_t *__pinoff, int __outfd,
                        __off64_t *__poutoff, size_t __length,
                        unsigned int __flags);

extern int fdatasync(int __fildes);
extern char *crypt(const char *__key, const char *__salt)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern void swab(const void *__restrict __from, void *__restrict __to,
                 ssize_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)))
__attribute__((__access__(__read_only__, 1, 3)))
__attribute__((__access__(__write_only__, 2, 3)));
int getentropy(void *__buffer, size_t __length)
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 1, 2)));
extern int close_range(unsigned int __fd, unsigned int __max_fd, int __flags)
    __attribute__((__nothrow__, __leaf__));

extern ssize_t __read_chk(int __fd, void *__buf, size_t __nbytes,
                          size_t __buflen)
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 2, 3)));
extern ssize_t __read_alias(int __fd, void *__buf,
                            size_t __nbytes) __asm__(""
                                                     "read")

    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 2, 3)));
extern ssize_t __read_chk_warn(int __fd, void *__buf, size_t __nbytes,
                               size_t __buflen) __asm__(""
                                                        "__read_chk")

    __attribute__((__warn_unused_result__))
    __attribute__((__warning__("read called with bigger length than size of "
                               "the destination buffer")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
__attribute__((__warn_unused_result__)) ssize_t
read(int __fd, void *__buf, size_t __nbytes) {
  return ((((__typeof(__nbytes))0 < (__typeof(__nbytes))-1 ||
            (__builtin_constant_p(__nbytes) && (__nbytes) > 0)) &&
           __builtin_constant_p(
               (((long unsigned int)(__nbytes)) <=
                (__builtin_object_size(__buf, 0)) / (sizeof(char)))) &&
           (((long unsigned int)(__nbytes)) <=
            (__builtin_object_size(__buf, 0)) / (sizeof(char))))
              ? __read_alias(__fd, __buf, __nbytes)
              : ((((__typeof(__nbytes))0 < (__typeof(__nbytes))-1 ||
                   (__builtin_constant_p(__nbytes) && (__nbytes) > 0)) &&
                  __builtin_constant_p(
                      (((long unsigned int)(__nbytes)) <=
                       (__builtin_object_size(__buf, 0)) / (sizeof(char)))) &&
                  !(((long unsigned int)(__nbytes)) <=
                    (__builtin_object_size(__buf, 0)) / (sizeof(char))))
                     ? __read_chk_warn(__fd, __buf, __nbytes,
                                       __builtin_object_size(__buf, 0))
                     : __read_chk(__fd, __buf, __nbytes,
                                  __builtin_object_size(__buf, 0))))

      ;
}

extern ssize_t __pread_chk(int __fd, void *__buf, size_t __nbytes,
                           __off_t __offset, size_t __bufsize)
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 2, 3)));
extern ssize_t __pread64_chk(int __fd, void *__buf, size_t __nbytes,
                             __off64_t __offset, size_t __bufsize)
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 2, 3)));
extern ssize_t __pread_alias(int __fd, void *__buf, size_t __nbytes,
                             __off_t __offset) __asm__(""
                                                       "pread")

    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 2, 3)));
extern ssize_t __pread64_alias(int __fd, void *__buf, size_t __nbytes,
                               __off64_t __offset) __asm__(""
                                                           "pread64")

    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 2, 3)));
extern ssize_t __pread_chk_warn(int __fd, void *__buf, size_t __nbytes,
                                __off_t __offset,
                                size_t __bufsize) __asm__(""
                                                          "__pread_chk")

    __attribute__((__warn_unused_result__))
    __attribute__((__warning__("pread called with bigger length than size of "
                               "the destination buffer")));
extern ssize_t __pread64_chk_warn(int __fd, void *__buf, size_t __nbytes,
                                  __off64_t __offset,
                                  size_t __bufsize) __asm__(""
                                                            "__pread64_chk")

    __attribute__((__warn_unused_result__))
    __attribute__((__warning__("pread64 called with bigger length than size of "
                               "the destination buffer")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
__attribute__((__warn_unused_result__)) ssize_t
pread(int __fd, void *__buf, size_t __nbytes, __off_t __offset) {
  return ((((__typeof(__nbytes))0 < (__typeof(__nbytes))-1 ||
            (__builtin_constant_p(__nbytes) && (__nbytes) > 0)) &&
           __builtin_constant_p(
               (((long unsigned int)(__nbytes)) <=
                (__builtin_object_size(__buf, 0)) / (sizeof(char)))) &&
           (((long unsigned int)(__nbytes)) <=
            (__builtin_object_size(__buf, 0)) / (sizeof(char))))
              ? __pread_alias(__fd, __buf, __nbytes, __offset)
              : ((((__typeof(__nbytes))0 < (__typeof(__nbytes))-1 ||
                   (__builtin_constant_p(__nbytes) && (__nbytes) > 0)) &&
                  __builtin_constant_p(
                      (((long unsigned int)(__nbytes)) <=
                       (__builtin_object_size(__buf, 0)) / (sizeof(char)))) &&
                  !(((long unsigned int)(__nbytes)) <=
                    (__builtin_object_size(__buf, 0)) / (sizeof(char))))
                     ? __pread_chk_warn(__fd, __buf, __nbytes, __offset,
                                        __builtin_object_size(__buf, 0))
                     : __pread_chk(__fd, __buf, __nbytes, __offset,
                                   __builtin_object_size(__buf, 0))))

      ;
}
extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
__attribute__((__warn_unused_result__)) ssize_t
pread64(int __fd, void *__buf, size_t __nbytes, __off64_t __offset) {
  return ((((__typeof(__nbytes))0 < (__typeof(__nbytes))-1 ||
            (__builtin_constant_p(__nbytes) && (__nbytes) > 0)) &&
           __builtin_constant_p(
               (((long unsigned int)(__nbytes)) <=
                (__builtin_object_size(__buf, 0)) / (sizeof(char)))) &&
           (((long unsigned int)(__nbytes)) <=
            (__builtin_object_size(__buf, 0)) / (sizeof(char))))
              ? __pread64_alias(__fd, __buf, __nbytes, __offset)
              : ((((__typeof(__nbytes))0 < (__typeof(__nbytes))-1 ||
                   (__builtin_constant_p(__nbytes) && (__nbytes) > 0)) &&
                  __builtin_constant_p(
                      (((long unsigned int)(__nbytes)) <=
                       (__builtin_object_size(__buf, 0)) / (sizeof(char)))) &&
                  !(((long unsigned int)(__nbytes)) <=
                    (__builtin_object_size(__buf, 0)) / (sizeof(char))))
                     ? __pread64_chk_warn(__fd, __buf, __nbytes, __offset,
                                          __builtin_object_size(__buf, 0))
                     : __pread64_chk(__fd, __buf, __nbytes, __offset,
                                     __builtin_object_size(__buf, 0))))

      ;
}

extern ssize_t __readlink_chk(const char *__restrict __path,
                              char *__restrict __buf, size_t __len,
                              size_t __buflen)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)))
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 2, 3)));
extern ssize_t __readlink_alias(const char *__restrict __path,
                                char *__restrict __buf,
                                size_t __len) __asm__(""
                                                      "readlink")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__nonnull__(1, 2))) __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 2, 3)));
extern ssize_t __readlink_chk_warn(const char *__restrict __path,
                                   char *__restrict __buf, size_t __len,
                                   size_t __buflen) __asm__(""
                                                            "__readlink_chk")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__nonnull__(1, 2))) __attribute__((__warn_unused_result__))
    __attribute__((__warning__("readlink called with bigger length "
                               "than size of destination buffer")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
__attribute__((__nonnull__(1, 2))) __attribute__((__warn_unused_result__))
ssize_t __attribute__((__nothrow__, __leaf__))
readlink(const char *__restrict __path, char *__restrict __buf, size_t __len)

{
  return ((((__typeof(__len))0 < (__typeof(__len))-1 ||
            (__builtin_constant_p(__len) && (__len) > 0)) &&
           __builtin_constant_p(
               (((long unsigned int)(__len)) <=
                (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char)))) &&
           (((long unsigned int)(__len)) <=
            (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char))))
              ? __readlink_alias(__path, __buf, __len)
              : ((((__typeof(__len))0 < (__typeof(__len))-1 ||
                   (__builtin_constant_p(__len) && (__len) > 0)) &&
                  __builtin_constant_p((((long unsigned int)(__len)) <=
                                        (__builtin_object_size(__buf, 2 > 1)) /
                                            (sizeof(char)))) &&
                  !(((long unsigned int)(__len)) <=
                    (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char))))
                     ? __readlink_chk_warn(__path, __buf, __len,
                                           __builtin_object_size(__buf, 2 > 1))
                     : __readlink_chk(__path, __buf, __len,
                                      __builtin_object_size(__buf, 2 > 1))))

      ;
}

extern ssize_t __readlinkat_chk(int __fd, const char *__restrict __path,
                                char *__restrict __buf, size_t __len,
                                size_t __buflen)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)))
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 3, 4)));
extern ssize_t __readlinkat_alias(int __fd, const char *__restrict __path,
                                  char *__restrict __buf,
                                  size_t __len) __asm__(""
                                                        "readlinkat")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__nonnull__(2, 3))) __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 3, 4)));
extern ssize_t
__readlinkat_chk_warn(int __fd, const char *__restrict __path,
                      char *__restrict __buf, size_t __len,
                      size_t __buflen) __asm__(""
                                               "__readlinkat_chk")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__nonnull__(2, 3))) __attribute__((__warn_unused_result__))
    __attribute__((__warning__("readlinkat called with bigger "
                               "length than size of destination "
                               "buffer")))

    ;

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
__attribute__((__nonnull__(2, 3))) __attribute__((__warn_unused_result__))
ssize_t __attribute__((__nothrow__, __leaf__))
readlinkat(int __fd, const char *__restrict __path, char *__restrict __buf,
           size_t __len)

{
  return (
      (((__typeof(__len))0 < (__typeof(__len))-1 ||
        (__builtin_constant_p(__len) && (__len) > 0)) &&
       __builtin_constant_p(
           (((long unsigned int)(__len)) <=
            (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char)))) &&
       (((long unsigned int)(__len)) <=
        (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char))))
          ? __readlinkat_alias(__fd, __path, __buf, __len)
          : ((((__typeof(__len))0 < (__typeof(__len))-1 ||
               (__builtin_constant_p(__len) && (__len) > 0)) &&
              __builtin_constant_p(
                  (((long unsigned int)(__len)) <=
                   (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char)))) &&
              !(((long unsigned int)(__len)) <=
                (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char))))
                 ? __readlinkat_chk_warn(__fd, __path, __buf, __len,
                                         __builtin_object_size(__buf, 2 > 1))
                 : __readlinkat_chk(__fd, __path, __buf, __len,
                                    __builtin_object_size(__buf, 2 > 1))))

      ;
}

extern char *__getcwd_chk(char *__buf, size_t __size, size_t __buflen)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__));
extern char *__getcwd_alias(char *__buf, size_t __size) __asm__(""
                                                                "getcwd")
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__));
extern char *__getcwd_chk_warn(char *__buf, size_t __size,
                               size_t __buflen) __asm__(""
                                                        "__getcwd_chk")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__warn_unused_result__))
    __attribute__((__warning__("getcwd caller with bigger length than size of "
                               "destination buffer")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
__attribute__((__warn_unused_result__)) char *__attribute__((__nothrow__,
                                                             __leaf__))
getcwd(char *__buf, size_t __size) {
  return ((((__typeof(__size))0 < (__typeof(__size))-1 ||
            (__builtin_constant_p(__size) && (__size) > 0)) &&
           __builtin_constant_p(
               (((long unsigned int)(__size)) <=
                (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char)))) &&
           (((long unsigned int)(__size)) <=
            (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char))))
              ? __getcwd_alias(__buf, __size)
              : ((((__typeof(__size))0 < (__typeof(__size))-1 ||
                   (__builtin_constant_p(__size) && (__size) > 0)) &&
                  __builtin_constant_p((((long unsigned int)(__size)) <=
                                        (__builtin_object_size(__buf, 2 > 1)) /
                                            (sizeof(char)))) &&
                  !(((long unsigned int)(__size)) <=
                    (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char))))
                     ? __getcwd_chk_warn(__buf, __size,
                                         __builtin_object_size(__buf, 2 > 1))
                     : __getcwd_chk(__buf, __size,
                                    __builtin_object_size(__buf, 2 > 1))))

      ;
}

extern char *__getwd_chk(char *__buf, size_t buflen)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 1, 2)));
extern char *__getwd_warn(char *__buf) __asm__(""
                                               "getwd")
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__warn_unused_result__))
    __attribute__((__warning__("please use getcwd instead, as getwd "
                               "doesn't specify buffer size")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
__attribute__((__nonnull__(1))) __attribute__((__deprecated__))
__attribute__((__warn_unused_result__)) char *__attribute__((__nothrow__,
                                                             __leaf__))
getwd(char *__buf) {
  if (__builtin_object_size(__buf, 2 > 1) != (size_t)-1)
    return __getwd_chk(__buf, __builtin_object_size(__buf, 2 > 1));
  return __getwd_warn(__buf);
}

extern size_t __confstr_chk(int __name, char *__buf, size_t __len,
                            size_t __buflen)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__access__(__write_only__, 2, 3)));
extern size_t __confstr_alias(int __name, char *__buf,
                              size_t __len) __asm__(""
                                                    "confstr")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__access__(__write_only__, 2, 3)));
extern size_t __confstr_chk_warn(int __name, char *__buf, size_t __len,
                                 size_t __buflen) __asm__(""
                                                          "__confstr_chk")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__warning__(
        "confstr called with bigger length than size of destination "
        "buffer")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) size_t
    __attribute__((__nothrow__, __leaf__))
    confstr(int __name, char *__buf, size_t __len) {
  return ((((__typeof(__len))0 < (__typeof(__len))-1 ||
            (__builtin_constant_p(__len) && (__len) > 0)) &&
           __builtin_constant_p(
               (((long unsigned int)(__len)) <=
                (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char)))) &&
           (((long unsigned int)(__len)) <=
            (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char))))
              ? __confstr_alias(__name, __buf, __len)
              : ((((__typeof(__len))0 < (__typeof(__len))-1 ||
                   (__builtin_constant_p(__len) && (__len) > 0)) &&
                  __builtin_constant_p((((long unsigned int)(__len)) <=
                                        (__builtin_object_size(__buf, 2 > 1)) /
                                            (sizeof(char)))) &&
                  !(((long unsigned int)(__len)) <=
                    (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char))))
                     ? __confstr_chk_warn(__name, __buf, __len,
                                          __builtin_object_size(__buf, 2 > 1))
                     : __confstr_chk(__name, __buf, __len,
                                     __builtin_object_size(__buf, 2 > 1))))

      ;
}

extern int __getgroups_chk(int __size, __gid_t __list[], size_t __listlen)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 2, 1)));
extern int __getgroups_alias(int __size, __gid_t __list[]) __asm__(""
                                                                   "getgroups")
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 2, 1)));
extern int
__getgroups_chk_warn(int __size, __gid_t __list[], size_t __listlen) __asm__(
    ""
    "__getgroups_chk") __attribute__((__nothrow__, __leaf__))

__attribute__((__warn_unused_result__))
__attribute__((__warning__("getgroups called with bigger group count than what "
                           "can fit into destination buffer")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
    __attribute__((__nothrow__, __leaf__))
    getgroups(int __size, __gid_t __list[]) {
  return ((((__typeof(__size))0 < (__typeof(__size))-1 ||
            (__builtin_constant_p(__size) && (__size) > 0)) &&
           __builtin_constant_p(
               (((long unsigned int)(__size)) <=
                (__builtin_object_size(__list, 2 > 1)) / (sizeof(__gid_t)))) &&
           (((long unsigned int)(__size)) <=
            (__builtin_object_size(__list, 2 > 1)) / (sizeof(__gid_t))))
              ? __getgroups_alias(__size, __list)
              : ((((__typeof(__size))0 < (__typeof(__size))-1 ||
                   (__builtin_constant_p(__size) && (__size) > 0)) &&
                  __builtin_constant_p((((long unsigned int)(__size)) <=
                                        (__builtin_object_size(__list, 2 > 1)) /
                                            (sizeof(__gid_t)))) &&
                  !(((long unsigned int)(__size)) <=
                    (__builtin_object_size(__list, 2 > 1)) / (sizeof(__gid_t))))
                     ? __getgroups_chk_warn(
                           __size, __list, __builtin_object_size(__list, 2 > 1))
                     : __getgroups_chk(__size, __list,
                                       __builtin_object_size(__list, 2 > 1))))

      ;
}

extern int __ttyname_r_chk(int __fd, char *__buf, size_t __buflen,
                           size_t __nreal)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)))
    __attribute__((__access__(__write_only__, 2, 3)));
extern int __ttyname_r_alias(int __fd, char *__buf,
                             size_t __buflen) __asm__(""
                                                      "ttyname_r")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__nonnull__(2)));
extern int __ttyname_r_chk_warn(int __fd, char *__buf, size_t __buflen,
                                size_t __nreal) __asm__(""
                                                        "__ttyname_r_chk")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__nonnull__(2)))
    __attribute__((__warning__("ttyname_r called with bigger buflen than "
                               "size of destination buffer")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
    __attribute__((__nothrow__, __leaf__))
    ttyname_r(int __fd, char *__buf, size_t __buflen) {
  return ((((__typeof(__buflen))0 < (__typeof(__buflen))-1 ||
            (__builtin_constant_p(__buflen) && (__buflen) > 0)) &&
           __builtin_constant_p(
               (((long unsigned int)(__buflen)) <=
                (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char)))) &&
           (((long unsigned int)(__buflen)) <=
            (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char))))
              ? __ttyname_r_alias(__fd, __buf, __buflen)
              : ((((__typeof(__buflen))0 < (__typeof(__buflen))-1 ||
                   (__builtin_constant_p(__buflen) && (__buflen) > 0)) &&
                  __builtin_constant_p((((long unsigned int)(__buflen)) <=
                                        (__builtin_object_size(__buf, 2 > 1)) /
                                            (sizeof(char)))) &&
                  !(((long unsigned int)(__buflen)) <=
                    (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char))))
                     ? __ttyname_r_chk_warn(__fd, __buf, __buflen,
                                            __builtin_object_size(__buf, 2 > 1))
                     : __ttyname_r_chk(__fd, __buf, __buflen,
                                       __builtin_object_size(__buf, 2 > 1))))

      ;
}

extern int __getlogin_r_chk(char *__buf, size_t __buflen, size_t __nreal)
    __attribute__((__nonnull__(1)))
    __attribute__((__access__(__write_only__, 1, 2)));
extern int __getlogin_r_alias(char *__buf,
                              size_t __buflen) __asm__(""
                                                       "getlogin_r")
    __attribute__((__nonnull__(1)));
extern int __getlogin_r_chk_warn(char *__buf, size_t __buflen,
                                 size_t __nreal) __asm__(""
                                                         "__getlogin_r_chk")

    __attribute__((__nonnull__(1)))
    __attribute__((__warning__("getlogin_r called with bigger buflen than "
                               "size of destination buffer")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
getlogin_r(char *__buf, size_t __buflen) {
  return ((((__typeof(__buflen))0 < (__typeof(__buflen))-1 ||
            (__builtin_constant_p(__buflen) && (__buflen) > 0)) &&
           __builtin_constant_p(
               (((long unsigned int)(__buflen)) <=
                (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char)))) &&
           (((long unsigned int)(__buflen)) <=
            (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char))))
              ? __getlogin_r_alias(__buf, __buflen)
              : ((((__typeof(__buflen))0 < (__typeof(__buflen))-1 ||
                   (__builtin_constant_p(__buflen) && (__buflen) > 0)) &&
                  __builtin_constant_p((((long unsigned int)(__buflen)) <=
                                        (__builtin_object_size(__buf, 2 > 1)) /
                                            (sizeof(char)))) &&
                  !(((long unsigned int)(__buflen)) <=
                    (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char))))
                     ? __getlogin_r_chk_warn(
                           __buf, __buflen, __builtin_object_size(__buf, 2 > 1))
                     : __getlogin_r_chk(__buf, __buflen,
                                        __builtin_object_size(__buf, 2 > 1))))

      ;
}

extern int __gethostname_chk(char *__buf, size_t __buflen, size_t __nreal)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__access__(__write_only__, 1, 2)));
extern int __gethostname_alias(char *__buf,
                               size_t __buflen) __asm__(""
                                                        "gethostname")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__nonnull__(1)))
    __attribute__((__access__(__write_only__, 1, 2)));
extern int __gethostname_chk_warn(char *__buf, size_t __buflen,
                                  size_t __nreal) __asm__(""
                                                          "__gethostname_chk")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__nonnull__(1)))
    __attribute__((__warning__("gethostname called with bigger buflen than "
                               "size of destination buffer")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
    __attribute__((__nothrow__, __leaf__))
    gethostname(char *__buf, size_t __buflen) {
  return ((((__typeof(__buflen))0 < (__typeof(__buflen))-1 ||
            (__builtin_constant_p(__buflen) && (__buflen) > 0)) &&
           __builtin_constant_p(
               (((long unsigned int)(__buflen)) <=
                (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char)))) &&
           (((long unsigned int)(__buflen)) <=
            (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char))))
              ? __gethostname_alias(__buf, __buflen)
              : ((((__typeof(__buflen))0 < (__typeof(__buflen))-1 ||
                   (__builtin_constant_p(__buflen) && (__buflen) > 0)) &&
                  __builtin_constant_p((((long unsigned int)(__buflen)) <=
                                        (__builtin_object_size(__buf, 2 > 1)) /
                                            (sizeof(char)))) &&
                  !(((long unsigned int)(__buflen)) <=
                    (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char))))
                     ? __gethostname_chk_warn(
                           __buf, __buflen, __builtin_object_size(__buf, 2 > 1))
                     : __gethostname_chk(__buf, __buflen,
                                         __builtin_object_size(__buf, 2 > 1))))

      ;
}

extern int __getdomainname_chk(char *__buf, size_t __buflen, size_t __nreal)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 1, 2)));
extern int __getdomainname_alias(char *__buf,
                                 size_t __buflen) __asm__(""
                                                          "getdomainname")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 1, 2)));
extern int
__getdomainname_chk_warn(char *__buf, size_t __buflen,
                         size_t __nreal) __asm__(""
                                                 "__getdomainname_chk")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__))
    __attribute__((__warning__("getdomainname called with bigger "
                               "buflen than size of destination "
                               "buffer")))

    ;

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
    __attribute__((__nothrow__, __leaf__))
    getdomainname(char *__buf, size_t __buflen) {
  return (
      (((__typeof(__buflen))0 < (__typeof(__buflen))-1 ||
        (__builtin_constant_p(__buflen) && (__buflen) > 0)) &&
       __builtin_constant_p(
           (((long unsigned int)(__buflen)) <=
            (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char)))) &&
       (((long unsigned int)(__buflen)) <=
        (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char))))
          ? __getdomainname_alias(__buf, __buflen)
          : ((((__typeof(__buflen))0 < (__typeof(__buflen))-1 ||
               (__builtin_constant_p(__buflen) && (__buflen) > 0)) &&
              __builtin_constant_p(
                  (((long unsigned int)(__buflen)) <=
                   (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char)))) &&
              !(((long unsigned int)(__buflen)) <=
                (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char))))
                 ? __getdomainname_chk_warn(__buf, __buflen,
                                            __builtin_object_size(__buf, 2 > 1))
                 : __getdomainname_chk(__buf, __buflen,
                                       __builtin_object_size(__buf, 2 > 1))))

      ;
}

extern __pid_t gettid(void) __attribute__((__nothrow__, __leaf__));

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int rpl_pipe2(int fd[2], int flags) __attribute__((__nonnull__(1)));
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;

enum {
  SS_ONSTACK = 1,

  SS_DISABLE

};

extern int sigaltstack(const stack_t *__restrict __ss,
                       stack_t *__restrict __oss)
    __attribute__((__nothrow__, __leaf__));

struct sigstack {
  void *ss_sp;
  int ss_onstack;
};

extern int sigstack(struct sigstack *__ss, struct sigstack *__oss)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__deprecated__));

extern int sighold(int __sig) __attribute__((__nothrow__, __leaf__))
__attribute__((__deprecated__("Use the sigprocmask function instead")));

extern int sigrelse(int __sig) __attribute__((__nothrow__, __leaf__))
__attribute__((__deprecated__("Use the sigprocmask function instead")));

extern int sigignore(int __sig) __attribute__((__nothrow__, __leaf__))
__attribute__((__deprecated__("Use the signal function instead")));

extern __sighandler_t sigset(int __sig, __sighandler_t __disp)
    __attribute__((__nothrow__, __leaf__)) __attribute__((
        __deprecated__("Use the signal and sigprocmask functions instead")));

extern int pthread_sigmask(int __how, const __sigset_t *__restrict __newmask,
                           __sigset_t *__restrict __oldmask)
    __attribute__((__nothrow__, __leaf__));

extern int pthread_kill(pthread_t __threadid, int __signo)
    __attribute__((__nothrow__, __leaf__));

extern int pthread_sigqueue(pthread_t __threadid, int __signo,
                            const union sigval __value)
    __attribute__((__nothrow__, __leaf__));

extern int __libc_current_sigrtmin(void) __attribute__((__nothrow__, __leaf__));

extern int __libc_current_sigrtmax(void) __attribute__((__nothrow__, __leaf__));

extern int tgkill(__pid_t __tgid, __pid_t __tid, int __signal);

extern int _gl_cxxalias_dummy

    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

    ;
extern int _gl_cxxalias_dummy;

typedef void (*_gl_function_taking_int_returning_void_t)(int);
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int is_selinux_enabled(void);

extern int is_selinux_mls_enabled(void);

typedef char *security_context_t

    __attribute__((deprecated))

    ;

extern void freecon(char *con);

extern void freeconary(char **con);

extern int getcon(char **con);
extern int getcon_raw(char **con);
extern int setcon(const char *con);
extern int setcon_raw(const char *con);

extern int getpidcon(pid_t pid, char **con);
extern int getpidcon_raw(pid_t pid, char **con);

extern int getprevcon(char **con);
extern int getprevcon_raw(char **con);

extern int getexeccon(char **con);
extern int getexeccon_raw(char **con);

extern int setexeccon(const char *con);
extern int setexeccon_raw(const char *con);

extern int getfscreatecon(char **con);
extern int getfscreatecon_raw(char **con);

extern int setfscreatecon(const char *context);
extern int setfscreatecon_raw(const char *context);

extern int getkeycreatecon(char **con);
extern int getkeycreatecon_raw(char **con);

extern int setkeycreatecon(const char *context);
extern int setkeycreatecon_raw(const char *context);

extern int getsockcreatecon(char **con);
extern int getsockcreatecon_raw(char **con);

extern int setsockcreatecon(const char *context);
extern int setsockcreatecon_raw(const char *context);

extern int rpl_getfilecon(const char *path, char **con);
extern int getfilecon_raw(const char *path, char **con);
extern int rpl_lgetfilecon(const char *path, char **con);
extern int lgetfilecon_raw(const char *path, char **con);
extern int rpl_fgetfilecon(int fd, char **con);
extern int fgetfilecon_raw(int fd, char **con);

extern int setfilecon(const char *path, const char *con);
extern int setfilecon_raw(const char *path, const char *con);
extern int lsetfilecon(const char *path, const char *con);
extern int lsetfilecon_raw(const char *path, const char *con);
extern int fsetfilecon(int fd, const char *con);
extern int fsetfilecon_raw(int fd, const char *con);

extern int getpeercon(int fd, char **con);
extern int getpeercon_raw(int fd, char **con);

typedef unsigned int access_vector_t;
typedef unsigned short security_class_t;

struct av_decision {
  access_vector_t allowed;
  access_vector_t decided;
  access_vector_t auditallow;
  access_vector_t auditdeny;
  unsigned int seqno;
  unsigned int flags;
};

struct selinux_opt {
  int type;
  const char *value;
};

union selinux_callback {

  int

      __attribute__((format(printf, 2, 3)))

      (*func_log)(int type, const char *fmt, ...);

  int (*func_audit)(void *auditdata, security_class_t cls, char *msgbuf,
                    size_t msgbufsize);

  int (*func_validate)(char **ctx);

  int (*func_setenforce)(int enforcing);

  int (*func_policyload)(int seqno);
};

extern union selinux_callback selinux_get_callback(int type);
extern void selinux_set_callback(int type, union selinux_callback cb);
extern int security_compute_av(const char *scon, const char *tcon,
                               security_class_t tclass,
                               access_vector_t requested,
                               struct av_decision *avd);
extern int security_compute_av_raw(const char *scon, const char *tcon,
                                   security_class_t tclass,
                                   access_vector_t requested,
                                   struct av_decision *avd);

extern int security_compute_av_flags(const char *scon, const char *tcon,
                                     security_class_t tclass,
                                     access_vector_t requested,
                                     struct av_decision *avd);
extern int security_compute_av_flags_raw(const char *scon, const char *tcon,
                                         security_class_t tclass,
                                         access_vector_t requested,
                                         struct av_decision *avd);

extern int security_compute_create(const char *scon, const char *tcon,
                                   security_class_t tclass, char **newcon);
extern int security_compute_create_raw(const char *scon, const char *tcon,
                                       security_class_t tclass, char **newcon);
extern int security_compute_create_name(const char *scon, const char *tcon,
                                        security_class_t tclass,
                                        const char *objname, char **newcon);
extern int security_compute_create_name_raw(const char *scon, const char *tcon,
                                            security_class_t tclass,
                                            const char *objname, char **newcon);

extern int security_compute_relabel(const char *scon, const char *tcon,
                                    security_class_t tclass, char **newcon);
extern int security_compute_relabel_raw(const char *scon, const char *tcon,
                                        security_class_t tclass, char **newcon);

extern int security_compute_member(const char *scon, const char *tcon,
                                   security_class_t tclass, char **newcon);
extern int security_compute_member_raw(const char *scon, const char *tcon,
                                       security_class_t tclass, char **newcon);

extern int security_compute_user(const char *scon, const char *username,
                                 char ***con);
extern int security_compute_user_raw(const char *scon, const char *username,
                                     char ***con);

extern int security_validatetrans(const char *scon, const char *tcon,
                                  security_class_t tclass, const char *newcon);
extern int security_validatetrans_raw(const char *scon, const char *tcon,
                                      security_class_t tclass,
                                      const char *newcon);

extern int security_load_policy(void *data, size_t len);

extern int security_get_initial_context(const char *name, char **con);
extern int security_get_initial_context_raw(const char *name, char **con);
extern int selinux_mkload_policy(int preservebools);
extern int selinux_init_load_policy(int *enforce);

typedef struct {
  char *name;
  int value;
} SELboolean;

extern int security_set_boolean_list(size_t boolcnt, SELboolean *boollist,
                                     int permanent);

extern int security_load_booleans(char *path)

    __attribute__((deprecated))

    ;

extern int security_check_context(const char *con);
extern int security_check_context_raw(const char *con);

extern int security_canonicalize_context(const char *con, char **canoncon);
extern int security_canonicalize_context_raw(const char *con, char **canoncon);

extern int security_getenforce(void);

extern int security_setenforce(int value);

extern int security_reject_unknown(void);

extern int security_deny_unknown(void);

extern int security_get_checkreqprot(void);

extern int security_disable(void);

extern int security_policyvers(void);

extern int security_get_boolean_names(char ***names, int *len);

extern int security_get_boolean_pending(const char *name);

extern int security_get_boolean_active(const char *name);

extern int security_set_boolean(const char *name, int value);

extern int security_commit_booleans(void);

struct security_class_mapping {
  const char *name;
  const char *perms[sizeof(access_vector_t) * 8 + 1];
};
extern int selinux_set_mapping(struct security_class_mapping *map);

extern security_class_t mode_to_security_class(mode_t mode);

extern security_class_t string_to_security_class(const char *name);
extern const char *security_class_to_string(security_class_t cls);

extern const char *security_av_perm_to_string(security_class_t tclass,
                                              access_vector_t perm);
extern access_vector_t string_to_av_perm(security_class_t tclass,
                                         const char *name);

extern int security_av_string(security_class_t tclass, access_vector_t av,
                              char **result);

extern void print_access_vector(security_class_t tclass, access_vector_t av);

extern void selinux_flush_class_cache(void);

extern void set_matchpathcon_printf(void (*f)(const char *fmt, ...));

extern void set_matchpathcon_invalidcon(int (*f)(const char *path,
                                                 unsigned lineno,
                                                 char *context));

extern void set_matchpathcon_canoncon(int (*f)(const char *path,
                                               unsigned lineno,
                                               char **context));

extern void set_matchpathcon_flags(unsigned int flags);
extern int matchpathcon_init(const char *path)

    __attribute__((
        deprecated("Use selabel_open with backend SELABEL_CTX_FILE")))

    ;

extern int matchpathcon_init_prefix(const char *path, const char *prefix);

extern void matchpathcon_fini(void)

    __attribute__((deprecated("Use selabel_close")))

    ;

extern int realpath_not_final(const char *name, char *resolved_path);

extern int matchpathcon(const char *path, mode_t mode, char **con)

    __attribute__((deprecated("Use selabel_lookup instead")))

    ;

extern int matchpathcon_index(const char *path, mode_t mode, char **con);

extern int matchpathcon_filespec_add(ino_t ino, int specind, const char *file);

extern void matchpathcon_filespec_destroy(void);

extern void matchpathcon_filespec_eval(void);

extern void matchpathcon_checkmatches(char *str);

extern int matchmediacon(const char *media, char **con);

extern int selinux_getenforcemode(int *enforce);

extern char *selinux_boolean_sub(const char *boolean_name);

extern int selinux_getpolicytype(char **policytype);

extern const char *selinux_policy_root(void);

extern int selinux_set_policy_root(const char *rootpath);

extern const char *selinux_current_policy_path(void);
extern const char *selinux_binary_policy_path(void);
extern const char *selinux_failsafe_context_path(void);
extern const char *selinux_removable_context_path(void);
extern const char *selinux_default_context_path(void);
extern const char *selinux_user_contexts_path(void);
extern const char *selinux_file_context_path(void);
extern const char *selinux_file_context_homedir_path(void);
extern const char *selinux_file_context_local_path(void);
extern const char *selinux_file_context_subs_path(void);
extern const char *selinux_file_context_subs_dist_path(void);
extern const char *selinux_homedir_context_path(void);
extern const char *selinux_media_context_path(void);
extern const char *selinux_virtual_domain_context_path(void);
extern const char *selinux_virtual_image_context_path(void);
extern const char *selinux_lxc_contexts_path(void);
extern const char *selinux_x_context_path(void);
extern const char *selinux_sepgsql_context_path(void);
extern const char *selinux_openrc_contexts_path(void);
extern const char *selinux_openssh_contexts_path(void);
extern const char *selinux_snapperd_contexts_path(void);
extern const char *selinux_systemd_contexts_path(void);
extern const char *selinux_contexts_path(void);
extern const char *selinux_securetty_types_path(void);
extern const char *selinux_booleans_subs_path(void);

extern const char *selinux_booleans_path(void)

    __attribute__((deprecated))

    ;
extern const char *selinux_customizable_types_path(void);

extern const char *selinux_users_path(void)

    __attribute__((deprecated))

    ;
extern const char *selinux_usersconf_path(void);
extern const char *selinux_translations_path(void);
extern const char *selinux_colors_path(void);
extern const char *selinux_netfilter_context_path(void);
extern const char *selinux_path(void);
extern int selinux_check_access(const char *scon, const char *tcon,
                                const char *tclass, const char *perm,
                                void *auditdata);

extern int selinux_check_passwd_access(access_vector_t requested)

    __attribute__((deprecated("Use selinux_check_access")))

    ;

extern int checkPasswdAccess(access_vector_t requested)

    __attribute__((deprecated("Use selinux_check_access")))

    ;

extern int selinux_check_securetty_context(const char *tty_context);

extern void set_selinuxmnt(const char *mnt);

extern int selinuxfs_exists(void);

extern void fini_selinuxmnt(void);

extern int setexecfilecon(const char *filename, const char *fallback_type);

extern int rpm_execcon(unsigned int verified, const char *filename,
                       char *const argv[], char *const envp[])

    __attribute__((deprecated("Use setexecfilecon and execve")))

    ;

extern int is_context_customizable(const char *scontext);

extern int selinux_trans_to_raw_context(const char *trans, char **rawp);
extern int selinux_raw_to_trans_context(const char *raw, char **transp);

extern int selinux_raw_context_to_color(const char *raw, char **color_str);

extern int getseuserbyname(const char *linuxuser, char **seuser, char **level);

extern int getseuser(const char *username, const char *service, char **r_seuser,
                     char **r_level);

extern int selinux_file_context_cmp(const char *a, const char *b);

extern int selinux_file_context_verify(const char *path, mode_t mode);

extern int selinux_lsetfilecon_default(const char *path);

extern void selinux_reset_config(void);

typedef unsigned int wint_t;

typedef __mbstate_t mbstate_t;

struct __locale_struct {

  struct __locale_data *__locales[13];

  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;

  const char *__names[13];
};

typedef struct __locale_struct *__locale_t;

typedef __locale_t locale_t;

struct tm;

extern wchar_t *wcscpy(wchar_t *__restrict __dest,
                       const wchar_t *__restrict __src)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern wchar_t *wcsncpy(wchar_t *__restrict __dest,
                        const wchar_t *__restrict __src, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern wchar_t *wcscat(wchar_t *__restrict __dest,
                       const wchar_t *__restrict __src)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern wchar_t *wcsncat(wchar_t *__restrict __dest,
                        const wchar_t *__restrict __src, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern int wcscmp(const wchar_t *__s1, const wchar_t *__s2)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

extern int wcsncmp(const wchar_t *__s1, const wchar_t *__s2, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

extern int wcscasecmp(const wchar_t *__s1, const wchar_t *__s2)
    __attribute__((__nothrow__, __leaf__));

extern int wcsncasecmp(const wchar_t *__s1, const wchar_t *__s2, size_t __n)
    __attribute__((__nothrow__, __leaf__));

extern int wcscasecmp_l(const wchar_t *__s1, const wchar_t *__s2,
                        locale_t __loc) __attribute__((__nothrow__, __leaf__));

extern int wcsncasecmp_l(const wchar_t *__s1, const wchar_t *__s2, size_t __n,
                         locale_t __loc) __attribute__((__nothrow__, __leaf__));

extern int wcscoll(const wchar_t *__s1, const wchar_t *__s2)
    __attribute__((__nothrow__, __leaf__));

extern size_t wcsxfrm(wchar_t *__restrict __s1, const wchar_t *__restrict __s2,
                      size_t __n) __attribute__((__nothrow__, __leaf__));

extern int wcscoll_l(const wchar_t *__s1, const wchar_t *__s2, locale_t __loc)
    __attribute__((__nothrow__, __leaf__));

extern size_t wcsxfrm_l(wchar_t *__s1, const wchar_t *__s2, size_t __n,
                        locale_t __loc) __attribute__((__nothrow__, __leaf__));

extern wchar_t *wcsdup(const wchar_t *__s)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__malloc__(__builtin_free, 1)));
extern wchar_t *wcschr(const wchar_t *__wcs, wchar_t __wc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__));
extern wchar_t *wcsrchr(const wchar_t *__wcs, wchar_t __wc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__));

extern wchar_t *wcschrnul(const wchar_t *__s, wchar_t __wc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__));

extern size_t wcscspn(const wchar_t *__wcs, const wchar_t *__reject)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__));

extern size_t wcsspn(const wchar_t *__wcs, const wchar_t *__accept)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__));
extern wchar_t *wcspbrk(const wchar_t *__wcs, const wchar_t *__accept)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__));
extern wchar_t *wcsstr(const wchar_t *__haystack, const wchar_t *__needle)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__));

extern wchar_t *wcstok(wchar_t *__restrict __s,
                       const wchar_t *__restrict __delim,
                       wchar_t **__restrict __ptr)
    __attribute__((__nothrow__, __leaf__));

extern size_t wcslen(const wchar_t *__s) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__));
extern wchar_t *wcswcs(const wchar_t *__haystack, const wchar_t *__needle)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__));

extern size_t wcsnlen(const wchar_t *__s, size_t __maxlen)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__));
extern wchar_t *wmemchr(const wchar_t *__s, wchar_t __c, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__));

extern int wmemcmp(const wchar_t *__s1, const wchar_t *__s2, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__));

extern wchar_t *wmemcpy(wchar_t *__restrict __s1,
                        const wchar_t *__restrict __s2, size_t __n)
    __attribute__((__nothrow__, __leaf__));

extern wchar_t *wmemmove(wchar_t *__s1, const wchar_t *__s2, size_t __n)
    __attribute__((__nothrow__, __leaf__));

extern wchar_t *wmemset(wchar_t *__s, wchar_t __c, size_t __n)
    __attribute__((__nothrow__, __leaf__));

extern wchar_t *wmempcpy(wchar_t *__restrict __s1,
                         const wchar_t *__restrict __s2, size_t __n)
    __attribute__((__nothrow__, __leaf__));

extern wint_t btowc(int __c) __attribute__((__nothrow__, __leaf__));

extern int wctob(wint_t __c) __attribute__((__nothrow__, __leaf__));

extern int mbsinit(const mbstate_t *__ps) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__));

extern size_t mbrtowc(wchar_t *__restrict __pwc, const char *__restrict __s,
                      size_t __n, mbstate_t *__restrict __p)
    __attribute__((__nothrow__, __leaf__));

extern size_t wcrtomb(char *__restrict __s, wchar_t __wc,
                      mbstate_t *__restrict __ps)
    __attribute__((__nothrow__, __leaf__));

extern size_t __mbrlen(const char *__restrict __s, size_t __n,
                       mbstate_t *__restrict __ps)
    __attribute__((__nothrow__, __leaf__));
extern size_t mbrlen(const char *__restrict __s, size_t __n,
                     mbstate_t *__restrict __ps)
    __attribute__((__nothrow__, __leaf__));
extern size_t mbsrtowcs(wchar_t *__restrict __dst,
                        const char **__restrict __src, size_t __len,
                        mbstate_t *__restrict __ps)
    __attribute__((__nothrow__, __leaf__));

extern size_t wcsrtombs(char *__restrict __dst,
                        const wchar_t **__restrict __src, size_t __len,
                        mbstate_t *__restrict __ps)
    __attribute__((__nothrow__, __leaf__));

extern size_t mbsnrtowcs(wchar_t *__restrict __dst,
                         const char **__restrict __src, size_t __nmc,
                         size_t __len, mbstate_t *__restrict __ps)
    __attribute__((__nothrow__, __leaf__));

extern size_t wcsnrtombs(char *__restrict __dst,
                         const wchar_t **__restrict __src, size_t __nwc,
                         size_t __len, mbstate_t *__restrict __ps)
    __attribute__((__nothrow__, __leaf__));

extern int wcwidth(wchar_t __c) __attribute__((__nothrow__, __leaf__));

extern int wcswidth(const wchar_t *__s, size_t __n)
    __attribute__((__nothrow__, __leaf__));

extern double wcstod(const wchar_t *__restrict __nptr,
                     wchar_t **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__));

extern float wcstof(const wchar_t *__restrict __nptr,
                    wchar_t **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__));
extern long double wcstold(const wchar_t *__restrict __nptr,
                           wchar_t **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__));
extern _Float32 wcstof32(const wchar_t *__restrict __nptr,
                         wchar_t **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__));

extern _Float64 wcstof64(const wchar_t *__restrict __nptr,
                         wchar_t **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__));

extern _Float128 wcstof128(const wchar_t *__restrict __nptr,
                           wchar_t **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__));

extern _Float32x wcstof32x(const wchar_t *__restrict __nptr,
                           wchar_t **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__));

extern _Float64x wcstof64x(const wchar_t *__restrict __nptr,
                           wchar_t **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__));
extern long int wcstol(const wchar_t *__restrict __nptr,
                       wchar_t **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__));

extern unsigned long int wcstoul(const wchar_t *__restrict __nptr,
                                 wchar_t **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__));

__extension__ extern long long int wcstoll(const wchar_t *__restrict __nptr,
                                           wchar_t **__restrict __endptr,
                                           int __base)
    __attribute__((__nothrow__, __leaf__));

__extension__ extern unsigned long long int
wcstoull(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr,
         int __base) __attribute__((__nothrow__, __leaf__));

__extension__ extern long long int wcstoq(const wchar_t *__restrict __nptr,
                                          wchar_t **__restrict __endptr,
                                          int __base)
    __attribute__((__nothrow__, __leaf__));

__extension__ extern unsigned long long int
wcstouq(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr,
        int __base) __attribute__((__nothrow__, __leaf__));

extern long int wcstol_l(const wchar_t *__restrict __nptr,
                         wchar_t **__restrict __endptr, int __base,
                         locale_t __loc) __attribute__((__nothrow__, __leaf__));

extern unsigned long int wcstoul_l(const wchar_t *__restrict __nptr,
                                   wchar_t **__restrict __endptr, int __base,
                                   locale_t __loc)
    __attribute__((__nothrow__, __leaf__));

__extension__ extern long long int wcstoll_l(const wchar_t *__restrict __nptr,
                                             wchar_t **__restrict __endptr,
                                             int __base, locale_t __loc)
    __attribute__((__nothrow__, __leaf__));

__extension__ extern unsigned long long int
wcstoull_l(const wchar_t *__restrict __nptr, wchar_t **__restrict __endptr,
           int __base, locale_t __loc) __attribute__((__nothrow__, __leaf__));

extern double wcstod_l(const wchar_t *__restrict __nptr,
                       wchar_t **__restrict __endptr, locale_t __loc)
    __attribute__((__nothrow__, __leaf__));

extern float wcstof_l(const wchar_t *__restrict __nptr,
                      wchar_t **__restrict __endptr, locale_t __loc)
    __attribute__((__nothrow__, __leaf__));

extern long double wcstold_l(const wchar_t *__restrict __nptr,
                             wchar_t **__restrict __endptr, locale_t __loc)
    __attribute__((__nothrow__, __leaf__));
extern _Float32 wcstof32_l(const wchar_t *__restrict __nptr,
                           wchar_t **__restrict __endptr, locale_t __loc)
    __attribute__((__nothrow__, __leaf__));

extern _Float64 wcstof64_l(const wchar_t *__restrict __nptr,
                           wchar_t **__restrict __endptr, locale_t __loc)
    __attribute__((__nothrow__, __leaf__));

extern _Float128 wcstof128_l(const wchar_t *__restrict __nptr,
                             wchar_t **__restrict __endptr, locale_t __loc)
    __attribute__((__nothrow__, __leaf__));

extern _Float32x wcstof32x_l(const wchar_t *__restrict __nptr,
                             wchar_t **__restrict __endptr, locale_t __loc)
    __attribute__((__nothrow__, __leaf__));

extern _Float64x wcstof64x_l(const wchar_t *__restrict __nptr,
                             wchar_t **__restrict __endptr, locale_t __loc)
    __attribute__((__nothrow__, __leaf__));
extern wchar_t *wcpcpy(wchar_t *__restrict __dest,
                       const wchar_t *__restrict __src)
    __attribute__((__nothrow__, __leaf__));

extern wchar_t *wcpncpy(wchar_t *__restrict __dest,
                        const wchar_t *__restrict __src, size_t __n)
    __attribute__((__nothrow__, __leaf__));
extern __FILE *open_wmemstream(wchar_t **__bufloc, size_t *__sizeloc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__malloc__(rpl_fclose, 1)));

extern int fwide(__FILE *__fp, int __mode)
    __attribute__((__nothrow__, __leaf__));

extern int fwprintf(__FILE *__restrict __stream,
                    const wchar_t *__restrict __format, ...);

extern int wprintf(const wchar_t *__restrict __format, ...);

extern int swprintf(wchar_t *__restrict __s, size_t __n,
                    const wchar_t *__restrict __format, ...)
    __attribute__((__nothrow__, __leaf__));

extern int vfwprintf(__FILE *__restrict __s, const wchar_t *__restrict __format,
                     __gnuc_va_list __arg);

extern int vwprintf(const wchar_t *__restrict __format, __gnuc_va_list __arg);

extern int vswprintf(wchar_t *__restrict __s, size_t __n,
                     const wchar_t *__restrict __format, __gnuc_va_list __arg)
    __attribute__((__nothrow__, __leaf__));

extern int fwscanf(__FILE *__restrict __stream,
                   const wchar_t *__restrict __format, ...);

extern int wscanf(const wchar_t *__restrict __format, ...);

extern int swscanf(const wchar_t *__restrict __s,
                   const wchar_t *__restrict __format, ...)
    __attribute__((__nothrow__, __leaf__));
extern int fwscanf(__FILE *__restrict __stream,
                   const wchar_t *__restrict __format,
                   ...) __asm__(""
                                "__isoc99_fwscanf")

    ;
extern int wscanf(const wchar_t *__restrict __format,
                  ...) __asm__(""
                               "__isoc99_wscanf")

    ;
extern int swscanf(const wchar_t *__restrict __s,
                   const wchar_t *__restrict __format,
                   ...) __asm__(""
                                "__isoc99_swscanf")
    __attribute__((__nothrow__, __leaf__))

    ;
extern int vfwscanf(__FILE *__restrict __s, const wchar_t *__restrict __format,
                    __gnuc_va_list __arg);

extern int vwscanf(const wchar_t *__restrict __format, __gnuc_va_list __arg);

extern int vswscanf(const wchar_t *__restrict __s,
                    const wchar_t *__restrict __format, __gnuc_va_list __arg)
    __attribute__((__nothrow__, __leaf__));

extern int vfwscanf(__FILE *__restrict __s, const wchar_t *__restrict __format,
                    __gnuc_va_list __arg) __asm__(""
                                                  "__isoc99_vfwscanf")

    ;
extern int vwscanf(const wchar_t *__restrict __format,
                   __gnuc_va_list __arg) __asm__(""
                                                 "__isoc99_vwscanf")

    ;
extern int vswscanf(const wchar_t *__restrict __s,
                    const wchar_t *__restrict __format,
                    __gnuc_va_list __arg) __asm__(""
                                                  "__isoc99_vswscanf")
    __attribute__((__nothrow__, __leaf__))

    ;
extern wint_t fgetwc(__FILE *__stream);
extern wint_t getwc(__FILE *__stream);

extern wint_t getwchar(void);

extern wint_t fputwc(wchar_t __wc, __FILE *__stream);
extern wint_t putwc(wchar_t __wc, __FILE *__stream);

extern wint_t putwchar(wchar_t __wc);

extern wchar_t *fgetws(wchar_t *__restrict __ws, int __n,
                       __FILE *__restrict __stream);

extern int fputws(const wchar_t *__restrict __ws, __FILE *__restrict __stream);

extern wint_t ungetwc(wint_t __wc, __FILE *__stream);
extern wint_t getwc_unlocked(__FILE *__stream);
extern wint_t getwchar_unlocked(void);

extern wint_t fgetwc_unlocked(__FILE *__stream);

extern wint_t fputwc_unlocked(wchar_t __wc, __FILE *__stream);
extern wint_t putwc_unlocked(wchar_t __wc, __FILE *__stream);
extern wint_t putwchar_unlocked(wchar_t __wc);
extern wchar_t *fgetws_unlocked(wchar_t *__restrict __ws, int __n,
                                __FILE *__restrict __stream);

extern int fputws_unlocked(const wchar_t *__restrict __ws,
                           __FILE *__restrict __stream);

extern size_t wcsftime(wchar_t *__restrict __s, size_t __maxsize,
                       const wchar_t *__restrict __format,
                       const struct tm *__restrict __tp)
    __attribute__((__nothrow__, __leaf__));

extern size_t wcsftime_l(wchar_t *__restrict __s, size_t __maxsize,
                         const wchar_t *__restrict __format,
                         const struct tm *__restrict __tp, locale_t __loc)
    __attribute__((__nothrow__, __leaf__));

extern wchar_t *__wmemcpy_chk(wchar_t *__restrict __s1,
                              const wchar_t *__restrict __s2, size_t __n,
                              size_t __ns1)
    __attribute__((__nothrow__, __leaf__));
extern wchar_t *__wmemcpy_alias(wchar_t *__restrict __s1,
                                const wchar_t *__restrict __s2,
                                size_t __n) __asm__(""
                                                    "wmemcpy")
    __attribute__((__nothrow__, __leaf__))

    ;
extern wchar_t *__wmemcpy_chk_warn(wchar_t *__restrict __s1,
                                   const wchar_t *__restrict __s2, size_t __n,
                                   size_t __ns1) __asm__(""
                                                         "__wmemcpy_chk")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__warning__(
        "wmemcpy called with length bigger than size of destination "
        "buffer")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
wchar_t *__attribute__((__nothrow__, __leaf__))
wmemcpy(wchar_t *__restrict __s1, const wchar_t *__restrict __s2, size_t __n)

{
  return ((((__typeof(__n))0 < (__typeof(__n))-1 ||
            (__builtin_constant_p(__n) && (__n) > 0)) &&
           __builtin_constant_p(
               (((long unsigned int)(__n)) <=
                (__builtin_object_size(__s1, 0)) / (sizeof(wchar_t)))) &&
           (((long unsigned int)(__n)) <=
            (__builtin_object_size(__s1, 0)) / (sizeof(wchar_t))))
              ? __wmemcpy_alias(__s1, __s2, __n)
              : ((((__typeof(__n))0 < (__typeof(__n))-1 ||
                   (__builtin_constant_p(__n) && (__n) > 0)) &&
                  __builtin_constant_p(
                      (((long unsigned int)(__n)) <=
                       (__builtin_object_size(__s1, 0)) / (sizeof(wchar_t)))) &&
                  !(((long unsigned int)(__n)) <=
                    (__builtin_object_size(__s1, 0)) / (sizeof(wchar_t))))
                     ? __wmemcpy_chk_warn(__s1, __s2, __n,
                                          (__builtin_object_size(__s1, 0)) /
                                              (sizeof(wchar_t)))
                     : __wmemcpy_chk(__s1, __s2, __n,
                                     (__builtin_object_size(__s1, 0)) /
                                         (sizeof(wchar_t)))))

      ;
}

extern wchar_t *__wmemmove_chk(wchar_t *__s1, const wchar_t *__s2, size_t __n,
                               size_t __ns1)
    __attribute__((__nothrow__, __leaf__));
extern wchar_t *__wmemmove_alias(wchar_t *__s1, const wchar_t *__s2,
                                 size_t __n) __asm__(""
                                                     "wmemmove")
    __attribute__((__nothrow__, __leaf__))

    ;
extern wchar_t *__wmemmove_chk_warn(wchar_t *__s1, const wchar_t *__s2,
                                    size_t __n,
                                    size_t __ns1) __asm__(""
                                                          "__wmemmove_chk")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__warning__(
        "wmemmove called with length bigger than size of destination "
        "buffer")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
wchar_t *__attribute__((__nothrow__, __leaf__))
wmemmove(wchar_t *__s1, const wchar_t *__s2, size_t __n) {
  return ((((__typeof(__n))0 < (__typeof(__n))-1 ||
            (__builtin_constant_p(__n) && (__n) > 0)) &&
           __builtin_constant_p(
               (((long unsigned int)(__n)) <=
                (__builtin_object_size(__s1, 0)) / (sizeof(wchar_t)))) &&
           (((long unsigned int)(__n)) <=
            (__builtin_object_size(__s1, 0)) / (sizeof(wchar_t))))
              ? __wmemmove_alias(__s1, __s2, __n)
              : ((((__typeof(__n))0 < (__typeof(__n))-1 ||
                   (__builtin_constant_p(__n) && (__n) > 0)) &&
                  __builtin_constant_p(
                      (((long unsigned int)(__n)) <=
                       (__builtin_object_size(__s1, 0)) / (sizeof(wchar_t)))) &&
                  !(((long unsigned int)(__n)) <=
                    (__builtin_object_size(__s1, 0)) / (sizeof(wchar_t))))
                     ? __wmemmove_chk_warn(__s1, __s2, __n,
                                           (__builtin_object_size(__s1, 0)) /
                                               (sizeof(wchar_t)))
                     : __wmemmove_chk(__s1, __s2, __n,
                                      (__builtin_object_size(__s1, 0)) /
                                          (sizeof(wchar_t)))))

      ;
}

extern wchar_t *__wmempcpy_chk(wchar_t *__restrict __s1,
                               const wchar_t *__restrict __s2, size_t __n,
                               size_t __ns1)
    __attribute__((__nothrow__, __leaf__));
extern wchar_t *__wmempcpy_alias(wchar_t *__restrict __s1,
                                 const wchar_t *__restrict __s2,
                                 size_t __n) __asm__(""
                                                     "wmempcpy")
    __attribute__((__nothrow__, __leaf__))

    ;
extern wchar_t *__wmempcpy_chk_warn(wchar_t *__restrict __s1,
                                    const wchar_t *__restrict __s2, size_t __n,
                                    size_t __ns1) __asm__(""
                                                          "__wmempcpy_chk")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__warning__(
        "wmempcpy called with length bigger than size of destination "
        "buffer")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
wchar_t *__attribute__((__nothrow__, __leaf__))
wmempcpy(wchar_t *__restrict __s1, const wchar_t *__restrict __s2, size_t __n)

{
  return ((((__typeof(__n))0 < (__typeof(__n))-1 ||
            (__builtin_constant_p(__n) && (__n) > 0)) &&
           __builtin_constant_p(
               (((long unsigned int)(__n)) <=
                (__builtin_object_size(__s1, 0)) / (sizeof(wchar_t)))) &&
           (((long unsigned int)(__n)) <=
            (__builtin_object_size(__s1, 0)) / (sizeof(wchar_t))))
              ? __wmempcpy_alias(__s1, __s2, __n)
              : ((((__typeof(__n))0 < (__typeof(__n))-1 ||
                   (__builtin_constant_p(__n) && (__n) > 0)) &&
                  __builtin_constant_p(
                      (((long unsigned int)(__n)) <=
                       (__builtin_object_size(__s1, 0)) / (sizeof(wchar_t)))) &&
                  !(((long unsigned int)(__n)) <=
                    (__builtin_object_size(__s1, 0)) / (sizeof(wchar_t))))
                     ? __wmempcpy_chk_warn(__s1, __s2, __n,
                                           (__builtin_object_size(__s1, 0)) /
                                               (sizeof(wchar_t)))
                     : __wmempcpy_chk(__s1, __s2, __n,
                                      (__builtin_object_size(__s1, 0)) /
                                          (sizeof(wchar_t)))))

      ;
}

extern wchar_t *__wmemset_chk(wchar_t *__s, wchar_t __c, size_t __n,
                              size_t __ns)
    __attribute__((__nothrow__, __leaf__));
extern wchar_t *__wmemset_alias(wchar_t *__s, wchar_t __c,
                                size_t __n) __asm__(""
                                                    "wmemset")
    __attribute__((__nothrow__, __leaf__));
extern wchar_t *__wmemset_chk_warn(wchar_t *__s, wchar_t __c, size_t __n,
                                   size_t __ns) __asm__(""
                                                        "__wmemset_chk")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__warning__(
        "wmemset called with length bigger than size of destination "
        "buffer")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
wchar_t *__attribute__((__nothrow__, __leaf__))
wmemset(wchar_t *__s, wchar_t __c, size_t __n) {
  return ((((__typeof(__n))0 < (__typeof(__n))-1 ||
            (__builtin_constant_p(__n) && (__n) > 0)) &&
           __builtin_constant_p(
               (((long unsigned int)(__n)) <=
                (__builtin_object_size(__s, 0)) / (sizeof(wchar_t)))) &&
           (((long unsigned int)(__n)) <=
            (__builtin_object_size(__s, 0)) / (sizeof(wchar_t))))
              ? __wmemset_alias(__s, __c, __n)
              : ((((__typeof(__n))0 < (__typeof(__n))-1 ||
                   (__builtin_constant_p(__n) && (__n) > 0)) &&
                  __builtin_constant_p(
                      (((long unsigned int)(__n)) <=
                       (__builtin_object_size(__s, 0)) / (sizeof(wchar_t)))) &&
                  !(((long unsigned int)(__n)) <=
                    (__builtin_object_size(__s, 0)) / (sizeof(wchar_t))))
                     ? __wmemset_chk_warn(__s, __c, __n,
                                          (__builtin_object_size(__s, 0)) /
                                              (sizeof(wchar_t)))
                     : __wmemset_chk(__s, __c, __n,
                                     (__builtin_object_size(__s, 0)) /
                                         (sizeof(wchar_t)))))

      ;
}

extern wchar_t *__wcscpy_chk(wchar_t *__restrict __dest,
                             const wchar_t *__restrict __src, size_t __n)
    __attribute__((__nothrow__, __leaf__));
extern wchar_t *
__wcscpy_alias(wchar_t *__restrict __dest,
               const wchar_t *__restrict __src) __asm__(""
                                                        "wcscpy")
    __attribute__((__nothrow__, __leaf__))

    ;

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
wchar_t *__attribute__((__nothrow__, __leaf__))
wcscpy(wchar_t *__restrict __dest, const wchar_t *__restrict __src) {
  size_t sz = __builtin_object_size(__dest, 2 > 1);
  if (sz != (size_t)-1)
    return __wcscpy_chk(__dest, __src, sz / sizeof(wchar_t));
  return __wcscpy_alias(__dest, __src);
}

extern wchar_t *__wcpcpy_chk(wchar_t *__restrict __dest,
                             const wchar_t *__restrict __src, size_t __destlen)
    __attribute__((__nothrow__, __leaf__));
extern wchar_t *
__wcpcpy_alias(wchar_t *__restrict __dest,
               const wchar_t *__restrict __src) __asm__(""
                                                        "wcpcpy")
    __attribute__((__nothrow__, __leaf__))

    ;

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
wchar_t *__attribute__((__nothrow__, __leaf__))
wcpcpy(wchar_t *__restrict __dest, const wchar_t *__restrict __src) {
  size_t sz = __builtin_object_size(__dest, 2 > 1);
  if (sz != (size_t)-1)
    return __wcpcpy_chk(__dest, __src, sz / sizeof(wchar_t));
  return __wcpcpy_alias(__dest, __src);
}

extern wchar_t *__wcsncpy_chk(wchar_t *__restrict __dest,
                              const wchar_t *__restrict __src, size_t __n,
                              size_t __destlen)
    __attribute__((__nothrow__, __leaf__));
extern wchar_t *__wcsncpy_alias(wchar_t *__restrict __dest,
                                const wchar_t *__restrict __src,
                                size_t __n) __asm__(""
                                                    "wcsncpy")
    __attribute__((__nothrow__, __leaf__))

    ;
extern wchar_t *__wcsncpy_chk_warn(wchar_t *__restrict __dest,
                                   const wchar_t *__restrict __src, size_t __n,
                                   size_t __destlen) __asm__(""
                                                             "__wcsncpy_chk")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__warning__(
        "wcsncpy called with length bigger than size of destination "
        "buffer")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
wchar_t *__attribute__((__nothrow__, __leaf__))
wcsncpy(wchar_t *__restrict __dest, const wchar_t *__restrict __src, size_t __n)

{
  return (
      (((__typeof(__n))0 < (__typeof(__n))-1 ||
        (__builtin_constant_p(__n) && (__n) > 0)) &&
       __builtin_constant_p(
           (((long unsigned int)(__n)) <=
            (__builtin_object_size(__dest, 2 > 1)) / (sizeof(wchar_t)))) &&
       (((long unsigned int)(__n)) <=
        (__builtin_object_size(__dest, 2 > 1)) / (sizeof(wchar_t))))
          ? __wcsncpy_alias(__dest, __src, __n)
          : ((((__typeof(__n))0 < (__typeof(__n))-1 ||
               (__builtin_constant_p(__n) && (__n) > 0)) &&
              __builtin_constant_p((((long unsigned int)(__n)) <=
                                    (__builtin_object_size(__dest, 2 > 1)) /
                                        (sizeof(wchar_t)))) &&
              !(((long unsigned int)(__n)) <=
                (__builtin_object_size(__dest, 2 > 1)) / (sizeof(wchar_t))))
                 ? __wcsncpy_chk_warn(__dest, __src, __n,
                                      (__builtin_object_size(__dest, 2 > 1)) /
                                          (sizeof(wchar_t)))
                 : __wcsncpy_chk(__dest, __src, __n,
                                 (__builtin_object_size(__dest, 2 > 1)) /
                                     (sizeof(wchar_t)))))

      ;
}

extern wchar_t *__wcpncpy_chk(wchar_t *__restrict __dest,
                              const wchar_t *__restrict __src, size_t __n,
                              size_t __destlen)
    __attribute__((__nothrow__, __leaf__));
extern wchar_t *__wcpncpy_alias(wchar_t *__restrict __dest,
                                const wchar_t *__restrict __src,
                                size_t __n) __asm__(""
                                                    "wcpncpy")
    __attribute__((__nothrow__, __leaf__))

    ;
extern wchar_t *__wcpncpy_chk_warn(wchar_t *__restrict __dest,
                                   const wchar_t *__restrict __src, size_t __n,
                                   size_t __destlen) __asm__(""
                                                             "__wcpncpy_chk")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__warning__(
        "wcpncpy called with length bigger than size of destination "
        "buffer")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
wchar_t *__attribute__((__nothrow__, __leaf__))
wcpncpy(wchar_t *__restrict __dest, const wchar_t *__restrict __src, size_t __n)

{
  return (
      (((__typeof(__n))0 < (__typeof(__n))-1 ||
        (__builtin_constant_p(__n) && (__n) > 0)) &&
       __builtin_constant_p(
           (((long unsigned int)(__n)) <=
            (__builtin_object_size(__dest, 2 > 1)) / (sizeof(wchar_t)))) &&
       (((long unsigned int)(__n)) <=
        (__builtin_object_size(__dest, 2 > 1)) / (sizeof(wchar_t))))
          ? __wcpncpy_alias(__dest, __src, __n)
          : ((((__typeof(__n))0 < (__typeof(__n))-1 ||
               (__builtin_constant_p(__n) && (__n) > 0)) &&
              __builtin_constant_p((((long unsigned int)(__n)) <=
                                    (__builtin_object_size(__dest, 2 > 1)) /
                                        (sizeof(wchar_t)))) &&
              !(((long unsigned int)(__n)) <=
                (__builtin_object_size(__dest, 2 > 1)) / (sizeof(wchar_t))))
                 ? __wcpncpy_chk_warn(__dest, __src, __n,
                                      (__builtin_object_size(__dest, 2 > 1)) /
                                          (sizeof(wchar_t)))
                 : __wcpncpy_chk(__dest, __src, __n,
                                 (__builtin_object_size(__dest, 2 > 1)) /
                                     (sizeof(wchar_t)))))

      ;
}

extern wchar_t *__wcscat_chk(wchar_t *__restrict __dest,
                             const wchar_t *__restrict __src, size_t __destlen)
    __attribute__((__nothrow__, __leaf__));
extern wchar_t *
__wcscat_alias(wchar_t *__restrict __dest,
               const wchar_t *__restrict __src) __asm__(""
                                                        "wcscat")
    __attribute__((__nothrow__, __leaf__))

    ;

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
wchar_t *__attribute__((__nothrow__, __leaf__))
wcscat(wchar_t *__restrict __dest, const wchar_t *__restrict __src) {
  size_t sz = __builtin_object_size(__dest, 2 > 1);
  if (sz != (size_t)-1)
    return __wcscat_chk(__dest, __src, sz / sizeof(wchar_t));
  return __wcscat_alias(__dest, __src);
}

extern wchar_t *__wcsncat_chk(wchar_t *__restrict __dest,
                              const wchar_t *__restrict __src, size_t __n,
                              size_t __destlen)
    __attribute__((__nothrow__, __leaf__));
extern wchar_t *__wcsncat_alias(wchar_t *__restrict __dest,
                                const wchar_t *__restrict __src,
                                size_t __n) __asm__(""
                                                    "wcsncat")
    __attribute__((__nothrow__, __leaf__))

    ;

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
wchar_t *__attribute__((__nothrow__, __leaf__))
wcsncat(wchar_t *__restrict __dest, const wchar_t *__restrict __src, size_t __n)

{
  size_t sz = __builtin_object_size(__dest, 2 > 1);
  if (sz != (size_t)-1)
    return __wcsncat_chk(__dest, __src, __n, sz / sizeof(wchar_t));
  return __wcsncat_alias(__dest, __src, __n);
}

extern int __swprintf_chk(wchar_t *__restrict __s, size_t __n, int __flag,
                          size_t __s_len, const wchar_t *__restrict __format,
                          ...) __attribute__((__nothrow__, __leaf__));

extern int __swprintf_alias(wchar_t *__restrict __s, size_t __n,
                            const wchar_t *__restrict __fmt,
                            ...) __asm__(""
                                         "swprintf")
    __attribute__((__nothrow__, __leaf__))

    ;

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__))
__attribute__((__artificial__)) int __attribute__((__nothrow__, __leaf__))
swprintf(wchar_t *__restrict __s, size_t __n, const wchar_t *__restrict __fmt,
         ...)

{
  size_t sz = __builtin_object_size(__s, 2 > 1);
  if (sz != (size_t)-1 || 2 > 1)
    return __swprintf_chk(__s, __n, 2 - 1, sz / sizeof(wchar_t), __fmt,
                          __builtin_va_arg_pack());
  return __swprintf_alias(__s, __n, __fmt, __builtin_va_arg_pack());
}
extern int __vswprintf_chk(wchar_t *__restrict __s, size_t __n, int __flag,
                           size_t __s_len, const wchar_t *__restrict __format,
                           __gnuc_va_list __arg)
    __attribute__((__nothrow__, __leaf__));

extern int __vswprintf_alias(wchar_t *__restrict __s, size_t __n,
                             const wchar_t *__restrict __fmt,
                             __gnuc_va_list __ap) __asm__(""
                                                          "vswprintf")
    __attribute__((__nothrow__, __leaf__))

    ;

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__))
__attribute__((__artificial__)) int __attribute__((__nothrow__, __leaf__))
vswprintf(wchar_t *__restrict __s, size_t __n, const wchar_t *__restrict __fmt,
          __gnuc_va_list __ap)

{
  size_t sz = __builtin_object_size(__s, 2 > 1);
  if (sz != (size_t)-1 || 2 > 1)
    return __vswprintf_chk(__s, __n, 2 - 1, sz / sizeof(wchar_t), __fmt, __ap);
  return __vswprintf_alias(__s, __n, __fmt, __ap);
}

extern int __fwprintf_chk(__FILE *__restrict __stream, int __flag,
                          const wchar_t *__restrict __format, ...);
extern int __wprintf_chk(int __flag, const wchar_t *__restrict __format, ...);
extern int __vfwprintf_chk(__FILE *__restrict __stream, int __flag,
                           const wchar_t *__restrict __format,
                           __gnuc_va_list __ap);
extern int __vwprintf_chk(int __flag, const wchar_t *__restrict __format,
                          __gnuc_va_list __ap);

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
wprintf(const wchar_t *__restrict __fmt, ...) {
  return __wprintf_chk(2 - 1, __fmt, __builtin_va_arg_pack());
}

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
fwprintf(__FILE *__restrict __stream, const wchar_t *__restrict __fmt, ...) {
  return __fwprintf_chk(__stream, 2 - 1, __fmt, __builtin_va_arg_pack());
}

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
vwprintf(const wchar_t *__restrict __fmt, __gnuc_va_list __ap) {
  return __vwprintf_chk(2 - 1, __fmt, __ap);
}

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
vfwprintf(__FILE *__restrict __stream, const wchar_t *__restrict __fmt,
          __gnuc_va_list __ap) {
  return __vfwprintf_chk(__stream, 2 - 1, __fmt, __ap);
}

extern wchar_t *__fgetws_chk(wchar_t *__restrict __s, size_t __size, int __n,
                             __FILE *__restrict __stream)
    __attribute__((__warn_unused_result__));
extern wchar_t *__fgetws_alias(wchar_t *__restrict __s, int __n,
                               __FILE *__restrict __stream) __asm__(""
                                                                    "fgetws")

    __attribute__((__warn_unused_result__));
extern wchar_t *
__fgetws_chk_warn(wchar_t *__restrict __s, size_t __size, int __n,
                  __FILE *__restrict __stream) __asm__(""
                                                       "__fgetws_chk")

    __attribute__((__warn_unused_result__))
    __attribute__((__warning__("fgetws called with bigger size than length "
                               "of destination buffer")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
__attribute__((__warn_unused_result__)) wchar_t *
fgetws(wchar_t *__restrict __s, int __n, __FILE *__restrict __stream) {
  size_t sz = __builtin_object_size(__s, 2 > 1);
  if ((((__typeof(__n))0 < (__typeof(__n))-1 ||
        (__builtin_constant_p(__n) && (__n) > 0)) &&
       __builtin_constant_p(
           (((long unsigned int)(__n)) <= (sz) / (sizeof(wchar_t)))) &&
       (((long unsigned int)(__n)) <= (sz) / (sizeof(wchar_t)))))
    return __fgetws_alias(__s, __n, __stream);
  if ((((__typeof(__n))0 < (__typeof(__n))-1 ||
        (__builtin_constant_p(__n) && (__n) > 0)) &&
       __builtin_constant_p(
           (((long unsigned int)(__n)) <= (sz) / (sizeof(wchar_t)))) &&
       !(((long unsigned int)(__n)) <= (sz) / (sizeof(wchar_t)))))
    return __fgetws_chk_warn(__s, sz / sizeof(wchar_t), __n, __stream);
  return __fgetws_chk(__s, sz / sizeof(wchar_t), __n, __stream);
}

extern wchar_t *__fgetws_unlocked_chk(wchar_t *__restrict __s, size_t __size,
                                      int __n, __FILE *__restrict __stream)
    __attribute__((__warn_unused_result__));
extern wchar_t *
__fgetws_unlocked_alias(wchar_t *__restrict __s, int __n,
                        __FILE *__restrict __stream) __asm__(""
                                                             "fgetws_unlocked")

    __attribute__((__warn_unused_result__));
extern wchar_t *__fgetws_unlocked_chk_warn(
    wchar_t *__restrict __s, size_t __size, int __n,
    __FILE *__restrict __stream) __asm__(""
                                         "__fgetws_unlocked_chk")

    __attribute__((__warn_unused_result__)) __attribute__((
        __warning__("fgetws_unlocked called with bigger size than length "
                    "of destination buffer")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
__attribute__((__warn_unused_result__)) wchar_t *
fgetws_unlocked(wchar_t *__restrict __s, int __n, __FILE *__restrict __stream) {
  size_t sz = __builtin_object_size(__s, 2 > 1);
  if ((((__typeof(__n))0 < (__typeof(__n))-1 ||
        (__builtin_constant_p(__n) && (__n) > 0)) &&
       __builtin_constant_p(
           (((long unsigned int)(__n)) <= (sz) / (sizeof(wchar_t)))) &&
       (((long unsigned int)(__n)) <= (sz) / (sizeof(wchar_t)))))
    return __fgetws_unlocked_alias(__s, __n, __stream);
  if ((((__typeof(__n))0 < (__typeof(__n))-1 ||
        (__builtin_constant_p(__n) && (__n) > 0)) &&
       __builtin_constant_p(
           (((long unsigned int)(__n)) <= (sz) / (sizeof(wchar_t)))) &&
       !(((long unsigned int)(__n)) <= (sz) / (sizeof(wchar_t)))))
    return __fgetws_unlocked_chk_warn(__s, sz / sizeof(wchar_t), __n, __stream);
  return __fgetws_unlocked_chk(__s, sz / sizeof(wchar_t), __n, __stream);
}

extern size_t __wcrtomb_chk(char *__restrict __s, wchar_t __wchar,
                            mbstate_t *__restrict __p, size_t __buflen)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__));
extern size_t __wcrtomb_alias(char *__restrict __s, wchar_t __wchar,
                              mbstate_t *__restrict __ps) __asm__(""
                                                                  "wcrtomb")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__warn_unused_result__));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
__attribute__((__warn_unused_result__)) size_t
    __attribute__((__nothrow__, __leaf__))
    wcrtomb(char *__restrict __s, wchar_t __wchar, mbstate_t *__restrict __ps)

{

  if (__builtin_object_size(__s, 2 > 1) != (size_t)-1 &&
      16 > __builtin_object_size(__s, 2 > 1))
    return __wcrtomb_chk(__s, __wchar, __ps, __builtin_object_size(__s, 2 > 1));
  return __wcrtomb_alias(__s, __wchar, __ps);
}

extern size_t __mbsrtowcs_chk(wchar_t *__restrict __dst,
                              const char **__restrict __src, size_t __len,
                              mbstate_t *__restrict __ps, size_t __dstlen)
    __attribute__((__nothrow__, __leaf__));
extern size_t __mbsrtowcs_alias(wchar_t *__restrict __dst,
                                const char **__restrict __src, size_t __len,
                                mbstate_t *__restrict __ps) __asm__(""
                                                                    "mbsrtowcs")
    __attribute__((__nothrow__, __leaf__))

    ;
extern size_t __mbsrtowcs_chk_warn(
    wchar_t *__restrict __dst, const char **__restrict __src, size_t __len,
    mbstate_t *__restrict __ps,
    size_t __dstlen) __asm__(""
                             "__mbsrtowcs_chk") __attribute__((__nothrow__,
                                                               __leaf__))

__attribute__((__warning__("mbsrtowcs called with dst buffer smaller than len "
                           "* sizeof (wchar_t)")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) size_t
    __attribute__((__nothrow__, __leaf__))
    mbsrtowcs(wchar_t *__restrict __dst, const char **__restrict __src,
              size_t __len, mbstate_t *__restrict __ps)

{
  return (
      (((__typeof(__len))0 < (__typeof(__len))-1 ||
        (__builtin_constant_p(__len) && (__len) > 0)) &&
       __builtin_constant_p(
           (((long unsigned int)(__len)) <=
            (__builtin_object_size(__dst, 2 > 1)) / (sizeof(wchar_t)))) &&
       (((long unsigned int)(__len)) <=
        (__builtin_object_size(__dst, 2 > 1)) / (sizeof(wchar_t))))
          ? __mbsrtowcs_alias(__dst, __src, __len, __ps)
          : ((((__typeof(__len))0 < (__typeof(__len))-1 ||
               (__builtin_constant_p(__len) && (__len) > 0)) &&
              __builtin_constant_p((((long unsigned int)(__len)) <=
                                    (__builtin_object_size(__dst, 2 > 1)) /
                                        (sizeof(wchar_t)))) &&
              !(((long unsigned int)(__len)) <=
                (__builtin_object_size(__dst, 2 > 1)) / (sizeof(wchar_t))))
                 ? __mbsrtowcs_chk_warn(__dst, __src, __len, __ps,
                                        (__builtin_object_size(__dst, 2 > 1)) /
                                            (sizeof(wchar_t)))
                 : __mbsrtowcs_chk(__dst, __src, __len, __ps,
                                   (__builtin_object_size(__dst, 2 > 1)) /
                                       (sizeof(wchar_t)))))

      ;
}

extern size_t __wcsrtombs_chk(char *__restrict __dst,
                              const wchar_t **__restrict __src, size_t __len,
                              mbstate_t *__restrict __ps, size_t __dstlen)
    __attribute__((__nothrow__, __leaf__));
extern size_t __wcsrtombs_alias(char *__restrict __dst,
                                const wchar_t **__restrict __src, size_t __len,
                                mbstate_t *__restrict __ps) __asm__(""
                                                                    "wcsrtombs")
    __attribute__((__nothrow__, __leaf__))

    ;
extern size_t __wcsrtombs_chk_warn(char *__restrict __dst,
                                   const wchar_t **__restrict __src,
                                   size_t __len, mbstate_t *__restrict __ps,
                                   size_t __dstlen) __asm__(""
                                                            "__wcsrtombs_chk")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((
        __warning__("wcsrtombs called with dst buffer smaller than len")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) size_t
    __attribute__((__nothrow__, __leaf__))
    wcsrtombs(char *__restrict __dst, const wchar_t **__restrict __src,
              size_t __len, mbstate_t *__restrict __ps)

{
  return ((((__typeof(__len))0 < (__typeof(__len))-1 ||
            (__builtin_constant_p(__len) && (__len) > 0)) &&
           __builtin_constant_p(
               (((long unsigned int)(__len)) <=
                (__builtin_object_size(__dst, 2 > 1)) / (sizeof(char)))) &&
           (((long unsigned int)(__len)) <=
            (__builtin_object_size(__dst, 2 > 1)) / (sizeof(char))))
              ? __wcsrtombs_alias(__dst, __src, __len, __ps)
              : ((((__typeof(__len))0 < (__typeof(__len))-1 ||
                   (__builtin_constant_p(__len) && (__len) > 0)) &&
                  __builtin_constant_p((((long unsigned int)(__len)) <=
                                        (__builtin_object_size(__dst, 2 > 1)) /
                                            (sizeof(char)))) &&
                  !(((long unsigned int)(__len)) <=
                    (__builtin_object_size(__dst, 2 > 1)) / (sizeof(char))))
                     ? __wcsrtombs_chk_warn(__dst, __src, __len, __ps,
                                            __builtin_object_size(__dst, 2 > 1))
                     : __wcsrtombs_chk(__dst, __src, __len, __ps,
                                       __builtin_object_size(__dst, 2 > 1))))

      ;
}

extern size_t __mbsnrtowcs_chk(wchar_t *__restrict __dst,
                               const char **__restrict __src, size_t __nmc,
                               size_t __len, mbstate_t *__restrict __ps,
                               size_t __dstlen)
    __attribute__((__nothrow__, __leaf__));
extern size_t
__mbsnrtowcs_alias(wchar_t *__restrict __dst, const char **__restrict __src,
                   size_t __nmc, size_t __len,
                   mbstate_t *__restrict __ps) __asm__(""
                                                       "mbsnrtowcs")
    __attribute__((__nothrow__, __leaf__))

    ;
extern size_t __mbsnrtowcs_chk_warn(
    wchar_t *__restrict __dst, const char **__restrict __src, size_t __nmc,
    size_t __len, mbstate_t *__restrict __ps,
    size_t __dstlen) __asm__(""
                             "__mbsnrtowcs_chk") __attribute__((__nothrow__,
                                                                __leaf__))

__attribute__((__warning__("mbsnrtowcs called with dst buffer smaller than len "
                           "* sizeof (wchar_t)")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) size_t
    __attribute__((__nothrow__, __leaf__))
    mbsnrtowcs(wchar_t *__restrict __dst, const char **__restrict __src,
               size_t __nmc, size_t __len, mbstate_t *__restrict __ps)

{
  return (
      (((__typeof(__len))0 < (__typeof(__len))-1 ||
        (__builtin_constant_p(__len) && (__len) > 0)) &&
       __builtin_constant_p(
           (((long unsigned int)(__len)) <=
            (__builtin_object_size(__dst, 2 > 1)) / (sizeof(wchar_t)))) &&
       (((long unsigned int)(__len)) <=
        (__builtin_object_size(__dst, 2 > 1)) / (sizeof(wchar_t))))
          ? __mbsnrtowcs_alias(__dst, __src, __nmc, __len, __ps)
          : ((((__typeof(__len))0 < (__typeof(__len))-1 ||
               (__builtin_constant_p(__len) && (__len) > 0)) &&
              __builtin_constant_p((((long unsigned int)(__len)) <=
                                    (__builtin_object_size(__dst, 2 > 1)) /
                                        (sizeof(wchar_t)))) &&
              !(((long unsigned int)(__len)) <=
                (__builtin_object_size(__dst, 2 > 1)) / (sizeof(wchar_t))))
                 ? __mbsnrtowcs_chk_warn(__dst, __src, __nmc, __len, __ps,
                                         (__builtin_object_size(__dst, 2 > 1)) /
                                             (sizeof(wchar_t)))
                 : __mbsnrtowcs_chk(__dst, __src, __nmc, __len, __ps,
                                    (__builtin_object_size(__dst, 2 > 1)) /
                                        (sizeof(wchar_t)))))

      ;
}

extern size_t __wcsnrtombs_chk(char *__restrict __dst,
                               const wchar_t **__restrict __src, size_t __nwc,
                               size_t __len, mbstate_t *__restrict __ps,
                               size_t __dstlen)
    __attribute__((__nothrow__, __leaf__));
extern size_t
__wcsnrtombs_alias(char *__restrict __dst, const wchar_t **__restrict __src,
                   size_t __nwc, size_t __len,
                   mbstate_t *__restrict __ps) __asm__(""
                                                       "wcsnrtombs")
    __attribute__((__nothrow__, __leaf__))

    ;
extern size_t
__wcsnrtombs_chk_warn(char *__restrict __dst, const wchar_t **__restrict __src,
                      size_t __nwc, size_t __len, mbstate_t *__restrict __ps,
                      size_t __dstlen) __asm__(""
                                               "__wcsnrtombs_chk")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((
        __warning__("wcsnrtombs called with dst buffer smaller than len")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) size_t
    __attribute__((__nothrow__, __leaf__))
    wcsnrtombs(char *__restrict __dst, const wchar_t **__restrict __src,
               size_t __nwc, size_t __len, mbstate_t *__restrict __ps)

{
  return (
      (((__typeof(__len))0 < (__typeof(__len))-1 ||
        (__builtin_constant_p(__len) && (__len) > 0)) &&
       __builtin_constant_p(
           (((long unsigned int)(__len)) <=
            (__builtin_object_size(__dst, 2 > 1)) / (sizeof(char)))) &&
       (((long unsigned int)(__len)) <=
        (__builtin_object_size(__dst, 2 > 1)) / (sizeof(char))))
          ? __wcsnrtombs_alias(__dst, __src, __nwc, __len, __ps)
          : ((((__typeof(__len))0 < (__typeof(__len))-1 ||
               (__builtin_constant_p(__len) && (__len) > 0)) &&
              __builtin_constant_p(
                  (((long unsigned int)(__len)) <=
                   (__builtin_object_size(__dst, 2 > 1)) / (sizeof(char)))) &&
              !(((long unsigned int)(__len)) <=
                (__builtin_object_size(__dst, 2 > 1)) / (sizeof(char))))
                 ? __wcsnrtombs_chk_warn(__dst, __src, __nwc, __len, __ps,
                                         __builtin_object_size(__dst, 2 > 1))
                 : __wcsnrtombs_chk(__dst, __src, __nwc, __len, __ps,
                                    __builtin_object_size(__dst, 2 > 1))))

      ;
}

extern void free(void *);
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern size_t rpl_mbrtowc(wchar_t *__restrict__ pwc, const char *__restrict__ s,
                          size_t n, mbstate_t *__restrict__ ps)

    ;
extern int _gl_cxxalias_dummy

    ;
extern int _gl_cxxalias_dummy;
extern size_t rpl_mbrlen(const char *__restrict__ s, size_t n,
                         mbstate_t *__restrict__ ps);
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

    ;

extern int _gl_cxxalias_dummy;
extern wchar_t *wcsdup(const wchar_t *s) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1)))

;
extern wchar_t *wcsdup(const wchar_t *s) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1)))

;

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;

typedef void *nl_catd;

typedef int nl_item;

extern nl_catd catopen(const char *__cat_name, int __flag)
    __attribute__((__nonnull__(1)));

extern char *catgets(nl_catd __catalog, int __set, int __number,
                     const char *__string)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern int catclose(nl_catd __catalog) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

enum {

  ABDAY_1 = (((2) << 16) | (0)),

  ABDAY_2,

  ABDAY_3,

  ABDAY_4,

  ABDAY_5,

  ABDAY_6,

  ABDAY_7,

  DAY_1,

  DAY_2,

  DAY_3,

  DAY_4,

  DAY_5,

  DAY_6,

  DAY_7,

  ABMON_1,

  ABMON_2,

  ABMON_3,

  ABMON_4,

  ABMON_5,

  ABMON_6,

  ABMON_7,

  ABMON_8,

  ABMON_9,

  ABMON_10,

  ABMON_11,

  ABMON_12,

  MON_1,

  MON_2,

  MON_3,

  MON_4,

  MON_5,

  MON_6,

  MON_7,

  MON_8,

  MON_9,

  MON_10,

  MON_11,

  MON_12,

  AM_STR,

  PM_STR,

  D_T_FMT,

  D_FMT,

  T_FMT,

  T_FMT_AMPM,

  ERA,

  __ERA_YEAR,

  ERA_D_FMT,

  ALT_DIGITS,

  ERA_D_T_FMT,

  ERA_T_FMT,

  _NL_TIME_ERA_NUM_ENTRIES,
  _NL_TIME_ERA_ENTRIES,

  _NL_WABDAY_1,
  _NL_WABDAY_2,
  _NL_WABDAY_3,
  _NL_WABDAY_4,
  _NL_WABDAY_5,
  _NL_WABDAY_6,
  _NL_WABDAY_7,

  _NL_WDAY_1,
  _NL_WDAY_2,
  _NL_WDAY_3,
  _NL_WDAY_4,
  _NL_WDAY_5,
  _NL_WDAY_6,
  _NL_WDAY_7,

  _NL_WABMON_1,
  _NL_WABMON_2,
  _NL_WABMON_3,
  _NL_WABMON_4,
  _NL_WABMON_5,
  _NL_WABMON_6,
  _NL_WABMON_7,
  _NL_WABMON_8,
  _NL_WABMON_9,
  _NL_WABMON_10,
  _NL_WABMON_11,
  _NL_WABMON_12,

  _NL_WMON_1,
  _NL_WMON_2,
  _NL_WMON_3,
  _NL_WMON_4,
  _NL_WMON_5,
  _NL_WMON_6,
  _NL_WMON_7,
  _NL_WMON_8,
  _NL_WMON_9,
  _NL_WMON_10,
  _NL_WMON_11,
  _NL_WMON_12,

  _NL_WAM_STR,
  _NL_WPM_STR,

  _NL_WD_T_FMT,
  _NL_WD_FMT,
  _NL_WT_FMT,
  _NL_WT_FMT_AMPM,

  _NL_WERA_YEAR,
  _NL_WERA_D_FMT,
  _NL_WALT_DIGITS,
  _NL_WERA_D_T_FMT,
  _NL_WERA_T_FMT,

  _NL_TIME_WEEK_NDAYS,
  _NL_TIME_WEEK_1STDAY,
  _NL_TIME_WEEK_1STWEEK,
  _NL_TIME_FIRST_WEEKDAY,
  _NL_TIME_FIRST_WORKDAY,
  _NL_TIME_CAL_DIRECTION,
  _NL_TIME_TIMEZONE,

  _DATE_FMT,

  _NL_W_DATE_FMT,

  _NL_TIME_CODESET,

  __ALTMON_1,
  __ALTMON_2,
  __ALTMON_3,
  __ALTMON_4,
  __ALTMON_5,
  __ALTMON_6,
  __ALTMON_7,
  __ALTMON_8,
  __ALTMON_9,
  __ALTMON_10,
  __ALTMON_11,
  __ALTMON_12,
  _NL_WALTMON_1,
  _NL_WALTMON_2,
  _NL_WALTMON_3,
  _NL_WALTMON_4,
  _NL_WALTMON_5,
  _NL_WALTMON_6,
  _NL_WALTMON_7,
  _NL_WALTMON_8,
  _NL_WALTMON_9,
  _NL_WALTMON_10,
  _NL_WALTMON_11,
  _NL_WALTMON_12,

  _NL_ABALTMON_1,
  _NL_ABALTMON_2,
  _NL_ABALTMON_3,
  _NL_ABALTMON_4,
  _NL_ABALTMON_5,
  _NL_ABALTMON_6,
  _NL_ABALTMON_7,
  _NL_ABALTMON_8,
  _NL_ABALTMON_9,
  _NL_ABALTMON_10,
  _NL_ABALTMON_11,
  _NL_ABALTMON_12,

  _NL_WABALTMON_1,
  _NL_WABALTMON_2,
  _NL_WABALTMON_3,
  _NL_WABALTMON_4,
  _NL_WABALTMON_5,
  _NL_WABALTMON_6,
  _NL_WABALTMON_7,
  _NL_WABALTMON_8,
  _NL_WABALTMON_9,
  _NL_WABALTMON_10,
  _NL_WABALTMON_11,
  _NL_WABALTMON_12,

  _NL_NUM_LC_TIME,

  _NL_COLLATE_NRULES = (((3) << 16) | (0)),
  _NL_COLLATE_RULESETS,
  _NL_COLLATE_TABLEMB,
  _NL_COLLATE_WEIGHTMB,
  _NL_COLLATE_EXTRAMB,
  _NL_COLLATE_INDIRECTMB,
  _NL_COLLATE_GAP1,
  _NL_COLLATE_GAP2,
  _NL_COLLATE_GAP3,
  _NL_COLLATE_TABLEWC,
  _NL_COLLATE_WEIGHTWC,
  _NL_COLLATE_EXTRAWC,
  _NL_COLLATE_INDIRECTWC,
  _NL_COLLATE_SYMB_HASH_SIZEMB,
  _NL_COLLATE_SYMB_TABLEMB,
  _NL_COLLATE_SYMB_EXTRAMB,
  _NL_COLLATE_COLLSEQMB,
  _NL_COLLATE_COLLSEQWC,
  _NL_COLLATE_CODESET,
  _NL_NUM_LC_COLLATE,

  _NL_CTYPE_CLASS = (((0) << 16) | (0)),
  _NL_CTYPE_TOUPPER,
  _NL_CTYPE_GAP1,
  _NL_CTYPE_TOLOWER,
  _NL_CTYPE_GAP2,
  _NL_CTYPE_CLASS32,
  _NL_CTYPE_GAP3,
  _NL_CTYPE_GAP4,
  _NL_CTYPE_GAP5,
  _NL_CTYPE_GAP6,
  _NL_CTYPE_CLASS_NAMES,
  _NL_CTYPE_MAP_NAMES,
  _NL_CTYPE_WIDTH,
  _NL_CTYPE_MB_CUR_MAX,
  _NL_CTYPE_CODESET_NAME,
  CODESET = _NL_CTYPE_CODESET_NAME,

  _NL_CTYPE_TOUPPER32,
  _NL_CTYPE_TOLOWER32,
  _NL_CTYPE_CLASS_OFFSET,
  _NL_CTYPE_MAP_OFFSET,
  _NL_CTYPE_INDIGITS_MB_LEN,
  _NL_CTYPE_INDIGITS0_MB,
  _NL_CTYPE_INDIGITS1_MB,
  _NL_CTYPE_INDIGITS2_MB,
  _NL_CTYPE_INDIGITS3_MB,
  _NL_CTYPE_INDIGITS4_MB,
  _NL_CTYPE_INDIGITS5_MB,
  _NL_CTYPE_INDIGITS6_MB,
  _NL_CTYPE_INDIGITS7_MB,
  _NL_CTYPE_INDIGITS8_MB,
  _NL_CTYPE_INDIGITS9_MB,
  _NL_CTYPE_INDIGITS_WC_LEN,
  _NL_CTYPE_INDIGITS0_WC,
  _NL_CTYPE_INDIGITS1_WC,
  _NL_CTYPE_INDIGITS2_WC,
  _NL_CTYPE_INDIGITS3_WC,
  _NL_CTYPE_INDIGITS4_WC,
  _NL_CTYPE_INDIGITS5_WC,
  _NL_CTYPE_INDIGITS6_WC,
  _NL_CTYPE_INDIGITS7_WC,
  _NL_CTYPE_INDIGITS8_WC,
  _NL_CTYPE_INDIGITS9_WC,
  _NL_CTYPE_OUTDIGIT0_MB,
  _NL_CTYPE_OUTDIGIT1_MB,
  _NL_CTYPE_OUTDIGIT2_MB,
  _NL_CTYPE_OUTDIGIT3_MB,
  _NL_CTYPE_OUTDIGIT4_MB,
  _NL_CTYPE_OUTDIGIT5_MB,
  _NL_CTYPE_OUTDIGIT6_MB,
  _NL_CTYPE_OUTDIGIT7_MB,
  _NL_CTYPE_OUTDIGIT8_MB,
  _NL_CTYPE_OUTDIGIT9_MB,
  _NL_CTYPE_OUTDIGIT0_WC,
  _NL_CTYPE_OUTDIGIT1_WC,
  _NL_CTYPE_OUTDIGIT2_WC,
  _NL_CTYPE_OUTDIGIT3_WC,
  _NL_CTYPE_OUTDIGIT4_WC,
  _NL_CTYPE_OUTDIGIT5_WC,
  _NL_CTYPE_OUTDIGIT6_WC,
  _NL_CTYPE_OUTDIGIT7_WC,
  _NL_CTYPE_OUTDIGIT8_WC,
  _NL_CTYPE_OUTDIGIT9_WC,
  _NL_CTYPE_TRANSLIT_TAB_SIZE,
  _NL_CTYPE_TRANSLIT_FROM_IDX,
  _NL_CTYPE_TRANSLIT_FROM_TBL,
  _NL_CTYPE_TRANSLIT_TO_IDX,
  _NL_CTYPE_TRANSLIT_TO_TBL,
  _NL_CTYPE_TRANSLIT_DEFAULT_MISSING_LEN,
  _NL_CTYPE_TRANSLIT_DEFAULT_MISSING,
  _NL_CTYPE_TRANSLIT_IGNORE_LEN,
  _NL_CTYPE_TRANSLIT_IGNORE,
  _NL_CTYPE_MAP_TO_NONASCII,
  _NL_CTYPE_NONASCII_CASE,
  _NL_CTYPE_EXTRA_MAP_1,
  _NL_CTYPE_EXTRA_MAP_2,
  _NL_CTYPE_EXTRA_MAP_3,
  _NL_CTYPE_EXTRA_MAP_4,
  _NL_CTYPE_EXTRA_MAP_5,
  _NL_CTYPE_EXTRA_MAP_6,
  _NL_CTYPE_EXTRA_MAP_7,
  _NL_CTYPE_EXTRA_MAP_8,
  _NL_CTYPE_EXTRA_MAP_9,
  _NL_CTYPE_EXTRA_MAP_10,
  _NL_CTYPE_EXTRA_MAP_11,
  _NL_CTYPE_EXTRA_MAP_12,
  _NL_CTYPE_EXTRA_MAP_13,
  _NL_CTYPE_EXTRA_MAP_14,
  _NL_NUM_LC_CTYPE,

  __INT_CURR_SYMBOL = (((4) << 16) | (0)),

  __CURRENCY_SYMBOL,

  __MON_DECIMAL_POINT,

  __MON_THOUSANDS_SEP,

  __MON_GROUPING,

  __POSITIVE_SIGN,

  __NEGATIVE_SIGN,

  __INT_FRAC_DIGITS,

  __FRAC_DIGITS,

  __P_CS_PRECEDES,

  __P_SEP_BY_SPACE,

  __N_CS_PRECEDES,

  __N_SEP_BY_SPACE,

  __P_SIGN_POSN,

  __N_SIGN_POSN,

  _NL_MONETARY_CRNCYSTR,

  __INT_P_CS_PRECEDES,

  __INT_P_SEP_BY_SPACE,

  __INT_N_CS_PRECEDES,

  __INT_N_SEP_BY_SPACE,

  __INT_P_SIGN_POSN,

  __INT_N_SIGN_POSN,

  _NL_MONETARY_DUO_INT_CURR_SYMBOL,
  _NL_MONETARY_DUO_CURRENCY_SYMBOL,
  _NL_MONETARY_DUO_INT_FRAC_DIGITS,
  _NL_MONETARY_DUO_FRAC_DIGITS,
  _NL_MONETARY_DUO_P_CS_PRECEDES,
  _NL_MONETARY_DUO_P_SEP_BY_SPACE,
  _NL_MONETARY_DUO_N_CS_PRECEDES,
  _NL_MONETARY_DUO_N_SEP_BY_SPACE,
  _NL_MONETARY_DUO_INT_P_CS_PRECEDES,
  _NL_MONETARY_DUO_INT_P_SEP_BY_SPACE,
  _NL_MONETARY_DUO_INT_N_CS_PRECEDES,
  _NL_MONETARY_DUO_INT_N_SEP_BY_SPACE,
  _NL_MONETARY_DUO_P_SIGN_POSN,
  _NL_MONETARY_DUO_N_SIGN_POSN,
  _NL_MONETARY_DUO_INT_P_SIGN_POSN,
  _NL_MONETARY_DUO_INT_N_SIGN_POSN,
  _NL_MONETARY_UNO_VALID_FROM,
  _NL_MONETARY_UNO_VALID_TO,
  _NL_MONETARY_DUO_VALID_FROM,
  _NL_MONETARY_DUO_VALID_TO,
  _NL_MONETARY_CONVERSION_RATE,
  _NL_MONETARY_DECIMAL_POINT_WC,
  _NL_MONETARY_THOUSANDS_SEP_WC,
  _NL_MONETARY_CODESET,
  _NL_NUM_LC_MONETARY,

  __DECIMAL_POINT = (((1) << 16) | (0)),

  RADIXCHAR = __DECIMAL_POINT,

  __THOUSANDS_SEP,

  THOUSEP = __THOUSANDS_SEP,

  __GROUPING,

  _NL_NUMERIC_DECIMAL_POINT_WC,
  _NL_NUMERIC_THOUSANDS_SEP_WC,
  _NL_NUMERIC_CODESET,
  _NL_NUM_LC_NUMERIC,

  __YESEXPR = (((5) << 16) | (0)),

  __NOEXPR,

  __YESSTR,

  __NOSTR,

  _NL_MESSAGES_CODESET,
  _NL_NUM_LC_MESSAGES,

  _NL_PAPER_HEIGHT = (((7) << 16) | (0)),
  _NL_PAPER_WIDTH,
  _NL_PAPER_CODESET,
  _NL_NUM_LC_PAPER,

  _NL_NAME_NAME_FMT = (((8) << 16) | (0)),
  _NL_NAME_NAME_GEN,
  _NL_NAME_NAME_MR,
  _NL_NAME_NAME_MRS,
  _NL_NAME_NAME_MISS,
  _NL_NAME_NAME_MS,
  _NL_NAME_CODESET,
  _NL_NUM_LC_NAME,

  _NL_ADDRESS_POSTAL_FMT = (((9) << 16) | (0)),
  _NL_ADDRESS_COUNTRY_NAME,
  _NL_ADDRESS_COUNTRY_POST,
  _NL_ADDRESS_COUNTRY_AB2,
  _NL_ADDRESS_COUNTRY_AB3,
  _NL_ADDRESS_COUNTRY_CAR,
  _NL_ADDRESS_COUNTRY_NUM,
  _NL_ADDRESS_COUNTRY_ISBN,
  _NL_ADDRESS_LANG_NAME,
  _NL_ADDRESS_LANG_AB,
  _NL_ADDRESS_LANG_TERM,
  _NL_ADDRESS_LANG_LIB,
  _NL_ADDRESS_CODESET,
  _NL_NUM_LC_ADDRESS,

  _NL_TELEPHONE_TEL_INT_FMT = (((10) << 16) | (0)),
  _NL_TELEPHONE_TEL_DOM_FMT,
  _NL_TELEPHONE_INT_SELECT,
  _NL_TELEPHONE_INT_PREFIX,
  _NL_TELEPHONE_CODESET,
  _NL_NUM_LC_TELEPHONE,

  _NL_MEASUREMENT_MEASUREMENT = (((11) << 16) | (0)),
  _NL_MEASUREMENT_CODESET,
  _NL_NUM_LC_MEASUREMENT,

  _NL_IDENTIFICATION_TITLE = (((12) << 16) | (0)),
  _NL_IDENTIFICATION_SOURCE,
  _NL_IDENTIFICATION_ADDRESS,
  _NL_IDENTIFICATION_CONTACT,
  _NL_IDENTIFICATION_EMAIL,
  _NL_IDENTIFICATION_TEL,
  _NL_IDENTIFICATION_FAX,
  _NL_IDENTIFICATION_LANGUAGE,
  _NL_IDENTIFICATION_TERRITORY,
  _NL_IDENTIFICATION_AUDIENCE,
  _NL_IDENTIFICATION_APPLICATION,
  _NL_IDENTIFICATION_ABBREVIATION,
  _NL_IDENTIFICATION_REVISION,
  _NL_IDENTIFICATION_DATE,
  _NL_IDENTIFICATION_CATEGORY,
  _NL_IDENTIFICATION_CODESET,
  _NL_NUM_LC_IDENTIFICATION,

  _NL_NUM
};
extern char *nl_langinfo(nl_item __item) __attribute__((__nothrow__, __leaf__));

extern char *nl_langinfo_l(nl_item __item, locale_t __l);

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;

struct timex {
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

  int : 32;
  int : 32;
  int : 32;
  int : 32;
  int : 32;
  int : 32;
  int : 32;
  int : 32;
  int : 32;
  int : 32;
  int : 32;
};

extern int clock_adjtime(__clockid_t __clock_id, struct timex *__utx)
    __attribute__((__nothrow__, __leaf__));

struct tm {
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

struct itimerspec {
  struct timespec it_interval;
  struct timespec it_value;
};
struct sigevent;

extern clock_t clock(void) __attribute__((__nothrow__, __leaf__));

extern time_t time(time_t *__timer) __attribute__((__nothrow__, __leaf__));

extern double difftime(time_t __time1, time_t __time0)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));

extern time_t mktime(struct tm *__tp) __attribute__((__nothrow__, __leaf__));
extern size_t strftime(char *__restrict __s, size_t __maxsize,
                       const char *__restrict __format,
                       const struct tm *__restrict __tp)
    __attribute__((__nothrow__, __leaf__));

extern char *strptime(const char *__restrict __s, const char *__restrict __fmt,
                      struct tm *__tp) __attribute__((__nothrow__, __leaf__));

extern size_t strftime_l(char *__restrict __s, size_t __maxsize,
                         const char *__restrict __format,
                         const struct tm *__restrict __tp, locale_t __loc)
    __attribute__((__nothrow__, __leaf__));

extern char *strptime_l(const char *__restrict __s,
                        const char *__restrict __fmt, struct tm *__tp,
                        locale_t __loc) __attribute__((__nothrow__, __leaf__));

extern struct tm *gmtime(const time_t *__timer)
    __attribute__((__nothrow__, __leaf__));

extern struct tm *localtime(const time_t *__timer)
    __attribute__((__nothrow__, __leaf__));
extern struct tm *gmtime_r(const time_t *__restrict __timer,
                           struct tm *__restrict __tp)
    __attribute__((__nothrow__, __leaf__));

extern struct tm *localtime_r(const time_t *__restrict __timer,
                              struct tm *__restrict __tp)
    __attribute__((__nothrow__, __leaf__));
extern char *asctime(const struct tm *__tp)
    __attribute__((__nothrow__, __leaf__));

extern char *ctime(const time_t *__timer)
    __attribute__((__nothrow__, __leaf__));
extern char *asctime_r(const struct tm *__restrict __tp, char *__restrict __buf)
    __attribute__((__nothrow__, __leaf__));

extern char *ctime_r(const time_t *__restrict __timer, char *__restrict __buf)
    __attribute__((__nothrow__, __leaf__));
extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;

extern char *tzname[2];

extern void tzset(void) __attribute__((__nothrow__, __leaf__));

extern int daylight;
extern long int timezone;
extern time_t timegm(struct tm *__tp) __attribute__((__nothrow__, __leaf__));

extern time_t timelocal(struct tm *__tp) __attribute__((__nothrow__, __leaf__));
extern int dysize(int __year) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
extern int nanosleep(const struct timespec *__requested_time,
                     struct timespec *__remaining);

extern int clock_getres(clockid_t __clock_id, struct timespec *__res)
    __attribute__((__nothrow__, __leaf__));

extern int clock_gettime(clockid_t __clock_id, struct timespec *__tp)
    __attribute__((__nothrow__, __leaf__));

extern int clock_settime(clockid_t __clock_id, const struct timespec *__tp)
    __attribute__((__nothrow__, __leaf__));
extern int clock_nanosleep(clockid_t __clock_id, int __flags,
                           const struct timespec *__req,
                           struct timespec *__rem);
extern int clock_getcpuclockid(pid_t __pid, clockid_t *__clock_id)
    __attribute__((__nothrow__, __leaf__));

extern int timer_create(clockid_t __clock_id, struct sigevent *__restrict __evp,
                        timer_t *__restrict __timerid)
    __attribute__((__nothrow__, __leaf__));

extern int timer_delete(timer_t __timerid)
    __attribute__((__nothrow__, __leaf__));

extern int timer_settime(timer_t __timerid, int __flags,
                         const struct itimerspec *__restrict __value,
                         struct itimerspec *__restrict __ovalue)
    __attribute__((__nothrow__, __leaf__));

extern int timer_gettime(timer_t __timerid, struct itimerspec *__value)
    __attribute__((__nothrow__, __leaf__));
extern int timer_getoverrun(timer_t __timerid)
    __attribute__((__nothrow__, __leaf__));

extern int timespec_get(struct timespec *__ts, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int timespec_getres(struct timespec *__ts, int __base)
    __attribute__((__nothrow__, __leaf__));
extern int getdate_err;
extern struct tm *getdate(const char *__string);
extern int getdate_r(const char *__restrict __string,
                     struct tm *__restrict __resbufp);

struct __time_t_must_be_integral {
  unsigned int __floating_time_t_unsupported : (time_t)1;
};
extern int rpl_nanosleep(struct timespec const *__rqtp, struct timespec *__rmtp)
    __attribute__((__nonnull__(1)))

    ;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
typedef struct tm_zone *timezone_t;
extern timezone_t tzalloc(char const *__name);
extern int _gl_cxxalias_dummy;

extern void tzfree(timezone_t __tz);
extern int _gl_cxxalias_dummy;

extern struct tm *localtime_rz(timezone_t __tz,
                               time_t const *__restrict__ __timer,
                               struct tm *__restrict__ __result)
    __attribute__((__nonnull__(2, 3)))

    ;
extern int _gl_cxxalias_dummy

    ;

extern time_t mktime_z(timezone_t __tz, struct tm *__restrict__ __tm)
    __attribute__((__nonnull__(2)))

    ;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;

struct stat {

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

struct stat64 {

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
extern int stat(const char *__restrict __file, struct stat *__restrict __buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern int fstat(int __fd, struct stat *__buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int stat64(const char *__restrict __file,
                  struct stat64 *__restrict __buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int fstat64(int __fd, struct stat64 *__buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int fstatat(int __fd, const char *__restrict __file,
                   struct stat *__restrict __buf, int __flag)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));
extern int fstatat64(int __fd, const char *__restrict __file,
                     struct stat64 *__restrict __buf, int __flag)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));
extern int lstat(const char *__restrict __file, struct stat *__restrict __buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int lstat64(const char *__restrict __file,
                   struct stat64 *__restrict __buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int chmod(const char *__file, __mode_t __mode)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern int lchmod(const char *__file, __mode_t __mode)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern int fchmod(int __fd, __mode_t __mode)
    __attribute__((__nothrow__, __leaf__));

extern int fchmodat(int __fd, const char *__file, __mode_t __mode, int __flag)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)))
    __attribute__((__warn_unused_result__));

extern __mode_t umask(__mode_t __mask) __attribute__((__nothrow__, __leaf__));

extern __mode_t getumask(void) __attribute__((__nothrow__, __leaf__));

extern int mkdir(const char *__path, __mode_t __mode)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern int mkdirat(int __fd, const char *__path, __mode_t __mode)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));

extern int mknod(const char *__path, __mode_t __mode, __dev_t __dev)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern int mknodat(int __fd, const char *__path, __mode_t __mode, __dev_t __dev)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));

extern int mkfifo(const char *__path, __mode_t __mode)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern int mkfifoat(int __fd, const char *__path, __mode_t __mode)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));

extern int utimensat(int __fd, const char *__path,
                     const struct timespec __times[2], int __flags)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int futimens(int __fd, const struct timespec __times[2])
    __attribute__((__nothrow__, __leaf__));

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
typedef char *__kernel_caddr_t;
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

int statx(int __dirfd, const char *__restrict __path, int __flags,
          unsigned int __mask, struct statx *__restrict __buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 5)));

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int rpl_mknod(char const *file, mode_t mode, dev_t dev)
    __attribute__((__nonnull__(1)));
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;

extern long int __sysconf(int __name) __attribute__((__nothrow__, __leaf__));

struct timezone {
  int tz_minuteswest;
  int tz_dsttime;
};
extern int gettimeofday(struct timeval *__restrict __tv, void *__restrict __tz)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int settimeofday(const struct timeval *__tv, const struct timezone *__tz)
    __attribute__((__nothrow__, __leaf__));

extern int adjtime(const struct timeval *__delta, struct timeval *__olddelta)
    __attribute__((__nothrow__, __leaf__));
enum __itimer_which {

  ITIMER_REAL = 0,

  ITIMER_VIRTUAL = 1,

  ITIMER_PROF = 2

};

struct itimerval {

  struct timeval it_interval;

  struct timeval it_value;
};

typedef enum __itimer_which __itimer_which_t;

extern int getitimer(__itimer_which_t __which, struct itimerval *__value)
    __attribute__((__nothrow__, __leaf__));

extern int setitimer(__itimer_which_t __which,
                     const struct itimerval *__restrict __new,
                     struct itimerval *__restrict __old)
    __attribute__((__nothrow__, __leaf__));

extern int utimes(const char *__file, const struct timeval __tvp[2])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int lutimes(const char *__file, const struct timeval __tvp[2])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern int futimes(int __fd, const struct timeval __tvp[2])
    __attribute__((__nothrow__, __leaf__));
extern int futimesat(int __fd, const char *__file,
                     const struct timeval __tvp[2])
    __attribute__((__nothrow__, __leaf__));

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;

extern unsigned int gnu_dev_major(__dev_t __dev)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern unsigned int gnu_dev_minor(__dev_t __dev)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern __dev_t gnu_dev_makedev(unsigned int __major, unsigned int __minor)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));

extern void *memcpy(void *__restrict __dest, const void *__restrict __src,
                    size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));

extern void *memmove(void *__dest, const void *__src, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern void *memccpy(void *__restrict __dest, const void *__restrict __src,
                     int __c, size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)))
__attribute__((__access__(__write_only__, 1, 4)));

extern void *memset(void *__s, int __c, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern int memcmp(const void *__s1, const void *__s2, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern int __memcmpeq(const void *__s1, const void *__s2, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern void *memchr(const void *__s, int __c, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));
extern void *rawmemchr(const void *__s, int __c)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));
extern void *memrchr(const void *__s, int __c, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)))
    __attribute__((__access__(__read_only__, 1, 3)));

extern char *strcpy(char *__restrict __dest, const char *__restrict __src)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern char *strncpy(char *__restrict __dest, const char *__restrict __src,
                     size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));

extern char *strcat(char *__restrict __dest, const char *__restrict __src)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern char *strncat(char *__restrict __dest, const char *__restrict __src,
                     size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));

extern int strcmp(const char *__s1, const char *__s2)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

extern int strncmp(const char *__s1, const char *__s2, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

extern int strcoll(const char *__s1, const char *__s2)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

extern size_t strxfrm(char *__restrict __dest, const char *__restrict __src,
                      size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2)))
__attribute__((__access__(__write_only__, 1, 3)));

extern int strcoll_l(const char *__s1, const char *__s2, locale_t __l)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2, 3)));

extern size_t strxfrm_l(char *__dest, const char *__src, size_t __n,
                        locale_t __l) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2, 4)))
__attribute__((__access__(__write_only__, 1, 3)));

extern char *strdup(const char *__s) __attribute__((__nothrow__, __leaf__))
__attribute__((__malloc__)) __attribute__((__nonnull__(1)));

extern char *strndup(const char *__string, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__nonnull__(1)));
extern char *strchr(const char *__s, int __c)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));
extern char *strrchr(const char *__s, int __c)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));
extern char *strchrnul(const char *__s, int __c)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));

extern size_t strcspn(const char *__s, const char *__reject)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

extern size_t strspn(const char *__s, const char *__accept)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern char *strpbrk(const char *__s, const char *__accept)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern char *strstr(const char *__haystack, const char *__needle)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

extern char *strtok(char *__restrict __s, const char *__restrict __delim)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));

extern char *__strtok_r(char *__restrict __s, const char *__restrict __delim,
                        char **__restrict __save_ptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));

extern char *strtok_r(char *__restrict __s, const char *__restrict __delim,
                      char **__restrict __save_ptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));
extern char *strcasestr(const char *__haystack, const char *__needle)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

extern void *memmem(const void *__haystack, size_t __haystacklen,
                    const void *__needle, size_t __needlelen)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 3)))
    __attribute__((__access__(__read_only__, 1, 2)))
    __attribute__((__access__(__read_only__, 3, 4)));

extern void *__mempcpy(void *__restrict __dest, const void *__restrict __src,
                       size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern void *mempcpy(void *__restrict __dest, const void *__restrict __src,
                     size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));

extern size_t strlen(const char *__s) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));

extern size_t strnlen(const char *__string, size_t __maxlen)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));

extern char *strerror(int __errnum) __attribute__((__nothrow__, __leaf__));
extern char *strerror_r(int __errnum, char *__buf, size_t __buflen)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)))
    __attribute__((__warn_unused_result__))
    __attribute__((__access__(__write_only__, 2, 3)));

extern const char *strerrordesc_np(int __err)
    __attribute__((__nothrow__, __leaf__));

extern const char *strerrorname_np(int __err)
    __attribute__((__nothrow__, __leaf__));

extern char *strerror_l(int __errnum, locale_t __l)
    __attribute__((__nothrow__, __leaf__));

extern int bcmp(const void *__s1, const void *__s2, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

extern void bcopy(const void *__src, void *__dest, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern void bzero(void *__s, size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern char *index(const char *__s, int __c)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));
extern char *rindex(const char *__s, int __c)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));

extern int ffs(int __i) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));

extern int ffsl(long int __l) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
__extension__ extern int ffsll(long long int __ll)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));

extern int strcasecmp(const char *__s1, const char *__s2)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

extern int strncasecmp(const char *__s1, const char *__s2, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

extern int strcasecmp_l(const char *__s1, const char *__s2, locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2, 3)));

extern int strncasecmp_l(const char *__s1, const char *__s2, size_t __n,
                         locale_t __loc) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1, 2, 4)));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) void
    __attribute__((__nothrow__, __leaf__))
    bcopy(const void *__src, void *__dest, size_t __len) {
  (void)__builtin___memmove_chk(__dest, __src, __len,
                                __builtin_object_size(__dest, 0));
}

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) void
    __attribute__((__nothrow__, __leaf__)) bzero(void *__dest, size_t __len) {
  (void)__builtin___memset_chk(__dest, '\0', __len,
                               __builtin_object_size(__dest, 0));
}

extern void explicit_bzero(void *__s, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__access__(__write_only__, 1, 2)));

extern char *strsep(char **__restrict __stringp, const char *__restrict __delim)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern char *strsignal(int __sig) __attribute__((__nothrow__, __leaf__));

extern const char *sigabbrev_np(int __sig)
    __attribute__((__nothrow__, __leaf__));

extern const char *sigdescr_np(int __sig)
    __attribute__((__nothrow__, __leaf__));

extern char *__stpcpy(char *__restrict __dest, const char *__restrict __src)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern char *stpcpy(char *__restrict __dest, const char *__restrict __src)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern char *__stpncpy(char *__restrict __dest, const char *__restrict __src,
                       size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern char *stpncpy(char *__restrict __dest, const char *__restrict __src,
                     size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));

extern int strverscmp(const char *__s1, const char *__s2)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

extern char *strfry(char *__string) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

extern void *memfrob(void *__s, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__access__(__read_write__, 1, 2)));
extern char *basename(const char *__filename)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__))
__attribute__((__artificial__)) void *__attribute__((__nothrow__, __leaf__))
memcpy(void *__restrict __dest, const void *__restrict __src, size_t __len)

{
  return __builtin___memcpy_chk(__dest, __src, __len,
                                __builtin_object_size(__dest, 0));
}

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__))
__attribute__((__artificial__)) void *__attribute__((__nothrow__, __leaf__))
memmove(void *__dest, const void *__src, size_t __len) {
  return __builtin___memmove_chk(__dest, __src, __len,
                                 __builtin_object_size(__dest, 0));
}

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__))
__attribute__((__artificial__)) void *__attribute__((__nothrow__, __leaf__))
mempcpy(void *__restrict __dest, const void *__restrict __src, size_t __len)

{
  return __builtin___mempcpy_chk(__dest, __src, __len,
                                 __builtin_object_size(__dest, 0));
}
extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__))
__attribute__((__artificial__)) void *__attribute__((__nothrow__, __leaf__))
memset(void *__dest, int __ch, size_t __len) {
  return __builtin___memset_chk(__dest, __ch, __len,
                                __builtin_object_size(__dest, 0));
}

void __explicit_bzero_chk(void *__dest, size_t __len, size_t __destlen)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__access__(__write_only__, 1, 2)));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) void
    __attribute__((__nothrow__, __leaf__))
    explicit_bzero(void *__dest, size_t __len) {
  __explicit_bzero_chk(__dest, __len, __builtin_object_size(__dest, 0));
}

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__))
__attribute__((__artificial__)) char *__attribute__((__nothrow__, __leaf__))
strcpy(char *__restrict __dest, const char *__restrict __src) {
  return __builtin___strcpy_chk(__dest, __src,
                                __builtin_object_size(__dest, 2 > 1));
}

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__))
__attribute__((__artificial__)) char *__attribute__((__nothrow__, __leaf__))
stpcpy(char *__restrict __dest, const char *__restrict __src) {
  return __builtin___stpcpy_chk(__dest, __src,
                                __builtin_object_size(__dest, 2 > 1));
}

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__))
__attribute__((__artificial__)) char *__attribute__((__nothrow__, __leaf__))
strncpy(char *__restrict __dest, const char *__restrict __src, size_t __len)

{
  return __builtin___strncpy_chk(__dest, __src, __len,
                                 __builtin_object_size(__dest, 2 > 1));
}

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__))
__attribute__((__artificial__)) char *__attribute__((__nothrow__, __leaf__))
stpncpy(char *__dest, const char *__src, size_t __n) {
  return __builtin___stpncpy_chk(__dest, __src, __n,
                                 __builtin_object_size(__dest, 2 > 1));
}
extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__))
__attribute__((__artificial__)) char *__attribute__((__nothrow__, __leaf__))
strcat(char *__restrict __dest, const char *__restrict __src) {
  return __builtin___strcat_chk(__dest, __src,
                                __builtin_object_size(__dest, 2 > 1));
}

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__))
__attribute__((__artificial__)) char *__attribute__((__nothrow__, __leaf__))
strncat(char *__restrict __dest, const char *__restrict __src, size_t __len)

{
  return __builtin___strncat_chk(__dest, __src, __len,
                                 __builtin_object_size(__dest, 2 > 1));
}

extern void free(void *);
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

    ;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

    ;

extern int _gl_cxxalias_dummy;
extern char *strdup(char const *__s) __attribute__((__nonnull__(1)))
__attribute__((__malloc__)) __attribute__((__malloc__(free, 1)))

;

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern char *strndup(char const *__s, size_t __n)
    __attribute__((__nonnull__(1))) __attribute__((__malloc__))
    __attribute__((__malloc__(free, 1)))

    ;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern size_t mbslen(const char *string) __attribute__((__pure__))
__attribute__((__nonnull__(1)))

;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern char *mbschr(const char *string, int c) __attribute__((__pure__))
__attribute__((__nonnull__(1)))

;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern char *mbsstr(const char *haystack, const char *needle)

    __attribute__((__pure__))

    __attribute__((__nonnull__(1, 2)));
extern int mbscasecmp(const char *s1, const char *s2)

    __attribute__((__pure__))

    __attribute__((__nonnull__(1, 2)));
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;

extern int *__errno_location(void) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));

extern char *program_invocation_name;
extern char *program_invocation_short_name;

typedef int error_t;

typedef struct {
  int quot;
  int rem;
} div_t;

typedef struct {
  long int quot;
  long int rem;
} ldiv_t;

__extension__ typedef struct {
  long long int quot;
  long long int rem;
} lldiv_t;
extern size_t __ctype_get_mb_cur_max(void)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__));

extern double atof(const char *__nptr) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)))
__attribute__((__warn_unused_result__));

extern int atoi(const char *__nptr) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)))
__attribute__((__warn_unused_result__));

extern long int atol(const char *__nptr) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)))
__attribute__((__warn_unused_result__));

__extension__ extern long long int atoll(const char *__nptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));

extern double strtod(const char *__restrict __nptr, char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern float strtof(const char *__restrict __nptr, char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern long double strtold(const char *__restrict __nptr,
                           char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern _Float32 strtof32(const char *__restrict __nptr,
                         char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern _Float64 strtof64(const char *__restrict __nptr,
                         char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern _Float128 strtof128(const char *__restrict __nptr,
                           char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern _Float32x strtof32x(const char *__restrict __nptr,
                           char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern _Float64x strtof64x(const char *__restrict __nptr,
                           char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern long int strtol(const char *__restrict __nptr,
                       char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern unsigned long int strtoul(const char *__restrict __nptr,
                                 char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

__extension__ extern long long int
strtoq(const char *__restrict __nptr, char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

__extension__ extern unsigned long long int
strtouq(const char *__restrict __nptr, char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

__extension__ extern long long int
strtoll(const char *__restrict __nptr, char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

__extension__ extern unsigned long long int
strtoull(const char *__restrict __nptr, char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern int strfromd(char *__dest, size_t __size, const char *__format,
                    double __f) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3)));

extern int strfromf(char *__dest, size_t __size, const char *__format,
                    float __f) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3)));

extern int strfroml(char *__dest, size_t __size, const char *__format,
                    long double __f) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3)));
extern int strfromf32(char *__dest, size_t __size, const char *__format,
                      _Float32 __f) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3)));

extern int strfromf64(char *__dest, size_t __size, const char *__format,
                      _Float64 __f) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3)));

extern int strfromf128(char *__dest, size_t __size, const char *__format,
                       _Float128 __f) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3)));

extern int strfromf32x(char *__dest, size_t __size, const char *__format,
                       _Float32x __f) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3)));

extern int strfromf64x(char *__dest, size_t __size, const char *__format,
                       _Float64x __f) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3)));
extern long int strtol_l(const char *__restrict __nptr,
                         char **__restrict __endptr, int __base, locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 4)));

extern unsigned long int strtoul_l(const char *__restrict __nptr,
                                   char **__restrict __endptr, int __base,
                                   locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 4)));

__extension__ extern long long int strtoll_l(const char *__restrict __nptr,
                                             char **__restrict __endptr,
                                             int __base, locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 4)));

__extension__ extern unsigned long long int
strtoull_l(const char *__restrict __nptr, char **__restrict __endptr,
           int __base, locale_t __loc) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 4)));

extern double strtod_l(const char *__restrict __nptr,
                       char **__restrict __endptr, locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));

extern float strtof_l(const char *__restrict __nptr, char **__restrict __endptr,
                      locale_t __loc) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 3)));

extern long double strtold_l(const char *__restrict __nptr,
                             char **__restrict __endptr, locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));
extern _Float32 strtof32_l(const char *__restrict __nptr,
                           char **__restrict __endptr, locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));

extern _Float64 strtof64_l(const char *__restrict __nptr,
                           char **__restrict __endptr, locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));

extern _Float128 strtof128_l(const char *__restrict __nptr,
                             char **__restrict __endptr, locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));

extern _Float32x strtof32x_l(const char *__restrict __nptr,
                             char **__restrict __endptr, locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));

extern _Float64x strtof64x_l(const char *__restrict __nptr,
                             char **__restrict __endptr, locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 3)));
extern char *l64a(long int __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__warn_unused_result__));

extern long int a64l(const char *__s) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)))
__attribute__((__warn_unused_result__));

extern long int random(void) __attribute__((__nothrow__, __leaf__));

extern void srandom(unsigned int __seed) __attribute__((__nothrow__, __leaf__));

extern char *initstate(unsigned int __seed, char *__statebuf, size_t __statelen)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));

extern char *setstate(char *__statebuf) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

struct random_data {
  int32_t *fptr;
  int32_t *rptr;
  int32_t *state;
  int rand_type;
  int rand_deg;
  int rand_sep;
  int32_t *end_ptr;
};

extern int random_r(struct random_data *__restrict __buf,
                    int32_t *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern int srandom_r(unsigned int __seed, struct random_data *__buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));

extern int initstate_r(unsigned int __seed, char *__restrict __statebuf,
                       size_t __statelen, struct random_data *__restrict __buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 4)));

extern int setstate_r(char *__restrict __statebuf,
                      struct random_data *__restrict __buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern int rand(void) __attribute__((__nothrow__, __leaf__));

extern void srand(unsigned int __seed) __attribute__((__nothrow__, __leaf__));

extern int rand_r(unsigned int *__seed) __attribute__((__nothrow__, __leaf__));

extern double drand48(void) __attribute__((__nothrow__, __leaf__));
extern double erand48(unsigned short int __xsubi[3])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern long int lrand48(void) __attribute__((__nothrow__, __leaf__));
extern long int nrand48(unsigned short int __xsubi[3])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern long int mrand48(void) __attribute__((__nothrow__, __leaf__));
extern long int jrand48(unsigned short int __xsubi[3])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern void srand48(long int __seedval) __attribute__((__nothrow__, __leaf__));
extern unsigned short int *seed48(unsigned short int __seed16v[3])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern void lcong48(unsigned short int __param[7])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

struct drand48_data {
  unsigned short int __x[3];
  unsigned short int __old_x[3];
  unsigned short int __c;
  unsigned short int __init;
  __extension__ unsigned long long int __a;
};

extern int drand48_r(struct drand48_data *__restrict __buffer,
                     double *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int erand48_r(unsigned short int __xsubi[3],
                     struct drand48_data *__restrict __buffer,
                     double *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern int lrand48_r(struct drand48_data *__restrict __buffer,
                     long int *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int nrand48_r(unsigned short int __xsubi[3],
                     struct drand48_data *__restrict __buffer,
                     long int *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern int mrand48_r(struct drand48_data *__restrict __buffer,
                     long int *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int jrand48_r(unsigned short int __xsubi[3],
                     struct drand48_data *__restrict __buffer,
                     long int *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern int srand48_r(long int __seedval, struct drand48_data *__buffer)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));

extern int seed48_r(unsigned short int __seed16v[3],
                    struct drand48_data *__buffer)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern int lcong48_r(unsigned short int __param[7],
                     struct drand48_data *__buffer)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern void *malloc(size_t __size) __attribute__((__nothrow__, __leaf__))
__attribute__((__malloc__)) __attribute__((__alloc_size__(1)))
__attribute__((__warn_unused_result__));

extern void *calloc(size_t __nmemb, size_t __size)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__alloc_size__(1, 2)))
    __attribute__((__warn_unused_result__));

extern void *realloc(void *__ptr, size_t __size)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__)) __attribute__((__alloc_size__(2)));

extern void free(void *__ptr) __attribute__((__nothrow__, __leaf__));

extern void *reallocarray(void *__ptr, size_t __nmemb, size_t __size)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__))
    __attribute__((__alloc_size__(2, 3)))
    __attribute__((__malloc__(__builtin_free, 1)));

extern void *reallocarray(void *__ptr, size_t __nmemb, size_t __size)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__malloc__(reallocarray, 1)));
extern void *valloc(size_t __size) __attribute__((__nothrow__, __leaf__))
__attribute__((__malloc__)) __attribute__((__alloc_size__(1)))
__attribute__((__warn_unused_result__));

extern int posix_memalign(void **__memptr, size_t __alignment, size_t __size)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__warn_unused_result__));

extern void *aligned_alloc(size_t __alignment, size_t __size)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__alloc_align__(1))) __attribute__((__alloc_size__(2)))
    __attribute__((__warn_unused_result__));

extern void abort(void) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));

extern int atexit(void (*__func)(void)) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

extern int at_quick_exit(void (*__func)(void))
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern int on_exit(void (*__func)(int __status, void *__arg), void *__arg)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern void exit(int __status) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));

extern void quick_exit(int __status) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));

extern void _Exit(int __status) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));

extern char *getenv(const char *__name) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));

extern char *secure_getenv(const char *__name)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__warn_unused_result__));

extern int putenv(char *__string) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

extern int setenv(const char *__name, const char *__value, int __replace)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));

extern int unsetenv(const char *__name) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

extern int clearenv(void) __attribute__((__nothrow__, __leaf__));
extern char *mktemp(char *__template) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int mkstemp(char *__template) __attribute__((__nonnull__(1)))
__attribute__((__warn_unused_result__));
extern int mkstemp64(char *__template) __attribute__((__nonnull__(1)))
__attribute__((__warn_unused_result__));
extern int mkstemps(char *__template, int __suffixlen)
    __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
extern int mkstemps64(char *__template, int __suffixlen)
    __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
extern char *mkdtemp(char *__template) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
extern int mkostemp(char *__template, int __flags)
    __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
extern int mkostemp64(char *__template, int __flags)
    __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
extern int mkostemps(char *__template, int __suffixlen, int __flags)
    __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
extern int mkostemps64(char *__template, int __suffixlen, int __flags)
    __attribute__((__nonnull__(1))) __attribute__((__warn_unused_result__));
extern int system(const char *__command)
    __attribute__((__warn_unused_result__));

extern char *canonicalize_file_name(const char *__name)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__malloc__)) __attribute__((__malloc__(__builtin_free, 1)))
    __attribute__((__warn_unused_result__));
extern char *realpath(const char *__restrict __name,
                      char *__restrict __resolved)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__));

typedef int (*__compar_fn_t)(const void *, const void *);

typedef __compar_fn_t comparison_fn_t;

typedef int (*__compar_d_fn_t)(const void *, const void *, void *);

extern void *bsearch(const void *__key, const void *__base, size_t __nmemb,
                     size_t __size, __compar_fn_t __compar)
    __attribute__((__nonnull__(1, 2, 5)))
    __attribute__((__warn_unused_result__));

extern void qsort(void *__base, size_t __nmemb, size_t __size,
                  __compar_fn_t __compar) __attribute__((__nonnull__(1, 4)));

extern void qsort_r(void *__base, size_t __nmemb, size_t __size,
                    __compar_d_fn_t __compar, void *__arg)
    __attribute__((__nonnull__(1, 4)));

extern int abs(int __x) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__)) __attribute__((__warn_unused_result__));
extern long int labs(long int __x) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__)) __attribute__((__warn_unused_result__));

__extension__ extern long long int llabs(long long int __x)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__))
    __attribute__((__warn_unused_result__));

extern div_t div(int __numer, int __denom)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__))
    __attribute__((__warn_unused_result__));
extern ldiv_t ldiv(long int __numer, long int __denom)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__))
    __attribute__((__warn_unused_result__));

__extension__ extern lldiv_t lldiv(long long int __numer, long long int __denom)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__))
    __attribute__((__warn_unused_result__));
extern char *ecvt(double __value, int __ndigit, int *__restrict __decpt,
                  int *__restrict __sign) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3, 4))) __attribute__((__warn_unused_result__));

extern char *fcvt(double __value, int __ndigit, int *__restrict __decpt,
                  int *__restrict __sign) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3, 4))) __attribute__((__warn_unused_result__));

extern char *gcvt(double __value, int __ndigit, char *__buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)))
    __attribute__((__warn_unused_result__));

extern char *qecvt(long double __value, int __ndigit, int *__restrict __decpt,
                   int *__restrict __sign)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3, 4)))
    __attribute__((__warn_unused_result__));
extern char *qfcvt(long double __value, int __ndigit, int *__restrict __decpt,
                   int *__restrict __sign)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3, 4)))
    __attribute__((__warn_unused_result__));
extern char *qgcvt(long double __value, int __ndigit, char *__buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)))
    __attribute__((__warn_unused_result__));

extern int ecvt_r(double __value, int __ndigit, int *__restrict __decpt,
                  int *__restrict __sign, char *__restrict __buf, size_t __len)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__nonnull__(3, 4, 5)));
extern int fcvt_r(double __value, int __ndigit, int *__restrict __decpt,
                  int *__restrict __sign, char *__restrict __buf, size_t __len)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__nonnull__(3, 4, 5)));

extern int qecvt_r(long double __value, int __ndigit, int *__restrict __decpt,
                   int *__restrict __sign, char *__restrict __buf, size_t __len)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__nonnull__(3, 4, 5)));
extern int qfcvt_r(long double __value, int __ndigit, int *__restrict __decpt,
                   int *__restrict __sign, char *__restrict __buf, size_t __len)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__nonnull__(3, 4, 5)));

extern int mblen(const char *__s, size_t __n)
    __attribute__((__nothrow__, __leaf__));

extern int mbtowc(wchar_t *__restrict __pwc, const char *__restrict __s,
                  size_t __n) __attribute__((__nothrow__, __leaf__));

extern int wctomb(char *__s, wchar_t __wchar)
    __attribute__((__nothrow__, __leaf__));

extern size_t mbstowcs(wchar_t *__restrict __pwcs, const char *__restrict __s,
                       size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__access__(__read_only__, 2)));

extern size_t wcstombs(char *__restrict __s, const wchar_t *__restrict __pwcs,
                       size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__access__(__write_only__, 1, 3)))
__attribute__((__access__(__read_only__, 2)));

extern int rpmatch(const char *__response)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__warn_unused_result__));
extern int getsubopt(char **__restrict __optionp,
                     char *const *__restrict __tokens,
                     char **__restrict __valuep)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2, 3)))
    __attribute__((__warn_unused_result__));

extern int posix_openpt(int __oflag) __attribute__((__warn_unused_result__));

extern int grantpt(int __fd) __attribute__((__nothrow__, __leaf__));

extern int unlockpt(int __fd) __attribute__((__nothrow__, __leaf__));

extern char *ptsname(int __fd) __attribute__((__nothrow__, __leaf__))
__attribute__((__warn_unused_result__));

extern int ptsname_r(int __fd, char *__buf, size_t __buflen)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)))
    __attribute__((__access__(__write_only__, 2, 3)));

extern int getpt(void);

extern int getloadavg(double __loadavg[], int __nelem)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern char *__realpath_chk(const char *__restrict __name,
                            char *__restrict __resolved, size_t __resolvedlen)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__));
extern char *__realpath_alias(const char *__restrict __name,
                              char *__restrict __resolved) __asm__(""
                                                                   "realpath")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__warn_unused_result__));
extern char *__realpath_chk_warn(const char *__restrict __name,
                                 char *__restrict __resolved,
                                 size_t __resolvedlen) __asm__(""
                                                               "__realpath_chk")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__warn_unused_result__)) __attribute__((
        __warning__("second argument of realpath must be either NULL or at "
                    "least PATH_MAX bytes long buffer")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
__attribute__((__warn_unused_result__)) char *__attribute__((__nothrow__,
                                                             __leaf__))
realpath(const char *__restrict __name, char *__restrict __resolved) {
  size_t sz = __builtin_object_size(__resolved, 2 > 1);

  if (sz == (size_t)-1)
    return __realpath_alias(__name, __resolved);

  if ((((__typeof(4096))0 < (__typeof(4096))-1 ||
        (__builtin_constant_p(4096) && (4096) > 0)) &&
       __builtin_constant_p(
           (((long unsigned int)(4096)) <= (sz) / (sizeof(char)))) &&
       !(((long unsigned int)(4096)) <= (sz) / (sizeof(char)))))
    return __realpath_chk_warn(__name, __resolved, sz);

  return __realpath_chk(__name, __resolved, sz);
}

extern int __ptsname_r_chk(int __fd, char *__buf, size_t __buflen,
                           size_t __nreal)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)))
    __attribute__((__access__(__write_only__, 2, 3)));
extern int __ptsname_r_alias(int __fd, char *__buf,
                             size_t __buflen) __asm__(""
                                                      "ptsname_r")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__nonnull__(2)))
    __attribute__((__access__(__write_only__, 2, 3)));
extern int __ptsname_r_chk_warn(int __fd, char *__buf, size_t __buflen,
                                size_t __nreal) __asm__(""
                                                        "__ptsname_r_chk")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__nonnull__(2)))
    __attribute__((__warning__("ptsname_r called with buflen bigger than "
                               "size of buf")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
    __attribute__((__nothrow__, __leaf__))
    ptsname_r(int __fd, char *__buf, size_t __buflen) {
  return ((((__typeof(__buflen))0 < (__typeof(__buflen))-1 ||
            (__builtin_constant_p(__buflen) && (__buflen) > 0)) &&
           __builtin_constant_p(
               (((long unsigned int)(__buflen)) <=
                (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char)))) &&
           (((long unsigned int)(__buflen)) <=
            (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char))))
              ? __ptsname_r_alias(__fd, __buf, __buflen)
              : ((((__typeof(__buflen))0 < (__typeof(__buflen))-1 ||
                   (__builtin_constant_p(__buflen) && (__buflen) > 0)) &&
                  __builtin_constant_p((((long unsigned int)(__buflen)) <=
                                        (__builtin_object_size(__buf, 2 > 1)) /
                                            (sizeof(char)))) &&
                  !(((long unsigned int)(__buflen)) <=
                    (__builtin_object_size(__buf, 2 > 1)) / (sizeof(char))))
                     ? __ptsname_r_chk_warn(__fd, __buf, __buflen,
                                            __builtin_object_size(__buf, 2 > 1))
                     : __ptsname_r_chk(__fd, __buf, __buflen,
                                       __builtin_object_size(__buf, 2 > 1))))

      ;
}

extern int __wctomb_chk(char *__s, wchar_t __wchar, size_t __buflen)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__));
extern int __wctomb_alias(char *__s, wchar_t __wchar) __asm__(""
                                                              "wctomb")
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
__attribute__((__warn_unused_result__)) int
    __attribute__((__nothrow__, __leaf__)) wctomb(char *__s, wchar_t __wchar) {

  if (__builtin_object_size(__s, 2 > 1) != (size_t)-1 &&
      16 > __builtin_object_size(__s, 2 > 1))
    return __wctomb_chk(__s, __wchar, __builtin_object_size(__s, 2 > 1));
  return __wctomb_alias(__s, __wchar);
}

extern size_t __mbstowcs_chk(wchar_t *__restrict __dst,
                             const char *__restrict __src, size_t __len,
                             size_t __dstlen)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__access__(__write_only__, 1, 3)))
    __attribute__((__access__(__read_only__, 2)));
extern size_t __mbstowcs_alias(wchar_t *__restrict __dst,
                               const char *__restrict __src,
                               size_t __len) __asm__(""
                                                     "mbstowcs")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__access__(__write_only__, 1, 3)))
    __attribute__((__access__(__read_only__, 2)));
extern size_t __mbstowcs_chk_warn(
    wchar_t *__restrict __dst, const char *__restrict __src, size_t __len,
    size_t __dstlen) __asm__(""
                             "__mbstowcs_chk") __attribute__((__nothrow__,
                                                              __leaf__))

__attribute__((__warning__("mbstowcs called with dst buffer smaller than len "
                           "* sizeof (wchar_t)")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
size_t __attribute__((__nothrow__, __leaf__))
mbstowcs(wchar_t *__restrict __dst, const char *__restrict __src, size_t __len)

{
  return (
      (((__typeof(__len))0 < (__typeof(__len))-1 ||
        (__builtin_constant_p(__len) && (__len) > 0)) &&
       __builtin_constant_p(
           (((long unsigned int)(__len)) <=
            (__builtin_object_size(__dst, 2 > 1)) / (sizeof(wchar_t)))) &&
       (((long unsigned int)(__len)) <=
        (__builtin_object_size(__dst, 2 > 1)) / (sizeof(wchar_t))))
          ? __mbstowcs_alias(__dst, __src, __len)
          : ((((__typeof(__len))0 < (__typeof(__len))-1 ||
               (__builtin_constant_p(__len) && (__len) > 0)) &&
              __builtin_constant_p((((long unsigned int)(__len)) <=
                                    (__builtin_object_size(__dst, 2 > 1)) /
                                        (sizeof(wchar_t)))) &&
              !(((long unsigned int)(__len)) <=
                (__builtin_object_size(__dst, 2 > 1)) / (sizeof(wchar_t))))
                 ? __mbstowcs_chk_warn(__dst, __src, __len,
                                       (__builtin_object_size(__dst, 2 > 1)) /
                                           (sizeof(wchar_t)))
                 : __mbstowcs_chk(__dst, __src, __len,
                                  (__builtin_object_size(__dst, 2 > 1)) /
                                      (sizeof(wchar_t)))))

      ;
}

extern size_t __wcstombs_chk(char *__restrict __dst,
                             const wchar_t *__restrict __src, size_t __len,
                             size_t __dstlen)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__access__(__write_only__, 1, 3)))
    __attribute__((__access__(__read_only__, 2)));
extern size_t __wcstombs_alias(char *__restrict __dst,
                               const wchar_t *__restrict __src,
                               size_t __len) __asm__(""
                                                     "wcstombs")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((__access__(__write_only__, 1, 3)))
    __attribute__((__access__(__read_only__, 2)));
extern size_t __wcstombs_chk_warn(char *__restrict __dst,
                                  const wchar_t *__restrict __src, size_t __len,
                                  size_t __dstlen) __asm__(""
                                                           "__wcstombs_chk")
    __attribute__((__nothrow__, __leaf__))

    __attribute__((
        __warning__("wcstombs called with dst buffer smaller than len")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__))
size_t __attribute__((__nothrow__, __leaf__))
wcstombs(char *__restrict __dst, const wchar_t *__restrict __src, size_t __len)

{
  return ((((__typeof(__len))0 < (__typeof(__len))-1 ||
            (__builtin_constant_p(__len) && (__len) > 0)) &&
           __builtin_constant_p(
               (((long unsigned int)(__len)) <=
                (__builtin_object_size(__dst, 2 > 1)) / (sizeof(char)))) &&
           (((long unsigned int)(__len)) <=
            (__builtin_object_size(__dst, 2 > 1)) / (sizeof(char))))
              ? __wcstombs_alias(__dst, __src, __len)
              : ((((__typeof(__len))0 < (__typeof(__len))-1 ||
                   (__builtin_constant_p(__len) && (__len) > 0)) &&
                  __builtin_constant_p((((long unsigned int)(__len)) <=
                                        (__builtin_object_size(__dst, 2 > 1)) /
                                            (sizeof(char)))) &&
                  !(((long unsigned int)(__len)) <=
                    (__builtin_object_size(__dst, 2 > 1)) / (sizeof(char))))
                     ? __wcstombs_chk_warn(__dst, __src, __len,
                                           __builtin_object_size(__dst, 2 > 1))
                     : __wcstombs_chk(__dst, __src, __len,
                                      __builtin_object_size(__dst, 2 > 1))))

      ;
}

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern void *aligned_alloc(size_t alignment, size_t size)
    __attribute__((__malloc__)) __attribute__((__malloc__(free, 1)))

    ;
extern void *calloc(size_t nmemb, size_t size) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1)))

;

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern char *canonicalize_file_name(const char *name)
    __attribute__((__nonnull__(1))) __attribute__((__malloc__))
    __attribute__((__malloc__(free, 1)))

    ;

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern void *malloc(size_t size) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1)))

;

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern void *realloc(void *ptr, size_t size)
    __attribute__((__malloc__(free, 1)))

    ;

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;

extern char const *Version;

enum {
  EXIT_TIMEDOUT = 124,
  EXIT_CANCELED = 125,
  EXIT_CANNOT_INVOKE = 126,
  EXIT_ENOENT = 127
};

extern int volatile exit_failure;

static inline void initialize_exit_failure(int status) {
  if (status != 1)
    exit_failure = status;
}

struct flock {
  short int l_type;
  short int l_whence;

  __off_t l_start;
  __off_t l_len;

  __pid_t l_pid;
};

struct flock64 {
  short int l_type;
  short int l_whence;
  __off64_t l_start;
  __off64_t l_len;
  __pid_t l_pid;
};

struct iovec {
  void *iov_base;
  size_t iov_len;
};
enum __pid_type {
  F_OWNER_TID = 0,
  F_OWNER_PID,
  F_OWNER_PGRP,
  F_OWNER_GID = F_OWNER_PGRP
};

struct f_owner_ex {
  enum __pid_type type;
  __pid_t pid;
};

struct file_handle {
  unsigned int handle_bytes;
  int handle_type;

  unsigned char f_handle[0];
};

extern __ssize_t readahead(int __fd, __off64_t __offset, size_t __count)
    __attribute__((__nothrow__, __leaf__));

extern int sync_file_range(int __fd, __off64_t __offset, __off64_t __count,
                           unsigned int __flags);

extern __ssize_t vmsplice(int __fdout, const struct iovec *__iov,
                          size_t __count, unsigned int __flags);

extern __ssize_t splice(int __fdin, __off64_t *__offin, int __fdout,
                        __off64_t *__offout, size_t __len,
                        unsigned int __flags);

extern __ssize_t tee(int __fdin, int __fdout, size_t __len,
                     unsigned int __flags);

extern int fallocate(int __fd, int __mode, __off_t __offset, __off_t __len);
extern int fallocate64(int __fd, int __mode, __off64_t __offset,
                       __off64_t __len);

extern int name_to_handle_at(int __dfd, const char *__name,
                             struct file_handle *__handle, int *__mnt_id,
                             int __flags)
    __attribute__((__nothrow__, __leaf__));

extern int open_by_handle_at(int __mountdirfd, struct file_handle *__handle,
                             int __flags);

extern int fcntl(int __fd, int __cmd, ...);
extern int fcntl64(int __fd, int __cmd, ...);
extern int open(const char *__file, int __oflag, ...)
    __attribute__((__nonnull__(1)));
extern int open64(const char *__file, int __oflag, ...)
    __attribute__((__nonnull__(1)));
extern int openat(int __fd, const char *__file, int __oflag, ...)
    __attribute__((__nonnull__(2)));
extern int openat64(int __fd, const char *__file, int __oflag, ...)
    __attribute__((__nonnull__(2)));
extern int creat(const char *__file, mode_t __mode)
    __attribute__((__nonnull__(1)));
extern int creat64(const char *__file, mode_t __mode)
    __attribute__((__nonnull__(1)));
extern int posix_fadvise(int __fd, off_t __offset, off_t __len, int __advise)
    __attribute__((__nothrow__, __leaf__));
extern int posix_fadvise64(int __fd, off64_t __offset, off64_t __len,
                           int __advise) __attribute__((__nothrow__, __leaf__));
extern int posix_fallocate(int __fd, off_t __offset, off_t __len);
extern int posix_fallocate64(int __fd, off64_t __offset, off64_t __len);

extern int __open_2(const char *__path, int __oflag)
    __attribute__((__nonnull__(1)));
extern int __open_alias(const char *__path, int __oflag, ...) __asm__(""
                                                                      "open")
    __attribute__((__nonnull__(1)));

extern void __open_too_many_args(void) __attribute__((
    __error__("open can be called either with 2 or 3 arguments, not more")));
extern void __open_missing_mode(void) __attribute__((__error__(
    "open with O_CREAT or O_TMPFILE in second argument needs 3 arguments")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
open(const char *__path, int __oflag, ...) {
  if (__builtin_va_arg_pack_len() > 1)
    __open_too_many_args();

  if (__builtin_constant_p(__oflag)) {
    if ((((__oflag)&0100) != 0 ||
         ((__oflag) & (020000000 | 0200000)) == (020000000 | 0200000)) &&
        __builtin_va_arg_pack_len() < 1) {
      __open_missing_mode();
      return __open_2(__path, __oflag);
    }
    return __open_alias(__path, __oflag, __builtin_va_arg_pack());
  }

  if (__builtin_va_arg_pack_len() < 1)
    return __open_2(__path, __oflag);

  return __open_alias(__path, __oflag, __builtin_va_arg_pack());
}

extern int __open64_2(const char *__path, int __oflag)
    __attribute__((__nonnull__(1)));
extern int __open64_alias(const char *__path, int __oflag,
                          ...) __asm__(""
                                       "open64")
    __attribute__((__nonnull__(1)));
extern void __open64_too_many_args(void) __attribute__((
    __error__("open64 can be called either with 2 or 3 arguments, not more")));
extern void __open64_missing_mode(void) __attribute__((__error__(
    "open64 with O_CREAT or O_TMPFILE in second argument needs 3 arguments")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
open64(const char *__path, int __oflag, ...) {
  if (__builtin_va_arg_pack_len() > 1)
    __open64_too_many_args();

  if (__builtin_constant_p(__oflag)) {
    if ((((__oflag)&0100) != 0 ||
         ((__oflag) & (020000000 | 0200000)) == (020000000 | 0200000)) &&
        __builtin_va_arg_pack_len() < 1) {
      __open64_missing_mode();
      return __open64_2(__path, __oflag);
    }
    return __open64_alias(__path, __oflag, __builtin_va_arg_pack());
  }

  if (__builtin_va_arg_pack_len() < 1)
    return __open64_2(__path, __oflag);

  return __open64_alias(__path, __oflag, __builtin_va_arg_pack());
}

extern int __openat_2(int __fd, const char *__path, int __oflag)
    __attribute__((__nonnull__(2)));
extern int __openat_alias(int __fd, const char *__path, int __oflag,
                          ...) __asm__(""
                                       "openat")

    __attribute__((__nonnull__(2)));
extern void __openat_too_many_args(void) __attribute__((
    __error__("openat can be called either with 3 or 4 arguments, not more")));
extern void __openat_missing_mode(void) __attribute__((__error__(
    "openat with O_CREAT or O_TMPFILE in third argument needs 4 arguments")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
openat(int __fd, const char *__path, int __oflag, ...) {
  if (__builtin_va_arg_pack_len() > 1)
    __openat_too_many_args();

  if (__builtin_constant_p(__oflag)) {
    if ((((__oflag)&0100) != 0 ||
         ((__oflag) & (020000000 | 0200000)) == (020000000 | 0200000)) &&
        __builtin_va_arg_pack_len() < 1) {
      __openat_missing_mode();
      return __openat_2(__fd, __path, __oflag);
    }
    return __openat_alias(__fd, __path, __oflag, __builtin_va_arg_pack());
  }

  if (__builtin_va_arg_pack_len() < 1)
    return __openat_2(__fd, __path, __oflag);

  return __openat_alias(__fd, __path, __oflag, __builtin_va_arg_pack());
}

extern int __openat64_2(int __fd, const char *__path, int __oflag)
    __attribute__((__nonnull__(2)));
extern int __openat64_alias(int __fd, const char *__path, int __oflag,
                            ...) __asm__(""
                                         "openat64")

    __attribute__((__nonnull__(2)));
extern void __openat64_too_many_args(void) __attribute__((__error__(
    "openat64 can be called either with 3 or 4 arguments, not more")));
extern void __openat64_missing_mode(void) __attribute__((__error__(
    "openat64 with O_CREAT or O_TMPFILE in third argument needs 4 arguments")));

extern __inline __attribute__((__always_inline__))
__attribute__((__gnu_inline__)) __attribute__((__artificial__)) int
openat64(int __fd, const char *__path, int __oflag, ...) {
  if (__builtin_va_arg_pack_len() > 1)
    __openat64_too_many_args();

  if (__builtin_constant_p(__oflag)) {
    if ((((__oflag)&0100) != 0 ||
         ((__oflag) & (020000000 | 0200000)) == (020000000 | 0200000)) &&
        __builtin_va_arg_pack_len() < 1) {
      __openat64_missing_mode();
      return __openat64_2(__fd, __path, __oflag);
    }
    return __openat64_alias(__fd, __path, __oflag, __builtin_va_arg_pack());
  }

  if (__builtin_va_arg_pack_len() < 1)
    return __openat64_2(__fd, __path, __oflag);

  return __openat64_alias(__fd, __path, __oflag, __builtin_va_arg_pack());
}

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int rpl_fcntl(int fd, int action, ...);
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;

enum { O_PATHSEARCH = 010000000 };

struct dirent {

  __ino_t d_ino;
  __off_t d_off;

  unsigned short int d_reclen;
  unsigned char d_type;
  char d_name[256];
};

struct dirent64 {
  __ino64_t d_ino;
  __off64_t d_off;
  unsigned short int d_reclen;
  unsigned char d_type;
  char d_name[256];
};
enum {
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

extern DIR *opendir(const char *__name) __attribute__((__nonnull__(1)));

extern DIR *fdopendir(int __fd);

extern int closedir(DIR *__dirp) __attribute__((__nonnull__(1)));
extern struct dirent *readdir(DIR *__dirp) __attribute__((__nonnull__(1)));
extern struct dirent64 *readdir64(DIR *__dirp) __attribute__((__nonnull__(1)));
extern int readdir_r(DIR *__restrict __dirp, struct dirent *__restrict __entry,
                     struct dirent **__restrict __result)
    __attribute__((__nonnull__(1, 2, 3))) __attribute__((__deprecated__));
extern int readdir64_r(DIR *__restrict __dirp,
                       struct dirent64 *__restrict __entry,
                       struct dirent64 **__restrict __result)
    __attribute__((__nonnull__(1, 2, 3))) __attribute__((__deprecated__));

extern void rewinddir(DIR *__dirp) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

extern void seekdir(DIR *__dirp, long int __pos)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern long int telldir(DIR *__dirp) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

extern int dirfd(DIR *__dirp) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int scandir(const char *__restrict __dir,
                   struct dirent ***__restrict __namelist,
                   int (*__selector)(const struct dirent *),
                   int (*__cmp)(const struct dirent **, const struct dirent **))
    __attribute__((__nonnull__(1, 2)));
extern int scandir64(const char *__restrict __dir,
                     struct dirent64 ***__restrict __namelist,
                     int (*__selector)(const struct dirent64 *),
                     int (*__cmp)(const struct dirent64 **,
                                  const struct dirent64 **))
    __attribute__((__nonnull__(1, 2)));
extern int scandirat(int __dfd, const char *__restrict __dir,
                     struct dirent ***__restrict __namelist,
                     int (*__selector)(const struct dirent *),
                     int (*__cmp)(const struct dirent **,
                                  const struct dirent **))
    __attribute__((__nonnull__(2, 3)));
extern int scandirat64(int __dfd, const char *__restrict __dir,
                       struct dirent64 ***__restrict __namelist,
                       int (*__selector)(const struct dirent64 *),
                       int (*__cmp)(const struct dirent64 **,
                                    const struct dirent64 **))
    __attribute__((__nonnull__(2, 3)));

extern int alphasort(const struct dirent **__e1, const struct dirent **__e2)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern int alphasort64(const struct dirent64 **__e1,
                       const struct dirent64 **__e2)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern __ssize_t getdirentries(int __fd, char *__restrict __buf,
                               size_t __nbytes, __off_t *__restrict __basep)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 4)));
extern __ssize_t getdirentries64(int __fd, char *__restrict __buf,
                                 size_t __nbytes, __off64_t *__restrict __basep)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 4)));

extern int versionsort(const struct dirent **__e1, const struct dirent **__e2)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern int versionsort64(const struct dirent64 **__e1,
                         const struct dirent64 **__e2)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

extern __ssize_t getdents64(int __fd, void *__buffer, size_t __length)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern DIR *opendir(const char *dir_name) __attribute__((__nonnull__(1)))
__attribute__((__malloc__)) __attribute__((__malloc__(closedir, 1)))

;

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern DIR *fdopendir(int fd) __attribute__((__malloc__))
__attribute__((__malloc__(closedir, 1)))

;

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;

enum { NOT_AN_INODE_NUMBER = 0 };

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

typedef struct {
  long int quot;
  long int rem;
} imaxdiv_t;
extern intmax_t imaxabs(intmax_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));

extern imaxdiv_t imaxdiv(intmax_t __numer, intmax_t __denom)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));

extern intmax_t strtoimax(const char *__restrict __nptr,
                          char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__));

extern uintmax_t strtoumax(const char *__restrict __nptr,
                           char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__));

extern intmax_t wcstoimax(const __gwchar_t *__restrict __nptr,
                          __gwchar_t **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__));

extern uintmax_t wcstoumax(const __gwchar_t *__restrict __nptr,
                           __gwchar_t **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__));

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;

enum { TIMESPEC_HZ = 1000000000 };
enum { LOG10_TIMESPEC_HZ = 9 };

enum { TIMESPEC_RESOLUTION = TIMESPEC_HZ };
enum { LOG10_TIMESPEC_RESOLUTION = LOG10_TIMESPEC_HZ };

inline struct timespec make_timespec(time_t s, long int ns) {
  struct timespec r;
  r.tv_sec = s;
  r.tv_nsec = ns;
  return r;
}

inline int __attribute__((__pure__))
timespec_cmp(struct timespec a, struct timespec b) {
  return 2 * (((a.tv_sec) > (b.tv_sec)) - ((a.tv_sec) < (b.tv_sec))) +
         (((a.tv_nsec) > (b.tv_nsec)) - ((a.tv_nsec) < (b.tv_nsec)));
}

inline int __attribute__((__pure__)) timespec_sign(struct timespec a) {
  return (((a.tv_sec) > (0)) - ((a.tv_sec) < (0))) + (!a.tv_sec & !!a.tv_nsec);
}

struct timespec timespec_add(struct timespec, struct timespec)
    __attribute__((__const__));
struct timespec timespec_sub(struct timespec, struct timespec)
    __attribute__((__const__));
struct timespec dtotimespec(double) __attribute__((__const__));

inline double timespectod(struct timespec a) {
  return a.tv_sec + a.tv_nsec / 1e9;
}

long int gettime_res(void);
struct timespec current_timespec(void);
void gettime(struct timespec *) __attribute__((__nonnull__(1)));
int settime(struct timespec const *) __attribute__((__nonnull__(1)));

enum {
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
extern const unsigned short int **__ctype_b_loc(void)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern const __int32_t **__ctype_tolower_loc(void)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern const __int32_t **__ctype_toupper_loc(void)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern int isalnum(int) __attribute__((__nothrow__, __leaf__));
extern int isalpha(int) __attribute__((__nothrow__, __leaf__));
extern int iscntrl(int) __attribute__((__nothrow__, __leaf__));
extern int isdigit(int) __attribute__((__nothrow__, __leaf__));
extern int islower(int) __attribute__((__nothrow__, __leaf__));
extern int isgraph(int) __attribute__((__nothrow__, __leaf__));
extern int isprint(int) __attribute__((__nothrow__, __leaf__));
extern int ispunct(int) __attribute__((__nothrow__, __leaf__));
extern int isspace(int) __attribute__((__nothrow__, __leaf__));
extern int isupper(int) __attribute__((__nothrow__, __leaf__));
extern int isxdigit(int) __attribute__((__nothrow__, __leaf__));

extern int tolower(int __c) __attribute__((__nothrow__, __leaf__));

extern int toupper(int __c) __attribute__((__nothrow__, __leaf__));

extern int isblank(int) __attribute__((__nothrow__, __leaf__));

extern int isctype(int __c, int __mask) __attribute__((__nothrow__, __leaf__));

extern int isascii(int __c) __attribute__((__nothrow__, __leaf__));

extern int toascii(int __c) __attribute__((__nothrow__, __leaf__));

extern int _toupper(int) __attribute__((__nothrow__, __leaf__));
extern int _tolower(int) __attribute__((__nothrow__, __leaf__));
extern int isalnum_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int isalpha_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int iscntrl_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int isdigit_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int islower_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int isgraph_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int isprint_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int ispunct_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int isspace_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int isupper_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int isxdigit_l(int, locale_t) __attribute__((__nothrow__, __leaf__));

extern int isblank_l(int, locale_t) __attribute__((__nothrow__, __leaf__));

extern int __tolower_l(int __c, locale_t __l)
    __attribute__((__nothrow__, __leaf__));
extern int tolower_l(int __c, locale_t __l)
    __attribute__((__nothrow__, __leaf__));

extern int __toupper_l(int __c, locale_t __l)
    __attribute__((__nothrow__, __leaf__));
extern int toupper_l(int __c, locale_t __l)
    __attribute__((__nothrow__, __leaf__));

static inline unsigned char to_uchar(char ch) { return ch; }

static inline _Bool

field_sep(unsigned char ch) {
  return ((*__ctype_b_loc())[(int)((ch))] & (unsigned short int)_ISblank) ||
         ch == '\n';
}

struct lconv {

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

extern char *setlocale(int __category, const char *__locale)
    __attribute__((__nothrow__, __leaf__));

extern struct lconv *localeconv(void) __attribute__((__nothrow__, __leaf__));
extern locale_t newlocale(int __category_mask, const char *__locale,
                          locale_t __base)
    __attribute__((__nothrow__, __leaf__));
extern locale_t duplocale(locale_t __dataset)
    __attribute__((__nothrow__, __leaf__));

extern void freelocale(locale_t __dataset)
    __attribute__((__nothrow__, __leaf__));

extern locale_t uselocale(locale_t __dataset)
    __attribute__((__nothrow__, __leaf__));

extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int setlocale_null_r(int category, char *buf, size_t bufsize)
    __attribute__((__nonnull__(2)));
extern const char *setlocale_null(int category);

extern char *gettext(const char *__msgid) __attribute__((__nothrow__, __leaf__))
__attribute__((__format_arg__(1)));

extern char *dgettext(const char *__domainname, const char *__msgid)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__format_arg__(2)));
extern char *__dgettext(const char *__domainname, const char *__msgid)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__format_arg__(2)));

extern char *dcgettext(const char *__domainname, const char *__msgid,
                       int __category) __attribute__((__nothrow__, __leaf__))
__attribute__((__format_arg__(2)));
extern char *__dcgettext(const char *__domainname, const char *__msgid,
                         int __category) __attribute__((__nothrow__, __leaf__))
__attribute__((__format_arg__(2)));

extern char *ngettext(const char *__msgid1, const char *__msgid2,
                      unsigned long int __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__format_arg__(1)))
    __attribute__((__format_arg__(2)));

extern char *dngettext(const char *__domainname, const char *__msgid1,
                       const char *__msgid2, unsigned long int __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__format_arg__(2)))
    __attribute__((__format_arg__(3)));

extern char *dcngettext(const char *__domainname, const char *__msgid1,
                        const char *__msgid2, unsigned long int __n,
                        int __category) __attribute__((__nothrow__, __leaf__))
__attribute__((__format_arg__(2))) __attribute__((__format_arg__(3)));

extern char *textdomain(const char *__domainname)
    __attribute__((__nothrow__, __leaf__));

extern char *bindtextdomain(const char *__domainname, const char *__dirname)
    __attribute__((__nothrow__, __leaf__));

extern char *bind_textdomain_codeset(const char *__domainname,
                                     const char *__codeset)
    __attribute__((__nothrow__, __leaf__));

__inline

    static const char *
    pgettext_aux(const char *domain, const char *msg_ctxt_id, const char *msgid,
                 int category) {
  const char *translation = dcgettext(domain, msg_ctxt_id, category);
  if (translation == msg_ctxt_id)
    return msgid;
  else
    return translation;
}

__inline

    static const char *
    npgettext_aux(const char *domain, const char *msg_ctxt_id,
                  const char *msgid, const char *msgid_plural,
                  unsigned long int n, int category) {
  const char *translation =
      dcngettext(domain, msg_ctxt_id, msgid_plural, n, category);
  if (translation == msg_ctxt_id || translation == msgid_plural)
    return (n == 1 ? msgid : msgid_plural);
  else
    return translation;
}

__inline

    static const char *
    dcpgettext_expr(const char *domain, const char *msgctxt, const char *msgid,
                    int category) {
  size_t msgctxt_len = strlen(msgctxt) + 1;
  size_t msgid_len = strlen(msgid) + 1;
  const char *translation;

  char buf[1024];
  char *msg_ctxt_id = (msgctxt_len + msgid_len <= sizeof(buf)
                           ? buf
                           : (char *)malloc(msgctxt_len + msgid_len));
  if (msg_ctxt_id != ((void *)0))

  {
    int found_translation;
    memcpy(msg_ctxt_id, msgctxt, msgctxt_len - 1);
    msg_ctxt_id[msgctxt_len - 1] = '\004';
    memcpy(msg_ctxt_id + msgctxt_len, msgid, msgid_len);
    translation = dcgettext(domain, msg_ctxt_id, category);
    found_translation = (translation != msg_ctxt_id);

    if (msg_ctxt_id != buf)
      free(msg_ctxt_id);

    if (found_translation)
      return translation;
  }
  return msgid;
}

__inline

    static const char *
    dcnpgettext_expr(const char *domain, const char *msgctxt, const char *msgid,
                     const char *msgid_plural, unsigned long int n,
                     int category) {
  size_t msgctxt_len = strlen(msgctxt) + 1;
  size_t msgid_len = strlen(msgid) + 1;
  const char *translation;

  char buf[1024];
  char *msg_ctxt_id = (msgctxt_len + msgid_len <= sizeof(buf)
                           ? buf
                           : (char *)malloc(msgctxt_len + msgid_len));
  if (msg_ctxt_id != ((void *)0))

  {
    int found_translation;
    memcpy(msg_ctxt_id, msgctxt, msgctxt_len - 1);
    msg_ctxt_id[msgctxt_len - 1] = '\004';
    memcpy(msg_ctxt_id + msgctxt_len, msgid, msgid_len);
    translation = dcngettext(domain, msg_ctxt_id, msgid_plural, n, category);
    found_translation =
        !(translation == msg_ctxt_id || translation == msgid_plural);

    if (msg_ctxt_id != buf)
      free(msg_ctxt_id);

    if (found_translation)
      return translation;
  }
  return (n == 1 ? msgid : msgid_plural);
}
static inline unsigned long int select_plural(uintmax_t n) {

  enum { PLURAL_REDUCER = 1000000 };
  return (n <= (0x7fffffffffffffffL * 2UL + 1UL)
              ? n
              : n % PLURAL_REDUCER + PLURAL_REDUCER);
}

typedef ptrdiff_t idx_t;

_Noreturn void xalloc_die(void);

void *xmalloc(size_t s) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1))) __attribute__((__alloc_size__(1)))
__attribute__((__returns_nonnull__));
void *ximalloc(idx_t s) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1))) __attribute__((__alloc_size__(1)))
__attribute__((__returns_nonnull__));
void *xinmalloc(idx_t n, idx_t s) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1))) __attribute__((__alloc_size__(1, 2)))
__attribute__((__returns_nonnull__));
void *xzalloc(size_t s) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1))) __attribute__((__alloc_size__(1)))
__attribute__((__returns_nonnull__));
void *xizalloc(idx_t s) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1))) __attribute__((__alloc_size__(1)))
__attribute__((__returns_nonnull__));
void *xcalloc(size_t n, size_t s) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1))) __attribute__((__alloc_size__(1, 2)))
__attribute__((__returns_nonnull__));
void *xicalloc(idx_t n, idx_t s) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1))) __attribute__((__alloc_size__(1, 2)))
__attribute__((__returns_nonnull__));
void *xrealloc(void *p, size_t s) __attribute__((__alloc_size__(2)));
void *xirealloc(void *p, idx_t s) __attribute__((__alloc_size__(2)))
__attribute__((__returns_nonnull__));
void *xreallocarray(void *p, size_t n, size_t s)
    __attribute__((__alloc_size__(2, 3)));
void *xireallocarray(void *p, idx_t n, idx_t s)
    __attribute__((__alloc_size__(2, 3))) __attribute__((__returns_nonnull__));
void *x2realloc(void *p, size_t *ps) __attribute__((__returns_nonnull__));
void *x2nrealloc(void *p, size_t *pn, size_t s)
    __attribute__((__returns_nonnull__));
void *xpalloc(void *pa, idx_t *pn, idx_t n_incr_min, ptrdiff_t n_max, idx_t s)
    __attribute__((__returns_nonnull__));
void *xmemdup(void const *p, size_t s) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1))) __attribute__((__alloc_size__(2)))
__attribute__((__returns_nonnull__));
void *ximemdup(void const *p, idx_t s) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1))) __attribute__((__alloc_size__(2)))
__attribute__((__returns_nonnull__));
char *ximemdup0(void const *p, idx_t s) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1))) __attribute__((__returns_nonnull__));
char *xstrdup(char const *str) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1))) __attribute__((__returns_nonnull__));
void *xnmalloc(size_t n, size_t s) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1))) __attribute__((__alloc_size__(1, 2)))
__attribute__((__returns_nonnull__));

inline void *xnrealloc(void *p, size_t n, size_t s)
    __attribute__((__alloc_size__(2, 3)));
inline void *xnrealloc(void *p, size_t n, size_t s) {
  return xreallocarray(p, n, s);
}

char *xcharalloc(size_t n) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1))) __attribute__((__alloc_size__(1)))
__attribute__((__returns_nonnull__));

extern char *last_component(char const *filename) __attribute__((__pure__));

extern size_t base_len(char const *filename) __attribute__((__pure__));
char *base_name(char const *file) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1))) __attribute__((__returns_nonnull__));
char *dir_name(char const *file) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1))) __attribute__((__returns_nonnull__));

char *mdir_name(char const *file) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1)));
size_t dir_len(char const *file) __attribute__((__pure__));

_Bool strip_trailing_slashes(char *file);

_Noreturn void openat_restore_fail(int);
_Noreturn void openat_save_fail(int);
inline int chownat(int fd, char const *file, uid_t owner, gid_t group) {
  return fchownat(fd, file, owner, group, 0);
}

inline int lchownat(int fd, char const *file, uid_t owner, gid_t group) {
  return fchownat(fd, file, owner, group, 0x100);
}
inline int chmodat(int fd, char const *file, mode_t mode) {
  return fchmodat(fd, file, mode, 0);
}

inline int lchmodat(int fd, char const *file, mode_t mode) {
  return fchmodat(fd, file, mode, 0x100);
}

static inline _Bool

dot_or_dotdot(char const *file_name) {
  if (file_name[0] == '.') {
    char sep = file_name[(file_name[1] == '.') + 1];
    return (!sep || ((sep) == '/'));
  } else
    return 0;
}

static inline struct dirent const *readdir_ignoring_dot_and_dotdot(DIR *dirp) {
  while (1) {
    struct dirent const *dp = readdir(dirp);
    if (dp == ((void *)0) || !dot_or_dotdot(dp->d_name))
      return dp;
  }
}

static inline _Bool

is_empty_dir(int fd_cwd, char const *dir) {
  DIR *dirp;
  struct dirent const *dp;
  int saved_errno;
  int fd = openat(fd_cwd, dir,
                  (00 | 0200000

                   | 0400 | 0400000 | 04000));

  if (fd < 0)
    return 0;

  dirp = fdopendir(fd);
  if (dirp == ((void *)0)) {
    close(fd);
    return 0;
  }

  (*__errno_location()) = 0;
  dp = readdir_ignoring_dot_and_dotdot(dirp);
  saved_errno = (*__errno_location());
  closedir(dirp);

  (*__errno_location()) = saved_errno;
  if (dp != ((void *)0))
    return 0;
  return saved_errno == 0 ? 1 : 0;
}

enum {
  GETOPT_HELP_CHAR = ((-0x7f - 1) - 2),
  GETOPT_VERSION_CHAR = ((-0x7f - 1) - 3)
};
void close_stdin_set_file_name(const char *file);
void close_stdin(void);
void close_stdout_set_file_name(const char *file);
void close_stdout_set_ignore_EPIPE(_Bool ignore);
void close_stdout(void);

extern const char version_etc_copyright[];
extern void version_etc_arn(FILE *stream, const char *command_name,
                            const char *package, const char *version,
                            const char *const *authors, size_t n_authors);

extern void version_etc_ar(FILE *stream, const char *command_name,
                           const char *package, const char *version,
                           const char *const *authors);

extern void version_etc_va(FILE *stream, const char *command_name,
                           const char *package, const char *version,
                           va_list authors);

extern void version_etc(FILE *stream, const char *command_name,
                        const char *package, const char *version, ...)
    __attribute__((__sentinel__(0)));

extern void unused__emit_bug_reporting_address(void);

extern const char *proper_name(const char *name);

extern const char *proper_name_utf8(const char *name_ascii,
                                    const char *name_utf8);

extern const char *program_name;

extern void set_program_name(const char *argv0);
__attribute__((__const__)) static inline size_t gcd(size_t u, size_t v) {
  do {
    size_t t = u % v;
    u = v;
    v = t;
  } while (v);

  return u;
}

__attribute__((__const__)) static inline size_t lcm(size_t u, size_t v) {
  return u * (v / gcd(u, v));
}

static inline void *ptr_align(void const *ptr, size_t alignment) {
  char const *p0 = ptr;
  char const *p1 = p0 + alignment - 1;
  return (void *)(p1 - (size_t)p1 % alignment);
}

__attribute__((__pure__)) static inline _Bool

is_nul(void const *buf, size_t length) {
  const unsigned char *p = buf;
  unsigned char word;

  if (!length)
    return 1;

  while (__builtin_expect((length & (sizeof word - 1)), 0)) {
    if (*p)
      return 0;
    p++;
    length--;
    if (!length)
      return 1;
  }

  for (;;) {
    memcpy(&word, p, sizeof word);
    if (word)
      return 0;
    p += sizeof word;
    length -= sizeof word;
    if (!length)
      return 1;
    if (__builtin_expect((length & 15), 0) == 0)
      break;
  }

  return memcmp(buf, p, length) == 0;
}
static inline void emit_stdin_note(void) {
  fputs_unlocked(
      dcgettext(((void *)0),
                "\nWith no FILE, or when FILE is -, read standard input.\n", 5),
      stdout)

      ;
}
static inline void emit_mandatory_arg_note(void) {
  fputs_unlocked(dcgettext(((void *)0),
                           "\nMandatory arguments to long options are "
                           "mandatory for short options too.\n",
                           5),
                 stdout)

      ;
}

static inline void emit_size_note(void) {
  fputs_unlocked(
      dcgettext(((void *)0),
                "\nThe SIZE argument is an integer and optional unit (example: "
                "10K is 10*1024).\nUnits are K,M,G,T,P,E,Z,Y (powers of 1024) "
                "or KB,MB,... (powers of 1000).\nBinary prefixes can be used, "
                "too: KiB=K, MiB=M, and so on.\n",
                5),
      stdout)

      ;
}

static inline void emit_blocksize_note(char const *program) {
  printf(dcgettext(((void *)0),
                   "\nDisplay values are in units of the first available SIZE "
                   "from --block-size,\nand the %s_BLOCK_SIZE, BLOCK_SIZE and "
                   "BLOCKSIZE environment variables.\nOtherwise, units default "
                   "to 1024 bytes (or 512 if POSIXLY_CORRECT is set).\n",
                   5)

             ,
         program);
}

static inline void emit_backup_suffix_note(void) {
  fputs_unlocked(
      dcgettext(
          ((void *)0),
          "\nThe backup suffix is '~', unless set with --suffix or "
          "SIMPLE_BACKUP_SUFFIX.\nThe version control method may be selected "
          "via the --backup option or through\nthe VERSION_CONTROL environment "
          "variable.  Here are the values:\n\n",
          5),
      stdout)

      ;
  fputs_unlocked(
      dcgettext(((void *)0),
                "  none, off       never make backups (even if --backup is "
                "given)\n  numbered, t     make numbered backups\n  existing, "
                "nil   numbered if numbered backups exist, simple otherwise\n  "
                "simple, never   always make simple backups\n",
                5),
      stdout)

      ;
}

static inline void emit_ancillary_info(char const *program) {
  struct infomap {
    char const *program;
    char const *node;
  } const infomap[] = {
      {"[", "test invocation"},        {"coreutils", "Multi-call invocation"},
      {"sha224sum", "sha2 utilities"}, {"sha256sum", "sha2 utilities"},
      {"sha384sum", "sha2 utilities"}, {"sha512sum", "sha2 utilities"},
      {((void *)0), ((void *)0)}};

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && !(strcmp(program, map_prog->program) == 0))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf(dcgettext(((void *)0), "\n%s online help: <%s>\n", 5), "GNU coreutils",
         "https://www.gnu.org/software/coreutils/");

  char const *lc_messages = setlocale(5, ((void *)0));
  if (lc_messages && strncmp(lc_messages,
                             ""
                             "en_"
                             "",
                             sizeof("en_") - 1)) {

    fputs_unlocked(dcgettext(((void *)0),
                             "Report any translation bugs to "
                             "<https://translationproject.org/team/>\n",
                             5),
                   stdout);
  }

  char const *url_program = (strcmp(program, "[") == 0) ? "test" : program;
  printf(dcgettext(((void *)0), "Full documentation <%s%s>\n", 5),
         "https://www.gnu.org/software/coreutils/", url_program);
  printf(dcgettext(((void *)0),
                   "or available locally via: info '(coreutils) %s%s'\n", 5),
         node, node == program ? " invocation" : "");
}

char *imaxtostr(intmax_t, char *);
char *inttostr(int, char *);
char *offtostr(off_t, char *);
char *uinttostr(unsigned int, char *);
char *umaxtostr(uintmax_t, char *);

static inline char *timetostr(time_t t, char *buf) {
  return ((!((time_t)0 < (time_t)-1)) ? imaxtostr(t, buf) : umaxtostr(t, buf));
}

static inline char *bad_cast(char const *s) { return (char *)s; }

static inline _Bool

usable_st_size(struct stat const *sb) {
  return (((((sb->st_mode)) & 0170000) == (0100000)) ||
          ((((sb->st_mode)) & 0170000) == (0120000))

          || ((sb)->st_mode - (sb)->st_mode) || 0);
}

_Noreturn void usage(int status);
static inline char *stzncpy(char *__restrict__ dest,
                            char const *__restrict__ src, size_t len) {
  char const *src_end = src + len;
  while (src < src_end && *src)
    *dest++ = *src++;
  *dest = 0;
  return dest;
}
static inline _Bool

is_ENOTSUP(int err) {
  return err == 95 || (95 != 95 && err == 95);
}

enum quoting_style {
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

enum quoting_flags {

  QA_ELIDE_NULL_BYTES = 0x01,

  QA_ELIDE_OUTER_QUOTES = 0x02,

  QA_SPLIT_TRIGRAPHS = 0x04
};

extern char const *const quoting_style_args[];
extern enum quoting_style const quoting_style_vals[];

struct quoting_options;

struct quoting_options *clone_quoting_options(struct quoting_options *o)
    __attribute__((__malloc__)) __attribute__((__malloc__(free, 1)))
    __attribute__((__returns_nonnull__));

enum quoting_style get_quoting_style(struct quoting_options const *o);

void set_quoting_style(struct quoting_options *o, enum quoting_style s);
int set_char_quoting(struct quoting_options *o, char c, int i);

int set_quoting_flags(struct quoting_options *o, int i);
void set_custom_quoting(struct quoting_options *o, char const *left_quote,
                        char const *right_quote);
size_t quotearg_buffer(char *__restrict__ buffer, size_t buffersize,
                       char const *arg, size_t argsize,
                       struct quoting_options const *o);

char *quotearg_alloc(char const *arg, size_t argsize,
                     struct quoting_options const *o)
    __attribute__((__malloc__)) __attribute__((__malloc__(free, 1)))
    __attribute__((__returns_nonnull__));

char *quotearg_alloc_mem(char const *arg, size_t argsize, size_t *size,
                         struct quoting_options const *o)
    __attribute__((__malloc__)) __attribute__((__malloc__(free, 1)))
    __attribute__((__returns_nonnull__));
char *quotearg_n(int n, char const *arg);

char *quotearg(char const *arg);

char *quotearg_n_mem(int n, char const *arg, size_t argsize);

char *quotearg_mem(char const *arg, size_t argsize);

char *quotearg_n_style(int n, enum quoting_style s, char const *arg);

char *quotearg_n_style_mem(int n, enum quoting_style s, char const *arg,
                           size_t argsize);

char *quotearg_style(enum quoting_style s, char const *arg);

char *quotearg_style_mem(enum quoting_style s, char const *arg, size_t argsize);

char *quotearg_char(char const *arg, char ch);

char *quotearg_char_mem(char const *arg, size_t argsize, char ch);

char *quotearg_colon(char const *arg);

char *quotearg_colon_mem(char const *arg, size_t argsize);

char *quotearg_n_style_colon(int n, enum quoting_style s, char const *arg);

char *quotearg_n_custom(int n, char const *left_quote, char const *right_quote,
                        char const *arg);

char *quotearg_n_custom_mem(int n, char const *left_quote,
                            char const *right_quote, char const *arg,
                            size_t argsize);

char *quotearg_custom(char const *left_quote, char const *right_quote,
                      char const *arg);

char *quotearg_custom_mem(char const *left_quote, char const *right_quote,
                          char const *arg, size_t argsize);

void quotearg_free(void);

extern int fnmatch(const char *__pattern, const char *__name, int __flags);

_Bool acl_errno_valid(int) __attribute__((__const__));
int file_has_acl(char const *, struct stat const *);
int qset_acl(char const *, int, mode_t);
int set_acl(char const *, int, mode_t);
int qcopy_acl(char const *, int, char const *, int, mode_t);
int copy_acl(char const *, int, char const *, int, mode_t);
int chmod_or_fchmod(char const *, int, mode_t);

extern struct quoting_options quote_quoting_options;

char const *quote_n_mem(int n, char const *arg, size_t argsize);

char const *quote_mem(char const *arg, size_t argsize);

char const *quote_n(int n, char const *arg);

char const *quote(char const *arg);
ptrdiff_t argmatch(char const *arg, char const *const *arglist,
                   void const *vallist, size_t valsize)
    __attribute__((__pure__));

ptrdiff_t argmatch_exact(char const *arg, char const *const *arglist)
    __attribute__((__pure__));
typedef void (*argmatch_exit_fn)(void);
extern argmatch_exit_fn argmatch_die;

void argmatch_invalid(char const *context, char const *value,
                      ptrdiff_t problem);
void argmatch_valid(char const *const *arglist, void const *vallist,
                    size_t valsize);
ptrdiff_t __xargmatch_internal(char const *context, char const *arg,
                               char const *const *arglist, void const *vallist,
                               size_t valsize, argmatch_exit_fn exit_fn,

                               _Bool allow_abbreviation);
char const *argmatch_to_argument(void const *value, char const *const *arglist,
                                 void const *vallist, size_t valsize)
    __attribute__((__pure__));
extern int c_strcasecmp(const char *s1, const char *s2)
    __attribute__((__pure__));

extern int c_strncasecmp(const char *s1, const char *s2, size_t n)
    __attribute__((__pure__));

struct dev_ino {
  ino_t st_ino;
  dev_t st_dev;
};

extern void error(int __status, int __errnum, const char *__format, ...)

    __attribute__((__format__(__gnu_printf__, 3, 4)))

    ;

extern void error_at_line(int __status, int __errnum, const char *__fname,
                          unsigned int __lineno, const char *__format, ...)

    __attribute__((__format__(__gnu_printf__, 5, 6)))

    ;

extern void (*error_print_progname)(void);

extern unsigned int error_message_count;

extern int error_one_per_line;

char *file_name_concat(char const *dir, char const *base, char **base_in_result)
    __attribute__((__malloc__)) __attribute__((__malloc__(free, 1)))
    __attribute__((__returns_nonnull__));

char *mfile_name_concat(char const *dir, char const *base,
                        char **base_in_result) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1)));
extern _Bool hard_locale(int category);

struct hash_tuning {

  float shrink_threshold;
  float shrink_factor;
  float growth_threshold;
  float growth_factor;

  _Bool is_n_buckets;
};

typedef struct hash_tuning Hash_tuning;

struct hash_table;

typedef struct hash_table Hash_table;
extern size_t hash_get_n_buckets(const Hash_table *table)
    __attribute__((__pure__));

extern size_t hash_get_n_buckets_used(const Hash_table *table)
    __attribute__((__pure__));

extern size_t hash_get_n_entries(const Hash_table *table)
    __attribute__((__pure__));

extern size_t hash_get_max_bucket_length(const Hash_table *table)
    __attribute__((__pure__));

extern _Bool hash_table_ok(const Hash_table *table) __attribute__((__pure__));

extern void hash_print_statistics(const Hash_table *table, FILE *stream);

extern void *hash_lookup(const Hash_table *table, const void *entry);
extern void *hash_get_first(const Hash_table *table) __attribute__((__pure__));

extern void *hash_get_next(const Hash_table *table, const void *entry);

extern size_t hash_get_entries(const Hash_table *table, void **buffer,
                               size_t buffer_size);

typedef _Bool (*Hash_processor)(void *entry, void *processor_data);
extern size_t hash_do_for_each(const Hash_table *table,
                               Hash_processor processor, void *processor_data);

extern size_t hash_string(const char *string, size_t n_buckets)
    __attribute__((__pure__));

extern void hash_reset_tuning(Hash_tuning *tuning);

typedef size_t (*Hash_hasher)(const void *entry, size_t table_size);
typedef _Bool (*Hash_comparator)(const void *entry1, const void *entry2);
typedef void (*Hash_data_freer)(void *entry);

extern void hash_free(Hash_table *table);

extern Hash_table *
hash_initialize(size_t candidate, const Hash_tuning *tuning, Hash_hasher hasher,
                Hash_comparator comparator, Hash_data_freer data_freer)
    __attribute__((__malloc__)) __attribute__((__malloc__(hash_free, 1)));

extern Hash_table *hash_xinitialize(size_t candidate, const Hash_tuning *tuning,
                                    Hash_hasher hasher,
                                    Hash_comparator comparator,
                                    Hash_data_freer data_freer)
    __attribute__((__malloc__)) __attribute__((__malloc__(hash_free, 1)))
    __attribute__((__returns_nonnull__));

extern void hash_clear(Hash_table *table);

extern _Bool hash_rehash(Hash_table *table, size_t candidate);

extern void *hash_insert(Hash_table *table, const void *entry);

extern void *hash_xinsert(Hash_table *table, const void *entry);
extern int hash_insert_if_absent(Hash_table *table, const void *entry,
                                 const void **matched_ent);

extern void *hash_remove(Hash_table *table, const void *entry);

extern void *hash_delete(Hash_table *table, const void *entry);

enum strtol_error {
  LONGINT_OK = 0,

  LONGINT_OVERFLOW = 1,
  LONGINT_INVALID_SUFFIX_CHAR = 2,

  LONGINT_INVALID_SUFFIX_CHAR_WITH_OVERFLOW =
      (LONGINT_INVALID_SUFFIX_CHAR | LONGINT_OVERFLOW),
  LONGINT_INVALID = 4
};
typedef enum strtol_error strtol_error;

strtol_error xstrtol(const char *, char **, int, long int *, const char *);
strtol_error xstrtoul(const char *, char **, int, unsigned long int *,
                      const char *);
strtol_error xstrtoll(const char *, char **, int, long long int *,
                      const char *);
strtol_error xstrtoull(const char *, char **, int, unsigned long long int *,
                       const char *);
strtol_error xstrtoimax(const char *, char **, int, intmax_t *, const char *);
strtol_error xstrtoumax(const char *, char **, int, uintmax_t *, const char *);
enum {

  human_ceiling = 0,

  human_round_to_nearest = 1,

  human_floor = 2,

  human_group_digits = 4,

  human_suppress_point_zero = 8,

  human_autoscale = 16,

  human_base_1024 = 32,

  human_space_before_unit = 64,

  human_SI = 128,

  human_B = 256
};

char *human_readable(uintmax_t, char *, int, uintmax_t, uintmax_t);

enum strtol_error human_options(char const *, int *, uintmax_t *);

extern void strmode(mode_t mode, char *str);

extern void filemodestring(struct stat const *statp, char *str);
int filevercmp(char const *a, char const *b) __attribute__((__pure__));

int filenvercmp(char const *a, ptrdiff_t alen, char const *b, ptrdiff_t blen)
    __attribute__((__pure__));

extern char *getuser(uid_t uid);
extern char *getgroup(gid_t gid);
extern uid_t *getuidbyname(const char *user);
extern gid_t *getgidbyname(const char *group);
extern int ls_mode;
extern int gnu_mbswidth(const char *string, int flags);

extern int mbsnwidth(const char *buf, size_t nbytes, int flags);

void mpsort(void const **, size_t, int (*)(void const *, void const *));

struct _obstack_chunk {
  char *limit;
  struct _obstack_chunk *prev;
  char contents[];
};

struct obstack {
  size_t chunk_size;
  struct _obstack_chunk *chunk;
  char *object_base;
  char *next_free;
  char *chunk_limit;
  union {
    size_t i;
    void *p;
  } temp;
  size_t alignment_mask;

  union {
    void *(*plain)(size_t);
    void *(*extra)(void *, size_t);
  } chunkfun;
  union {
    void (*plain)(void *);
    void (*extra)(void *, void *);
  } freefun;

  void *extra_arg;
  unsigned use_extra_arg : 1;
  unsigned maybe_empty_object : 1;

  unsigned alloc_failed : 1;
};

extern void _obstack_newchunk(struct obstack *, size_t);
extern void _obstack_free(struct obstack *, void *);
extern int _obstack_begin(struct obstack *, size_t, size_t, void *(*)(size_t),
                          void (*)(void *));
extern int _obstack_begin_1(struct obstack *, size_t, size_t,
                            void *(*)(void *, size_t), void (*)(void *, void *),
                            void *);
extern size_t _obstack_memory_used(struct obstack *)

    __attribute__((__pure__));

extern __attribute__((__noreturn__)) void (*obstack_alloc_failed_handler)(void);

extern int obstack_exit_failure;

static inline ssize_t smack_new_label_from_self(char **label) { return -1; }

static inline int smack_set_label_for_self(char const *label) { return -1; }

static inline _Bool

is_smack_enabled(void) {

  return 0;
}

inline long int __attribute__((__pure__))
get_stat_atime_ns(struct stat const *st) {

  return ((st)->st_atim).tv_nsec;
}

inline long int __attribute__((__pure__))
get_stat_ctime_ns(struct stat const *st) {

  return ((st)->st_ctim).tv_nsec;
}

inline long int __attribute__((__pure__))
get_stat_mtime_ns(struct stat const *st) {

  return ((st)->st_mtim).tv_nsec;
}

inline long int __attribute__((__pure__))
get_stat_birthtime_ns(struct stat const *st) {

  return 0;
}

inline struct timespec __attribute__((__pure__))
get_stat_atime(struct stat const *st) {

  return ((st)->st_atim);
}

inline struct timespec __attribute__((__pure__))
get_stat_ctime(struct stat const *st) {

  return ((st)->st_ctim);
}

inline struct timespec __attribute__((__pure__))
get_stat_mtime(struct stat const *st) {

  return ((st)->st_mtim);
}

inline struct timespec __attribute__((__pure__))
get_stat_birthtime(struct stat const *st) {
  struct timespec t;
  t.tv_sec = -1;
  t.tv_nsec = -1;
  return t;
}

inline int stat_time_normalize(int result, struct stat *st) { return result; }

size_t nstrftime(char *__restrict__, size_t, char const *, struct tm const *,
                 timezone_t __tz, int __ns);

intmax_t xdectoimax(char const *n_str, intmax_t min, intmax_t max,
                    char const *suffixes, char const *err, int err_exit)
    __attribute__((__nonnull__(1, 5)));
uintmax_t xdectoumax(char const *n_str, uintmax_t min, uintmax_t max,
                     char const *suffixes, char const *err, int err_exit)
    __attribute__((__nonnull__(1, 5)));

intmax_t xnumtoimax(char const *n_str, int base, intmax_t min, intmax_t max,
                    char const *suffixes, char const *err, int err_exit)
    __attribute__((__nonnull__(1, 6)));
uintmax_t xnumtoumax(char const *n_str, int base, uintmax_t min, uintmax_t max,
                     char const *suffixes, char const *err, int err_exit)
    __attribute__((__nonnull__(1, 6)));

_Noreturn void xstrtol_fatal(enum strtol_error, int, char,
                             struct option const *, char const *);

extern char *areadlink(char const *filename)
    __attribute__((__malloc__(free, 1)));
extern char *areadlink_with_size(char const *filename, size_t size_hint)
    __attribute__((__malloc__(free, 1)));

extern char *areadlinkat(int fd, char const *filename)
    __attribute__((__malloc__(free, 1)));

extern char *areadlinkat_with_size(int fd, char const *filename,
                                   size_t size_hint)
    __attribute__((__malloc__(free, 1)));

typedef enum { MBS_ALIGN_LEFT, MBS_ALIGN_RIGHT, MBS_ALIGN_CENTER } mbs_align_t;

enum {

  MBA_UNIBYTE_FALLBACK = 0x0001,

  MBA_UNIBYTE_ONLY = 0x0002,

  MBA_NO_LEFT_PAD = 0x0004,

  MBA_NO_RIGHT_PAD = 0x0008
};

size_t mbsalign(char const *src, char *dest, size_t dest_size, size_t *width,
                mbs_align_t align, int flags) __attribute__((__nonnull__));

char *ambsalign(char const *src, size_t *width, mbs_align_t align, int flags)
    __attribute__((__malloc__)) __attribute__((__malloc__(free, 1)))
    __attribute__((__nonnull__));
static char const G_line[] = {
    '  ' '  ' '  ' '  ' '  ' 'C', 'O', 'L', 'O', 'R', 'T', 'E', 'R', 'M', ' ',
    '?', '*', 0, 'T', 'E', 'R', 'M', ' ', 'E', 't', 'e', 'r', 'm', 0, 'T', 'E',
    'R', 'M', ' ', 'a', 'n', 's', 'i', 0, 'T', 'E', 'R', 'M', ' ', '*', 'c',
    'o', 'l', 'o', 'r', '*', 0, 'T', 'E', 'R', 'M', ' ', 'c', 'o', 'n', '[',
    '0', '-', '9', ']', '*', 'x', '[', '0', '-', '9', ']', '*', 0, 'T', 'E',
    'R', 'M', ' ', 'c', 'o', 'n', 's', '2', '5', 0, 'T', 'E', 'R', 'M', ' ',
    'c', 'o', 'n', 's', 'o', 'l', 'e', 0, 'T', 'E', 'R', 'M', ' ', 'c', 'y',
    'g', 'w', 'i', 'n', 0, 'T', 'E', 'R', 'M', ' ', '*', 'd', 'i', 'r', 'e',
    'c', 't', '*', 0, 'T', 'E', 'R', 'M', ' ', 'd', 't', 't', 'e', 'r', 'm', 0,
    'T', 'E', 'R', 'M', ' ', 'g', 'n', 'o', 'm', 'e', 0, 'T', 'E', 'R', 'M',
    ' ', 'h', 'u', 'r', 'd', 0, 'T', 'E', 'R', 'M', ' ', 'j', 'f', 'b', 't',
    'e', 'r', 'm', 0, 'T', 'E', 'R', 'M', ' ', 'k', 'o', 'n', 's', 'o', 'l',
    'e', 0, 'T', 'E', 'R', 'M', ' ', 'k', 't', 'e', 'r', 'm', 0, 'T', 'E', 'R',
    'M', ' ', 'l', 'i', 'n', 'u', 'x', 0, 'T', 'E', 'R', 'M', ' ', 'l', 'i',
    'n', 'u', 'x', '-', 'c', 0, 'T', 'E', 'R', 'M', ' ', 'm', 'l', 't', 'e',
    'r', 'm', 0, 'T', 'E', 'R', 'M', ' ', 'p', 'u', 't', 't', 'y', 0, 'T', 'E',
    'R', 'M', ' ', 'r', 'x', 'v', 't', '*', 0, 'T', 'E', 'R', 'M', ' ', 's',
    'c', 'r', 'e', 'e', 'n', '*', 0, 'T', 'E', 'R', 'M', ' ', 's', 't', 0, 'T',
    'E', 'R', 'M', ' ', 't', 'e', 'r', 'm', 'i', 'n', 'a', 't', 'o', 'r', 0,
    'T', 'E', 'R', 'M', ' ', 't', 'm', 'u', 'x', '*', 0, 'T', 'E', 'R', 'M',
    ' ', 'v', 't', '1', '0', '0', 0, 'T', 'E', 'R', 'M', ' ', 'x', 't', 'e',
    'r', 'm', '*', 0, '  ' '  ' '  ' '  ' '  ' '  ' 'R', 'E', 'S', 'E', 'T',
    ' ', '0', ' ', '  ' D ',' I ',' R ',' ',' 0 ',' 1 ',';
',' 3 ',' 4 ',' ',' 'L', 'I', 'N', 'K', ' ', '0', '1', ';', '3', '6', ' ',
    '  ' ',' 'M', 'U', 'L', 'T', 'I', 'H', 'A', 'R', 'D', 'L', 'I', 'N', 'K',
    ' ', '0', '0', ' ', '  ' F ',' I ',' F ',' O ',' ',' 4 ',' 0 ',';
',' 3 ',' 3 ',' ',' 'S', 'O', 'C', 'K', ' ', '0', '1', ';', '3', '5', ' ',
    '  ' D ',' O ',' O ',' R ',' ',' 0 ',' 1 ',';
',' 3 ',' 5 ',' ',' 'B', 'L', 'K', ' ', '4', '0', ';', '3', '3', ';', '0', '1',
    ' ', '  ' C ',' H ',' R ',' ',' 4 ',' 0 ',';
',' 3 ',' 3 ',';
',' 0 ',' 1 ',' ',' 'O', 'R', 'P', 'H', 'A', 'N', ' ', '4', '0', ';', '3', '1',
    ';', '0', '1', ' ',
    '  ' M ',' I ',' S ',' S ',' I ',' N ',' G ',' ',' 0 ',' 0 ',' ',' 'S', 'E',
    'T', 'U', 'I', 'D', ' ', '3', '7', ';', '4', '1', ' ',
    '  ' S ',' E ',' T ',' G ',' I ',' D ',' ',' 3 ',' 0 ',';
',' 4 ',' 3 ',' ',' 'C', 'A', 'P', 'A', 'B', 'I', 'L', 'I', 'T', 'Y', ' ', '0',
    '0', ' ',
    '  ' S ',' T ',' I ',' C ',' K ',' Y ','_ ',' O ',' T ',' H ',' E ',' R ','_ ',' W ',' R ',' I ',' T ',' A ',' B ',' L',' E ',' ',' 3 ',' 0 ',';
',' 4 ',' 2 ',' ',' 'O', 'T', 'H', 'E', 'R', '_', 'W', 'R', 'I', 'T', 'A', 'B',
    'L', 'E', ' ', '3', '4', ';', '4', '2', ' ',
    '  ' S ',' T ',' I ',' C ',' K ',' Y ',' ',' 3 ',' 7 ',';
',' 4 ',' 4 ',' ',' '  ' E ',' X ',' E ',' C ',' ',' 0 ',' 1 ',';
',' 3 ',' 2',0, '  ' '  ' '  ' '  ' '  ' '  ' '  ' ',' '.', 't', 'a', 'r', ' ',
    '0', '1', ';', '3', '1', 0, '.', 't', 'g', 'z', ' ', '0', '1', ';', '3',
    '1', 0, '.', 'a', 'r', 'c', ' ', '0', '1', ';', '3', '1', 0, '.', 'a', 'r',
    'j', ' ', '0', '1', ';', '3', '1', 0, '.', 't', 'a', 'z', ' ', '0', '1',
    ';', '3', '1', 0, '.', 'l', 'h', 'a', ' ', '0', '1', ';', '3', '1', 0, '.',
    'l', 'z', '4', ' ', '0', '1', ';', '3', '1', 0, '.', 'l', 'z', 'h', ' ',
    '0', '1', ';', '3', '1', 0, '.', 'l', 'z', 'm', 'a', ' ', '0', '1', ';',
    '3', '1', 0, '.', 't', 'l', 'z', ' ', '0', '1', ';', '3', '1', 0, '.', 't',
    'x', 'z', ' ', '0', '1', ';', '3', '1', 0, '.', 't', 'z', 'o', ' ', '0',
    '1', ';', '3', '1', 0, '.', 't', '7', 'z', ' ', '0', '1', ';', '3', '1', 0,
    '.', 'z', 'i', 'p', ' ', '0', '1', ';', '3', '1', 0, '.', 'z', ' ', '0',
    '1', ';', '3', '1', 0, '.', 'd', 'z', ' ', '0', '1', ';', '3', '1', 0, '.',
    'g', 'z', ' ', '0', '1', ';', '3', '1', 0, '.', 'l', 'r', 'z', ' ', '0',
    '1', ';', '3', '1', 0, '.', 'l', 'z', ' ', '0', '1', ';', '3', '1', 0, '.',
    'l', 'z', 'o', ' ', '0', '1', ';', '3', '1', 0, '.', 'x', 'z', ' ', '0',
    '1', ';', '3', '1', 0, '.', 'z', 's', 't', ' ', '0', '1', ';', '3', '1', 0,
    '.', 't', 'z', 's', 't', ' ', '0', '1', ';', '3', '1', 0, '.', 'b', 'z',
    '2', ' ', '0', '1', ';', '3', '1', 0, '.', 'b', 'z', ' ', '0', '1', ';',
    '3', '1', 0, '.', 't', 'b', 'z', ' ', '0', '1', ';', '3', '1', 0, '.', 't',
    'b', 'z', '2', ' ', '0', '1', ';', '3', '1', 0, '.', 't', 'z', ' ', '0',
    '1', ';', '3', '1', 0, '.', 'd', 'e', 'b', ' ', '0', '1', ';', '3', '1', 0,
    '.', 'r', 'p', 'm', ' ', '0', '1', ';', '3', '1', 0, '.', 'j', 'a', 'r',
    ' ', '0', '1', ';', '3', '1', 0, '.', 'w', 'a', 'r', ' ', '0', '1', ';',
    '3', '1', 0, '.', 'e', 'a', 'r', ' ', '0', '1', ';', '3', '1', 0, '.', 's',
    'a', 'r', ' ', '0', '1', ';', '3', '1', 0, '.', 'r', 'a', 'r', ' ', '0',
    '1', ';', '3', '1', 0, '.', 'a', 'l', 'z', ' ', '0', '1', ';', '3', '1', 0,
    '.', 'a', 'c', 'e', ' ', '0', '1', ';', '3', '1', 0, '.', 'z', 'o', 'o',
    ' ', '0', '1', ';', '3', '1', 0, '.', 'c', 'p', 'i', 'o', ' ', '0', '1',
    ';', '3', '1', 0, '.', '7', 'z', ' ', '0', '1', ';', '3', '1', 0, '.', 'r',
    'z', ' ', '0', '1', ';', '3', '1', 0, '.', 'c', 'a', 'b', ' ', '0', '1',
    ';', '3', '1', 0, '.', 'w', 'i', 'm', ' ', '0', '1', ';', '3', '1', 0, '.',
    's', 'w', 'm', ' ', '0', '1', ';', '3', '1', 0, '.', 'd', 'w', 'm', ' ',
    '0', '1', ';', '3', '1', 0, '.', 'e', 's', 'd', ' ', '0', '1', ';', '3',
    '1', 0, '  '.',' a ',' v ',' i ',' f ',' ',' 0 ',' 1 ',';
',' 3 ',' 5',0, '.', 'j', 'p', 'g', ' ', '0', '1', ';', '3', '5', 0, '.', 'j',
    'p', 'e', 'g', ' ', '0', '1', ';', '3', '5', 0, '.', 'm', 'j', 'p', 'g',
    ' ', '0', '1', ';', '3', '5', 0, '.', 'm', 'j', 'p', 'e', 'g', ' ', '0',
    '1', ';', '3', '5', 0, '.', 'g', 'i', 'f', ' ', '0', '1', ';', '3', '5', 0,
    '.', 'b', 'm', 'p', ' ', '0', '1', ';', '3', '5', 0, '.', 'p', 'b', 'm',
    ' ', '0', '1', ';', '3', '5', 0, '.', 'p', 'g', 'm', ' ', '0', '1', ';',
    '3', '5', 0, '.', 'p', 'p', 'm', ' ', '0', '1', ';', '3', '5', 0, '.', 't',
    'g', 'a', ' ', '0', '1', ';', '3', '5', 0, '.', 'x', 'b', 'm', ' ', '0',
    '1', ';', '3', '5', 0, '.', 'x', 'p', 'm', ' ', '0', '1', ';', '3', '5', 0,
    '.', 't', 'i', 'f', ' ', '0', '1', ';', '3', '5', 0, '.', 't', 'i', 'f',
    'f', ' ', '0', '1', ';', '3', '5', 0, '.', 'p', 'n', 'g', ' ', '0', '1',
    ';', '3', '5', 0, '.', 's', 'v', 'g', ' ', '0', '1', ';', '3', '5', 0, '.',
    's', 'v', 'g', 'z', ' ', '0', '1', ';', '3', '5', 0, '.', 'm', 'n', 'g',
    ' ', '0', '1', ';', '3', '5', 0, '.', 'p', 'c', 'x', ' ', '0', '1', ';',
    '3', '5', 0, '.', 'm', 'o', 'v', ' ', '0', '1', ';', '3', '5', 0, '.', 'm',
    'p', 'g', ' ', '0', '1', ';', '3', '5', 0, '.', 'm', 'p', 'e', 'g', ' ',
    '0', '1', ';', '3', '5', 0, '.', 'm', '2', 'v', ' ', '0', '1', ';', '3',
    '5', 0, '.', 'm', 'k', 'v', ' ', '0', '1', ';', '3', '5', 0, '.', 'w', 'e',
    'b', 'm', ' ', '0', '1', ';', '3', '5', 0, '.', 'w', 'e', 'b', 'p', ' ',
    '0', '1', ';', '3', '5', 0, '.', 'o', 'g', 'm', ' ', '0', '1', ';', '3',
    '5', 0, '.', 'm', 'p', '4', ' ', '0', '1', ';', '3', '5', 0, '.', 'm', '4',
    'v', ' ', '0', '1', ';', '3', '5', 0, '.', 'm', 'p', '4', 'v', ' ', '0',
    '1', ';', '3', '5', 0, '.', 'v', 'o', 'b', ' ', '0', '1', ';', '3', '5', 0,
    '.', 'q', 't', ' ', '0', '1', ';', '3', '5', 0, '.', 'n', 'u', 'v', ' ',
    '0', '1', ';', '3', '5', 0, '.', 'w', 'm', 'v', ' ', '0', '1', ';', '3',
    '5', 0, '.', 'a', 's', 'f', ' ', '0', '1', ';', '3', '5', 0, '.', 'r', 'm',
    ' ', '0', '1', ';', '3', '5', 0, '.', 'r', 'm', 'v', 'b', ' ', '0', '1',
    ';', '3', '5', 0, '.', 'f', 'l', 'c', ' ', '0', '1', ';', '3', '5', 0, '.',
    'a', 'v', 'i', ' ', '0', '1', ';', '3', '5', 0, '.', 'f', 'l', 'i', ' ',
    '0', '1', ';', '3', '5', 0, '.', 'f', 'l', 'v', ' ', '0', '1', ';', '3',
    '5', 0, '.', 'g', 'l', ' ', '0', '1', ';', '3', '5', 0, '.', 'd', 'l', ' ',
    '0', '1', ';', '3', '5', 0, '.', 'x', 'c', 'f', ' ', '0', '1', ';', '3',
    '5', 0, '.', 'x', 'w', 'd', ' ', '0', '1', ';', '3', '5', 0, '.', 'y', 'u',
    'v', ' ', '0', '1', ';', '3', '5', 0, '.', 'c', 'g', 'm', ' ', '0', '1',
    ';', '3', '5', 0, '.', 'e', 'm', 'f', ' ', '0', '1', ';', '3', '5', 0,
    '  '.',' o ',' g ',' v ',' ',' 0 ',' 1 ',';
',' 3 ',' 5',0, '.', 'o', 'g', 'x', ' ', '0', '1', ';', '3', '5', 0,
    '  '.',' a ',' a ',' c ',' ',' 0 ',' 0 ',';
',' 3 ',' 6',0, '.', 'a', 'u', ' ', '0', '0', ';', '3', '6', 0, '.', 'f', 'l',
    'a', 'c', ' ', '0', '0', ';', '3', '6', 0, '.', 'm', '4', 'a', ' ', '0',
    '0', ';', '3', '6', 0, '.', 'm', 'i', 'd', ' ', '0', '0', ';', '3', '6', 0,
    '.', 'm', 'i', 'd', 'i', ' ', '0', '0', ';', '3', '6', 0, '.', 'm', 'k',
    'a', ' ', '0', '0', ';', '3', '6', 0, '.', 'm', 'p', '3', ' ', '0', '0',
    ';', '3', '6', 0, '.', 'm', 'p', 'c', ' ', '0', '0', ';', '3', '6', 0, '.',
    'o', 'g', 'g', ' ', '0', '0', ';', '3', '6', 0, '.', 'r', 'a', ' ', '0',
    '0', ';', '3', '6', 0, '.', 'w', 'a', 'v', ' ', '0', '0', ';', '3', '6', 0,
    '  '.',' o ',' g ',' a ',' ',' 0 ',' 0 ',';
',' 3 ',' 6',0, '.', 'o', 'p', 'u', 's', ' ', '0', '0', ';', '3', '6', 0, '.',
    's', 'p', 'x', ' ', '0', '0', ';', '3', '6', 0, '.', 'x', 's', 'p', 'f',
    ' ', '0', '0', ';', '3', '6', 0, '  ' * ',' ~',' ',' 0 ',' 0 ',';
',' 9 ',' 0',0, '*', '  '.',' b ',' a ',' k ',' ',' 0 ',' 0 ',';
',' 9 ',' 0',0, '.', 'o', 'l', 'd', ' ', '0', '0', ';', '9', '0', 0, '.', 'o',
    'r', 'i', 'g', ' ', '0', '0', ';', '9', '0', 0, '.', 'p', 'a', 'r', 't',
    ' ', '0', '0', ';', '9', '0', 0, '.', 'r', 'e', 'j', ' ', '0', '0', ';',
    '9', '0', 0, '.', 's', 'w', 'p', ' ', '0', '0', ';', '9', '0', 0, '.', 't',
    'm', 'p', ' ', '0', '0', ';', '9', '0', 0, '.', 'd', 'p', 'k', 'g', '-',
    'd', 'i', 's', 't', ' ', '0', '0', ';', '9', '0', 0, '.', 'd', 'p', 'k',
    'g', '-', 'o', 'l', 'd', ' ', '0', '0', ';', '9', '0', 0, '.', 'u', 'c',
    'f', '-', 'd', 'i', 's', 't', ' ', '0', '0', ';', '9', '0', 0, '.', 'u',
    'c', 'f', '-', 'n', 'e', 'w', ' ', '0', '0', ';', '9', '0', 0, '.', 'u',
    'c', 'f', '-', 'o', 'l', 'd', ' ', '0', '0', ';', '9', '0', 0, '.', 'r',
    'p', 'm', 'n', 'e', 'w', ' ', '0', '0', ';', '9', '0', 0, '.', 'r', 'p',
    'm', 'o', 'r', 'i', 'g', ' ', '0', '0', ';', '9', '0', 0, '.', 'r', 'p',
    'm', 's', 'a', 'v', 'e', ' ', '0', '0', ';', '9', '0', 0, '  '
}
;

char *xgethostname(void) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1)));

inline _Bool

c_isalnum(int c) {
  switch (c) {
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
  case 'a' + (0):
  case 'b' + (0):
  case 'c' + (0):
  case 'd' + (0):
  case 'e' + (0):
  case 'f' + (0):
  case 'g' + (0):
  case 'h' + (0):
  case 'i' + (0):
  case 'j' + (0):
  case 'k' + (0):
  case 'l' + (0):
  case 'm' + (0):
  case 'n' + (0):
  case 'o' + (0):
  case 'p' + (0):
  case 'q' + (0):
  case 'r' + (0):
  case 's' + (0):
  case 't' + (0):
  case 'u' + (0):
  case 'v' + (0):
  case 'w' + (0):
  case 'x' + (0):
  case 'y' + (0):
  case 'z' + (0):
  case 'a' + ('A' - 'a'):
  case 'b' + ('A' - 'a'):
  case 'c' + ('A' - 'a'):
  case 'd' + ('A' - 'a'):
  case 'e' + ('A' - 'a'):
  case 'f' + ('A' - 'a'):
  case 'g' + ('A' - 'a'):
  case 'h' + ('A' - 'a'):
  case 'i' + ('A' - 'a'):
  case 'j' + ('A' - 'a'):
  case 'k' + ('A' - 'a'):
  case 'l' + ('A' - 'a'):
  case 'm' + ('A' - 'a'):
  case 'n' + ('A' - 'a'):
  case 'o' + ('A' - 'a'):
  case 'p' + ('A' - 'a'):
  case 'q' + ('A' - 'a'):
  case 'r' + ('A' - 'a'):
  case 's' + ('A' - 'a'):
  case 't' + ('A' - 'a'):
  case 'u' + ('A' - 'a'):
  case 'v' + ('A' - 'a'):
  case 'w' + ('A' - 'a'):
  case 'x' + ('A' - 'a'):
  case 'y' + ('A' - 'a'):
  case 'z' + ('A' - 'a'):
    return 1;
  default:
    return 0;
  }
}

inline _Bool

c_isalpha(int c) {
  switch (c) {
  case 'a' + (0):
  case 'b' + (0):
  case 'c' + (0):
  case 'd' + (0):
  case 'e' + (0):
  case 'f' + (0):
  case 'g' + (0):
  case 'h' + (0):
  case 'i' + (0):
  case 'j' + (0):
  case 'k' + (0):
  case 'l' + (0):
  case 'm' + (0):
  case 'n' + (0):
  case 'o' + (0):
  case 'p' + (0):
  case 'q' + (0):
  case 'r' + (0):
  case 's' + (0):
  case 't' + (0):
  case 'u' + (0):
  case 'v' + (0):
  case 'w' + (0):
  case 'x' + (0):
  case 'y' + (0):
  case 'z' + (0):
  case 'a' + ('A' - 'a'):
  case 'b' + ('A' - 'a'):
  case 'c' + ('A' - 'a'):
  case 'd' + ('A' - 'a'):
  case 'e' + ('A' - 'a'):
  case 'f' + ('A' - 'a'):
  case 'g' + ('A' - 'a'):
  case 'h' + ('A' - 'a'):
  case 'i' + ('A' - 'a'):
  case 'j' + ('A' - 'a'):
  case 'k' + ('A' - 'a'):
  case 'l' + ('A' - 'a'):
  case 'm' + ('A' - 'a'):
  case 'n' + ('A' - 'a'):
  case 'o' + ('A' - 'a'):
  case 'p' + ('A' - 'a'):
  case 'q' + ('A' - 'a'):
  case 'r' + ('A' - 'a'):
  case 's' + ('A' - 'a'):
  case 't' + ('A' - 'a'):
  case 'u' + ('A' - 'a'):
  case 'v' + ('A' - 'a'):
  case 'w' + ('A' - 'a'):
  case 'x' + ('A' - 'a'):
  case 'y' + ('A' - 'a'):
  case 'z' + ('A' - 'a'):
    return 1;
  default:
    return 0;
  }
}

inline _Bool

c_isascii(int c) {
  switch (c) {
  case ' ':
  case '\a':
  case '\b':
  case '\f':
  case '\n':
  case '\r':
  case '\t':
  case '\v':
  case '\x00':
  case '\x01':
  case '\x02':
  case '\x03':
  case '\x04':
  case '\x05':
  case '\x06':
  case '\x0e':
  case '\x0f':
  case '\x10':
  case '\x11':
  case '\x12':
  case '\x13':
  case '\x14':
  case '\x15':
  case '\x16':
  case '\x17':
  case '\x18':
  case '\x19':
  case '\x1a':
  case '\x1b':
  case '\x1c':
  case '\x1d':
  case '\x1e':
  case '\x1f':
  case '\x7f':
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
  case 'a' + (0):
  case 'b' + (0):
  case 'c' + (0):
  case 'd' + (0):
  case 'e' + (0):
  case 'f' + (0):
  case 'g' + (0):
  case 'h' + (0):
  case 'i' + (0):
  case 'j' + (0):
  case 'k' + (0):
  case 'l' + (0):
  case 'm' + (0):
  case 'n' + (0):
  case 'o' + (0):
  case 'p' + (0):
  case 'q' + (0):
  case 'r' + (0):
  case 's' + (0):
  case 't' + (0):
  case 'u' + (0):
  case 'v' + (0):
  case 'w' + (0):
  case 'x' + (0):
  case 'y' + (0):
  case 'z' + (0):
  case '!':
  case '"':
  case '    case ' a ' + (' A ' - ' a '): case ' b ' + (' A ' - ' a '): case ' c ' + (' A ' - ' a '): case ' d ' + (' A ' - ' a '): case ' e ' + (' A ' - ' a '): case ' f ' + (' A ' - ' a '): case ' g ' + (' A ' - ' a '): case ' h ' + (' A ' - ' a '): case ' i ' + (' A ' - ' a '): case ' j ' + (' A ' - ' a '): case ' k ' + (' A ' - ' a '): case ' l ' + (' A ' - ' a '): case ' m ' + (' A ' - ' a '): case ' n ' + (' A ' - ' a '): case ' o ' + (' A ' - ' a '): case ' p ' + (' A ' - ' a '): case ' q ' + (' A ' - ' a '): case ' r ' + (' A ' - ' a '): case ' s ' + (' A ' - ' a '): case ' t ' + (' A ' - ' a '): case ' u' + (' A ' - ' a '): case ' v ' + (' A ' - ' a '): case ' w ' + (' A ' - ' a '): case ' x ' + (' A ' - ' a '): case ' y ' + (' A ' - ' a '): case ' z ' + (' A ' - ' a'): return 1;
      default:
    return 0;
  }
}

inline _Bool

c_isblank(int c) {
  return c == ' ' || c == '\t';
}

inline _Bool

c_iscntrl(int c) {
  switch (c) {
  case '\a':
  case '\b':
  case '\f':
  case '\n':
  case '\r':
  case '\t':
  case '\v':
  case '\x00':
  case '\x01':
  case '\x02':
  case '\x03':
  case '\x04':
  case '\x05':
  case '\x06':
  case '\x0e':
  case '\x0f':
  case '\x10':
  case '\x11':
  case '\x12':
  case '\x13':
  case '\x14':
  case '\x15':
  case '\x16':
  case '\x17':
  case '\x18':
  case '\x19':
  case '\x1a':
  case '\x1b':
  case '\x1c':
  case '\x1d':
  case '\x1e':
  case '\x1f':
  case '\x7f':
    return 1;
  default:
    return 0;
  }
}

inline _Bool

c_isdigit(int c) {
  switch (c) {
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
    return 1;
  default:
    return 0;
  }
}

inline _Bool

c_isgraph(int c) {
  switch (c) {
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
  case 'a' + (0):
  case 'b' + (0):
  case 'c' + (0):
  case 'd' + (0):
  case 'e' + (0):
  case 'f' + (0):
  case 'g' + (0):
  case 'h' + (0):
  case 'i' + (0):
  case 'j' + (0):
  case 'k' + (0):
  case 'l' + (0):
  case 'm' + (0):
  case 'n' + (0):
  case 'o' + (0):
  case 'p' + (0):
  case 'q' + (0):
  case 'r' + (0):
  case 's' + (0):
  case 't' + (0):
  case 'u' + (0):
  case 'v' + (0):
  case 'w' + (0):
  case 'x' + (0):
  case 'y' + (0):
  case 'z' + (0):
  case '!':
  case '"':
  case '    case ' a ' + (' A ' - ' a '): case ' b ' + (' A ' - ' a '): case ' c ' + (' A ' - ' a '): case ' d ' + (' A ' - ' a '): case ' e ' + (' A ' - ' a '): case ' f ' + (' A ' - ' a '): case ' g ' + (' A ' - ' a '): case ' h ' + (' A ' - ' a '): case ' i ' + (' A ' - ' a '): case ' j ' + (' A ' - ' a '): case ' k ' + (' A ' - ' a '): case ' l ' + (' A ' - ' a '): case ' m ' + (' A ' - ' a '): case ' n ' + (' A ' - ' a '): case ' o ' + (' A ' - ' a '): case ' p ' + (' A ' - ' a '): case ' q ' + (' A ' - ' a '): case ' r ' + (' A ' - ' a '): case ' s ' + (' A ' - ' a '): case ' t ' + (' A ' - ' a '): case ' u' + (' A ' - ' a '): case ' v ' + (' A ' - ' a '): case ' w ' + (' A ' - ' a '): case ' x ' + (' A ' - ' a '): case ' y ' + (' A ' - ' a '): case ' z ' + (' A ' - ' a'): return 1;
      default:
    return 0;
  }
}

inline _Bool

c_islower(int c) {
  switch (c) {
  case 'a' + (0):
  case 'b' + (0):
  case 'c' + (0):
  case 'd' + (0):
  case 'e' + (0):
  case 'f' + (0):
  case 'g' + (0):
  case 'h' + (0):
  case 'i' + (0):
  case 'j' + (0):
  case 'k' + (0):
  case 'l' + (0):
  case 'm' + (0):
  case 'n' + (0):
  case 'o' + (0):
  case 'p' + (0):
  case 'q' + (0):
  case 'r' + (0):
  case 's' + (0):
  case 't' + (0):
  case 'u' + (0):
  case 'v' + (0):
  case 'w' + (0):
  case 'x' + (0):
  case 'y' + (0):
  case 'z' + (0):
    return 1;
  default:
    return 0;
  }
}

inline _Bool

c_isprint(int c) {
  switch (c) {
  case ' ':
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
  case 'a' + (0):
  case 'b' + (0):
  case 'c' + (0):
  case 'd' + (0):
  case 'e' + (0):
  case 'f' + (0):
  case 'g' + (0):
  case 'h' + (0):
  case 'i' + (0):
  case 'j' + (0):
  case 'k' + (0):
  case 'l' + (0):
  case 'm' + (0):
  case 'n' + (0):
  case 'o' + (0):
  case 'p' + (0):
  case 'q' + (0):
  case 'r' + (0):
  case 's' + (0):
  case 't' + (0):
  case 'u' + (0):
  case 'v' + (0):
  case 'w' + (0):
  case 'x' + (0):
  case 'y' + (0):
  case 'z' + (0):
  case '!':
  case '"':
  case '    case ' a ' + (' A ' - ' a '): case ' b ' + (' A ' - ' a '): case ' c ' + (' A ' - ' a '): case ' d ' + (' A ' - ' a '): case ' e ' + (' A ' - ' a '): case ' f ' + (' A ' - ' a '): case ' g ' + (' A ' - ' a '): case ' h ' + (' A ' - ' a '): case ' i ' + (' A ' - ' a '): case ' j ' + (' A ' - ' a '): case ' k ' + (' A ' - ' a '): case ' l ' + (' A ' - ' a '): case ' m ' + (' A ' - ' a '): case ' n ' + (' A ' - ' a '): case ' o ' + (' A ' - ' a '): case ' p ' + (' A ' - ' a '): case ' q ' + (' A ' - ' a '): case ' r ' + (' A ' - ' a '): case ' s ' + (' A ' - ' a '): case ' t ' + (' A ' - ' a '): case ' u' + (' A ' - ' a '): case ' v ' + (' A ' - ' a '): case ' w ' + (' A ' - ' a '): case ' x ' + (' A ' - ' a '): case ' y ' + (' A ' - ' a '): case ' z ' + (' A ' - ' a'): return 1;
      default:
    return 0;
  }
}

inline _Bool

c_ispunct(int c) {
  switch (c) {
  case '!':
  case '"':
  case '      return  1; default:
    return 0;
  }
}

inline _Bool

c_isspace(int c) {
  switch (c) {
  case ' ':
  case '\t':
  case '\n':
  case '\v':
  case '\f':
  case '\r':
    return 1;
  default:
    return 0;
  }
}

inline _Bool

c_isupper(int c) {
  switch (c) {
  case 'a' + ('A' - 'a'):
  case 'b' + ('A' - 'a'):
  case 'c' + ('A' - 'a'):
  case 'd' + ('A' - 'a'):
  case 'e' + ('A' - 'a'):
  case 'f' + ('A' - 'a'):
  case 'g' + ('A' - 'a'):
  case 'h' + ('A' - 'a'):
  case 'i' + ('A' - 'a'):
  case 'j' + ('A' - 'a'):
  case 'k' + ('A' - 'a'):
  case 'l' + ('A' - 'a'):
  case 'm' + ('A' - 'a'):
  case 'n' + ('A' - 'a'):
  case 'o' + ('A' - 'a'):
  case 'p' + ('A' - 'a'):
  case 'q' + ('A' - 'a'):
  case 'r' + ('A' - 'a'):
  case 's' + ('A' - 'a'):
  case 't' + ('A' - 'a'):
  case 'u' + ('A' - 'a'):
  case 'v' + ('A' - 'a'):
  case 'w' + ('A' - 'a'):
  case 'x' + ('A' - 'a'):
  case 'y' + ('A' - 'a'):
  case 'z' + ('A' - 'a'):
    return 1;
  default:
    return 0;
  }
}

inline _Bool

c_isxdigit(int c) {
  switch (c) {
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
  case 'a' + (0):
  case 'b' + (0):
  case 'c' + (0):
  case 'd' + (0):
  case 'e' + (0):
  case 'f' + (0):
  case 'a' + ('A' - 'a'):
  case 'b' + ('A' - 'a'):
  case 'c' + ('A' - 'a'):
  case 'd' + ('A' - 'a'):
  case 'e' + ('A' - 'a'):
  case 'f' + ('A' - 'a'):
    return 1;
  default:
    return 0;
  }
}

inline int c_tolower(int c) {
  switch (c) {
  case 'a' + ('A' - 'a'):
  case 'b' + ('A' - 'a'):
  case 'c' + ('A' - 'a'):
  case 'd' + ('A' - 'a'):
  case 'e' + ('A' - 'a'):
  case 'f' + ('A' - 'a'):
  case 'g' + ('A' - 'a'):
  case 'h' + ('A' - 'a'):
  case 'i' + ('A' - 'a'):
  case 'j' + ('A' - 'a'):
  case 'k' + ('A' - 'a'):
  case 'l' + ('A' - 'a'):
  case 'm' + ('A' - 'a'):
  case 'n' + ('A' - 'a'):
  case 'o' + ('A' - 'a'):
  case 'p' + ('A' - 'a'):
  case 'q' + ('A' - 'a'):
  case 'r' + ('A' - 'a'):
  case 's' + ('A' - 'a'):
  case 't' + ('A' - 'a'):
  case 'u' + ('A' - 'a'):
  case 'v' + ('A' - 'a'):
  case 'w' + ('A' - 'a'):
  case 'x' + ('A' - 'a'):
  case 'y' + ('A' - 'a'):
  case 'z' + ('A' - 'a'):
    return c - 'A' + 'a';
  default:
    return c;
  }
}

inline int c_toupper(int c) {
  switch (c) {
  case 'a' + (0):
  case 'b' + (0):
  case 'c' + (0):
  case 'd' + (0):
  case 'e' + (0):
  case 'f' + (0):
  case 'g' + (0):
  case 'h' + (0):
  case 'i' + (0):
  case 'j' + (0):
  case 'k' + (0):
  case 'l' + (0):
  case 'm' + (0):
  case 'n' + (0):
  case 'o' + (0):
  case 'p' + (0):
  case 'q' + (0):
  case 'r' + (0):
  case 's' + (0):
  case 't' + (0):
  case 'u' + (0):
  case 'v' + (0):
  case 'w' + (0):
  case 'x' + (0):
  case 'y' + (0):
  case 'z' + (0):
    return c - 'a' + 'A';
  default:
    return c;
  }
}

enum canonicalize_mode_t {

  CAN_EXISTING = 0,

  CAN_ALL_BUT_LAST = 1,

  CAN_MISSING = 2,

  CAN_NOLINKS = 4
};
typedef enum canonicalize_mode_t canonicalize_mode_t;
char *canonicalize_filename_mode(const char *, canonicalize_mode_t)
    __attribute__((__malloc__)) __attribute__((__malloc__(free, 1)));
static inline struct timespec
statx_timestamp_to_timespec(struct statx_timestamp tsx) {
  struct timespec ts;

  ts.tv_sec = tsx.tv_sec;
  ts.tv_nsec = tsx.tv_nsec;
  return ts;
}

static inline void statx_to_stat(struct statx *stx, struct stat *stat) {
  stat->st_dev = gnu_dev_makedev(stx->stx_dev_major, stx->stx_dev_minor);
  stat->st_ino = stx->stx_ino;
  stat->st_mode = stx->stx_mode;
  stat->st_nlink = stx->stx_nlink;
  stat->st_uid = stx->stx_uid;
  stat->st_gid = stx->stx_gid;
  stat->st_rdev = gnu_dev_makedev(stx->stx_rdev_major, stx->stx_rdev_minor);
  stat->st_size = stx->stx_size;
  stat->st_blksize = stx->stx_blksize;

  stat->st_blocks = stx->stx_blocks;
  stat->st_atim = statx_timestamp_to_timespec(stx->stx_atime);
  stat->st_mtim = statx_timestamp_to_timespec(stx->stx_mtime);
  stat->st_ctim = statx_timestamp_to_timespec(stx->stx_ctime);
}

typedef struct __user_cap_header_struct {
  __u32 version;
  int pid;
} * cap_user_header_t;

typedef struct __user_cap_data_struct {
  __u32 effective;
  __u32 permitted;
  __u32 inheritable;
} * cap_user_data_t;
struct vfs_cap_data {
  __le32 magic_etc;
  struct {
    __le32 permitted;
    __le32 inheritable;
  } data[2];
};

struct vfs_ns_cap_data {
  __le32 magic_etc;
  struct {
    __le32 permitted;
    __le32 inheritable;
  } data[2];
  __le32 rootid;
};
typedef struct _cap_struct *cap_t;

typedef int cap_value_t;

extern cap_value_t cap_max_bits(void);

typedef enum {
  CAP_EFFECTIVE = 0,
  CAP_PERMITTED = 1,
  CAP_INHERITABLE = 2
} cap_flag_t;

typedef enum {
  CAP_IAB_INH = 2,
  CAP_IAB_AMB = 3,
  CAP_IAB_BOUND = 4
} cap_iab_vector_t;
typedef struct cap_iab_s *cap_iab_t;

typedef enum { CAP_CLEAR = 0, CAP_SET = 1 } cap_flag_value_t;

typedef unsigned cap_mode_t;

extern cap_t cap_dup(cap_t);
extern int cap_free(void *);
extern cap_t cap_init(void);
extern cap_iab_t cap_iab_init(void);

extern int cap_get_flag(cap_t, cap_value_t, cap_flag_t, cap_flag_value_t *);
extern int cap_set_flag(cap_t, cap_flag_t, int, const cap_value_t *,
                        cap_flag_value_t);
extern int cap_clear(cap_t);
extern int cap_clear_flag(cap_t, cap_flag_t);

extern cap_flag_value_t cap_iab_get_vector(cap_iab_t, cap_iab_vector_t,
                                           cap_value_t);
extern int cap_iab_set_vector(cap_iab_t, cap_iab_vector_t, cap_value_t,
                              cap_flag_value_t);
extern int cap_iab_fill(cap_iab_t, cap_iab_vector_t, cap_t, cap_flag_t);

extern cap_t cap_get_fd(int);
extern cap_t cap_get_file(const char *);
extern uid_t cap_get_nsowner(cap_t);
extern int cap_set_fd(int, cap_t);
extern int cap_set_file(const char *, cap_t);
extern int cap_set_nsowner(cap_t, uid_t);

extern cap_t cap_get_proc(void);
extern cap_t cap_get_pid(pid_t);
extern int cap_set_proc(cap_t);

extern int cap_get_bound(cap_value_t);
extern int cap_drop_bound(cap_value_t);

extern int cap_get_ambient(cap_value_t);
extern int cap_set_ambient(cap_value_t, cap_flag_value_t);
extern int cap_reset_ambient(void);

extern ssize_t cap_size(cap_t);
extern ssize_t cap_copy_ext(void *, cap_t, ssize_t);
extern cap_t cap_copy_int(const void *);

extern cap_t cap_from_text(const char *);
extern char *cap_to_text(cap_t, ssize_t *);
extern int cap_from_name(const char *, cap_value_t *);
extern char *cap_to_name(cap_value_t);

extern char *cap_iab_to_text(cap_iab_t iab);
extern cap_iab_t cap_iab_from_text(const char *text);

extern int cap_compare(cap_t, cap_t);

extern void
cap_set_syscall(long int (*new_syscall)(long int, long int, long int, long int),
                long int (*new_syscall6)(long int, long int, long int, long int,
                                         long int, long int, long int));

extern int cap_set_mode(cap_mode_t flavor);
extern cap_mode_t cap_get_mode(void);
extern const char *cap_mode_name(cap_mode_t flavor);

extern unsigned cap_get_secbits(void);
extern int cap_set_secbits(unsigned bits);

extern int cap_setuid(uid_t uid);
extern int cap_setgroups(gid_t gid, size_t ngroups, const gid_t groups[]);

extern cap_iab_t cap_iab_get_proc(void);
extern int cap_iab_set_proc(cap_iab_t iab);

typedef struct cap_launch_s *cap_launch_t;

extern cap_launch_t cap_new_launcher(const char *arg0, const char *const *argv,
                                     const char *const *envp);
extern void cap_launcher_callback(cap_launch_t attr,
                                  int(callback_fn)(void *detail));
extern void cap_launcher_setuid(cap_launch_t attr, uid_t uid);
extern void cap_launcher_setgroups(cap_launch_t attr, gid_t gid, int ngroups,
                                   const gid_t *groups);
extern void cap_launcher_set_mode(cap_launch_t attr, cap_mode_t flavor);
extern cap_iab_t cap_launcher_set_iab(cap_launch_t attr, cap_iab_t iab);
extern void cap_launcher_set_chroot(cap_launch_t attr, const char *chroot);
extern pid_t cap_launch(cap_launch_t attr, void *data);

extern int capget(cap_user_header_t header, cap_user_data_t data);
extern int capset(cap_user_header_t header, const cap_user_data_t data);

extern int capgetp(pid_t pid, cap_t cap_d);

extern int capsetp(pid_t pid, cap_t cap_d);

enum filetype {
  unknown,
  fifo,
  chardev,
  directory,
  blockdev,
  normal,
  symbolic_link,
  sock,
  whiteout,
  arg_directory
};

static char const filetype_letter[] = "?pcdb-lswd";

_Static_assert(sizeof filetype_letter - 1 == arg_directory + 1,
               "verify ("
               "sizeof filetype_letter - 1 == arg_directory + 1"
               ")");

enum acl_type { ACL_T_NONE, ACL_T_LSM_CONTEXT_ONLY, ACL_T_YES };

struct fileinfo {

  char *name;

  char *linkname;

  char *absolute_name;

  struct stat stat;

  enum filetype filetype;

  mode_t linkmode;

  char *scontext;

  _Bool stat_ok;

  _Bool linkok;

  enum acl_type acl_type;

  _Bool has_capability;

  int quoted;

  size_t width;
};

struct bin_str {
  size_t len;
  char const *string;
};

static size_t quote_name(char const *name,
                         struct quoting_options const *options,
                         int needs_general_quoting, const struct bin_str *color,

                         _Bool allow_pad, struct obstack *stack,
                         char const *absolute_name);
static size_t quote_name_buf(char **inbuf, size_t bufsize, char *name,
                             struct quoting_options const *options,
                             int needs_general_quoting, size_t *width,

                             _Bool *pad);
static char *make_link_name(char const *name, char const *linkname);
static int decode_switches(int argc, char **argv);
static _Bool file_ignored(char const *name);
static uintmax_t gobble_file(char const *name, enum filetype type, ino_t inode,
                             _Bool command_line_arg, char const *dirname);
static const struct bin_str *get_color_indicator(const struct fileinfo *f,

                                                 _Bool symlink_target);
static _Bool print_color_indicator(const struct bin_str *ind);
static void put_indicator(const struct bin_str *ind);
static void add_ignore_pattern(char const *pattern);
static void attach(char *dest, char const *dirname, char const *name);
static void clear_files(void);
static void extract_dirs_from_files(char const *dirname,

                                    _Bool command_line_arg);
static void get_link_name(char const *filename, struct fileinfo *f,

                          _Bool command_line_arg);
static void indent(size_t from, size_t to);
static size_t calculate_columns(_Bool by_columns);
static void print_current_files(void);
static void print_dir(char const *name, char const *realname,

                      _Bool command_line_arg);
static size_t print_file_name_and_frills(const struct fileinfo *f,
                                         size_t start_col);
static void print_horizontal(void);
static int format_user_width(uid_t u);
static int format_group_width(gid_t g);
static void print_long_format(const struct fileinfo *f);
static void print_many_per_line(void);
static size_t print_name_with_quoting(const struct fileinfo *f,

                                      _Bool symlink_target,
                                      struct obstack *stack, size_t start_col);
static void prep_non_filename_text(void);
static _Bool print_type_indicator(_Bool stat_ok, mode_t mode,
                                  enum filetype type);
static void print_with_separator(char sep);
static void queue_directory(char const *name, char const *realname,

                            _Bool command_line_arg);
static void sort_files(void);
static void parse_ls_color(void);

static int getenv_quoting_style(void);

static size_t quote_name_width(char const *name,
                               struct quoting_options const *options,
                               int needs_general_quoting);

enum { INITIAL_TABLE_SIZE = 30 };
static Hash_table *active_dir_set;
static struct fileinfo *cwd_file;

static size_t cwd_n_alloc;

static size_t cwd_n_used;

static _Bool cwd_some_quoted;

static _Bool align_variable_outer_quotes;

static void **sorted_file;
static size_t sorted_file_alloc;

static _Bool color_symlink_as_referent;

static char const *hostname;

static mode_t file_or_link_mode(struct fileinfo const *file) {
  return (color_symlink_as_referent && file->linkok ? file->linkmode
                                                    : file->stat.st_mode);
}

struct pending {
  char *name;

  char *realname;

  _Bool command_line_arg;
  struct pending *next;
};

static struct pending *pending_dirs;

static struct timespec current_time;

static _Bool print_scontext;
static char UNKNOWN_SECURITY_CONTEXT[] = "?";

static _Bool any_has_acl;

static int inode_number_width;
static int block_size_width;
static int nlink_width;
static int scontext_width;
static int owner_width;
static int group_width;
static int author_width;
static int major_device_number_width;
static int minor_device_number_width;
static int file_size_width;
enum format {
  long_format,
  one_per_line,
  many_per_line,
  horizontal,
  with_commas
};

static enum format format;

enum time_style {
  full_iso_time_style,
  long_iso_time_style,
  iso_time_style,
  locale_time_style
};

static char const *const time_style_args[] = {"full-iso", "long-iso", "iso",
                                              "locale", ((void *)0)

};
static enum time_style const time_style_types[] = {
    full_iso_time_style, long_iso_time_style, iso_time_style,
    locale_time_style};
_Static_assert((sizeof(time_style_args) / sizeof *(time_style_args)) ==
                   (sizeof(time_style_types) / sizeof *(time_style_types)) + 1,
               "verify ("
               "ARRAY_CARDINALITY (time_style_args) == ARRAY_CARDINALITY "
               "(time_style_types) + 1"
               ")");

enum time_type {
  time_mtime = 0,
  time_ctime,
  time_atime,
  time_btime,
  time_numtypes
};

static enum time_type time_type;

enum sort_type {
  sort_name = 0,
  sort_extension,
  sort_width,
  sort_size,
  sort_version,
  sort_time,
  sort_none,
  sort_numtypes
};

static enum sort_type sort_type;

static _Bool sort_reverse;

static _Bool print_owner = 1;

static _Bool print_author;

static _Bool print_group = 1;

static _Bool numeric_ids;

static _Bool print_block_size;

static int human_output_opts;

static uintmax_t output_block_size;

static int file_human_output_opts;
static uintmax_t file_output_block_size = 1;

static _Bool dired;
enum indicator_style { none = 0, slash, file_type, classify };

static enum indicator_style indicator_style;

static char const *const indicator_style_args[] = {"none", "slash", "file-type",
                                                   "classify", ((void *)0)

};
static enum indicator_style const indicator_style_types[] = {
    none, slash, file_type, classify};
_Static_assert(
    (sizeof(indicator_style_args) / sizeof *(indicator_style_args)) ==
        (sizeof(indicator_style_types) / sizeof *(indicator_style_types)) + 1,
    "verify ("
    "ARRAY_CARDINALITY (indicator_style_args) == ARRAY_CARDINALITY "
    "(indicator_style_types) + 1"
    ")");

static _Bool print_with_color;

static _Bool print_hyperlink;

static _Bool used_color = 0;

enum when_type { when_never, when_always, when_if_tty };

enum Dereference_symlink {
  DEREF_UNDEFINED = 0,
  DEREF_NEVER,
  DEREF_COMMAND_LINE_ARGUMENTS,
  DEREF_COMMAND_LINE_SYMLINK_TO_DIR,
  DEREF_ALWAYS
};

enum indicator_no {
  C_LEFT,
  C_RIGHT,
  C_END,
  C_RESET,
  C_NORM,
  C_FILE,
  C_DIR,
  C_LINK,
  C_FIFO,
  C_SOCK,
  C_BLK,
  C_CHR,
  C_MISSING,
  C_ORPHAN,
  C_EXEC,
  C_DOOR,
  C_SETUID,
  C_SETGID,
  C_STICKY,
  C_OTHER_WRITABLE,
  C_STICKY_OTHER_WRITABLE,
  C_CAP,
  C_MULTIHARDLINK,
  C_CLR_TO_EOL
};

static char const *const indicator_name[] = {
    "lc", "rc", "ec", "rs", "no", "fi", "di",       "ln", "pi",
    "so", "bd", "cd", "mi", "or", "ex", "do",       "su", "sg",
    "st", "ow", "tw", "ca", "mh", "cl", ((void *)0)

};

struct color_ext_type {
  struct bin_str ext;
  struct bin_str seq;
  struct color_ext_type *next;
};

static struct bin_str color_indicator[] = {
    {sizeof("\033[") - 1, "\033["},
    {sizeof("m") - 1, "m"},
    {0, ((void *)0)},
    {sizeof("0") - 1, "0"},
    {0, ((void *)0)},
    {0, ((void *)0)},
    {sizeof("01;34") - 1, "01;34"},
    {sizeof("01;36") - 1, "01;36"},
    {sizeof("33") - 1, "33"},
    {sizeof("01;35") - 1, "01;35"},
    {sizeof("01;33") - 1, "01;33"},
    {sizeof("01;33") - 1, "01;33"},
    {0, ((void *)0)},
    {0, ((void *)0)},
    {sizeof("01;32") - 1, "01;32"},
    {sizeof("01;35") - 1, "01;35"},
    {sizeof("37;41") - 1, "37;41"},
    {sizeof("30;43") - 1, "30;43"},
    {sizeof("37;44") - 1, "37;44"},
    {sizeof("34;42") - 1, "34;42"},
    {sizeof("30;42") - 1, "30;42"},
    {0, ((void *)0)},
    {0, ((void *)0)},
    {sizeof("\033[K") - 1, "\033[K"},
};

static struct color_ext_type *color_ext_list = ((void *)0);

static char *color_buf;

static _Bool check_symlink_mode;

static _Bool print_inode;

static enum Dereference_symlink dereference;

static _Bool recursive;

static _Bool immediate_dirs;

static _Bool directories_first;

static enum {

  IGNORE_DEFAULT = 0,

  IGNORE_DOT_AND_DOTDOT,

  IGNORE_MINIMAL
} ignore_mode;

struct ignore_pattern {
  char const *pattern;
  struct ignore_pattern *next;
};

static struct ignore_pattern *ignore_patterns;

static struct ignore_pattern *hide_patterns;
static _Bool qmark_funny_chars;

static struct quoting_options *filename_quoting_options;
static struct quoting_options *dirname_quoting_options;

static size_t tabsize;

static _Bool print_dir_name;

static size_t line_length;

static timezone_t localtz;

static _Bool format_needs_stat;

static _Bool format_needs_type;

enum {
  TIME_STAMP_LEN_MAXIMUM =
      (((1000) > ((((((sizeof(time_t) * 8) -
                      (!((__typeof__(time_t))0 < (__typeof__(time_t))-1))) *
                         146 +
                     484) /
                    485) +
                   (!((__typeof__(time_t))0 < (__typeof__(time_t))-1)))))
           ? (1000)
           : ((((((sizeof(time_t) * 8) -
                  (!((__typeof__(time_t))0 < (__typeof__(time_t))-1))) *
                     146 +
                 484) /
                485) +
               (!((__typeof__(time_t))0 < (__typeof__(time_t))-1)))))
};

static char const *long_time_format[2] = {"%b %e  %Y", "%b %e %H:%M"};

static sigset_t caught_signals;

static sig_atomic_t volatile interrupt_signal;

static sig_atomic_t volatile stop_signal_count;

static int exit_status;

enum {

  LS_MINOR_PROBLEM = 1,

  LS_FAILURE = 2
};

enum {
  AUTHOR_OPTION = 0x7f + 1,
  BLOCK_SIZE_OPTION,
  COLOR_OPTION,
  DEREFERENCE_COMMAND_LINE_SYMLINK_TO_DIR_OPTION,
  FILE_TYPE_INDICATOR_OPTION,
  FORMAT_OPTION,
  FULL_TIME_OPTION,
  GROUP_DIRECTORIES_FIRST_OPTION,
  HIDE_OPTION,
  HYPERLINK_OPTION,
  INDICATOR_STYLE_OPTION,
  QUOTING_STYLE_OPTION,
  SHOW_CONTROL_CHARS_OPTION,
  SI_OPTION,
  SORT_OPTION,
  TIME_OPTION,
  TIME_STYLE_OPTION,
  ZERO_OPTION,
};

static struct option const long_options[] = {
    {"all", 0, ((void *)0), 'a'},
    {"escape", 0, ((void *)0), 'b'},
    {"directory", 0, ((void *)0), 'd'},
    {"dired", 0, ((void *)0), 'D'},
    {"full-time", 0, ((void *)0), FULL_TIME_OPTION},
    {"group-directories-first", 0, ((void *)0), GROUP_DIRECTORIES_FIRST_OPTION},
    {"human-readable", 0, ((void *)0), 'h'},
    {"inode", 0, ((void *)0), 'i'},
    {"kibibytes", 0, ((void *)0), 'k'},
    {"numeric-uid-gid", 0, ((void *)0), 'n'},
    {"no-group", 0, ((void *)0), 'G'},
    {"hide-control-chars", 0, ((void *)0), 'q'},
    {"reverse", 0, ((void *)0), 'r'},
    {"size", 0, ((void *)0), 's'},
    {"width", 1, ((void *)0), 'w'},
    {"almost-all", 0, ((void *)0), 'A'},
    {"ignore-backups", 0, ((void *)0), 'B'},
    {"classify", 2, ((void *)0), 'F'},
    {"file-type", 0, ((void *)0), FILE_TYPE_INDICATOR_OPTION},
    {"si", 0, ((void *)0), SI_OPTION},
    {"dereference-command-line", 0, ((void *)0), 'H'},
    {"dereference-command-line-symlink-to-dir", 0, ((void *)0),
     DEREFERENCE_COMMAND_LINE_SYMLINK_TO_DIR_OPTION},
    {"hide", 1, ((void *)0), HIDE_OPTION},
    {"ignore", 1, ((void *)0), 'I'},
    {"indicator-style", 1, ((void *)0), INDICATOR_STYLE_OPTION},
    {"dereference", 0, ((void *)0), 'L'},
    {"literal", 0, ((void *)0), 'N'},
    {"quote-name", 0, ((void *)0), 'Q'},
    {"quoting-style", 1, ((void *)0), QUOTING_STYLE_OPTION},
    {"recursive", 0, ((void *)0), 'R'},
    {"format", 1, ((void *)0), FORMAT_OPTION},
    {"show-control-chars", 0, ((void *)0), SHOW_CONTROL_CHARS_OPTION},
    {"sort", 1, ((void *)0), SORT_OPTION},
    {"tabsize", 1, ((void *)0), 'T'},
    {"time", 1, ((void *)0), TIME_OPTION},
    {"time-style", 1, ((void *)0), TIME_STYLE_OPTION},
    {"zero", 0, ((void *)0), ZERO_OPTION},
    {"color", 2, ((void *)0), COLOR_OPTION},
    {"hyperlink", 2, ((void *)0), HYPERLINK_OPTION},
    {"block-size", 1, ((void *)0), BLOCK_SIZE_OPTION},
    {"context", 0, 0, 'Z'},
    {"author", 0, ((void *)0), AUTHOR_OPTION},
    {"help", 0, ((void *)0), GETOPT_HELP_CHAR},
    {"version", 0, ((void *)0), GETOPT_VERSION_CHAR},
    {((void *)0), 0, ((void *)0), 0}};

static char const *const format_args[] = {
    "verbose",  "long",          "commas",   "horizontal", "across",
    "vertical", "single-column", ((void *)0)

};
static enum format const format_types[] = {
    long_format, long_format,   with_commas, horizontal,
    horizontal,  many_per_line, one_per_line};
_Static_assert(
    (sizeof(format_args) / sizeof *(format_args)) ==
        (sizeof(format_types) / sizeof *(format_types)) + 1,
    "verify ("
    "ARRAY_CARDINALITY (format_args) == ARRAY_CARDINALITY (format_types) + 1"
    ")");

static char const *const sort_args[] = {"none",      "time",    "size",
                                        "extension", "version", "width",
                                        ((void *)0)

};
static enum sort_type const sort_types[] = {
    sort_none, sort_time, sort_size, sort_extension, sort_version, sort_width};
_Static_assert(
    (sizeof(sort_args) / sizeof *(sort_args)) ==
        (sizeof(sort_types) / sizeof *(sort_types)) + 1,
    "verify ("
    "ARRAY_CARDINALITY (sort_args) == ARRAY_CARDINALITY (sort_types) + 1"
    ")");

static char const *const time_args[] = {
    "atime",    "access", "use", "ctime", "status", "birth", "creation",

    ((void *)0)

};
static enum time_type const time_types[] = {
    time_atime, time_atime, time_atime, time_ctime,
    time_ctime, time_btime, time_btime,
};
_Static_assert(
    (sizeof(time_args) / sizeof *(time_args)) ==
        (sizeof(time_types) / sizeof *(time_types)) + 1,
    "verify ("
    "ARRAY_CARDINALITY (time_args) == ARRAY_CARDINALITY (time_types) + 1"
    ")");

static char const *const when_args[] = {

    "always", "yes", "force",  "never",    "no", "none",
    "auto",   "tty", "if-tty", ((void *)0)

};
static enum when_type const when_types[] = {
    when_always, when_always, when_always, when_never, when_never,
    when_never,  when_if_tty, when_if_tty, when_if_tty};
_Static_assert(
    (sizeof(when_args) / sizeof *(when_args)) ==
        (sizeof(when_types) / sizeof *(when_types)) + 1,
    "verify ("
    "ARRAY_CARDINALITY (when_args) == ARRAY_CARDINALITY (when_types) + 1"
    ")");

struct column_info {

  _Bool valid_len;
  size_t line_len;
  size_t *col_arr;
};

static struct column_info *column_info;

static size_t max_idx;

enum { MIN_COLUMN_WIDTH = 3 };

static off_t dired_pos;

static void dired_outbyte(char c) {
  dired_pos++;
  putchar_unlocked(c);
}

static void dired_outbuf(char const *s, size_t s_len) {
  dired_pos += s_len;
  fwrite_unlocked(s, sizeof *s, s_len, stdout);
}

static void dired_outstring(char const *s) { dired_outbuf(s, strlen(s)); }

static void dired_indent(void) {
  if (dired)
    dired_outstring("  ");
}

static struct obstack dired_obstack;

static struct obstack subdired_obstack;

static void push_current_dired_pos(struct obstack *obs) {
  if (dired)
    __extension__({
      struct obstack *__o = (obs);
      size_t __len = (sizeof dired_pos);
      if (__extension__({
            struct obstack const *__o1 = (__o);
            (size_t)(__o1->chunk_limit - __o1->next_free);
          }) < __len)
        _obstack_newchunk(__o, __len);
      memcpy(__o->next_free, &dired_pos, __len);
      __o->next_free += __len;
      (void)0;
    });
}

static struct obstack dev_ino_obstack;

static void dev_ino_push(dev_t dev, ino_t ino) {
  void *vdi;
  struct dev_ino *di;
  int dev_ino_size = sizeof *di;
  __extension__({
    struct obstack *__o = (&dev_ino_obstack);
    size_t __len = (dev_ino_size);
    if (__extension__({
          struct obstack const *__o1 = (__o);
          (size_t)(__o1->chunk_limit - __o1->next_free);
        }) < __len)
      _obstack_newchunk(__o, __len);
    ((void)((__o)->next_free += (__len)));
  });
  vdi = ((void *)(&dev_ino_obstack)->next_free);
  di = vdi;
  di--;
  di->st_dev = dev;
  di->st_ino = ino;
}

static struct dev_ino dev_ino_pop(void) {
  void *vdi;
  struct dev_ino *di;
  int dev_ino_size = sizeof *di;

  ((void)sizeof((dev_ino_size <= __extension__({
                   struct obstack const *__o = (&dev_ino_obstack);
                   (size_t)(__o->next_free - __o->object_base);
                 }))
                    ? 1
                    : 0),
   __extension__({
     if (dev_ino_size <= __extension__({
           struct obstack const *__o = (&dev_ino_obstack);
           (size_t)(__o->next_free - __o->object_base);
         }))
       ;
     else
       __assert_fail("dev_ino_size <= obstack_object_size (&dev_ino_obstack)",
                     "src/ls.c", 1053, __extension__ __PRETTY_FUNCTION__);
   }));
  ((void)((&dev_ino_obstack)->next_free += (-dev_ino_size)));
  vdi = ((void *)(&dev_ino_obstack)->next_free);
  di = vdi;
  return *di;
}

static void assert_matching_dev_ino(char const *name, struct dev_ino di) {
  struct stat sb;

  ((void)sizeof((name) ? 1 : 0), __extension__({
     if (name)
       ;
     else
       __assert_fail("name", "src/ls.c", 1064,
                     __extension__ __PRETTY_FUNCTION__);
   }));

  ((void)sizeof((0 <= stat(name, &sb)) ? 1 : 0), __extension__({
     if (0 <= stat(name, &sb))
       ;
     else
       __assert_fail("0 <= stat (name, &sb)", "src/ls.c", 1065,
                     __extension__ __PRETTY_FUNCTION__);
   }));

  ((void)sizeof((sb.st_dev == di.st_dev) ? 1 : 0), __extension__({
     if (sb.st_dev == di.st_dev)
       ;
     else
       __assert_fail("sb.st_dev == di.st_dev", "src/ls.c", 1066,
                     __extension__ __PRETTY_FUNCTION__);
   }));

  ((void)sizeof((sb.st_ino == di.st_ino) ? 1 : 0), __extension__({
     if (sb.st_ino == di.st_ino)
       ;
     else
       __assert_fail("sb.st_ino == di.st_ino", "src/ls.c", 1067,
                     __extension__ __PRETTY_FUNCTION__);
   }));
}

static char eolbyte = '\n';

static void dired_dump_obstack(char const *prefix, struct obstack *os) {
  size_t n_pos;

  n_pos = __extension__({
            struct obstack const *__o = (os);
            (size_t)(__o->next_free - __o->object_base);
          }) /
          sizeof(dired_pos);
  if (n_pos > 0) {
    off_t *pos = __extension__({
      struct obstack *__o1 = (os);
      void *__value = (void *)__o1->object_base;
      if (__o1->next_free == __value)
        __o1->maybe_empty_object = 1;
      __o1->next_free =
          ((sizeof(ptrdiff_t) < sizeof(void *) ? (__o1->object_base)
                                               : (char *)0) +
           (((__o1->next_free) -
             (sizeof(ptrdiff_t) < sizeof(void *) ? (__o1->object_base)
                                                 : (char *)0) +
             (__o1->alignment_mask)) &
            ~(__o1->alignment_mask)));
      if ((size_t)(__o1->next_free - (char *)__o1->chunk) >
          (size_t)(__o1->chunk_limit - (char *)__o1->chunk))
        __o1->next_free = __o1->chunk_limit;
      __o1->object_base = __o1->next_free;
      __value;
    });
    fputs_unlocked(prefix, stdout);
    for (size_t i = 0; i < n_pos; i++) {
      intmax_t p = pos[i];
      printf(" %"
             "l"
             "d",
             p);
    }
    putchar_unlocked('\n');
  }
}

static struct timespec get_stat_btime(struct stat const *st) {
  struct timespec btimespec;

  btimespec = get_stat_mtime(st);

  return btimespec;
}

__attribute__((__pure__)) static unsigned int time_type_to_statx(void) {
  switch (time_type) {
  case time_ctime:
    return 0x00000080U;
  case time_mtime:
    return 0x00000040U;
  case time_atime:
    return 0x00000020U;
  case time_btime:
    return 0x00000800U;
  default:
    abort();
  }
  return 0;
}

__attribute__((__pure__)) static unsigned int calc_req_mask(void) {
  unsigned int mask = 0x00000002U;

  if (print_inode)
    mask |= 0x00000100U;

  if (print_block_size)
    mask |= 0x00000400U;

  if (format == long_format) {
    mask |= 0x00000004U | 0x00000200U | time_type_to_statx();
    if (print_owner || print_author)
      mask |= 0x00000008U;
    if (print_group)
      mask |= 0x00000010U;
  }

  switch (sort_type) {
  case sort_none:
  case sort_name:
  case sort_version:
  case sort_extension:
  case sort_width:
    break;
  case sort_time:
    mask |= time_type_to_statx();
    break;
  case sort_size:
    mask |= 0x00000200U;
    break;
  default:
    abort();
  }

  return mask;
}

static int do_statx(int fd, char const *name, struct stat *st, int flags,
                    unsigned int mask) {
  struct statx stx;

  _Bool want_btime = mask & 0x00000800U;
  int ret = statx(fd, name, flags | 0x800, mask, &stx);
  if (ret >= 0) {
    statx_to_stat(&stx, st);

    if (want_btime) {
      if (stx.stx_mask & 0x00000800U)
        st->st_mtim = statx_timestamp_to_timespec(stx.stx_btime);
      else
        st->st_mtim.tv_sec = st->st_mtim.tv_nsec = -1;
    }
  }

  return ret;
}

static int do_stat(char const *name, struct stat *st) {
  return do_statx(-100, name, st, 0, calc_req_mask());
}

static int do_lstat(char const *name, struct stat *st) {
  return do_statx(-100, name, st, 0x100, calc_req_mask());
}

static int stat_for_mode(char const *name, struct stat *st) {
  return do_statx(-100, name, st, 0, 0x00000002U);
}

static int stat_for_ino(char const *name, struct stat *st) {
  return do_statx(-100, name, st, 0, 0x00000100U);
}

static int fstat_for_ino(int fd, struct stat *st) {
  return do_statx(fd, "", st, 0x1000, 0x00000100U);
}
__attribute__((__pure__)) static char const *first_percent_b(char const *fmt) {
  for (; *fmt; fmt++)
    if (fmt[0] == '%')
      switch (fmt[1]) {
      case 'b':
        return fmt;
      case '%':
        fmt++;
        break;
      }
  return ((void *)0);
}

static char RFC3986[256];
static void file_escape_init(void) {
  for (int i = 0; i < 256; i++)
    RFC3986[i] |= c_isalnum(i) || i == '~' || i == '-' || i == '.' || i == '_';
}
enum { MAX_MON_WIDTH = 12 };

enum { ABFORMAT_SIZE = 128 };
static char abformat[2][12][ABFORMAT_SIZE];

static _Bool use_abformat;

static _Bool

abmon_init(char abmon[12][ABFORMAT_SIZE]) {

  size_t required_mon_width = MAX_MON_WIDTH;
  size_t curr_max_width;
  do {
    curr_max_width = required_mon_width;
    required_mon_width = 0;
    for (int i = 0; i < 12; i++) {
      size_t width = curr_max_width;
      char const *abbr = nl_langinfo(ABMON_1 + i);
      if (strchr(abbr, '%'))
        return 0;
      mbs_align_t alignment = ((*__ctype_b_loc())[(int)((to_uchar(*abbr)))] &
                               (unsigned short int)_ISdigit)

                                  ? MBS_ALIGN_RIGHT
                                  : MBS_ALIGN_LEFT;
      size_t req =
          mbsalign(abbr, abmon[i], ABFORMAT_SIZE, &width, alignment, 0);
      if (!(req < ABFORMAT_SIZE))
        return 0;
      required_mon_width =
          (((required_mon_width) > (width)) ? (required_mon_width) : (width));
    }
  } while (curr_max_width > required_mon_width);

  return 1;
}

static void abformat_init(void) {
  char const *pb[2];
  for (int recent = 0; recent < 2; recent++)
    pb[recent] = first_percent_b(long_time_format[recent]);
  if (!(pb[0] || pb[1]))
    return;

  char abmon[12][ABFORMAT_SIZE];
  if (!abmon_init(abmon))
    return;

  for (int recent = 0; recent < 2; recent++) {
    char const *fmt = long_time_format[recent];
    for (int i = 0; i < 12; i++) {
      char *nfmt = abformat[recent][i];
      int nbytes;

      if (!pb[recent])
        nbytes = snprintf(nfmt, ABFORMAT_SIZE, "%s", fmt);
      else {
        if (!(pb[recent] - fmt <= (((ABFORMAT_SIZE) < (0x7fffffff))
                                       ? (ABFORMAT_SIZE)
                                       : (0x7fffffff))))
          return;
        int prefix_len = pb[recent] - fmt;
        nbytes = snprintf(nfmt, ABFORMAT_SIZE, "%.*s%s%s", prefix_len, fmt,
                          abmon[i], pb[recent] + 2);
      }

      if (!(0 <= nbytes && nbytes < ABFORMAT_SIZE))
        return;
    }
  }

  use_abformat = 1;
}

static size_t dev_ino_hash(void const *x, size_t table_size) {
  struct dev_ino const *p = x;
  return (uintmax_t)p->st_ino % table_size;
}

static _Bool

dev_ino_compare(void const *x, void const *y) {
  struct dev_ino const *a = x;
  struct dev_ino const *b = y;
  return ((*a).st_ino == (*b).st_ino && (*a).st_dev == (*b).st_dev) ? 1 : 0;
}

static void dev_ino_free(void *x) { free(x); }

static _Bool

visit_dir(dev_t dev, ino_t ino) {
  struct dev_ino *ent;
  struct dev_ino *ent_from_table;

  _Bool found_match;

  ent = xmalloc(sizeof *ent);
  ent->st_ino = ino;
  ent->st_dev = dev;

  ent_from_table = hash_insert(active_dir_set, ent);

  if (ent_from_table == ((void *)0)) {

    xalloc_die();
  }

  found_match = (ent_from_table != ent);

  if (found_match) {

    free(ent);
  }

  return found_match;
}

static void free_pending_ent(struct pending *p) {
  free(p->name);
  free(p->realname);
  free(p);
}

static _Bool

is_colored(enum indicator_no type) {
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  return !(len == 0 ||
           (len == 1 && strncmp(s,
                                ""
                                "0"
                                "",
                                sizeof("0") - 1) == 0) ||
           (len == 2 && strncmp(s,
                                ""
                                "00"
                                "",
                                sizeof("00") - 1) == 0));
}

static void restore_default_color(void) {
  put_indicator(&color_indicator[C_LEFT]);
  put_indicator(&color_indicator[C_RIGHT]);
}

static void set_normal_color(void) {
  if (print_with_color && is_colored(C_NORM)) {
    put_indicator(&color_indicator[C_LEFT]);
    put_indicator(&color_indicator[C_NORM]);
    put_indicator(&color_indicator[C_RIGHT]);
  }
}

static void sighandler(int sig) {
  if (!1)
    signal(sig, ((__sighandler_t)1));
  if (!interrupt_signal)
    interrupt_signal = sig;
}

static void stophandler(int sig) {
  if (!1)
    signal(sig, stophandler);
  if (!interrupt_signal)
    stop_signal_count++;
}

static void process_signals(void) {
  while (interrupt_signal || stop_signal_count) {
    int sig;
    int stops;
    sigset_t oldset;

    if (used_color)
      restore_default_color();
    fflush_unlocked(stdout);

    sigprocmask(0, &caught_signals, &oldset);

    sig = interrupt_signal;
    stops = stop_signal_count;

    if (stops) {
      stop_signal_count = stops - 1;
      sig = 19;
    } else
      signal(sig, ((__sighandler_t)0));

    raise(sig);
    sigprocmask(2, &oldset, ((void *)0));
  }
}

static void signal_setup(_Bool init) {

  static int const sig[] = {

      20,

      14, 1, 2, 13, 3, 15,

      29,

      27,

      26,

      24,

      25,

  };
  enum { nsigs = (sizeof(sig) / sizeof *(sig)) };

  int j;

  if (init) {

    struct sigaction act;

    sigemptyset(&caught_signals);
    for (j = 0; j < nsigs; j++) {
      sigaction(sig[j], ((void *)0), &act);
      if (act.__sigaction_handler.sa_handler != ((__sighandler_t)1))
        sigaddset(&caught_signals, sig[j]);
    }

    act.sa_mask = caught_signals;
    act.sa_flags = 0x10000000;

    for (j = 0; j < nsigs; j++)
      if (sigismember(&caught_signals, sig[j])) {
        act.__sigaction_handler.sa_handler =
            sig[j] == 20 ? stophandler : sighandler;
        sigaction(sig[j], &act, ((void *)0));
      }
  } else {

    for (j = 0; j < nsigs; j++)
      if (sigismember(&caught_signals, sig[j]))
        signal(sig[j], ((__sighandler_t)0));
  }
}

static void signal_init(void) { signal_setup(1); }

static void signal_restore(void) { signal_setup(0); }

int main(int argc, char **argv) {
  int i;
  struct pending *thispend;
  int n_files;

  ;
  set_program_name(argv[0]);
  setlocale(6, "");
  bindtextdomain("coreutils", "/usr/local/share/locale");
  textdomain("coreutils");

  initialize_exit_failure(LS_FAILURE);
  atexit(close_stdout);

  ((void)sizeof(((sizeof(color_indicator) / sizeof *(color_indicator)) + 1 ==
                 (sizeof(indicator_name) / sizeof *(indicator_name)))
                    ? 1
                    : 0),
   __extension__({
     if ((sizeof(color_indicator) / sizeof *(color_indicator)) + 1 ==
         (sizeof(indicator_name) / sizeof *(indicator_name)))
       ;
     else
       __assert_fail("ARRAY_CARDINALITY (color_indicator) + 1 == "
                     "ARRAY_CARDINALITY (indicator_name)",
                     "src/ls.c", 1660, __extension__ __PRETTY_FUNCTION__);
   }))

      ;

  exit_status = 0;
  print_dir_name = 1;
  pending_dirs = ((void *)0);

  current_time.tv_sec = ((time_t) ~(
      (time_t)(!(!((time_t)0 < (time_t)-1))
                   ? (time_t)-1
                   : ((((time_t)1 << ((sizeof(time_t) * 8) - 2)) - 1) * 2 +
                      1))));
  current_time.tv_nsec = -1;

  i = decode_switches(argc, argv);

  if (print_with_color)
    parse_ls_color();

  if (print_with_color) {

    tabsize = 0;
  }

  if (directories_first)
    check_symlink_mode = 1;
  else if (print_with_color) {

    if (is_colored(C_ORPHAN) ||
        (is_colored(C_EXEC) && color_symlink_as_referent) ||
        (is_colored(C_MISSING) && format == long_format))
      check_symlink_mode = 1;
  }

  if (dereference == DEREF_UNDEFINED)
    dereference = ((immediate_dirs || indicator_style == classify ||
                    format == long_format)
                       ? DEREF_NEVER
                       : DEREF_COMMAND_LINE_SYMLINK_TO_DIR);

  if (recursive) {
    active_dir_set =
        hash_initialize(INITIAL_TABLE_SIZE, ((void *)0), dev_ino_hash,
                        dev_ino_compare, dev_ino_free);
    if (active_dir_set == ((void *)0))
      xalloc_die();

    _obstack_begin((&dev_ino_obstack), 0, 0, (malloc), (free));
  }

  localtz = tzalloc(getenv("TZ"));

  format_needs_stat = sort_type == sort_time || sort_type == sort_size ||
                      format == long_format || print_scontext ||
                      print_block_size;
  format_needs_type =
      (!format_needs_stat && (recursive || print_with_color ||
                              indicator_style != none || directories_first));

  if (dired) {
    _obstack_begin((&dired_obstack), 0, 0, (malloc), (free));
    _obstack_begin((&subdired_obstack), 0, 0, (malloc), (free));
  }

  if (print_hyperlink) {
    file_escape_init();

    hostname = xgethostname();

    if (!hostname)
      hostname = "";
  }

  cwd_n_alloc = 100;
  cwd_file = xnmalloc(cwd_n_alloc, sizeof *cwd_file);
  cwd_n_used = 0;

  clear_files();

  n_files = argc - i;

  if (n_files <= 0) {
    if (immediate_dirs)
      gobble_file(".", directory, NOT_AN_INODE_NUMBER, 1, "");
    else
      queue_directory(".", ((void *)0), 1);
  } else
    do
      gobble_file(argv[i++], unknown, NOT_AN_INODE_NUMBER, 1, "");
    while (i < argc);

  if (cwd_n_used) {
    sort_files();
    if (!immediate_dirs)
      extract_dirs_from_files(((void *)0), 1);
  }

  if (cwd_n_used) {
    print_current_files();
    if (pending_dirs)
      dired_outbyte('\n');
  } else if (n_files <= 1 && pending_dirs && pending_dirs->next == 0)
    print_dir_name = 0;

  while (pending_dirs) {
    thispend = pending_dirs;
    pending_dirs = pending_dirs->next;

    if ((!!active_dir_set)) {
      if (thispend->name == ((void *)0)) {

        struct dev_ino di = dev_ino_pop();
        struct dev_ino *found = hash_remove(active_dir_set, &di);
        if (0)
          assert_matching_dev_ino(thispend->realname, di);

        ((void)sizeof((found) ? 1 : 0), __extension__({
           if (found)
             ;
           else
             __assert_fail("found", "src/ls.c", 1805,
                           __extension__ __PRETTY_FUNCTION__);
         }));
        dev_ino_free(found);
        free_pending_ent(thispend);
        continue;
      }
    }

    print_dir(thispend->name, thispend->realname, thispend->command_line_arg);

    free_pending_ent(thispend);
    print_dir_name = 1;
  }

  if (print_with_color && used_color) {
    int j;

    if (!(color_indicator[C_LEFT].len == 2 &&
          memcmp(color_indicator[C_LEFT].string, "\033[", 2) == 0 &&
          color_indicator[C_RIGHT].len == 1 &&
          color_indicator[C_RIGHT].string[0] == 'm'))
      restore_default_color();

    fflush_unlocked(stdout);

    signal_restore();

    for (j = stop_signal_count; j; j--)
      raise(19);
    j = interrupt_signal;
    if (j)
      raise(j);
  }

  if (dired) {

    dired_dump_obstack("//DIRED//", &dired_obstack);
    dired_dump_obstack("//SUBDIRED//", &subdired_obstack);
    printf("//DIRED-OPTIONS// --quoting-style=%s\n",
           quoting_style_args[get_quoting_style(filename_quoting_options)]);
  }

  if ((!!active_dir_set)) {

    ((void)sizeof((hash_get_n_entries(active_dir_set) == 0) ? 1 : 0),
     __extension__({
       if (hash_get_n_entries(active_dir_set) == 0)
         ;
       else
         __assert_fail("hash_get_n_entries (active_dir_set) == 0", "src/ls.c",
                       1857, __extension__ __PRETTY_FUNCTION__);
     }));
    hash_free(active_dir_set);
  }

  return exit_status;
}

static ptrdiff_t decode_line_length(char const *spec) {
  uintmax_t val;

  switch (xstrtoumax(spec, ((void *)0), 0, &val, "")) {
  case LONGINT_OK:
    return val <= ((((9223372036854775807L)) < ((18446744073709551615UL)))
                       ? ((9223372036854775807L))
                       : ((18446744073709551615UL)))
               ? val
               : 0;

  case LONGINT_OVERFLOW:
    return 0;

  default:
    return -1;
  }
}

static _Bool

stdout_isatty(void) {
  static signed char out_tty = -1;
  if (out_tty < 0)
    out_tty = isatty(1);
  ((out_tty == 0 || out_tty == 1) ? (void)0 : __builtin_unreachable());
  return out_tty;
}

static int decode_switches(int argc, char **argv) {
  char *time_style_option = ((void *)0);

  _Bool kibibytes_specified = 0;
  int format_opt = -1;
  int hide_control_chars_opt = -1;
  int quoting_style_opt = -1;
  int sort_opt = -1;
  ptrdiff_t tabsize_opt = -1;
  ptrdiff_t width_opt = -1;

  while (1) {
    int oi = -1;
    int c =
        getopt_long(argc, argv, "abcdfghiklmnopqrstuvw:xABCDFGHI:LNQRST:UXZ1",
                    long_options, &oi);
    if (c == -1)
      break;

    switch (c) {
    case 'a':
      ignore_mode = IGNORE_MINIMAL;
      break;

    case 'b':
      quoting_style_opt = escape_quoting_style;
      break;

    case 'c':
      time_type = time_ctime;
      break;

    case 'd':
      immediate_dirs = 1;
      break;

    case 'f':

      ignore_mode = IGNORE_MINIMAL;
      sort_opt = sort_none;
      if (format_opt == long_format)
        format_opt = -1;
      print_with_color = 0;
      print_hyperlink = 0;
      print_block_size = 0;
      break;

    case FILE_TYPE_INDICATOR_OPTION:
      indicator_style = file_type;
      break;

    case 'g':
      format_opt = long_format;
      print_owner = 0;
      break;

    case 'h':
      file_human_output_opts = human_output_opts =
          human_autoscale | human_SI | human_base_1024;
      file_output_block_size = output_block_size = 1;
      break;

    case 'i':
      print_inode = 1;
      break;

    case 'k':
      kibibytes_specified = 1;
      break;

    case 'l':
      format_opt = long_format;
      break;

    case 'm':
      format_opt = with_commas;
      break;

    case 'n':
      numeric_ids = 1;
      format_opt = long_format;
      break;

    case 'o':
      format_opt = long_format;
      print_group = 0;
      break;

    case 'p':
      indicator_style = slash;
      break;

    case 'q':
      hide_control_chars_opt = 1;
      break;

    case 'r':
      sort_reverse = 1;
      break;

    case 's':
      print_block_size = 1;
      break;

    case 't':
      sort_opt = sort_time;
      break;

    case 'u':
      time_type = time_atime;
      break;

    case 'v':
      sort_opt = sort_version;
      break;

    case 'w':
      width_opt = decode_line_length(optarg);
      if (width_opt < 0)
        ((!!sizeof(struct {
          _Static_assert(
              LS_FAILURE,
              "verify_expr ("
              "LS_FAILURE"
              ", "
              "(error (LS_FAILURE, 0, \"%s: %s\", dcgettext (((void *)0), "
              "\"invalid line width\", 5), quote (optarg)), assume (false))"
              ")");
          int _gl_dummy;
        }))
             ? ((error(LS_FAILURE, 0, "%s: %s",
                       dcgettext(((void *)0), "invalid line width", 5),
                       quote(optarg)),
                 ((0) ? (void)0 : __builtin_unreachable())))
             : ((error(LS_FAILURE, 0, "%s: %s",
                       dcgettext(((void *)0), "invalid line width", 5),
                       quote(optarg)),
                 ((0) ? (void)0 : __builtin_unreachable()))));
      break;

    case 'x':
      format_opt = horizontal;
      break;

    case 'A':
      ignore_mode = IGNORE_DOT_AND_DOTDOT;
      break;

    case 'B':
      add_ignore_pattern("*~");
      add_ignore_pattern(".*~");
      break;

    case 'C':
      format_opt = many_per_line;
      break;

    case 'D':
      dired = 1;
      break;

    case 'F': {
      int i;
      if (optarg)
        i = ((when_types)[__xargmatch_internal(
            "--classify", optarg, when_args, (void const *)(when_types),
            sizeof *(when_types), argmatch_die, 1)]);
      else

        i = when_always;

      if (i == when_always || (i == when_if_tty && stdout_isatty()))
        indicator_style = classify;
      break;
    }

    case 'G':
      print_group = 0;
      break;

    case 'H':
      dereference = DEREF_COMMAND_LINE_ARGUMENTS;
      break;

    case DEREFERENCE_COMMAND_LINE_SYMLINK_TO_DIR_OPTION:
      dereference = DEREF_COMMAND_LINE_SYMLINK_TO_DIR;
      break;

    case 'I':
      add_ignore_pattern(optarg);
      break;

    case 'L':
      dereference = DEREF_ALWAYS;
      break;

    case 'N':
      quoting_style_opt = literal_quoting_style;
      break;

    case 'Q':
      quoting_style_opt = c_quoting_style;
      break;

    case 'R':
      recursive = 1;
      break;

    case 'S':
      sort_opt = sort_size;
      break;

    case 'T':
      tabsize_opt = xnumtoumax(
          optarg, 0, 0,
          ((((9223372036854775807L)) < ((18446744073709551615UL)))
               ? ((9223372036854775807L))
               : ((18446744073709551615UL))),
          "", dcgettext(((void *)0), "invalid tab size", 5), LS_FAILURE);
      break;

    case 'U':
      sort_opt = sort_none;
      break;

    case 'X':
      sort_opt = sort_extension;
      break;

    case '1':

      if (format_opt != long_format)
        format_opt = one_per_line;
      break;

    case AUTHOR_OPTION:
      print_author = 1;
      break;

    case HIDE_OPTION: {
      struct ignore_pattern *hide = xmalloc(sizeof *hide);
      hide->pattern = optarg;
      hide->next = hide_patterns;
      hide_patterns = hide;
    } break;

    case SORT_OPTION:
      sort_opt = ((sort_types)[__xargmatch_internal(
          "--sort", optarg, sort_args, (void const *)(sort_types),
          sizeof *(sort_types), argmatch_die, 1)]);
      break;

    case GROUP_DIRECTORIES_FIRST_OPTION:
      directories_first = 1;
      break;

    case TIME_OPTION:
      time_type = ((time_types)[__xargmatch_internal(
          "--time", optarg, time_args, (void const *)(time_types),
          sizeof *(time_types), argmatch_die, 1)]);
      break;

    case FORMAT_OPTION:
      format_opt = ((format_types)[__xargmatch_internal(
          "--format", optarg, format_args, (void const *)(format_types),
          sizeof *(format_types), argmatch_die, 1)]);
      break;

    case FULL_TIME_OPTION:
      format_opt = long_format;
      time_style_option = bad_cast("full-iso");
      break;

    case COLOR_OPTION: {
      int i;
      if (optarg)
        i = ((when_types)[__xargmatch_internal(
            "--color", optarg, when_args, (void const *)(when_types),
            sizeof *(when_types), argmatch_die, 1)]);
      else

        i = when_always;

      print_with_color =
          (i == when_always || (i == when_if_tty && stdout_isatty()));
      break;
    }

    case HYPERLINK_OPTION: {
      int i;
      if (optarg)
        i = ((when_types)[__xargmatch_internal(
            "--hyperlink", optarg, when_args, (void const *)(when_types),
            sizeof *(when_types), argmatch_die, 1)]);
      else

        i = when_always;

      print_hyperlink =
          (i == when_always || (i == when_if_tty && stdout_isatty()));
      break;
    }

    case INDICATOR_STYLE_OPTION:
      indicator_style = ((indicator_style_types)[__xargmatch_internal(
          "--indicator-style", optarg, indicator_style_args,
          (void const *)(indicator_style_types),
          sizeof *(indicator_style_types), argmatch_die, 1)])

          ;
      break;

    case QUOTING_STYLE_OPTION:
      quoting_style_opt = ((quoting_style_vals)[__xargmatch_internal(
          "--quoting-style", optarg, quoting_style_args,
          (void const *)(quoting_style_vals), sizeof *(quoting_style_vals),
          argmatch_die, 1)])

          ;
      break;

    case TIME_STYLE_OPTION:
      time_style_option = optarg;
      break;

    case SHOW_CONTROL_CHARS_OPTION:
      hide_control_chars_opt = 0;
      break;

    case BLOCK_SIZE_OPTION: {
      enum strtol_error e =
          human_options(optarg, &human_output_opts, &output_block_size);
      if (e != LONGINT_OK)
        xstrtol_fatal(e, oi, 0, long_options, optarg);
      file_human_output_opts = human_output_opts;
      file_output_block_size = output_block_size;
    } break;

    case SI_OPTION:
      file_human_output_opts = human_output_opts = human_autoscale | human_SI;
      file_output_block_size = output_block_size = 1;
      break;

    case 'Z':
      print_scontext = 1;
      break;

    case ZERO_OPTION:
      eolbyte = 0;
      hide_control_chars_opt = 0;
      if (format_opt != long_format)
        format_opt = one_per_line;
      print_with_color = 0;
      quoting_style_opt = literal_quoting_style;
      break;

    case GETOPT_HELP_CHAR:
      usage(0);
      break;
      ;

    case GETOPT_VERSION_CHAR:
      version_etc(stdout,
                  (ls_mode == 1 ? "ls" : (ls_mode == 2 ? "dir" : "vdir")),
                  "GNU coreutils", Version, ("Richard M. Stallman"),
                  ("David MacKenzie"), (char *)((void *)0));
      exit(0);
      break;
      ;

    default:
      usage(LS_FAILURE);
    }
  }

  if (!output_block_size) {
    char const *ls_block_size = getenv("LS_BLOCK_SIZE");
    human_options(ls_block_size, &human_output_opts, &output_block_size);
    if (ls_block_size || getenv("BLOCK_SIZE")) {
      file_human_output_opts = human_output_opts;
      file_output_block_size = output_block_size;
    }
    if (kibibytes_specified) {
      human_output_opts = 0;
      output_block_size = 1024;
    }
  }

  format = (0 <= format_opt ? format_opt
            : ls_mode == 1  ? (stdout_isatty() ? many_per_line : one_per_line)
            : ls_mode == 2  ? many_per_line
                            : long_format);

  ptrdiff_t linelen = width_opt;
  if (format == many_per_line || format == horizontal ||
      format == with_commas || print_with_color) {

    if (linelen < 0) {

      struct winsize ws;
      if (stdout_isatty() && 0 <= ioctl(1, 0x5413, &ws) && 0 < ws.ws_col)
        linelen =
            ws.ws_col <=
                    ((((9223372036854775807L)) < ((18446744073709551615UL)))
                         ? ((9223372036854775807L))
                         : ((18446744073709551615UL)))
                ? ws.ws_col
                : 0;
    }

    if (linelen < 0) {
      char const *p = getenv("COLUMNS");
      if (p && *p) {
        linelen = decode_line_length(p);
        if (linelen < 0)
          error(0, 0,

                dcgettext(((void *)0),
                          "ignoring invalid width"
                          " in environment variable COLUMNS: %s",
                          5)

                    ,
                quote(p));
      }
    }
  }

  line_length = linelen < 0 ? 80 : linelen;

  max_idx = line_length / MIN_COLUMN_WIDTH;

  max_idx += line_length % MIN_COLUMN_WIDTH != 0;

  if (format == many_per_line || format == horizontal ||
      format == with_commas) {
    if (0 <= tabsize_opt)
      tabsize = tabsize_opt;
    else {
      tabsize = 8;
      char const *p = getenv("TABSIZE");
      if (p) {
        uintmax_t tmp;
        if (xstrtoumax(p, ((void *)0), 0, &tmp, "") == LONGINT_OK &&
            tmp <= (18446744073709551615UL))
          tabsize = tmp;
        else
          error(0, 0,

                dcgettext(((void *)0),
                          "ignoring invalid tab size"
                          " in environment variable TABSIZE: %s",
                          5)

                    ,
                quote(p));
      }
    }
  }

  qmark_funny_chars =
      (hide_control_chars_opt < 0 ? ls_mode == 1 && stdout_isatty()
                                  : hide_control_chars_opt);

  int qs = quoting_style_opt;
  if (qs < 0)
    qs = getenv_quoting_style();
  if (qs < 0)
    qs = (ls_mode == 1 ? (stdout_isatty() ? shell_escape_quoting_style : -1)
                       : escape_quoting_style);
  if (0 <= qs)
    set_quoting_style(((void *)0), qs);
  qs = get_quoting_style(((void *)0));
  align_variable_outer_quotes =
      ((format == long_format ||
        ((format == many_per_line || format == horizontal) && line_length)) &&
       (qs == shell_quoting_style || qs == shell_escape_quoting_style ||
        qs == c_maybe_quoting_style));
  filename_quoting_options = clone_quoting_options(((void *)0));
  if (qs == escape_quoting_style)
    set_char_quoting(filename_quoting_options, ' ', 1);
  if (file_type <= indicator_style) {
    char const *p;
    for (p = &"*=>@|"[indicator_style - file_type]; *p; p++)
      set_char_quoting(filename_quoting_options, *p, 1);
  }

  dirname_quoting_options = clone_quoting_options(((void *)0));
  set_char_quoting(dirname_quoting_options, ':', 1);

  dired &= (format == long_format) & !print_hyperlink;

  if (eolbyte < dired)
    ((!!sizeof(struct {
      _Static_assert(LS_FAILURE,
                     "verify_expr ("
                     "LS_FAILURE"
                     ", "
                     "(error (LS_FAILURE, 0, dcgettext (((void *)0), \"--dired "
                     "and --zero are incompatible\", 5)), assume (false))"
                     ")");
      int _gl_dummy;
    }))
         ? ((error(LS_FAILURE, 0,
                   dcgettext(((void *)0), "--dired and --zero are incompatible",
                             5)),
             ((0) ? (void)0 : __builtin_unreachable())))
         : ((error(LS_FAILURE, 0,
                   dcgettext(((void *)0), "--dired and --zero are incompatible",
                             5)),
             ((0) ? (void)0 : __builtin_unreachable()))));
  sort_type = (0 <= sort_opt ? sort_opt
               : (format != long_format &&
                  (time_type == time_ctime || time_type == time_atime ||
                   time_type == time_btime))
                   ? sort_time
                   : sort_name);

  if (format == long_format) {
    char *style = time_style_option;
    static char const posix_prefix[] = "posix-";

    if (!style)
      if (!(style = getenv("TIME_STYLE")))
        style = bad_cast("locale");

    while ((strncmp(style, posix_prefix, sizeof posix_prefix - 1) == 0)) {
      if (!hard_locale(2))
        return optind;
      style += sizeof posix_prefix - 1;
    }

    if (*style == '+') {
      char *p0 = style + 1;
      char *p1 = strchr(p0, '\n');
      if (!p1)
        p1 = p0;
      else {
        if (strchr(p1 + 1, '\n'))
          ((!!sizeof(struct {
            _Static_assert(
                LS_FAILURE,
                "verify_expr ("
                "LS_FAILURE"
                ", "
                "(error (LS_FAILURE, 0, dcgettext (((void *)0), \"invalid time "
                "style format %s\", 5), quote (p0)), assume (false))"
                ")");
            int _gl_dummy;
          }))
               ? ((error(LS_FAILURE, 0,
                         dcgettext(((void *)0), "invalid time style format %s",
                                   5),
                         quote(p0)),
                   ((0) ? (void)0 : __builtin_unreachable())))
               : ((error(LS_FAILURE, 0,
                         dcgettext(((void *)0), "invalid time style format %s",
                                   5),
                         quote(p0)),
                   ((0) ? (void)0 : __builtin_unreachable()))));
        *p1++ = '\0';
      }
      long_time_format[0] = p0;
      long_time_format[1] = p1;
    } else {
      ptrdiff_t res =
          argmatch(style, time_style_args, (char const *)time_style_types,
                   sizeof(*time_style_types));
      if (res < 0) {

        argmatch_invalid("time style", style, res);

        fputs_unlocked(dcgettext(((void *)0), "Valid arguments are:\n", 5),
                       stderr);
        char const *const *p = time_style_args;
        while (*p)
          fprintf(stderr, "  - [posix-]%s\n", *p++);
        fputs_unlocked(dcgettext(((void *)0),
                                 "  - +FORMAT (e.g., +%H:%M) for a 'date'-style"
                                 " format\n",
                                 5),
                       stderr);
        usage(LS_FAILURE);
      }
      switch (res) {
      case full_iso_time_style:
        long_time_format[0] = long_time_format[1] = "%Y-%m-%d %H:%M:%S.%N %z";
        break;

      case long_iso_time_style:
        long_time_format[0] = long_time_format[1] = "%Y-%m-%d %H:%M";
        break;

      case iso_time_style:
        long_time_format[0] = "%Y-%m-%d ";
        long_time_format[1] = "%m-%d %H:%M";
        break;

      case locale_time_style:
        if (hard_locale(2)) {
          for (int i = 0; i < 2; i++)
            long_time_format[i] =
                dcgettext(((void *)0), long_time_format[i], 2);
        }
      }
    }

    abformat_init();
  }

  return optind;
}
static _Bool

get_funky_string(char **dest, char const **src, _Bool equals_end,
                 size_t *output_count) {
  char num;
  size_t count;
  enum {
    ST_GND,
    ST_BACKSLASH,
    ST_OCTAL,
    ST_HEX,
    ST_CARET,
    ST_END,
    ST_ERROR
  } state;
  char const *p;
  char *q;

  p = *src;
  q = *dest;

  count = 0;
  num = 0;

  state = ST_GND;
  while (state < ST_END) {
    switch (state) {
    case ST_GND:
      switch (*p) {
      case ':':
      case '\0':
        state = ST_END;
        break;
      case '\\':
        state = ST_BACKSLASH;
        ++p;
        break;
      case '^':
        state = ST_CARET;
        ++p;
        break;
      case '=':
        if (equals_end) {
          state = ST_END;
          break;
        };
      default:
        *(q++) = *(p++);
        ++count;
        break;
      }
      break;

    case ST_BACKSLASH:
      switch (*p) {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
        state = ST_OCTAL;
        num = *p - '0';
        break;
      case 'x':
      case 'X':
        state = ST_HEX;
        num = 0;
        break;
      case 'a':
        num = '\a';
        break;
      case 'b':
        num = '\b';
        break;
      case 'e':
        num = 27;
        break;
      case 'f':
        num = '\f';
        break;
      case 'n':
        num = '\n';
        break;
      case 'r':
        num = '\r';
        break;
      case 't':
        num = '\t';
        break;
      case 'v':
        num = '\v';
        break;
      case '?':
        num = 127;
        break;
      case '_':
        num = ' ';
        break;
      case '\0':
        state = ST_ERROR;
        break;
      default:
        num = *p;
        break;
      }
      if (state == ST_BACKSLASH) {
        *(q++) = num;
        ++count;
        state = ST_GND;
      }
      ++p;
      break;

    case ST_OCTAL:
      if (*p < '0' || *p > '7') {
        *(q++) = num;
        ++count;
        state = ST_GND;
      } else
        num = (num << 3) + (*(p++) - '0');
      break;

    case ST_HEX:
      switch (*p) {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        num = (num << 4) + (*(p++) - '0');
        break;
      case 'a':
      case 'b':
      case 'c':
      case 'd':
      case 'e':
      case 'f':
        num = (num << 4) + (*(p++) - 'a') + 10;
        break;
      case 'A':
      case 'B':
      case 'C':
      case 'D':
      case 'E':
      case 'F':
        num = (num << 4) + (*(p++) - 'A') + 10;
        break;
      default:
        *(q++) = num;
        ++count;
        state = ST_GND;
        break;
      }
      break;

    case ST_CARET:
      state = ST_GND;
      if (*p >= '@' && *p <= '~') {
        *(q++) = *(p++) & 037;
        ++count;
      } else if (*p == '?') {
        *(q++) = 127;
        ++count;
      } else
        state = ST_ERROR;
      break;

    default:
      abort();
    }
  }

  *dest = q;
  *src = p;
  *output_count = count;

  return state != ST_ERROR;
}

enum parse_state { PS_START = 1, PS_2, PS_3, PS_4, PS_DONE, PS_FAIL };

static _Bool

known_term_type(void) {
  char const *term = getenv("TERM");
  if (!term || !*term)
    return 0;

  char const *line = G_line;
  while (line - G_line < sizeof(G_line)) {
    if (strncmp(line,
                ""
                "TERM "
                "",
                sizeof("TERM ") - 1) == 0) {
      if (fnmatch(line + 5, term, 0) == 0)
        return 1;
    }
    line += strlen(line) + 1;
  }

  return 0;
}

static void parse_ls_color(void) {
  char const *p;
  char *buf;
  int ind_no;
  char label[3];
  struct color_ext_type *ext;

  if ((p = getenv("LS_COLORS")) == ((void *)0) || *p == '\0') {

    char const *colorterm = getenv("COLORTERM");
    if (!(colorterm && *colorterm) && !known_term_type())
      print_with_color = 0;
    return;
  }

  ext = ((void *)0);
  strcpy(label, "??");

  buf = color_buf = xstrdup(p);

  enum parse_state state = PS_START;
  while (1) {
    switch (state) {
    case PS_START:
      switch (*p) {
      case ':':
        ++p;
        break;

      case '*':

        ext = xmalloc(sizeof *ext);
        ext->next = color_ext_list;
        color_ext_list = ext;

        ++p;
        ext->ext.string = buf;

        state = (get_funky_string(&buf, &p, 1, &ext->ext.len) ? PS_4 : PS_FAIL);
        break;

      case '\0':
        state = PS_DONE;
        goto done;

      default:
        label[0] = *(p++);
        state = PS_2;
        break;
      }
      break;

    case PS_2:
      if (*p) {
        label[1] = *(p++);
        state = PS_3;
      } else
        state = PS_FAIL;
      break;

    case PS_3:
      state = PS_FAIL;
      if (*(p++) == '=') {
        for (ind_no = 0; indicator_name[ind_no] != ((void *)0); ++ind_no) {
          if ((strcmp(label, indicator_name[ind_no]) == 0)) {
            color_indicator[ind_no].string = buf;
            state = (get_funky_string(&buf, &p, 0, &color_indicator[ind_no].len)
                         ? PS_START
                         : PS_FAIL);
            break;
          }
        }
        if (state == PS_FAIL)
          error(0, 0, dcgettext(((void *)0), "unrecognized prefix: %s", 5),
                quote(label));
      }
      break;

    case PS_4:
      if (*(p++) == '=') {
        ext->seq.string = buf;
        state =
            (get_funky_string(&buf, &p, 0, &ext->seq.len) ? PS_START : PS_FAIL);
      } else
        state = PS_FAIL;
      break;

    case PS_FAIL:
      goto done;

    default:
      abort();
    }
  }
done:

  if (state == PS_FAIL) {
    struct color_ext_type *e;
    struct color_ext_type *e2;

    error(0, 0,

          dcgettext(((void *)0),
                    "unparsable value for LS_COLORS environment variable", 5));
    free(color_buf);
    for (e = color_ext_list; e != ((void *)0);) {
      e2 = e;
      e = e->next;
      free(e2);
    }
    print_with_color = 0;
  }

  if (color_indicator[C_LINK].len == 6 &&
      !strncmp(color_indicator[C_LINK].string,
               ""
               "target"
               "",
               sizeof("target") - 1))
    color_symlink_as_referent = 1;
}

static int getenv_quoting_style(void) {
  char const *q_style = getenv("QUOTING_STYLE");
  if (!q_style)
    return -1;
  int i =
      argmatch(q_style, quoting_style_args, (void const *)(quoting_style_vals),
               sizeof *(quoting_style_vals));
  if (i < 0) {
    error(0, 0,

          dcgettext(((void *)0),
                    "ignoring invalid value"
                    " of environment variable QUOTING_STYLE: %s",
                    5)

              ,
          quote(q_style));
    return -1;
  }
  return quoting_style_vals[i];
}

static void set_exit_status(_Bool serious) {
  if (serious)
    exit_status = LS_FAILURE;
  else if (exit_status == 0)
    exit_status = LS_MINOR_PROBLEM;
}

static void file_failure(_Bool serious, char const *message, char const *file) {
  error(0, (*__errno_location()), message,
        quotearg_style(shell_escape_always_quoting_style, file));
  set_exit_status(serious);
}
static void queue_directory(char const *name, char const *realname,
                            _Bool command_line_arg) {
  struct pending *new = xmalloc(sizeof *new);
  new->realname = realname ? xstrdup(realname) : ((void *)0);
  new->name = name ? xstrdup(name) : ((void *)0);
  new->command_line_arg = command_line_arg;
  new->next = pending_dirs;
  pending_dirs = new;
}

static void print_dir(char const *name, char const *realname,
                      _Bool command_line_arg) {
  DIR *dirp;
  struct dirent *next;
  uintmax_t total_blocks = 0;
  static _Bool first = 1;

  (*__errno_location()) = 0;
  dirp = opendir(name);
  if (!dirp) {
    file_failure(command_line_arg,
                 dcgettext(((void *)0), "cannot open directory %s", 5), name);
    return;
  }

  if ((!!active_dir_set)) {
    struct stat dir_stat;
    int fd = dirfd(dirp);

    if ((0 <= fd ? fstat_for_ino(fd, &dir_stat)
                 : stat_for_ino(name, &dir_stat)) < 0) {
      file_failure(
          command_line_arg,

          dcgettext(((void *)0), "cannot determine device and inode of %s", 5),
          name);
      closedir(dirp);
      return;
    }

    if (visit_dir(dir_stat.st_dev, dir_stat.st_ino)) {
      error(
          0, 0,
          dcgettext(((void *)0), "%s: not listing already-listed directory", 5),
          quotearg_n_style_colon(0, shell_escape_quoting_style, name));
      closedir(dirp);
      set_exit_status(1);
      return;
    }

    dev_ino_push(dir_stat.st_dev, dir_stat.st_ino);
  }

  clear_files();

  if (recursive || print_dir_name) {
    if (!first)
      dired_outbyte('\n');
    first = 0;
    dired_indent();

    char *absolute_name = ((void *)0);
    if (print_hyperlink) {
      absolute_name = canonicalize_filename_mode(name, CAN_MISSING);
      if (!absolute_name)
        file_failure(command_line_arg,

                     dcgettext(((void *)0), "error canonicalizing %s", 5),
                     name);
    }
    quote_name(realname ? realname : name, dirname_quoting_options, -1,

               ((void *)0), 1, &subdired_obstack, absolute_name);

    free(absolute_name);

    dired_outstring(":\n");
  }

  while (1) {

    (*__errno_location()) = 0;
    next = readdir(dirp);
    if (next) {
      if (!file_ignored(next->d_name)) {
        enum filetype type = unknown;

        switch (next->d_type) {
        case DT_BLK:
          type = blockdev;
          break;
        case DT_CHR:
          type = chardev;
          break;
        case DT_DIR:
          type = directory;
          break;
        case DT_FIFO:
          type = fifo;
          break;
        case DT_LNK:
          type = symbolic_link;
          break;
        case DT_REG:
          type = normal;
          break;
        case DT_SOCK:
          type = sock;
          break;

        case DT_WHT:
          type = whiteout;
          break;
        }

        total_blocks += gobble_file(next->d_name, type, NOT_AN_INODE_NUMBER,

                                    0, name);

        if (format == one_per_line && sort_type == sort_none &&
            !print_block_size && !recursive) {

          sort_files();
          print_current_files();
          clear_files();
        }
      }
    } else if ((*__errno_location()) != 0) {
      file_failure(command_line_arg,
                   dcgettext(((void *)0), "reading directory %s", 5), name);
      if ((*__errno_location()) != 75)
        break;
    } else
      break;

    process_signals();
  }

  if (closedir(dirp) != 0) {
    file_failure(command_line_arg,
                 dcgettext(((void *)0), "closing directory %s", 5), name);
  }

  sort_files();

  if (recursive)
    extract_dirs_from_files(name, 0);

  if (format == long_format || print_block_size) {
    char buf[((2 * sizeof(uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 + 1 +
              3) +
             3];
    char *p = human_readable(total_blocks, buf + 1, human_output_opts,

                             512, output_block_size);
    char *pend = p + strlen(p);
    *--p = ' ';
    *pend++ = eolbyte;
    dired_indent();
    dired_outstring(dcgettext(((void *)0), "total", 5));
    dired_outbuf(p, pend - p);
  }

  if (cwd_n_used)
    print_current_files();
}

static void add_ignore_pattern(char const *pattern) {
  struct ignore_pattern *ignore;

  ignore = xmalloc(sizeof *ignore);
  ignore->pattern = pattern;

  ignore->next = ignore_patterns;
  ignore_patterns = ignore;
}

static _Bool

patterns_match(struct ignore_pattern const *patterns, char const *file) {
  struct ignore_pattern const *p;
  for (p = patterns; p; p = p->next)
    if (fnmatch(p->pattern, file, (1 << 2)) == 0)
      return 1;
  return 0;
}

static _Bool

file_ignored(char const *name) {
  return (
      (ignore_mode != IGNORE_MINIMAL && name[0] == '.' &&
       (ignore_mode == IGNORE_DEFAULT || !name[1 + (name[1] == '.')])) ||
      (ignore_mode == IGNORE_DEFAULT && patterns_match(hide_patterns, name)) ||
      patterns_match(ignore_patterns, name));
}

static uintmax_t unsigned_file_size(off_t size) {
  return size +
         (size < 0) *
             ((uintmax_t)((
                  off_t)(!(!((off_t)0 < (off_t)-1))
                             ? (off_t)-1
                             : ((((off_t)1 << ((sizeof(off_t) * 8) - 2)) - 1) *
                                    2 +
                                1))) -
              ((off_t) ~(
                  (off_t)(!(!((off_t)0 < (off_t)-1))
                              ? (off_t)-1
                              : ((((off_t)1 << ((sizeof(off_t) * 8) - 2)) - 1) *
                                     2 +
                                 1)))) +
              1);
}

static _Bool

has_capability(char const *name) {
  char *result;

  _Bool has_cap;

  cap_t cap_d = cap_get_file(name);
  if (cap_d == ((void *)0))
    return 0;

  result = cap_to_text(cap_d, ((void *)0));
  cap_free(cap_d);
  if (!result)
    return 0;

  has_cap = !!*result;

  cap_free(result);
  return has_cap;
}
static void free_ent(struct fileinfo *f) {
  free(f->name);
  free(f->linkname);
  free(f->absolute_name);
  if (f->scontext != UNKNOWN_SECURITY_CONTEXT) {
    if (is_smack_enabled())
      free(f->scontext);
    else
      freecon(f->scontext);
  }
}

static void clear_files(void) {
  for (size_t i = 0; i < cwd_n_used; i++) {
    struct fileinfo *f = sorted_file[i];
    free_ent(f);
  }

  cwd_n_used = 0;
  cwd_some_quoted = 0;
  any_has_acl = 0;
  inode_number_width = 0;
  block_size_width = 0;
  nlink_width = 0;
  owner_width = 0;
  group_width = 0;
  author_width = 0;
  scontext_width = 0;
  major_device_number_width = 0;
  minor_device_number_width = 0;
  file_size_width = 0;
}

static _Bool

errno_unsupported(int err) {
  return (err == 22 || err == 38 || is_ENOTSUP(err));
}

static int getfilecon_cache(char const *file, struct fileinfo *f, _Bool deref) {

  static dev_t unsupported_device;

  if (f->stat.st_dev == unsupported_device) {

    (*__errno_location()) = 95;
    return -1;
  }
  int r = 0;

  r = (deref ? rpl_getfilecon(file, &f->scontext)
             : rpl_lgetfilecon(file, &f->scontext));
  if (r < 0 && errno_unsupported((*__errno_location())))
    unsupported_device = f->stat.st_dev;
  return r;
}

static int file_has_acl_cache(char const *file, struct fileinfo *f) {

  static dev_t unsupported_device;

  if (f->stat.st_dev == unsupported_device) {

    (*__errno_location()) = 95;
    return 0;
  }

  (*__errno_location()) = 0;
  int n = file_has_acl(file, &f->stat);
  if (n <= 0 && errno_unsupported((*__errno_location())))
    unsupported_device = f->stat.st_dev;
  return n;
}

static _Bool

has_capability_cache(char const *file, struct fileinfo *f) {

  static dev_t unsupported_device;

  if (f->stat.st_dev == unsupported_device) {

    (*__errno_location()) = 95;
    return 0;
  }

  _Bool b = has_capability(file);
  if (!b && errno_unsupported((*__errno_location())))
    unsupported_device = f->stat.st_dev;
  return b;
}

static _Bool

needs_quoting(char const *name) {
  char test[2];
  size_t len =
      quotearg_buffer(test, sizeof test, name, -1, filename_quoting_options);
  return *name != *test || strlen(name) != len;
}

static uintmax_t gobble_file(char const *name, enum filetype type, ino_t inode,

                             _Bool command_line_arg, char const *dirname) {
  uintmax_t blocks = 0;
  struct fileinfo *f;

  ((void)sizeof((!command_line_arg || inode == NOT_AN_INODE_NUMBER) ? 1 : 0),
   __extension__({
     if (!command_line_arg || inode == NOT_AN_INODE_NUMBER)
       ;
     else
       __assert_fail("! command_line_arg || inode == NOT_AN_INODE_NUMBER",
                     "src/ls.c", 3335, __extension__ __PRETTY_FUNCTION__);
   }));

  if (cwd_n_used == cwd_n_alloc) {
    cwd_file = xnrealloc(cwd_file, cwd_n_alloc, 2 * sizeof *cwd_file);
    cwd_n_alloc *= 2;
  }

  f = &cwd_file[cwd_n_used];
  memset(f, '\0', sizeof *f);
  f->stat.st_ino = inode;
  f->filetype = type;

  f->quoted = -1;
  if ((!cwd_some_quoted) && align_variable_outer_quotes) {

    f->quoted = needs_quoting(name);
    if (f->quoted)
      cwd_some_quoted = 1;
  }

  if (command_line_arg || print_hyperlink || format_needs_stat

      || (type == directory && print_with_color &&
          (is_colored(C_OTHER_WRITABLE) || is_colored(C_STICKY) ||
           is_colored(C_STICKY_OTHER_WRITABLE)))

      || ((print_inode || format_needs_type) &&
          (type == symbolic_link || type == unknown) &&
          (dereference == DEREF_ALWAYS || color_symlink_as_referent ||
           check_symlink_mode))

      || (print_inode && inode == NOT_AN_INODE_NUMBER) ||
      (format_needs_type &&
       (type == unknown || command_line_arg

        || (type == normal &&
            (indicator_style == classify

             || (print_with_color &&
                 (is_colored(C_EXEC) || is_colored(C_SETUID) ||
                  is_colored(C_SETGID) || is_colored(C_CAP))))))))

  {

    char *full_name;

    _Bool do_deref;
    int err;

    if (name[0] == '/' || dirname[0] == 0)
      full_name = (char *)name;
    else {
      full_name = __builtin_alloca(strlen(name) + strlen(dirname) + 2);
      attach(full_name, dirname, name);
    }

    if (print_hyperlink) {
      f->absolute_name = canonicalize_filename_mode(full_name, CAN_MISSING);
      if (!f->absolute_name)
        file_failure(command_line_arg,

                     dcgettext(((void *)0), "error canonicalizing %s", 5),
                     full_name);
    }

    switch (dereference) {
    case DEREF_ALWAYS:
      err = do_stat(full_name, &f->stat);
      do_deref = 1;
      break;

    case DEREF_COMMAND_LINE_ARGUMENTS:
    case DEREF_COMMAND_LINE_SYMLINK_TO_DIR:
      if (command_line_arg) {

        _Bool need_lstat;
        err = do_stat(full_name, &f->stat);
        do_deref = 1;

        if (dereference == DEREF_COMMAND_LINE_ARGUMENTS)
          break;

        need_lstat =
            (err < 0 ? (*__errno_location()) == 2

                     : !((((f->stat.st_mode)) & 0170000) == (0040000)));
        if (!need_lstat)
          break;
      };

    default:
      err = do_lstat(full_name, &f->stat);
      do_deref = 0;
      break;
    }

    if (err != 0) {

      file_failure(command_line_arg,

                   dcgettext(((void *)0), "cannot access %s", 5), full_name);

      f->scontext = UNKNOWN_SECURITY_CONTEXT;

      if (command_line_arg)
        return 0;

      f->name = xstrdup(name);
      cwd_n_used++;

      return 0;
    }

    f->stat_ok = 1;

    if ((type == normal || ((((f->stat.st_mode)) & 0170000) == (0100000))) &&
        print_with_color && is_colored(C_CAP))
      f->has_capability = has_capability_cache(full_name, f);

    if (format == long_format || print_scontext) {

      _Bool have_scontext = 0;

      _Bool have_acl = 0;
      int attr_len = getfilecon_cache(full_name, f, do_deref);
      err = (attr_len < 0);

      if (err == 0) {
        if (is_smack_enabled())
          have_scontext = !(strcmp("_", f->scontext) == 0);
        else
          have_scontext = !(strcmp("unlabeled", f->scontext) == 0);
      } else {
        f->scontext = UNKNOWN_SECURITY_CONTEXT;

        if (is_ENOTSUP((*__errno_location())) || (*__errno_location()) == 61)
          err = 0;
      }

      if (err == 0 && format == long_format) {
        int n = file_has_acl_cache(full_name, f);
        err = (n < 0);
        have_acl = (0 < n);
      }

      f->acl_type = (!have_scontext && !have_acl
                         ? ACL_T_NONE
                         : (have_scontext && !have_acl ? ACL_T_LSM_CONTEXT_ONLY
                                                       : ACL_T_YES));
      any_has_acl |= f->acl_type != ACL_T_NONE;

      if (err)
        error(0, (*__errno_location()), "%s",
              quotearg_n_style_colon(0, shell_escape_quoting_style, full_name));
    }

    if (((((f->stat.st_mode)) & 0170000) == (0120000))

        && (format == long_format || check_symlink_mode)) {
      struct stat linkstats;

      get_link_name(full_name, f, command_line_arg);
      char *linkname = make_link_name(full_name, f->linkname);

      if (linkname && f->quoted == 0 && needs_quoting(f->linkname))
        f->quoted = -1;

      if (linkname && (file_type <= indicator_style || check_symlink_mode) &&
          stat_for_mode(linkname, &linkstats) == 0) {
        f->linkok = 1;
        f->linkmode = linkstats.st_mode;
      }
      free(linkname);
    }

    if (((((f->stat.st_mode)) & 0170000) == (0120000)))
      f->filetype = symbolic_link;
    else if (((((f->stat.st_mode)) & 0170000) == (0040000))) {
      if (command_line_arg && !immediate_dirs)
        f->filetype = arg_directory;
      else
        f->filetype = directory;
    } else
      f->filetype = normal;

    blocks = ((f->stat).st_blocks);
    if (format == long_format || print_block_size) {
      char buf[((2 * sizeof(uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 +
                1 + 3) +
               1];
      int len = gnu_mbswidth(human_readable(blocks, buf, human_output_opts,

                                            512, output_block_size),
                             0);
      if (block_size_width < len)
        block_size_width = len;
    }

    if (format == long_format) {
      if (print_owner) {
        int len = format_user_width(f->stat.st_uid);
        if (owner_width < len)
          owner_width = len;
      }

      if (print_group) {
        int len = format_group_width(f->stat.st_gid);
        if (group_width < len)
          group_width = len;
      }

      if (print_author) {
        int len = format_user_width(f->stat.st_uid);
        if (author_width < len)
          author_width = len;
      }
    }

    if (print_scontext) {
      int len = strlen(f->scontext);
      if (scontext_width < len)
        scontext_width = len;
    }

    if (format == long_format) {
      char b[((((((sizeof(uintmax_t) * 8) -
                  (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) *
                     146 +
                 484) /
                485) +
               (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) +
              1)];
      int b_len = strlen(umaxtostr(f->stat.st_nlink, b));
      if (nlink_width < b_len)
        nlink_width = b_len;

      if (((((f->stat.st_mode)) & 0170000) == (0020000)) ||
          ((((f->stat.st_mode)) & 0170000) == (0060000))) {
        char
            buf[((((((sizeof(uintmax_t) * 8) - (!((__typeof__(uintmax_t))0 <
                                                  (__typeof__(uintmax_t))-1))) *
                        146 +
                    484) /
                   485) +
                  (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) +
                 1)];
        int len = strlen(umaxtostr(gnu_dev_major(f->stat.st_rdev), buf));
        if (major_device_number_width < len)
          major_device_number_width = len;
        len = strlen(umaxtostr(gnu_dev_minor(f->stat.st_rdev), buf));
        if (minor_device_number_width < len)
          minor_device_number_width = len;
        len = major_device_number_width + 2 + minor_device_number_width;
        if (file_size_width < len)
          file_size_width = len;
      } else {
        char buf[((2 * sizeof(uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 +
                  1 + 3) +
                 1];
        uintmax_t size = unsigned_file_size(f->stat.st_size);
        int len = gnu_mbswidth(human_readable(size, buf, file_human_output_opts,
                                              1, file_output_block_size),
                               0);
        if (file_size_width < len)
          file_size_width = len;
      }
    }
  }

  if (print_inode) {
    char buf[((((((sizeof(uintmax_t) * 8) -
                  (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) *
                     146 +
                 484) /
                485) +
               (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) +
              1)];
    int len = strlen(umaxtostr(f->stat.st_ino, buf));
    if (inode_number_width < len)
      inode_number_width = len;
  }

  f->name = xstrdup(name);
  cwd_n_used++;

  return blocks;
}

static _Bool

is_directory(const struct fileinfo *f) {
  return f->filetype == directory || f->filetype == arg_directory;
}

static _Bool

is_linked_directory(const struct fileinfo *f) {
  return f->filetype == directory || f->filetype == arg_directory ||
         ((((f->linkmode)) & 0170000) == (0040000));
}

static void get_link_name(char const *filename, struct fileinfo *f,
                          _Bool command_line_arg) {
  f->linkname = areadlink_with_size(filename, f->stat.st_size);
  if (f->linkname == ((void *)0))
    file_failure(command_line_arg,
                 dcgettext(((void *)0), "cannot read symbolic link %s", 5),
                 filename);
}

static char *make_link_name(char const *name, char const *linkname) {
  if (!linkname)
    return ((void *)0);

  if ((((linkname)[0]) == '/'))
    return xstrdup(linkname);

  size_t prefix_len = dir_len(name);
  if (prefix_len == 0)
    return xstrdup(linkname);

  char *p = xmalloc(prefix_len + 1 + strlen(linkname) + 1);

  if (!((name[prefix_len - 1]) == '/'))
    ++prefix_len;

  stpcpy(stpncpy(p, name, prefix_len), linkname);
  return p;
}

static _Bool

basename_is_dot_or_dotdot(char const *name) {
  char const *base = last_component(name);
  return dot_or_dotdot(base);
}
static void extract_dirs_from_files(char const *dirname,
                                    _Bool command_line_arg) {
  size_t i;
  size_t j;

  _Bool ignore_dot_and_dot_dot = (dirname != ((void *)0));

  if (dirname && (!!active_dir_set)) {

    queue_directory(((void *)0), dirname, 0);
  }

  for (i = cwd_n_used; i-- != 0;) {
    struct fileinfo *f = sorted_file[i];

    if (is_directory(f) &&
        (!ignore_dot_and_dot_dot || !basename_is_dot_or_dotdot(f->name))) {
      if (!dirname || f->name[0] == '/')
        queue_directory(f->name, f->linkname, command_line_arg);
      else {
        char *name = file_name_concat(dirname, f->name, ((void *)0));
        queue_directory(name, f->linkname, command_line_arg);
        free(name);
      }
      if (f->filetype == arg_directory)
        free_ent(f);
    }
  }

  for (i = 0, j = 0; i < cwd_n_used; i++) {
    struct fileinfo *f = sorted_file[i];
    sorted_file[j] = f;
    j += (f->filetype != arg_directory);
  }
  cwd_n_used = j;
}

static jmp_buf failed_strcoll;

static int xstrcoll(char const *a, char const *b) {
  int diff;

  (*__errno_location()) = 0;
  diff = strcoll(a, b);
  if ((*__errno_location())) {
    error(0, (*__errno_location()),
          dcgettext(((void *)0), "cannot compare file names %s and %s", 5),
          quote_n(0, a), quote_n(1, b));
    set_exit_status(0);
    longjmp(failed_strcoll, 1);
  }
  return diff;
}

typedef void const *V;
typedef int (*qsortFunc)(V a, V b);

static int dirfirst_check(struct fileinfo const *a, struct fileinfo const *b,
                          int (*cmp)(V, V)) {
  int diff = is_linked_directory(b) - is_linked_directory(a);
  return diff ? diff : cmp(a, b);
}
static int cmp_ctime(struct fileinfo const *a, struct fileinfo const *b,
                     int (*cmp)(char const *, char const *)) {
  int diff = timespec_cmp(get_stat_ctime(&b->stat), get_stat_ctime(&a->stat));
  return diff ? diff : cmp(a->name, b->name);
}

static int cmp_mtime(struct fileinfo const *a, struct fileinfo const *b,
                     int (*cmp)(char const *, char const *)) {
  int diff = timespec_cmp(get_stat_mtime(&b->stat), get_stat_mtime(&a->stat));
  return diff ? diff : cmp(a->name, b->name);
}

static int cmp_atime(struct fileinfo const *a, struct fileinfo const *b,
                     int (*cmp)(char const *, char const *)) {
  int diff = timespec_cmp(get_stat_atime(&b->stat), get_stat_atime(&a->stat));
  return diff ? diff : cmp(a->name, b->name);
}

static int cmp_btime(struct fileinfo const *a, struct fileinfo const *b,
                     int (*cmp)(char const *, char const *)) {
  int diff = timespec_cmp(get_stat_btime(&b->stat), get_stat_btime(&a->stat));
  return diff ? diff : cmp(a->name, b->name);
}

static int off_cmp(off_t a, off_t b) { return a < b ? -1 : a > b; }

static int cmp_size(struct fileinfo const *a, struct fileinfo const *b,
                    int (*cmp)(char const *, char const *)) {
  int diff = off_cmp(b->stat.st_size, a->stat.st_size);
  return diff ? diff : cmp(a->name, b->name);
}

static int cmp_name(struct fileinfo const *a, struct fileinfo const *b,
                    int (*cmp)(char const *, char const *)) {
  return cmp(a->name, b->name);
}

static int cmp_extension(struct fileinfo const *a, struct fileinfo const *b,
                         int (*cmp)(char const *, char const *)) {
  char const *base1 = strrchr(a->name, '.');
  char const *base2 = strrchr(b->name, '.');
  int diff = cmp(base1 ? base1 : "", base2 ? base2 : "");
  return diff ? diff : cmp(a->name, b->name);
}

static size_t fileinfo_name_width(struct fileinfo const *f) {
  return f->width
             ? f->width
             : quote_name_width(f->name, filename_quoting_options, f->quoted);
}

static int cmp_width(struct fileinfo const *a, struct fileinfo const *b,
                     int (*cmp)(char const *, char const *)) {
  int diff = fileinfo_name_width(a) - fileinfo_name_width(b);
  return diff ? diff : cmp(a->name, b->name);
}

static int xstrcoll_ctime(V a, V b) { return cmp_ctime(a, b, xstrcoll); }
__attribute__((__pure__)) static int strcmp_ctime(V a, V b) {
  return cmp_ctime(a, b, strcmp);
}
static int rev_xstrcoll_ctime(V a, V b) { return cmp_ctime(b, a, xstrcoll); }
__attribute__((__pure__)) static int rev_strcmp_ctime(V a, V b) {
  return cmp_ctime(b, a, strcmp);
}
static int xstrcoll_df_ctime(V a, V b) {
  return dirfirst_check(a, b, xstrcoll_ctime);
}
__attribute__((__pure__)) static int strcmp_df_ctime(V a, V b) {
  return dirfirst_check(a, b, strcmp_ctime);
}
static int rev_xstrcoll_df_ctime(V a, V b) {
  return dirfirst_check(a, b, rev_xstrcoll_ctime);
}
__attribute__((__pure__)) static int rev_strcmp_df_ctime(V a, V b) {
  return dirfirst_check(a, b, rev_strcmp_ctime);
}
static int xstrcoll_mtime(V a, V b) { return cmp_mtime(a, b, xstrcoll); }
__attribute__((__pure__)) static int strcmp_mtime(V a, V b) {
  return cmp_mtime(a, b, strcmp);
}
static int rev_xstrcoll_mtime(V a, V b) { return cmp_mtime(b, a, xstrcoll); }
__attribute__((__pure__)) static int rev_strcmp_mtime(V a, V b) {
  return cmp_mtime(b, a, strcmp);
}
static int xstrcoll_df_mtime(V a, V b) {
  return dirfirst_check(a, b, xstrcoll_mtime);
}
__attribute__((__pure__)) static int strcmp_df_mtime(V a, V b) {
  return dirfirst_check(a, b, strcmp_mtime);
}
static int rev_xstrcoll_df_mtime(V a, V b) {
  return dirfirst_check(a, b, rev_xstrcoll_mtime);
}
__attribute__((__pure__)) static int rev_strcmp_df_mtime(V a, V b) {
  return dirfirst_check(a, b, rev_strcmp_mtime);
}
static int xstrcoll_atime(V a, V b) { return cmp_atime(a, b, xstrcoll); }
__attribute__((__pure__)) static int strcmp_atime(V a, V b) {
  return cmp_atime(a, b, strcmp);
}
static int rev_xstrcoll_atime(V a, V b) { return cmp_atime(b, a, xstrcoll); }
__attribute__((__pure__)) static int rev_strcmp_atime(V a, V b) {
  return cmp_atime(b, a, strcmp);
}
static int xstrcoll_df_atime(V a, V b) {
  return dirfirst_check(a, b, xstrcoll_atime);
}
__attribute__((__pure__)) static int strcmp_df_atime(V a, V b) {
  return dirfirst_check(a, b, strcmp_atime);
}
static int rev_xstrcoll_df_atime(V a, V b) {
  return dirfirst_check(a, b, rev_xstrcoll_atime);
}
__attribute__((__pure__)) static int rev_strcmp_df_atime(V a, V b) {
  return dirfirst_check(a, b, rev_strcmp_atime);
}
static int xstrcoll_btime(V a, V b) { return cmp_btime(a, b, xstrcoll); }
__attribute__((__pure__)) static int strcmp_btime(V a, V b) {
  return cmp_btime(a, b, strcmp);
}
static int rev_xstrcoll_btime(V a, V b) { return cmp_btime(b, a, xstrcoll); }
__attribute__((__pure__)) static int rev_strcmp_btime(V a, V b) {
  return cmp_btime(b, a, strcmp);
}
static int xstrcoll_df_btime(V a, V b) {
  return dirfirst_check(a, b, xstrcoll_btime);
}
__attribute__((__pure__)) static int strcmp_df_btime(V a, V b) {
  return dirfirst_check(a, b, strcmp_btime);
}
static int rev_xstrcoll_df_btime(V a, V b) {
  return dirfirst_check(a, b, rev_xstrcoll_btime);
}
__attribute__((__pure__)) static int rev_strcmp_df_btime(V a, V b) {
  return dirfirst_check(a, b, rev_strcmp_btime);
}
static int xstrcoll_size(V a, V b) { return cmp_size(a, b, xstrcoll); }
__attribute__((__pure__)) static int strcmp_size(V a, V b) {
  return cmp_size(a, b, strcmp);
}
static int rev_xstrcoll_size(V a, V b) { return cmp_size(b, a, xstrcoll); }
__attribute__((__pure__)) static int rev_strcmp_size(V a, V b) {
  return cmp_size(b, a, strcmp);
}
static int xstrcoll_df_size(V a, V b) {
  return dirfirst_check(a, b, xstrcoll_size);
}
__attribute__((__pure__)) static int strcmp_df_size(V a, V b) {
  return dirfirst_check(a, b, strcmp_size);
}
static int rev_xstrcoll_df_size(V a, V b) {
  return dirfirst_check(a, b, rev_xstrcoll_size);
}
__attribute__((__pure__)) static int rev_strcmp_df_size(V a, V b) {
  return dirfirst_check(a, b, rev_strcmp_size);
}
static int xstrcoll_name(V a, V b) { return cmp_name(a, b, xstrcoll); }
__attribute__((__pure__)) static int strcmp_name(V a, V b) {
  return cmp_name(a, b, strcmp);
}
static int rev_xstrcoll_name(V a, V b) { return cmp_name(b, a, xstrcoll); }
__attribute__((__pure__)) static int rev_strcmp_name(V a, V b) {
  return cmp_name(b, a, strcmp);
}
static int xstrcoll_df_name(V a, V b) {
  return dirfirst_check(a, b, xstrcoll_name);
}
__attribute__((__pure__)) static int strcmp_df_name(V a, V b) {
  return dirfirst_check(a, b, strcmp_name);
}
static int rev_xstrcoll_df_name(V a, V b) {
  return dirfirst_check(a, b, rev_xstrcoll_name);
}
__attribute__((__pure__)) static int rev_strcmp_df_name(V a, V b) {
  return dirfirst_check(a, b, rev_strcmp_name);
}
static int xstrcoll_extension(V a, V b) {
  return cmp_extension(a, b, xstrcoll);
}
__attribute__((__pure__)) static int strcmp_extension(V a, V b) {
  return cmp_extension(a, b, strcmp);
}
static int rev_xstrcoll_extension(V a, V b) {
  return cmp_extension(b, a, xstrcoll);
}
__attribute__((__pure__)) static int rev_strcmp_extension(V a, V b) {
  return cmp_extension(b, a, strcmp);
}
static int xstrcoll_df_extension(V a, V b) {
  return dirfirst_check(a, b, xstrcoll_extension);
}
__attribute__((__pure__)) static int strcmp_df_extension(V a, V b) {
  return dirfirst_check(a, b, strcmp_extension);
}
static int rev_xstrcoll_df_extension(V a, V b) {
  return dirfirst_check(a, b, rev_xstrcoll_extension);
}
__attribute__((__pure__)) static int rev_strcmp_df_extension(V a, V b) {
  return dirfirst_check(a, b, rev_strcmp_extension);
}
static int xstrcoll_width(V a, V b) { return cmp_width(a, b, xstrcoll); }
__attribute__((__pure__)) static int strcmp_width(V a, V b) {
  return cmp_width(a, b, strcmp);
}
static int rev_xstrcoll_width(V a, V b) { return cmp_width(b, a, xstrcoll); }
__attribute__((__pure__)) static int rev_strcmp_width(V a, V b) {
  return cmp_width(b, a, strcmp);
}
static int xstrcoll_df_width(V a, V b) {
  return dirfirst_check(a, b, xstrcoll_width);
}
__attribute__((__pure__)) static int strcmp_df_width(V a, V b) {
  return dirfirst_check(a, b, strcmp_width);
}
static int rev_xstrcoll_df_width(V a, V b) {
  return dirfirst_check(a, b, rev_xstrcoll_width);
}
__attribute__((__pure__)) static int rev_strcmp_df_width(V a, V b) {
  return dirfirst_check(a, b, rev_strcmp_width);
}
static int cmp_version(struct fileinfo const *a, struct fileinfo const *b) {
  int diff = filevercmp(a->name, b->name);
  return diff ? diff : strcmp(a->name, b->name);
}

static int xstrcoll_version(V a, V b) { return cmp_version(a, b); }
static int rev_xstrcoll_version(V a, V b) { return cmp_version(b, a); }
static int xstrcoll_df_version(V a, V b) {
  return dirfirst_check(a, b, xstrcoll_version);
}
static int rev_xstrcoll_df_version(V a, V b) {
  return dirfirst_check(a, b, rev_xstrcoll_version);
}
static qsortFunc const sort_functions[][2][2][2] = {
    {{
         {xstrcoll_name, xstrcoll_df_name},
         {rev_xstrcoll_name, rev_xstrcoll_df_name},
     },
     {
         {strcmp_name, strcmp_df_name},
         {rev_strcmp_name, rev_strcmp_df_name},
     }},
    {{
         {xstrcoll_extension, xstrcoll_df_extension},
         {rev_xstrcoll_extension, rev_xstrcoll_df_extension},
     },
     {
         {strcmp_extension, strcmp_df_extension},
         {rev_strcmp_extension, rev_strcmp_df_extension},
     }},
    {{
         {xstrcoll_width, xstrcoll_df_width},
         {rev_xstrcoll_width, rev_xstrcoll_df_width},
     },
     {
         {strcmp_width, strcmp_df_width},
         {rev_strcmp_width, rev_strcmp_df_width},
     }},
    {{
         {xstrcoll_size, xstrcoll_df_size},
         {rev_xstrcoll_size, rev_xstrcoll_df_size},
     },
     {
         {strcmp_size, strcmp_df_size},
         {rev_strcmp_size, rev_strcmp_df_size},
     }},

    {{
         {xstrcoll_version, xstrcoll_df_version},
         {rev_xstrcoll_version, rev_xstrcoll_df_version},
     },

     {
         {((void *)0), ((void *)0)},
         {((void *)0), ((void *)0)},
     }},

    {{
         {xstrcoll_mtime, xstrcoll_df_mtime},
         {rev_xstrcoll_mtime, rev_xstrcoll_df_mtime},
     },
     {
         {strcmp_mtime, strcmp_df_mtime},
         {rev_strcmp_mtime, rev_strcmp_df_mtime},
     }},
    {{
         {xstrcoll_ctime, xstrcoll_df_ctime},
         {rev_xstrcoll_ctime, rev_xstrcoll_df_ctime},
     },
     {
         {strcmp_ctime, strcmp_df_ctime},
         {rev_strcmp_ctime, rev_strcmp_df_ctime},
     }},
    {{
         {xstrcoll_atime, xstrcoll_df_atime},
         {rev_xstrcoll_atime, rev_xstrcoll_df_atime},
     },
     {
         {strcmp_atime, strcmp_df_atime},
         {rev_strcmp_atime, rev_strcmp_df_atime},
     }},
    {{
         {xstrcoll_btime, xstrcoll_df_btime},
         {rev_xstrcoll_btime, rev_xstrcoll_df_btime},
     },
     {
         {strcmp_btime, strcmp_df_btime},
         {rev_strcmp_btime, rev_strcmp_df_btime},
     }}};
_Static_assert(
    (sizeof(sort_functions) / sizeof *(sort_functions)) ==
        sort_numtypes - 2 + time_numtypes,
    "verify ("
    "ARRAY_CARDINALITY (sort_functions) == sort_numtypes - 2 + time_numtypes"
    ")");

static void initialize_ordering_vector(void) {
  for (size_t i = 0; i < cwd_n_used; i++)
    sorted_file[i] = &cwd_file[i];
}

static void update_current_files_info(void) {

  if (sort_type == sort_width ||
      (line_length && (format == many_per_line || format == horizontal))) {
    size_t i;
    for (i = 0; i < cwd_n_used; i++) {
      struct fileinfo *f = sorted_file[i];
      f->width = fileinfo_name_width(f);
    }
  }
}

static void sort_files(void) {

  _Bool use_strcmp;

  if (sorted_file_alloc < cwd_n_used + cwd_n_used / 2) {
    free(sorted_file);
    sorted_file = xnmalloc(cwd_n_used, 3 * sizeof *sorted_file);
    sorted_file_alloc = 3 * cwd_n_used;
  }

  initialize_ordering_vector();

  update_current_files_info();

  if (sort_type == sort_none)
    return;

  if (!_setjmp(failed_strcoll))
    use_strcmp = 0;
  else {
    use_strcmp = 1;

    ((void)sizeof((sort_type != sort_version) ? 1 : 0), __extension__({
       if (sort_type != sort_version)
         ;
       else
         __assert_fail("sort_type != sort_version", "src/ls.c", 4104,
                       __extension__ __PRETTY_FUNCTION__);
     }));
    initialize_ordering_vector();
  }

  mpsort((void const **)sorted_file, cwd_n_used,
         sort_functions[sort_type + (sort_type == sort_time ? time_type : 0)]
                       [use_strcmp][sort_reverse][directories_first]);
}

static void print_current_files(void) {
  size_t i;

  switch (format) {
  case one_per_line:
    for (i = 0; i < cwd_n_used; i++) {
      print_file_name_and_frills(sorted_file[i], 0);
      putchar_unlocked(eolbyte);
    }
    break;

  case many_per_line:
    if (!line_length)
      print_with_separator(' ');
    else
      print_many_per_line();
    break;

  case horizontal:
    if (!line_length)
      print_with_separator(' ');
    else
      print_horizontal();
    break;

  case with_commas:
    print_with_separator(',');
    break;

  case long_format:
    for (i = 0; i < cwd_n_used; i++) {
      set_normal_color();
      print_long_format(sorted_file[i]);
      dired_outbyte(eolbyte);
    }
    break;
  }
}

static size_t align_nstrftime(char *buf, size_t size, _Bool recent,
                              struct tm const *tm, timezone_t tz, int ns) {
  char const *nfmt =
      (use_abformat ? abformat[recent][tm->tm_mon] : long_time_format[recent]);
  return nstrftime(buf, size, nfmt, tm, tz, ns);
}

static int long_time_expected_width(void) {
  static int width = -1;

  if (width < 0) {
    time_t epoch = 0;
    struct tm tm;
    char buf[TIME_STAMP_LEN_MAXIMUM + 1];
    if (localtime_rz(localtz, &epoch, &tm)) {
      size_t len = align_nstrftime(buf, sizeof buf, 0, &tm, localtz, 0);
      if (len != 0)
        width = mbsnwidth(buf, len, 0);
    }

    if (width < 0)
      width = 0;
  }

  return width;
}

static void format_user_or_group(char const *name, uintmax_t id, int width) {
  if (name) {
    int width_gap = width - gnu_mbswidth(name, 0);
    int pad = (((0) > (width_gap)) ? (0) : (width_gap));
    dired_outstring(name);

    do
      dired_outbyte(' ');
    while (pad--);
  } else
    dired_pos += printf("%*"
                        "l"
                        "u"
                        " ",
                        width, id);
}

static void format_user(uid_t u, int width, _Bool stat_ok) {
  format_user_or_group(
      !stat_ok ? "?" : (numeric_ids ? ((void *)0) : getuser(u)), u, width);
}

static void format_group(gid_t g, int width, _Bool stat_ok) {
  format_user_or_group(
      !stat_ok ? "?" : (numeric_ids ? ((void *)0) : getgroup(g)), g, width);
}

static int format_user_or_group_width(char const *name, uintmax_t id) {
  if (name) {
    int len = gnu_mbswidth(name, 0);
    return (((0) > (len)) ? (0) : (len));
  } else
    return snprintf(((void *)0), 0,
                    "%"
                    "l"
                    "u",
                    id);
}

static int format_user_width(uid_t u) {
  return format_user_or_group_width(numeric_ids ? ((void *)0) : getuser(u), u);
}

static int format_group_width(gid_t g) {
  return format_user_or_group_width(numeric_ids ? ((void *)0) : getgroup(g), g);
}

static char *format_inode(char *buf, size_t buflen, const struct fileinfo *f) {

  ((void)sizeof(
       (((((((sizeof(uintmax_t) * 8) -
             (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) *
                146 +
            484) /
           485) +
          (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) +
         1) <= buflen)
           ? 1
           : 0),
   __extension__({
     if (((((((sizeof(uintmax_t) * 8) -
              (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) *
                 146 +
             484) /
            485) +
           (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) +
          1) <= buflen)
       ;
     else
       __assert_fail("INT_BUFSIZE_BOUND (uintmax_t) <= buflen", "src/ls.c",
                     4286, __extension__ __PRETTY_FUNCTION__);
   }));
  return (f->stat_ok && f->stat.st_ino != NOT_AN_INODE_NUMBER
              ? umaxtostr(f->stat.st_ino, buf)
              : (char *)"?");
}

static void print_long_format(const struct fileinfo *f) {
  char modebuf[12];
  char buf
      [((2 * sizeof(uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 + 1 + 3) +
       1 +
       ((2 * sizeof(uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 + 1 + 3) +
       1 + sizeof(modebuf) - 1 + 1 +
       ((((((sizeof(uintmax_t) * 8) -
            (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) *
               146 +
           484) /
          485) +
         (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) +
        1) +
       ((2 * sizeof(uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 + 1 + 3) +
       2 +
       ((2 * sizeof(uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 + 1 + 3) +
       1 + TIME_STAMP_LEN_MAXIMUM + 1];
  size_t s;
  char *p;
  struct timespec when_timespec;
  struct tm when_local;

  _Bool btime_ok = 1;

  if (f->stat_ok)
    filemodestring(&f->stat, modebuf);
  else {
    modebuf[0] = filetype_letter[f->filetype];
    memset(modebuf + 1, '?', 10);
    modebuf[11] = '\0';
  }
  if (!any_has_acl)
    modebuf[10] = '\0';
  else if (f->acl_type == ACL_T_LSM_CONTEXT_ONLY)
    modebuf[10] = '.';
  else if (f->acl_type == ACL_T_YES)
    modebuf[10] = '+';

  switch (time_type) {
  case time_ctime:
    when_timespec = get_stat_ctime(&f->stat);
    break;
  case time_mtime:
    when_timespec = get_stat_mtime(&f->stat);
    break;
  case time_atime:
    when_timespec = get_stat_atime(&f->stat);
    break;
  case time_btime:
    when_timespec = get_stat_btime(&f->stat);
    if (when_timespec.tv_sec == -1 && when_timespec.tv_nsec == -1)
      btime_ok = 0;
    break;
  default:
    abort();
  }

  p = buf;

  if (print_inode) {
    char hbuf[((((((sizeof(uintmax_t) * 8) -
                   (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) *
                      146 +
                  484) /
                 485) +
                (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) +
               1)];
    p += sprintf(p, "%*s ", inode_number_width,
                 format_inode(hbuf, sizeof hbuf, f));
  }

  if (print_block_size) {
    char hbuf[((2 * sizeof(uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 + 1 +
               3) +
              1];
    char const *blocks = (!f->stat_ok ? "?"
                                      : human_readable(((f->stat).st_blocks),
                                                       hbuf, human_output_opts,

                                                       512, output_block_size));
    int pad;
    for (pad = block_size_width - gnu_mbswidth(blocks, 0); 0 < pad; pad--)
      *p++ = ' ';
    while ((*p++ = *blocks++))
      continue;
    p[-1] = ' ';
  }

  {
    char hbuf[((((((sizeof(uintmax_t) * 8) -
                   (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) *
                      146 +
                  484) /
                 485) +
                (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) +
               1)];
    p += sprintf(p, "%s %*s ", modebuf, nlink_width,
                 !f->stat_ok ? "?" : umaxtostr(f->stat.st_nlink, hbuf));
  }

  dired_indent();

  if (print_owner || print_group || print_author || print_scontext) {
    dired_outbuf(buf, p - buf);

    if (print_owner)
      format_user(f->stat.st_uid, owner_width, f->stat_ok);

    if (print_group)
      format_group(f->stat.st_gid, group_width, f->stat_ok);

    if (print_author)
      format_user(f->stat.st_uid, author_width, f->stat_ok);

    if (print_scontext)
      format_user_or_group(f->scontext, 0, scontext_width);

    p = buf;
  }

  if (f->stat_ok && (((((f->stat.st_mode)) & 0170000) == (0020000)) ||
                     ((((f->stat.st_mode)) & 0170000) == (0060000)))) {
    char majorbuf[(
        (((((sizeof(uintmax_t) * 8) -
            (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) *
               146 +
           484) /
          485) +
         (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) +
        1)];
    char minorbuf[(
        (((((sizeof(uintmax_t) * 8) -
            (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) *
               146 +
           484) /
          485) +
         (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) +
        1)];
    int blanks_width = (file_size_width - (major_device_number_width + 2 +
                                           minor_device_number_width));
    p += sprintf(p, "%*s, %*s ",
                 major_device_number_width +
                     (((0) > (blanks_width)) ? (0) : (blanks_width)),
                 umaxtostr(gnu_dev_major(f->stat.st_rdev), majorbuf),
                 minor_device_number_width,
                 umaxtostr(gnu_dev_minor(f->stat.st_rdev), minorbuf));
  } else {
    char hbuf[((2 * sizeof(uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 + 1 +
               3) +
              1];
    char const *size =
        (!f->stat_ok ? "?"
                     : human_readable(unsigned_file_size(f->stat.st_size), hbuf,
                                      file_human_output_opts, 1,
                                      file_output_block_size));
    int pad;
    for (pad = file_size_width - gnu_mbswidth(size, 0); 0 < pad; pad--)
      *p++ = ' ';
    while ((*p++ = *size++))
      continue;
    p[-1] = ' ';
  }

  s = 0;
  *p = '\1';

  if (f->stat_ok && btime_ok &&
      localtime_rz(localtz, &when_timespec.tv_sec, &when_local)) {
    struct timespec six_months_ago;

    _Bool recent;

    if (timespec_cmp(current_time, when_timespec) < 0)
      gettime(&current_time);

    six_months_ago.tv_sec = current_time.tv_sec - 31556952 / 2;
    six_months_ago.tv_nsec = current_time.tv_nsec;

    recent = (timespec_cmp(six_months_ago, when_timespec) < 0 &&
              timespec_cmp(when_timespec, current_time) < 0);

    s = align_nstrftime(p, TIME_STAMP_LEN_MAXIMUM + 1, recent, &when_local,
                        localtz, when_timespec.tv_nsec);
  }

  if (s || !*p) {
    p += s;
    *p++ = ' ';
  } else {

    char hbuf[((((((sizeof(intmax_t) * 8) -
                   (!((__typeof__(intmax_t))0 < (__typeof__(intmax_t))-1))) *
                      146 +
                  484) /
                 485) +
                (!((__typeof__(intmax_t))0 < (__typeof__(intmax_t))-1))) +
               1)];
    p += sprintf(p, "%*s ", long_time_expected_width(),
                 (!f->stat_ok || !btime_ok
                      ? "?"
                      : timetostr(when_timespec.tv_sec, hbuf)));
  }

  dired_outbuf(buf, p - buf);
  size_t w = print_name_with_quoting(f, 0, &dired_obstack, p - buf);

  if (f->filetype == symbolic_link) {
    if (f->linkname) {
      dired_outstring(" -> ");
      print_name_with_quoting(f, 1, ((void *)0), (p - buf) + w + 4);
      if (indicator_style != none)
        print_type_indicator(1, f->linkmode, unknown);
    }
  } else if (indicator_style != none)
    print_type_indicator(f->stat_ok, f->stat.st_mode, f->filetype);
}
static size_t quote_name_buf(char **inbuf, size_t bufsize, char *name,
                             struct quoting_options const *options,
                             int needs_general_quoting, size_t *width,
                             _Bool *pad) {
  char *buf = *inbuf;
  size_t displayed_width = 0;
  size_t len = 0;

  _Bool quoted;

  enum quoting_style qs = get_quoting_style(options);

  _Bool needs_further_quoting =
      qmark_funny_chars &&
      (qs == shell_quoting_style || qs == shell_always_quoting_style ||
       qs == literal_quoting_style);

  if (needs_general_quoting != 0) {
    len = quotearg_buffer(buf, bufsize, name, -1, options);
    if (bufsize <= len) {
      buf = xmalloc(len + 1);
      quotearg_buffer(buf, len + 1, name, -1, options);
    }

    quoted = (*name != *buf) || strlen(name) != len;
  } else if (needs_further_quoting) {
    len = strlen(name);
    if (bufsize <= len)
      buf = xmalloc(len + 1);
    memcpy(buf, name, len + 1);

    quoted = 0;
  } else {
    len = strlen(name);
    buf = name;
    quoted = 0;
  }

  if (needs_further_quoting) {
    if ((__ctype_get_mb_cur_max()) > 1) {
      char const *p = buf;
      char const *plimit = buf + len;
      char *q = buf;
      displayed_width = 0;

      while (p < plimit)
        switch (*p) {
        case ' ':
        case '!':
        case '"':
        case '                case ' & ': case '\'':
        case '(':
        case ')':
        case '*':
        case '+':
        case ',':
        case '-':
        case '.':
        case '/':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case ':':
        case ';':
        case '<':
        case '=':
        case '>':
        case '?':
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'H':
        case 'I':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
        case 'O':
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
        case 'T':
        case 'U':
        case 'V':
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
        case '[':
        case '\\':
        case ']':
        case '^':
        case '_':
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
        case 'g':
        case 'h':
        case 'i':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'o':
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case 't':
        case 'u':
        case 'v':
        case 'w':
        case 'x':
        case 'y':
        case 'z':
        case '{':
        case '|':
        case '}':
        case '~':

          *q++ = *p++;
          displayed_width += 1;
          break;
        default:

        {
          mbstate_t mbstate = {
              0,
          };
          do {
            wchar_t wc;
            size_t bytes;
            int w;

            bytes = rpl_mbrtowc(&wc, p, plimit - p, &mbstate);

            if (bytes == (size_t)-1) {

              p++;
              *q++ = '?';
              displayed_width += 1;
              break;
            }

            if (bytes == (size_t)-2) {

              p = plimit;
              *q++ = '?';
              displayed_width += 1;
              break;
            }

            if (bytes == 0)

              bytes = 1;

            w = wcwidth(wc);
            if (w >= 0) {

              for (; bytes > 0; --bytes)
                *q++ = *p++;
              displayed_width += w;
            } else {

              p += bytes;
              *q++ = '?';
              displayed_width += 1;
            }
          } while (!mbsinit(&mbstate));
        } break;
        }

      len = q - buf;
    } else {
      char *p = buf;
      char const *plimit = buf + len;

      while (p < plimit) {
        if (!((*__ctype_b_loc())[(int)((to_uchar(*p)))] &
              (unsigned short int)_ISprint))
          *p = '?';
        p++;
      }
      displayed_width = len;
    }
  } else if (width != ((void *)0)) {
    if ((__ctype_get_mb_cur_max()) > 1)
      displayed_width = mbsnwidth(buf, len, 0);
    else {
      char const *p = buf;
      char const *plimit = buf + len;

      displayed_width = 0;
      while (p < plimit) {
        if (((*__ctype_b_loc())[(int)((to_uchar(*p)))] &
             (unsigned short int)_ISprint))
          displayed_width++;
        p++;
      }
    }
  }

  *pad = (align_variable_outer_quotes && cwd_some_quoted && !quoted);

  if (width != ((void *)0))
    *width = displayed_width;

  *inbuf = buf;

  return len;
}

static size_t quote_name_width(char const *name,
                               struct quoting_options const *options,
                               int needs_general_quoting) {
  char smallbuf[8192];
  char *buf = smallbuf;
  size_t width;

  _Bool pad;

  quote_name_buf(&buf, sizeof smallbuf, (char *)name, options,
                 needs_general_quoting, &width, &pad);

  if (buf != smallbuf && buf != name)
    free(buf);

  width += pad;

  return width;
}

static char *file_escape(char const *str, _Bool path) {
  char *esc = xnmalloc(3, strlen(str) + 1);
  char *p = esc;
  while (*str) {
    if (path && ((*str) == '/')) {
      *p++ = '/';
      str++;
    } else if (RFC3986[to_uchar(*str)])
      *p++ = *str++;
    else
      p += sprintf(p, "%%%02x", to_uchar(*str++));
  }
  *p = '\0';
  return esc;
}

static size_t quote_name(char const *name,
                         struct quoting_options const *options,
                         int needs_general_quoting, const struct bin_str *color,

                         _Bool allow_pad, struct obstack *stack,
                         char const *absolute_name) {
  char smallbuf[8192];
  char *buf = smallbuf;
  size_t len;

  _Bool pad;

  len = quote_name_buf(&buf, sizeof smallbuf, (char *)name, options,
                       needs_general_quoting, ((void *)0), &pad);

  if (pad && allow_pad)
    dired_outbyte(' ');

  if (color)
    print_color_indicator(color);

  _Bool skip_quotes = 0;

  if (absolute_name) {
    if (align_variable_outer_quotes && cwd_some_quoted && !pad) {
      skip_quotes = 1;
      putchar_unlocked(*buf);
    }
    char *h = file_escape(hostname, 0);
    char *n = file_escape(absolute_name, 1);

    printf("\033]8;;file://%s%s%s\a", h, *n == '/' ? "" : "/", n);
    free(h);
    free(n);
  }

  if (stack)
    push_current_dired_pos(stack);

  fwrite_unlocked(buf + skip_quotes, 1, len - (skip_quotes * 2), stdout);

  dired_pos += len;

  if (stack)
    push_current_dired_pos(stack);

  if (absolute_name) {
    fputs_unlocked("\033]8;;\a", stdout);
    if (skip_quotes)
      putchar_unlocked(*(buf + len - 1));
  }

  if (buf != smallbuf && buf != name)
    free(buf);

  return len + pad;
}

static size_t print_name_with_quoting(const struct fileinfo *f,

                                      _Bool symlink_target,
                                      struct obstack *stack, size_t start_col) {
  char const *name = symlink_target ? f->linkname : f->name;

  const struct bin_str *color =
      print_with_color ? get_color_indicator(f, symlink_target) : ((void *)0);

  _Bool used_color_this_time =
      (print_with_color && (color || is_colored(C_NORM)));

  size_t len = quote_name(name, filename_quoting_options, f->quoted, color,
                          !symlink_target, stack, f->absolute_name);

  process_signals();
  if (used_color_this_time) {
    prep_non_filename_text();

    if (line_length &&
        (start_col / line_length != (start_col + len - 1) / line_length))
      put_indicator(&color_indicator[C_CLR_TO_EOL]);
  }

  return len;
}

static void prep_non_filename_text(void) {
  if (color_indicator[C_END].string != ((void *)0))
    put_indicator(&color_indicator[C_END]);
  else {
    put_indicator(&color_indicator[C_LEFT]);
    put_indicator(&color_indicator[C_RESET]);
    put_indicator(&color_indicator[C_RIGHT]);
  }
}

static size_t print_file_name_and_frills(const struct fileinfo *f,
                                         size_t start_col) {
  char buf[(
      ((((2 * sizeof(uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 + 1 + 3) +
        1) > (((((((sizeof(uintmax_t) * 8) -
                   (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) *
                      146 +
                  484) /
                 485) +
                (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) +
               1)))
          ? (((2 * sizeof(uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 + 1 +
              3) +
             1)
          : (((((((sizeof(uintmax_t) * 8) -
                  (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) *
                     146 +
                 484) /
                485) +
               (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) +
              1)))];

  set_normal_color();

  if (print_inode)
    printf("%*s ", format == with_commas ? 0 : inode_number_width,
           format_inode(buf, sizeof buf, f));

  if (print_block_size)
    printf("%*s ", format == with_commas ? 0 : block_size_width,
           !f->stat_ok
               ? "?"
               : human_readable(((f->stat).st_blocks), buf, human_output_opts,

                                512, output_block_size));

  if (print_scontext)
    printf("%*s ", format == with_commas ? 0 : scontext_width, f->scontext);

  size_t width = print_name_with_quoting(f, 0, ((void *)0), start_col);

  if (indicator_style != none)
    width += print_type_indicator(f->stat_ok, f->stat.st_mode, f->filetype);

  return width;
}

static char get_type_indicator(_Bool stat_ok, mode_t mode, enum filetype type) {
  char c;

  if (stat_ok ? ((((mode)) & 0170000) == (0100000)) : type == normal) {
    if (stat_ok && indicator_style == classify &&
        (mode & (0100 | (0100 >> 3) | ((0100 >> 3) >> 3))))
      c = '*';
    else
      c = 0;
  } else {
    if (stat_ok ? ((((mode)) & 0170000) == (0040000))
                : type == directory || type == arg_directory)
      c = '/';
    else if (indicator_style == slash)
      c = 0;
    else if (stat_ok ? ((((mode)) & 0170000) == (0120000))
                     : type == symbolic_link)
      c = '@';
    else if (stat_ok ? ((((mode)) & 0170000) == (0010000)) : type == fifo)
      c = '|';
    else if (stat_ok ? ((((mode)) & 0170000) == (0140000)) : type == sock)
      c = '=';
    else if (stat_ok && 0)
      c = '>';
    else
      c = 0;
  }
  return c;
}

static _Bool

print_type_indicator(_Bool stat_ok, mode_t mode, enum filetype type) {
  char c = get_type_indicator(stat_ok, mode, type);
  if (c)
    dired_outbyte(c);
  return !!c;
}

static _Bool

print_color_indicator(const struct bin_str *ind) {
  if (ind) {

    if (is_colored(C_NORM))
      restore_default_color();
    put_indicator(&color_indicator[C_LEFT]);
    put_indicator(ind);
    put_indicator(&color_indicator[C_RIGHT]);
  }

  return ind != ((void *)0);
}

__attribute__((__pure__)) static const struct bin_str *
get_color_indicator(const struct fileinfo *f, _Bool symlink_target) {
  enum indicator_no type;
  struct color_ext_type *ext;
  size_t len;

  char const *name;
  mode_t mode;
  int linkok;
  if (symlink_target) {
    name = f->linkname;
    mode = f->linkmode;
    linkok = f->linkok ? 0 : -1;
  } else {
    name = f->name;
    mode = file_or_link_mode(f);
    linkok = f->linkok;
  }

  if (linkok == -1 && is_colored(C_MISSING))
    type = C_MISSING;
  else if (!f->stat_ok) {
    static enum indicator_no filetype_indicator[] = {
        C_ORPHAN, C_FIFO, C_CHR,  C_DIR,  C_BLK,
        C_FILE,   C_LINK, C_SOCK, C_FILE, C_DIR};
    type = filetype_indicator[f->filetype];
  } else {
    if (((((mode)) & 0170000) == (0100000))) {
      type = C_FILE;

      if ((mode & 04000) != 0 && is_colored(C_SETUID))
        type = C_SETUID;
      else if ((mode & 02000) != 0 && is_colored(C_SETGID))
        type = C_SETGID;
      else if (is_colored(C_CAP) && f->has_capability)
        type = C_CAP;
      else if ((mode & (0100 | (0100 >> 3) | ((0100 >> 3) >> 3))) != 0 &&
               is_colored(C_EXEC))
        type = C_EXEC;
      else if ((1 < f->stat.st_nlink) && is_colored(C_MULTIHARDLINK))
        type = C_MULTIHARDLINK;
    } else if (((((mode)) & 0170000) == (0040000))) {
      type = C_DIR;

      if ((mode & 01000) && (mode & ((0200 >> 3) >> 3)) &&
          is_colored(C_STICKY_OTHER_WRITABLE))
        type = C_STICKY_OTHER_WRITABLE;
      else if ((mode & ((0200 >> 3) >> 3)) != 0 && is_colored(C_OTHER_WRITABLE))
        type = C_OTHER_WRITABLE;
      else if ((mode & 01000) != 0 && is_colored(C_STICKY))
        type = C_STICKY;
    } else if (((((mode)) & 0170000) == (0120000)))
      type = C_LINK;
    else if (((((mode)) & 0170000) == (0010000)))
      type = C_FIFO;
    else if (((((mode)) & 0170000) == (0140000)))
      type = C_SOCK;
    else if (((((mode)) & 0170000) == (0060000)))
      type = C_BLK;
    else if (((((mode)) & 0170000) == (0020000)))
      type = C_CHR;
    else if (0)
      type = C_DOOR;
    else {

      type = C_ORPHAN;
    }
  }

  ext = ((void *)0);
  if (type == C_FILE) {

    len = strlen(name);
    name += len;
    for (ext = color_ext_list; ext != ((void *)0); ext = ext->next) {
      if (ext->ext.len <= len &&
          c_strncasecmp(name - ext->ext.len, ext->ext.string, ext->ext.len) ==
              0)
        break;
    }
  }

  if (type == C_LINK && !linkok) {
    if (color_symlink_as_referent || is_colored(C_ORPHAN))
      type = C_ORPHAN;
  }

  const struct bin_str *const s = ext ? &(ext->seq) : &color_indicator[type];

  return s->string ? s : ((void *)0);
}

static void put_indicator(const struct bin_str *ind) {
  if (!used_color) {
    used_color = 1;

    if (0 <= tcgetpgrp(1))
      signal_init();

    prep_non_filename_text();
  }

  fwrite_unlocked(ind->string, ind->len, 1, stdout);
}

static size_t length_of_file_name_and_frills(const struct fileinfo *f) {
  size_t len = 0;
  char buf[(
      ((((2 * sizeof(uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 + 1 + 3) +
        1) > (((((((sizeof(uintmax_t) * 8) -
                   (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) *
                      146 +
                  484) /
                 485) +
                (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) +
               1)))
          ? (((2 * sizeof(uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 + 1 +
              3) +
             1)
          : (((((((sizeof(uintmax_t) * 8) -
                  (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) *
                     146 +
                 484) /
                485) +
               (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) +
              1)))];

  if (print_inode)
    len += 1 + (format == with_commas ? strlen(umaxtostr(f->stat.st_ino, buf))
                                      : inode_number_width);

  if (print_block_size)
    len +=
        1 + (format == with_commas
                 ? strlen(!f->stat_ok ? "?"
                                      : human_readable(((f->stat).st_blocks),
                                                       buf, human_output_opts,
                                                       512, output_block_size))
                 : block_size_width);

  if (print_scontext)
    len += 1 + (format == with_commas ? strlen(f->scontext) : scontext_width);

  len += fileinfo_name_width(f);

  if (indicator_style != none) {
    char c = get_type_indicator(f->stat_ok, f->stat.st_mode, f->filetype);
    len += (c != 0);
  }

  return len;
}

static void print_many_per_line(void) {
  size_t row;
  size_t cols = calculate_columns(1);
  struct column_info const *line_fmt = &column_info[cols - 1];

  size_t rows = cwd_n_used / cols + (cwd_n_used % cols != 0);

  for (row = 0; row < rows; row++) {
    size_t col = 0;
    size_t filesno = row;
    size_t pos = 0;

    while (1) {
      struct fileinfo const *f = sorted_file[filesno];
      size_t name_length = length_of_file_name_and_frills(f);
      size_t max_name_length = line_fmt->col_arr[col++];
      print_file_name_and_frills(f, pos);

      filesno += rows;
      if (filesno >= cwd_n_used)
        break;

      indent(pos + name_length, pos + max_name_length);
      pos += max_name_length;
    }
    putchar_unlocked(eolbyte);
  }
}

static void print_horizontal(void) {
  size_t filesno;
  size_t pos = 0;
  size_t cols = calculate_columns(0);
  struct column_info const *line_fmt = &column_info[cols - 1];
  struct fileinfo const *f = sorted_file[0];
  size_t name_length = length_of_file_name_and_frills(f);
  size_t max_name_length = line_fmt->col_arr[0];

  print_file_name_and_frills(f, 0);

  for (filesno = 1; filesno < cwd_n_used; ++filesno) {
    size_t col = filesno % cols;

    if (col == 0) {
      putchar_unlocked(eolbyte);
      pos = 0;
    } else {
      indent(pos + name_length, pos + max_name_length);
      pos += max_name_length;
    }

    f = sorted_file[filesno];
    print_file_name_and_frills(f, pos);

    name_length = length_of_file_name_and_frills(f);
    max_name_length = line_fmt->col_arr[col];
  }
  putchar_unlocked(eolbyte);
}

static void print_with_separator(char sep) {
  size_t filesno;
  size_t pos = 0;

  for (filesno = 0; filesno < cwd_n_used; filesno++) {
    struct fileinfo const *f = sorted_file[filesno];
    size_t len = line_length ? length_of_file_name_and_frills(f) : 0;

    if (filesno != 0) {
      char separator;

      if (!line_length || ((pos + len + 2 < line_length) &&
                           (pos <= (18446744073709551615UL) - len - 2))) {
        pos += 2;
        separator = ' ';
      } else {
        pos = 0;
        separator = eolbyte;
      }

      putchar_unlocked(sep);
      putchar_unlocked(separator);
    }

    print_file_name_and_frills(f, pos);
    pos += len;
  }
  putchar_unlocked(eolbyte);
}

static void indent(size_t from, size_t to) {
  while (from < to) {
    if (tabsize != 0 && to / tabsize > (from + 1) / tabsize) {
      putchar_unlocked('\t');
      from += tabsize - from % tabsize;
    } else {
      putchar_unlocked(' ');
      from++;
    }
  }
}

static void attach(char *dest, char const *dirname, char const *name) {
  char const *dirnamep = dirname;

  if (dirname[0] != '.' || dirname[1] != 0) {
    while (*dirnamep)
      *dest++ = *dirnamep++;

    if (dirnamep > dirname && dirnamep[-1] != '/')
      *dest++ = '/';
  }
  while (*name)
    *dest++ = *name++;
  *dest = 0;
}

static void init_column_info(size_t max_cols) {
  size_t i;

  static size_t column_info_alloc;

  if (column_info_alloc < max_cols) {
    size_t new_column_info_alloc;
    size_t *p;

    if (!max_idx || max_cols < max_idx / 2) {

      column_info = xnrealloc(column_info, max_cols, 2 * sizeof *column_info);
      new_column_info_alloc = 2 * max_cols;
    } else {
      column_info = xnrealloc(column_info, max_idx, sizeof *column_info);
      new_column_info_alloc = max_idx;
    }

    {
      size_t column_info_growth = new_column_info_alloc - column_info_alloc;
      size_t s = column_info_alloc + 1 + new_column_info_alloc;
      size_t t = s * column_info_growth;
      if (s < new_column_info_alloc || t / column_info_growth != s)
        xalloc_die();
      p = xnmalloc(t / 2, sizeof *p);
    }

    for (i = column_info_alloc; i < new_column_info_alloc; i++) {
      column_info[i].col_arr = p;
      p += i + 1;
    }

    column_info_alloc = new_column_info_alloc;
  }

  for (i = 0; i < max_cols; ++i) {
    size_t j;

    column_info[i].valid_len = 1;
    column_info[i].line_len = (i + 1) * MIN_COLUMN_WIDTH;
    for (j = 0; j <= i; ++j)
      column_info[i].col_arr[j] = MIN_COLUMN_WIDTH;
  }
}

static size_t calculate_columns(_Bool by_columns) {
  size_t filesno;
  size_t cols;

  size_t max_cols = 0 < max_idx && max_idx < cwd_n_used ? max_idx : cwd_n_used;

  init_column_info(max_cols);

  for (filesno = 0; filesno < cwd_n_used; ++filesno) {
    struct fileinfo const *f = sorted_file[filesno];
    size_t name_length = length_of_file_name_and_frills(f);

    for (size_t i = 0; i < max_cols; ++i) {
      if (column_info[i].valid_len) {
        size_t idx = (by_columns ? filesno / ((cwd_n_used + i) / (i + 1))
                                 : filesno % (i + 1));
        size_t real_length = name_length + (idx == i ? 0 : 2);

        if (column_info[i].col_arr[idx] < real_length) {
          column_info[i].line_len +=
              (real_length - column_info[i].col_arr[idx]);
          column_info[i].col_arr[idx] = real_length;
          column_info[i].valid_len = (column_info[i].line_len < line_length);
        }
      }
    }
  }

  for (cols = max_cols; 1 < cols; --cols) {
    if (column_info[cols - 1].valid_len)
      break;
  }

  return cols;
}

void usage(int status) {
  if (status != 0)
    do {
      fprintf(
          stderr,
          dcgettext(((void *)0), "Try '%s --help' for more information.\n", 5),
          program_name);
    } while (0);
  else {
    printf(dcgettext(((void *)0), "Usage: %s [OPTION]... [FILE]...\n", 5),
           program_name);
    fputs_unlocked(
        dcgettext(((void *)0),
                  "List information about the FILEs (the current directory by "
                  "default).\nSort entries alphabetically if none of -cftuvSUX "
                  "nor --sort is specified.\n",
                  5),
        stdout)

        ;

    emit_mandatory_arg_note();

    fputs_unlocked(
        dcgettext(((void *)0),
                  "  -a, --all                  do not ignore entries starting "
                  "with .\n  -A, --almost-all           do not list implied . "
                  "and ..\n      --author               with -l, print the "
                  "author of each file\n  -b, --escape               print "
                  "C-style escapes for nongraphic characters\n",
                  5),
        stdout)

        ;
    fputs_unlocked(
        dcgettext(((void *)0),
                  "      --block-size=SIZE      with -l, scale sizes by SIZE "
                  "when printing them;\n                             e.g., "
                  "'--block-size=M'; see SIZE format below\n\n",
                  5),
        stdout)

        ;
    fputs_unlocked(dcgettext(((void *)0),
                             "  -B, --ignore-backups       do not list implied "
                             "entries ending with ~\n",
                             5),
                   stdout)

        ;
    fputs_unlocked(
        dcgettext(
            ((void *)0),
            "  -c                         with -lt: sort by, and show, ctime "
            "(time of last\n                             modification of file "
            "status information);\n                             with -l: show "
            "ctime and sort by name;\n                             otherwise: "
            "sort by ctime, newest first\n\n",
            5),
        stdout)

        ;
    fputs_unlocked(
        dcgettext(((void *)0),
                  "  -C                         list entries by columns\n      "
                  "--color[=WHEN]         color the output WHEN; more info "
                  "below\n  -d, --directory            list directories "
                  "themselves, not their contents\n  -D, --dired               "
                  " generate output designed for Emacs' dired mode\n",
                  5),
        stdout)

        ;
    fputs_unlocked(
        dcgettext(((void *)0),
                  "  -f                         list all entries in directory "
                  "order\n  -F, --classify[=WHEN]      append indicator (one "
                  "of */=>@|) to entries WHEN\n      --file-type            "
                  "likewise, except do not append '*'\n",
                  5),
        stdout)

        ;
    fputs_unlocked(
        dcgettext(((void *)0),
                  "      --format=WORD          across -x, commas -m, "
                  "horizontal -x, long -l,\n                             "
                  "single-column -1, verbose -l, vertical -C\n\n",
                  5),
        stdout)

        ;
    fputs_unlocked(
        dcgettext(
            ((void *)0),
            "      --full-time            like -l --time-style=full-iso\n", 5),
        stdout)

        ;
    fputs_unlocked(
        dcgettext(
            ((void *)0),
            "  -g                         like -l, but do not list owner\n", 5),
        stdout)

        ;
    fputs_unlocked(
        dcgettext(
            ((void *)0),
            "      --group-directories-first\n                             "
            "group directories before files;\n                             can "
            "be augmented with a --sort option, but any\n                      "
            "       use of --sort=none (-U) disables grouping\n\n",
            5),
        stdout)

        ;
    fputs_unlocked(dcgettext(((void *)0),
                             "  -G, --no-group             in a long listing, "
                             "don't print group names\n",
                             5),
                   stdout)

        ;
    fputs_unlocked(
        dcgettext(((void *)0),
                  "  -h, --human-readable       with -l and -s, print sizes "
                  "like 1K 234M 2G etc.\n      --si                   "
                  "likewise, but use powers of 1000 not 1024\n",
                  5),
        stdout)

        ;
    fputs_unlocked(
        dcgettext(((void *)0),
                  "  -H, --dereference-command-line\n                          "
                  "   follow symbolic links listed on the command line\n",
                  5),
        stdout)

        ;
    fputs_unlocked(
        dcgettext(((void *)0),
                  "      --dereference-command-line-symlink-to-dir\n           "
                  "                  follow each command line symbolic link\n  "
                  "                           that points to a directory\n\n",
                  5),
        stdout)

        ;
    fputs_unlocked(dcgettext(((void *)0),
                             "      --hide=PATTERN         do not list implied "
                             "entries matching shell PATTERN\n                 "
                             "            (overridden by -a or -A)\n\n",
                             5),
                   stdout)

        ;
    fputs_unlocked(
        dcgettext(((void *)0),
                  "      --hyperlink[=WHEN]     hyperlink file names WHEN\n",
                  5),
        stdout)

        ;
    fputs_unlocked(
        dcgettext(((void *)0),
                  "      --indicator-style=WORD\n                             "
                  "append indicator with style WORD to entry names:\n          "
                  "                   none (default), slash (-p),\n            "
                  "                 file-type (--file-type), classify (-F)\n\n",
                  5),
        stdout)

        ;
    fputs_unlocked(
        dcgettext(((void *)0),
                  "  -i, --inode                print the index number of each "
                  "file\n  -I, --ignore=PATTERN       do not list implied "
                  "entries matching shell PATTERN\n",
                  5),
        stdout)

        ;
    fputs_unlocked(
        dcgettext(((void *)0),
                  "  -k, --kibibytes            default to 1024-byte blocks "
                  "for file system usage;\n                             used "
                  "only with -s and per directory totals\n\n",
                  5),
        stdout)

        ;
    fputs_unlocked(
        dcgettext(((void *)0),
                  "  -l                         use a long listing format\n",
                  5),
        stdout)

        ;
    fputs_unlocked(
        dcgettext(((void *)0),
                  "  -L, --dereference          when showing file information "
                  "for a symbolic\n                             link, show "
                  "information for the file the link\n                         "
                  "    references rather than for the link itself\n\n",
                  5),
        stdout)

        ;
    fputs_unlocked(dcgettext(((void *)0),
                             "  -m                         fill width with a "
                             "comma separated list of entries\n",
                             5),
                   stdout)

        ;
    fputs_unlocked(
        dcgettext(
            ((void *)0),
            "  -n, --numeric-uid-gid      like -l, but list numeric user and "
            "group IDs\n  -N, --literal              print entry names without "
            "quoting\n  -o                         like -l, but do not list "
            "group information\n  -p, --indicator-style=slash\n                "
            "             append / indicator to directories\n",
            5),
        stdout)

        ;
    fputs_unlocked(dcgettext(((void *)0),
                             "  -q, --hide-control-chars   print ? instead of "
                             "nongraphic characters\n",
                             5),
                   stdout)

        ;
    fputs_unlocked(
        dcgettext(((void *)0),
                  "      --show-control-chars   show nongraphic characters "
                  "as-is (the default,\n                             unless "
                  "program is 'ls' and output is a terminal)\n\n",
                  5),
        stdout)

        ;
    fputs_unlocked(dcgettext(((void *)0),
                             "  -Q, --quote-name           enclose entry names "
                             "in double quotes\n",
                             5),
                   stdout)

        ;
    fputs_unlocked(
        dcgettext(
            ((void *)0),
            "      --quoting-style=WORD   use quoting style WORD for entry "
            "names:\n                             literal, locale, shell, "
            "shell-always,\n                             shell-escape, "
            "shell-escape-always, c, escape\n                             "
            "(overrides QUOTING_STYLE environment variable)\n\n",
            5),
        stdout)

        ;
    fputs_unlocked(
        dcgettext(((void *)0),
                  "  -r, --reverse              reverse order while sorting\n  "
                  "-R, --recursive            list subdirectories "
                  "recursively\n  -s, --size                 print the "
                  "allocated size of each file, in blocks\n",
                  5),
        stdout)

        ;
    fputs_unlocked(
        dcgettext(
            ((void *)0),
            "  -S                         sort by file size, largest first\n",
            5),
        stdout)

        ;
    fputs_unlocked(
        dcgettext(((void *)0),
                  "      --sort=WORD            sort by WORD instead of name: "
                  "none (-U), size (-S),\n                             time "
                  "(-t), version (-v), extension (-X), width\n\n",
                  5),
        stdout)

        ;
    fputs_unlocked(
        dcgettext(
            ((void *)0),
            "      --time=WORD            change the default of using "
            "modification times;\n                               access time "
            "(-u): atime, access, use;\n                               change "
            "time (-c): ctime, status;\n                               birth "
            "time: birth, creation;\n                             with -l, "
            "WORD determines which time to show;\n                             "
            "with --sort=time, sort by WORD (newest first)\n\n",
            5),
        stdout)

        ;
    fputs_unlocked(
        dcgettext(((void *)0),
                  "      --time-style=TIME_STYLE\n                             "
                  "time/date format with -l; see TIME_STYLE below\n",
                  5),
        stdout)

        ;
    fputs_unlocked(
        dcgettext(((void *)0),
                  "  -t                         sort by time, newest first; "
                  "see --time\n  -T, --tabsize=COLS         assume tab stops "
                  "at each COLS instead of 8\n",
                  5),
        stdout)

        ;
    fputs_unlocked(
        dcgettext(((void *)0),
                  "  -u                         with -lt: sort by, and show, "
                  "access time;\n                             with -l: show "
                  "access time and sort by name;\n                             "
                  "otherwise: sort by access time, newest first\n\n",
                  5),
        stdout)

        ;
    fputs_unlocked(dcgettext(((void *)0),
                             "  -U                         do not sort; list "
                             "entries in directory order\n",
                             5),
                   stdout)

        ;
    fputs_unlocked(dcgettext(((void *)0),
                             "  -v                         natural sort of "
                             "(version) numbers within text\n",
                             5),
                   stdout)

        ;
    fputs_unlocked(
        dcgettext(
            ((void *)0),
            "  -w, --width=COLS           set output width to COLS.  0 means "
            "no limit\n  -x                         list entries by lines "
            "instead of by columns\n  -X                         sort "
            "alphabetically by entry extension\n  -Z, --context              "
            "print any security context of each file\n      --zero             "
            "    end each output line with NUL, not newline\n  -1              "
            "           list one file per line\n",
            5),
        stdout)

        ;
    fputs_unlocked(dcgettext(((void *)0),
                             "      --help        display this help and exit\n",
                             5),
                   stdout);
    fputs_unlocked(
        dcgettext(((void *)0),
                  "      --version     output version information and exit\n",
                  5),
        stdout);
    emit_size_note();
    fputs_unlocked(
        dcgettext(
            ((void *)0),
            "\nThe TIME_STYLE argument can be full-iso, long-iso, iso, locale, "
            "or +FORMAT.\nFORMAT is interpreted like in date(1).  If FORMAT is "
            "FORMAT1<newline>FORMAT2,\nthen FORMAT1 applies to non-recent "
            "files and FORMAT2 to recent files.\nTIME_STYLE prefixed with "
            "'posix-' takes effect only outside the POSIX locale.\nAlso the "
            "TIME_STYLE environment variable sets the default style to use.\n",
            5),
        stdout)

        ;
    fputs_unlocked(dcgettext(((void *)0),
                             "\nThe WHEN argument defaults to 'always' and can "
                             "also be 'auto' or 'never'.\n",
                             5),
                   stdout)

        ;
    fputs_unlocked(
        dcgettext(
            ((void *)0),
            "\nUsing color to distinguish file types is disabled both by "
            "default and\nwith --color=never.  With --color=auto, ls emits "
            "color codes only when\nstandard output is connected to a "
            "terminal.  The LS_COLORS environment\nvariable can change the "
            "settings.  Use the dircolors(1) command to set it.\n",
            5),
        stdout)

        ;
    fputs_unlocked(
        dcgettext(((void *)0),
                  "\nExit status:\n 0  if OK,\n 1  if minor problems (e.g., "
                  "cannot access subdirectory),\n 2  if serious trouble (e.g., "
                  "cannot access command-line argument).\n",
                  5),
        stdout)

        ;
    emit_ancillary_info(
        (ls_mode == 1 ? "ls" : (ls_mode == 2 ? "dir" : "vdir")));
  }
  exit(status);
}

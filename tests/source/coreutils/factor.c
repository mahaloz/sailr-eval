

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

typedef long unsigned int size_t;

typedef __builtin_va_list __gnuc_va_list;

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
typedef __off_t off_t;

typedef __off64_t off64_t;

typedef __ssize_t ssize_t;

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
typedef __pid_t pid_t;

typedef __id_t id_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;

typedef __key_t key_t;

typedef __clock_t clock_t;

typedef __clockid_t clockid_t;
typedef __time_t time_t;

typedef __timer_t timer_t;

typedef __useconds_t useconds_t;

typedef __suseconds_t suseconds_t;

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

extern long int __sysconf(int __name) __attribute__((__nothrow__, __leaf__));

typedef unsigned long int mp_limb_t;
typedef long int mp_limb_signed_t;

typedef unsigned long int mp_bitcnt_t;

typedef struct {
  int _mp_alloc;

  int _mp_size;

  mp_limb_t *_mp_d;
} __mpz_struct;

typedef __mpz_struct MP_INT;
typedef __mpz_struct mpz_t[1];

typedef mp_limb_t *mp_ptr;
typedef const mp_limb_t *mp_srcptr;

typedef long int mp_size_t;
typedef long int mp_exp_t;

typedef struct {
  __mpz_struct _mp_num;
  __mpz_struct _mp_den;
} __mpq_struct;

typedef __mpq_struct MP_RAT;
typedef __mpq_struct mpq_t[1];

typedef struct {
  int _mp_prec;

  int _mp_size;

  mp_exp_t _mp_exp;
  mp_limb_t *_mp_d;
} __mpf_struct;

typedef __mpf_struct mpf_t[1];

typedef enum {
  GMP_RAND_ALG_DEFAULT = 0,
  GMP_RAND_ALG_LC = GMP_RAND_ALG_DEFAULT
} gmp_randalg_t;

typedef struct {
  mpz_t _mp_seed;
  gmp_randalg_t _mp_alg;
  union {
    void *_mp_lc;
  } _mp_algdata;
} __gmp_randstate_struct;
typedef __gmp_randstate_struct gmp_randstate_t[1];

typedef const __mpz_struct *mpz_srcptr;
typedef __mpz_struct *mpz_ptr;
typedef const __mpf_struct *mpf_srcptr;
typedef __mpf_struct *mpf_ptr;
typedef const __mpq_struct *mpq_srcptr;
typedef __mpq_struct *mpq_ptr;
void __gmp_set_memory_functions(void *(*)(size_t),
                                void *(*)(void *, size_t, size_t),
                                void (*)(void *, size_t));

void __gmp_get_memory_functions(void *(**)(size_t),
                                void *(**)(void *, size_t, size_t),
                                void (**)(void *, size_t));

extern const int __gmp_bits_per_limb;

extern int __gmp_errno;

extern const char *const __gmp_version;

void __gmp_randinit(gmp_randstate_t, gmp_randalg_t, ...);

void __gmp_randinit_default(gmp_randstate_t);

void __gmp_randinit_lc_2exp(gmp_randstate_t, mpz_srcptr, unsigned long int,
                            mp_bitcnt_t);

int __gmp_randinit_lc_2exp_size(gmp_randstate_t, mp_bitcnt_t);

void __gmp_randinit_mt(gmp_randstate_t);

void __gmp_randinit_set(gmp_randstate_t, const __gmp_randstate_struct *);

void __gmp_randseed(gmp_randstate_t, mpz_srcptr);

void __gmp_randseed_ui(gmp_randstate_t, unsigned long int);

void __gmp_randclear(gmp_randstate_t);

unsigned long __gmp_urandomb_ui(gmp_randstate_t, unsigned long);

unsigned long __gmp_urandomm_ui(gmp_randstate_t, unsigned long);

int __gmp_asprintf(char **, const char *, ...);

int __gmp_fprintf(FILE *, const char *, ...);
int __gmp_printf(const char *, ...);

int __gmp_snprintf(char *, size_t, const char *, ...);

int __gmp_sprintf(char *, const char *, ...);

int __gmp_vasprintf(char **, const char *, va_list);

int __gmp_vfprintf(FILE *, const char *, va_list);

int __gmp_vprintf(const char *, va_list);

int __gmp_vsnprintf(char *, size_t, const char *, va_list);

int __gmp_vsprintf(char *, const char *, va_list);

int __gmp_fscanf(FILE *, const char *, ...);

int __gmp_scanf(const char *, ...);

int __gmp_sscanf(const char *, const char *, ...);

int __gmp_vfscanf(FILE *, const char *, va_list);

int __gmp_vscanf(const char *, va_list);

int __gmp_vsscanf(const char *, const char *, va_list);

void *__gmpz_realloc(mpz_ptr, mp_size_t);

void __gmpz_abs(mpz_ptr, mpz_srcptr);

void __gmpz_add(mpz_ptr, mpz_srcptr, mpz_srcptr);

void __gmpz_add_ui(mpz_ptr, mpz_srcptr, unsigned long int);

void __gmpz_addmul(mpz_ptr, mpz_srcptr, mpz_srcptr);

void __gmpz_addmul_ui(mpz_ptr, mpz_srcptr, unsigned long int);

void __gmpz_and(mpz_ptr, mpz_srcptr, mpz_srcptr);

void __gmpz_array_init(mpz_ptr, mp_size_t, mp_size_t);

void __gmpz_bin_ui(mpz_ptr, mpz_srcptr, unsigned long int);

void __gmpz_bin_uiui(mpz_ptr, unsigned long int, unsigned long int);

void __gmpz_cdiv_q(mpz_ptr, mpz_srcptr, mpz_srcptr);

void __gmpz_cdiv_q_2exp(mpz_ptr, mpz_srcptr, mp_bitcnt_t);

unsigned long int __gmpz_cdiv_q_ui(mpz_ptr, mpz_srcptr, unsigned long int);

void __gmpz_cdiv_qr(mpz_ptr, mpz_ptr, mpz_srcptr, mpz_srcptr);

unsigned long int __gmpz_cdiv_qr_ui(mpz_ptr, mpz_ptr, mpz_srcptr,
                                    unsigned long int);

void __gmpz_cdiv_r(mpz_ptr, mpz_srcptr, mpz_srcptr);

void __gmpz_cdiv_r_2exp(mpz_ptr, mpz_srcptr, mp_bitcnt_t);

unsigned long int __gmpz_cdiv_r_ui(mpz_ptr, mpz_srcptr, unsigned long int);

unsigned long int __gmpz_cdiv_ui(mpz_srcptr, unsigned long int)
    __attribute__((__pure__));

void __gmpz_clear(mpz_ptr);

void __gmpz_clears(mpz_ptr, ...);

void __gmpz_clrbit(mpz_ptr, mp_bitcnt_t);

int __gmpz_cmp(mpz_srcptr, mpz_srcptr) __attribute__((__pure__));

int __gmpz_cmp_d(mpz_srcptr, double) __attribute__((__pure__));

int __gmpz_cmp_si(mpz_srcptr, signed long int) __attribute__((__pure__));

int __gmpz_cmp_ui(mpz_srcptr, unsigned long int) __attribute__((__pure__));

int __gmpz_cmpabs(mpz_srcptr, mpz_srcptr) __attribute__((__pure__));

int __gmpz_cmpabs_d(mpz_srcptr, double) __attribute__((__pure__));

int __gmpz_cmpabs_ui(mpz_srcptr, unsigned long int) __attribute__((__pure__));

void __gmpz_com(mpz_ptr, mpz_srcptr);

void __gmpz_combit(mpz_ptr, mp_bitcnt_t);

int __gmpz_congruent_p(mpz_srcptr, mpz_srcptr, mpz_srcptr)
    __attribute__((__pure__));

int __gmpz_congruent_2exp_p(mpz_srcptr, mpz_srcptr, mp_bitcnt_t)
    __attribute__((__pure__));

int __gmpz_congruent_ui_p(mpz_srcptr, unsigned long, unsigned long)
    __attribute__((__pure__));

void __gmpz_divexact(mpz_ptr, mpz_srcptr, mpz_srcptr);

void __gmpz_divexact_ui(mpz_ptr, mpz_srcptr, unsigned long);

int __gmpz_divisible_p(mpz_srcptr, mpz_srcptr) __attribute__((__pure__));

int __gmpz_divisible_ui_p(mpz_srcptr, unsigned long) __attribute__((__pure__));

int __gmpz_divisible_2exp_p(mpz_srcptr, mp_bitcnt_t) __attribute__((__pure__));

void __gmpz_dump(mpz_srcptr);

void *__gmpz_export(void *, size_t *, int, size_t, int, size_t, mpz_srcptr);

void __gmpz_fac_ui(mpz_ptr, unsigned long int);

void __gmpz_2fac_ui(mpz_ptr, unsigned long int);

void __gmpz_mfac_uiui(mpz_ptr, unsigned long int, unsigned long int);

void __gmpz_primorial_ui(mpz_ptr, unsigned long int);

void __gmpz_fdiv_q(mpz_ptr, mpz_srcptr, mpz_srcptr);

void __gmpz_fdiv_q_2exp(mpz_ptr, mpz_srcptr, mp_bitcnt_t);

unsigned long int __gmpz_fdiv_q_ui(mpz_ptr, mpz_srcptr, unsigned long int);

void __gmpz_fdiv_qr(mpz_ptr, mpz_ptr, mpz_srcptr, mpz_srcptr);

unsigned long int __gmpz_fdiv_qr_ui(mpz_ptr, mpz_ptr, mpz_srcptr,
                                    unsigned long int);

void __gmpz_fdiv_r(mpz_ptr, mpz_srcptr, mpz_srcptr);

void __gmpz_fdiv_r_2exp(mpz_ptr, mpz_srcptr, mp_bitcnt_t);

unsigned long int __gmpz_fdiv_r_ui(mpz_ptr, mpz_srcptr, unsigned long int);

unsigned long int __gmpz_fdiv_ui(mpz_srcptr, unsigned long int)
    __attribute__((__pure__));

void __gmpz_fib_ui(mpz_ptr, unsigned long int);

void __gmpz_fib2_ui(mpz_ptr, mpz_ptr, unsigned long int);

int __gmpz_fits_sint_p(mpz_srcptr) __attribute__((__pure__));

int __gmpz_fits_slong_p(mpz_srcptr) __attribute__((__pure__));

int __gmpz_fits_sshort_p(mpz_srcptr) __attribute__((__pure__));

int __gmpz_fits_uint_p(mpz_srcptr) __attribute__((__pure__));

int __gmpz_fits_ulong_p(mpz_srcptr) __attribute__((__pure__));

int __gmpz_fits_ushort_p(mpz_srcptr) __attribute__((__pure__));

void __gmpz_gcd(mpz_ptr, mpz_srcptr, mpz_srcptr);

unsigned long int __gmpz_gcd_ui(mpz_ptr, mpz_srcptr, unsigned long int);

void __gmpz_gcdext(mpz_ptr, mpz_ptr, mpz_ptr, mpz_srcptr, mpz_srcptr);

double __gmpz_get_d(mpz_srcptr) __attribute__((__pure__));

double __gmpz_get_d_2exp(signed long int *, mpz_srcptr);

long int __gmpz_get_si(mpz_srcptr) __attribute__((__pure__));

char *__gmpz_get_str(char *, int, mpz_srcptr);

unsigned long int __gmpz_get_ui(mpz_srcptr) __attribute__((__pure__));

mp_limb_t __gmpz_getlimbn(mpz_srcptr, mp_size_t) __attribute__((__pure__));

mp_bitcnt_t __gmpz_hamdist(mpz_srcptr, mpz_srcptr) __attribute__((__pure__));

void __gmpz_import(mpz_ptr, size_t, int, size_t, int, size_t, const void *);

void __gmpz_init(mpz_ptr);

void __gmpz_init2(mpz_ptr, mp_bitcnt_t);

void __gmpz_inits(mpz_ptr, ...);

void __gmpz_init_set(mpz_ptr, mpz_srcptr);

void __gmpz_init_set_d(mpz_ptr, double);

void __gmpz_init_set_si(mpz_ptr, signed long int);

int __gmpz_init_set_str(mpz_ptr, const char *, int);

void __gmpz_init_set_ui(mpz_ptr, unsigned long int);

size_t __gmpz_inp_raw(mpz_ptr, FILE *);

size_t __gmpz_inp_str(mpz_ptr, FILE *, int);

int __gmpz_invert(mpz_ptr, mpz_srcptr, mpz_srcptr);

void __gmpz_ior(mpz_ptr, mpz_srcptr, mpz_srcptr);

int __gmpz_jacobi(mpz_srcptr, mpz_srcptr) __attribute__((__pure__));

int __gmpz_kronecker_si(mpz_srcptr, long) __attribute__((__pure__));

int __gmpz_kronecker_ui(mpz_srcptr, unsigned long) __attribute__((__pure__));

int __gmpz_si_kronecker(long, mpz_srcptr) __attribute__((__pure__));

int __gmpz_ui_kronecker(unsigned long, mpz_srcptr) __attribute__((__pure__));

void __gmpz_lcm(mpz_ptr, mpz_srcptr, mpz_srcptr);

void __gmpz_lcm_ui(mpz_ptr, mpz_srcptr, unsigned long);

void __gmpz_lucnum_ui(mpz_ptr, unsigned long int);

void __gmpz_lucnum2_ui(mpz_ptr, mpz_ptr, unsigned long int);

int __gmpz_millerrabin(mpz_srcptr, int) __attribute__((__pure__));

void __gmpz_mod(mpz_ptr, mpz_srcptr, mpz_srcptr);

void __gmpz_mul(mpz_ptr, mpz_srcptr, mpz_srcptr);

void __gmpz_mul_2exp(mpz_ptr, mpz_srcptr, mp_bitcnt_t);

void __gmpz_mul_si(mpz_ptr, mpz_srcptr, long int);

void __gmpz_mul_ui(mpz_ptr, mpz_srcptr, unsigned long int);

void __gmpz_neg(mpz_ptr, mpz_srcptr);

void __gmpz_nextprime(mpz_ptr, mpz_srcptr);

size_t __gmpz_out_raw(FILE *, mpz_srcptr);

size_t __gmpz_out_str(FILE *, int, mpz_srcptr);

int __gmpz_perfect_power_p(mpz_srcptr) __attribute__((__pure__));

int __gmpz_perfect_square_p(mpz_srcptr) __attribute__((__pure__));

mp_bitcnt_t __gmpz_popcount(mpz_srcptr) __attribute__((__pure__));

void __gmpz_pow_ui(mpz_ptr, mpz_srcptr, unsigned long int);

void __gmpz_powm(mpz_ptr, mpz_srcptr, mpz_srcptr, mpz_srcptr);

void __gmpz_powm_sec(mpz_ptr, mpz_srcptr, mpz_srcptr, mpz_srcptr);

void __gmpz_powm_ui(mpz_ptr, mpz_srcptr, unsigned long int, mpz_srcptr);

int __gmpz_probab_prime_p(mpz_srcptr, int) __attribute__((__pure__));

void __gmpz_random(mpz_ptr, mp_size_t);

void __gmpz_random2(mpz_ptr, mp_size_t);

void __gmpz_realloc2(mpz_ptr, mp_bitcnt_t);

mp_bitcnt_t __gmpz_remove(mpz_ptr, mpz_srcptr, mpz_srcptr);

int __gmpz_root(mpz_ptr, mpz_srcptr, unsigned long int);

void __gmpz_rootrem(mpz_ptr, mpz_ptr, mpz_srcptr, unsigned long int);

void __gmpz_rrandomb(mpz_ptr, gmp_randstate_t, mp_bitcnt_t);

mp_bitcnt_t __gmpz_scan0(mpz_srcptr, mp_bitcnt_t) __attribute__((__pure__));

mp_bitcnt_t __gmpz_scan1(mpz_srcptr, mp_bitcnt_t) __attribute__((__pure__));

void __gmpz_set(mpz_ptr, mpz_srcptr);

void __gmpz_set_d(mpz_ptr, double);

void __gmpz_set_f(mpz_ptr, mpf_srcptr);

void __gmpz_set_q(mpz_ptr, mpq_srcptr);

void __gmpz_set_si(mpz_ptr, signed long int);

int __gmpz_set_str(mpz_ptr, const char *, int);

void __gmpz_set_ui(mpz_ptr, unsigned long int);

void __gmpz_setbit(mpz_ptr, mp_bitcnt_t);

size_t __gmpz_size(mpz_srcptr) __attribute__((__pure__));

size_t __gmpz_sizeinbase(mpz_srcptr, int) __attribute__((__pure__));

void __gmpz_sqrt(mpz_ptr, mpz_srcptr);

void __gmpz_sqrtrem(mpz_ptr, mpz_ptr, mpz_srcptr);

void __gmpz_sub(mpz_ptr, mpz_srcptr, mpz_srcptr);

void __gmpz_sub_ui(mpz_ptr, mpz_srcptr, unsigned long int);

void __gmpz_ui_sub(mpz_ptr, unsigned long int, mpz_srcptr);

void __gmpz_submul(mpz_ptr, mpz_srcptr, mpz_srcptr);

void __gmpz_submul_ui(mpz_ptr, mpz_srcptr, unsigned long int);

void __gmpz_swap(mpz_ptr, mpz_ptr);

unsigned long int __gmpz_tdiv_ui(mpz_srcptr, unsigned long int)
    __attribute__((__pure__));

void __gmpz_tdiv_q(mpz_ptr, mpz_srcptr, mpz_srcptr);

void __gmpz_tdiv_q_2exp(mpz_ptr, mpz_srcptr, mp_bitcnt_t);

unsigned long int __gmpz_tdiv_q_ui(mpz_ptr, mpz_srcptr, unsigned long int);

void __gmpz_tdiv_qr(mpz_ptr, mpz_ptr, mpz_srcptr, mpz_srcptr);

unsigned long int __gmpz_tdiv_qr_ui(mpz_ptr, mpz_ptr, mpz_srcptr,
                                    unsigned long int);

void __gmpz_tdiv_r(mpz_ptr, mpz_srcptr, mpz_srcptr);

void __gmpz_tdiv_r_2exp(mpz_ptr, mpz_srcptr, mp_bitcnt_t);

unsigned long int __gmpz_tdiv_r_ui(mpz_ptr, mpz_srcptr, unsigned long int);

int __gmpz_tstbit(mpz_srcptr, mp_bitcnt_t) __attribute__((__pure__));

void __gmpz_ui_pow_ui(mpz_ptr, unsigned long int, unsigned long int);

void __gmpz_urandomb(mpz_ptr, gmp_randstate_t, mp_bitcnt_t);

void __gmpz_urandomm(mpz_ptr, gmp_randstate_t, mpz_srcptr);

void __gmpz_xor(mpz_ptr, mpz_srcptr, mpz_srcptr);

mp_srcptr __gmpz_limbs_read(mpz_srcptr);

mp_ptr __gmpz_limbs_write(mpz_ptr, mp_size_t);

mp_ptr __gmpz_limbs_modify(mpz_ptr, mp_size_t);

void __gmpz_limbs_finish(mpz_ptr, mp_size_t);

mpz_srcptr __gmpz_roinit_n(mpz_ptr, mp_srcptr, mp_size_t);

void __gmpq_abs(mpq_ptr, mpq_srcptr);

void __gmpq_add(mpq_ptr, mpq_srcptr, mpq_srcptr);

void __gmpq_canonicalize(mpq_ptr);

void __gmpq_clear(mpq_ptr);

void __gmpq_clears(mpq_ptr, ...);

int __gmpq_cmp(mpq_srcptr, mpq_srcptr) __attribute__((__pure__));

int __gmpq_cmp_si(mpq_srcptr, long, unsigned long) __attribute__((__pure__));

int __gmpq_cmp_ui(mpq_srcptr, unsigned long int, unsigned long int)
    __attribute__((__pure__));

int __gmpq_cmp_z(mpq_srcptr, mpz_srcptr) __attribute__((__pure__));

void __gmpq_div(mpq_ptr, mpq_srcptr, mpq_srcptr);

void __gmpq_div_2exp(mpq_ptr, mpq_srcptr, mp_bitcnt_t);

int __gmpq_equal(mpq_srcptr, mpq_srcptr) __attribute__((__pure__));

void __gmpq_get_num(mpz_ptr, mpq_srcptr);

void __gmpq_get_den(mpz_ptr, mpq_srcptr);

double __gmpq_get_d(mpq_srcptr) __attribute__((__pure__));

char *__gmpq_get_str(char *, int, mpq_srcptr);

void __gmpq_init(mpq_ptr);

void __gmpq_inits(mpq_ptr, ...);

size_t __gmpq_inp_str(mpq_ptr, FILE *, int);

void __gmpq_inv(mpq_ptr, mpq_srcptr);

void __gmpq_mul(mpq_ptr, mpq_srcptr, mpq_srcptr);

void __gmpq_mul_2exp(mpq_ptr, mpq_srcptr, mp_bitcnt_t);

void __gmpq_neg(mpq_ptr, mpq_srcptr);

size_t __gmpq_out_str(FILE *, int, mpq_srcptr);

void __gmpq_set(mpq_ptr, mpq_srcptr);

void __gmpq_set_d(mpq_ptr, double);

void __gmpq_set_den(mpq_ptr, mpz_srcptr);

void __gmpq_set_f(mpq_ptr, mpf_srcptr);

void __gmpq_set_num(mpq_ptr, mpz_srcptr);

void __gmpq_set_si(mpq_ptr, signed long int, unsigned long int);

int __gmpq_set_str(mpq_ptr, const char *, int);

void __gmpq_set_ui(mpq_ptr, unsigned long int, unsigned long int);

void __gmpq_set_z(mpq_ptr, mpz_srcptr);

void __gmpq_sub(mpq_ptr, mpq_srcptr, mpq_srcptr);

void __gmpq_swap(mpq_ptr, mpq_ptr);

void __gmpf_abs(mpf_ptr, mpf_srcptr);

void __gmpf_add(mpf_ptr, mpf_srcptr, mpf_srcptr);

void __gmpf_add_ui(mpf_ptr, mpf_srcptr, unsigned long int);

void __gmpf_ceil(mpf_ptr, mpf_srcptr);

void __gmpf_clear(mpf_ptr);

void __gmpf_clears(mpf_ptr, ...);

int __gmpf_cmp(mpf_srcptr, mpf_srcptr) __attribute__((__pure__));

int __gmpf_cmp_z(mpf_srcptr, mpz_srcptr) __attribute__((__pure__));

int __gmpf_cmp_d(mpf_srcptr, double) __attribute__((__pure__));

int __gmpf_cmp_si(mpf_srcptr, signed long int) __attribute__((__pure__));

int __gmpf_cmp_ui(mpf_srcptr, unsigned long int) __attribute__((__pure__));

void __gmpf_div(mpf_ptr, mpf_srcptr, mpf_srcptr);

void __gmpf_div_2exp(mpf_ptr, mpf_srcptr, mp_bitcnt_t);

void __gmpf_div_ui(mpf_ptr, mpf_srcptr, unsigned long int);

void __gmpf_dump(mpf_srcptr);

int __gmpf_eq(mpf_srcptr, mpf_srcptr, mp_bitcnt_t) __attribute__((__pure__));

int __gmpf_fits_sint_p(mpf_srcptr) __attribute__((__pure__));

int __gmpf_fits_slong_p(mpf_srcptr) __attribute__((__pure__));

int __gmpf_fits_sshort_p(mpf_srcptr) __attribute__((__pure__));

int __gmpf_fits_uint_p(mpf_srcptr) __attribute__((__pure__));

int __gmpf_fits_ulong_p(mpf_srcptr) __attribute__((__pure__));

int __gmpf_fits_ushort_p(mpf_srcptr) __attribute__((__pure__));

void __gmpf_floor(mpf_ptr, mpf_srcptr);

double __gmpf_get_d(mpf_srcptr) __attribute__((__pure__));

double __gmpf_get_d_2exp(signed long int *, mpf_srcptr);

mp_bitcnt_t __gmpf_get_default_prec(void) __attribute__((__pure__));

mp_bitcnt_t __gmpf_get_prec(mpf_srcptr) __attribute__((__pure__));

long __gmpf_get_si(mpf_srcptr) __attribute__((__pure__));

char *__gmpf_get_str(char *, mp_exp_t *, int, size_t, mpf_srcptr);

unsigned long __gmpf_get_ui(mpf_srcptr) __attribute__((__pure__));

void __gmpf_init(mpf_ptr);

void __gmpf_init2(mpf_ptr, mp_bitcnt_t);

void __gmpf_inits(mpf_ptr, ...);

void __gmpf_init_set(mpf_ptr, mpf_srcptr);

void __gmpf_init_set_d(mpf_ptr, double);

void __gmpf_init_set_si(mpf_ptr, signed long int);

int __gmpf_init_set_str(mpf_ptr, const char *, int);

void __gmpf_init_set_ui(mpf_ptr, unsigned long int);

size_t __gmpf_inp_str(mpf_ptr, FILE *, int);

int __gmpf_integer_p(mpf_srcptr) __attribute__((__pure__));

void __gmpf_mul(mpf_ptr, mpf_srcptr, mpf_srcptr);

void __gmpf_mul_2exp(mpf_ptr, mpf_srcptr, mp_bitcnt_t);

void __gmpf_mul_ui(mpf_ptr, mpf_srcptr, unsigned long int);

void __gmpf_neg(mpf_ptr, mpf_srcptr);

size_t __gmpf_out_str(FILE *, int, size_t, mpf_srcptr);

void __gmpf_pow_ui(mpf_ptr, mpf_srcptr, unsigned long int);

void __gmpf_random2(mpf_ptr, mp_size_t, mp_exp_t);

void __gmpf_reldiff(mpf_ptr, mpf_srcptr, mpf_srcptr);

void __gmpf_set(mpf_ptr, mpf_srcptr);

void __gmpf_set_d(mpf_ptr, double);

void __gmpf_set_default_prec(mp_bitcnt_t);

void __gmpf_set_prec(mpf_ptr, mp_bitcnt_t);

void __gmpf_set_prec_raw(mpf_ptr, mp_bitcnt_t);

void __gmpf_set_q(mpf_ptr, mpq_srcptr);

void __gmpf_set_si(mpf_ptr, signed long int);

int __gmpf_set_str(mpf_ptr, const char *, int);

void __gmpf_set_ui(mpf_ptr, unsigned long int);

void __gmpf_set_z(mpf_ptr, mpz_srcptr);

size_t __gmpf_size(mpf_srcptr) __attribute__((__pure__));

void __gmpf_sqrt(mpf_ptr, mpf_srcptr);

void __gmpf_sqrt_ui(mpf_ptr, unsigned long int);

void __gmpf_sub(mpf_ptr, mpf_srcptr, mpf_srcptr);

void __gmpf_sub_ui(mpf_ptr, mpf_srcptr, unsigned long int);

void __gmpf_swap(mpf_ptr, mpf_ptr);

void __gmpf_trunc(mpf_ptr, mpf_srcptr);

void __gmpf_ui_div(mpf_ptr, unsigned long int, mpf_srcptr);

void __gmpf_ui_sub(mpf_ptr, unsigned long int, mpf_srcptr);

void __gmpf_urandomb(mpf_t, gmp_randstate_t, mp_bitcnt_t);
mp_limb_t __gmpn_add(mp_ptr, mp_srcptr, mp_size_t, mp_srcptr, mp_size_t);

mp_limb_t __gmpn_add_1(mp_ptr, mp_srcptr, mp_size_t, mp_limb_t);

mp_limb_t __gmpn_add_n(mp_ptr, mp_srcptr, mp_srcptr, mp_size_t);

mp_limb_t __gmpn_addmul_1(mp_ptr, mp_srcptr, mp_size_t, mp_limb_t);

int __gmpn_cmp(mp_srcptr, mp_srcptr, mp_size_t) __attribute__((__pure__));

int __gmpn_zero_p(mp_srcptr, mp_size_t) __attribute__((__pure__));

void __gmpn_divexact_1(mp_ptr, mp_srcptr, mp_size_t, mp_limb_t);

mp_limb_t __gmpn_divexact_by3c(mp_ptr, mp_srcptr, mp_size_t, mp_limb_t);

mp_limb_t __gmpn_divrem(mp_ptr, mp_size_t, mp_ptr, mp_size_t, mp_srcptr,
                        mp_size_t);

mp_limb_t __gmpn_divrem_1(mp_ptr, mp_size_t, mp_srcptr, mp_size_t, mp_limb_t);

mp_limb_t __gmpn_divrem_2(mp_ptr, mp_size_t, mp_ptr, mp_size_t, mp_srcptr);

mp_limb_t __gmpn_div_qr_1(mp_ptr, mp_limb_t *, mp_srcptr, mp_size_t, mp_limb_t);

mp_limb_t __gmpn_div_qr_2(mp_ptr, mp_ptr, mp_srcptr, mp_size_t, mp_srcptr);

mp_size_t __gmpn_gcd(mp_ptr, mp_ptr, mp_size_t, mp_ptr, mp_size_t);

mp_limb_t __gmpn_gcd_11(mp_limb_t, mp_limb_t) __attribute__((__pure__));

mp_limb_t __gmpn_gcd_1(mp_srcptr, mp_size_t, mp_limb_t)
    __attribute__((__pure__));

mp_limb_t __gmpn_gcdext_1(mp_limb_signed_t *, mp_limb_signed_t *, mp_limb_t,
                          mp_limb_t);

mp_size_t __gmpn_gcdext(mp_ptr, mp_ptr, mp_size_t *, mp_ptr, mp_size_t, mp_ptr,
                        mp_size_t);

size_t __gmpn_get_str(unsigned char *, int, mp_ptr, mp_size_t);

mp_bitcnt_t __gmpn_hamdist(mp_srcptr, mp_srcptr, mp_size_t)
    __attribute__((__pure__));

mp_limb_t __gmpn_lshift(mp_ptr, mp_srcptr, mp_size_t, unsigned int);

mp_limb_t __gmpn_mod_1(mp_srcptr, mp_size_t, mp_limb_t)
    __attribute__((__pure__));

mp_limb_t __gmpn_mul(mp_ptr, mp_srcptr, mp_size_t, mp_srcptr, mp_size_t);

mp_limb_t __gmpn_mul_1(mp_ptr, mp_srcptr, mp_size_t, mp_limb_t);

void __gmpn_mul_n(mp_ptr, mp_srcptr, mp_srcptr, mp_size_t);

void __gmpn_sqr(mp_ptr, mp_srcptr, mp_size_t);

mp_limb_t __gmpn_neg(mp_ptr, mp_srcptr, mp_size_t);

void __gmpn_com(mp_ptr, mp_srcptr, mp_size_t);

int __gmpn_perfect_square_p(mp_srcptr, mp_size_t) __attribute__((__pure__));

int __gmpn_perfect_power_p(mp_srcptr, mp_size_t) __attribute__((__pure__));

mp_bitcnt_t __gmpn_popcount(mp_srcptr, mp_size_t) __attribute__((__pure__));

mp_size_t __gmpn_pow_1(mp_ptr, mp_srcptr, mp_size_t, mp_limb_t, mp_ptr);

mp_limb_t __gmpn_preinv_mod_1(mp_srcptr, mp_size_t, mp_limb_t, mp_limb_t)
    __attribute__((__pure__));

void __gmpn_random(mp_ptr, mp_size_t);

void __gmpn_random2(mp_ptr, mp_size_t);

mp_limb_t __gmpn_rshift(mp_ptr, mp_srcptr, mp_size_t, unsigned int);

mp_bitcnt_t __gmpn_scan0(mp_srcptr, mp_bitcnt_t) __attribute__((__pure__));

mp_bitcnt_t __gmpn_scan1(mp_srcptr, mp_bitcnt_t) __attribute__((__pure__));

mp_size_t __gmpn_set_str(mp_ptr, const unsigned char *, size_t, int);

size_t __gmpn_sizeinbase(mp_srcptr, mp_size_t, int);

mp_size_t __gmpn_sqrtrem(mp_ptr, mp_ptr, mp_srcptr, mp_size_t);

mp_limb_t __gmpn_sub(mp_ptr, mp_srcptr, mp_size_t, mp_srcptr, mp_size_t);

mp_limb_t __gmpn_sub_1(mp_ptr, mp_srcptr, mp_size_t, mp_limb_t);

mp_limb_t __gmpn_sub_n(mp_ptr, mp_srcptr, mp_srcptr, mp_size_t);

mp_limb_t __gmpn_submul_1(mp_ptr, mp_srcptr, mp_size_t, mp_limb_t);

void __gmpn_tdiv_qr(mp_ptr, mp_ptr, mp_size_t, mp_srcptr, mp_size_t, mp_srcptr,
                    mp_size_t);

void __gmpn_and_n(mp_ptr, mp_srcptr, mp_srcptr, mp_size_t);

void __gmpn_andn_n(mp_ptr, mp_srcptr, mp_srcptr, mp_size_t);

void __gmpn_nand_n(mp_ptr, mp_srcptr, mp_srcptr, mp_size_t);

void __gmpn_ior_n(mp_ptr, mp_srcptr, mp_srcptr, mp_size_t);

void __gmpn_iorn_n(mp_ptr, mp_srcptr, mp_srcptr, mp_size_t);

void __gmpn_nior_n(mp_ptr, mp_srcptr, mp_srcptr, mp_size_t);

void __gmpn_xor_n(mp_ptr, mp_srcptr, mp_srcptr, mp_size_t);

void __gmpn_xnor_n(mp_ptr, mp_srcptr, mp_srcptr, mp_size_t);

void __gmpn_copyi(mp_ptr, mp_srcptr, mp_size_t);

void __gmpn_copyd(mp_ptr, mp_srcptr, mp_size_t);

void __gmpn_zero(mp_ptr, mp_size_t);

mp_limb_t __gmpn_cnd_add_n(mp_limb_t, mp_ptr, mp_srcptr, mp_srcptr, mp_size_t);

mp_limb_t __gmpn_cnd_sub_n(mp_limb_t, mp_ptr, mp_srcptr, mp_srcptr, mp_size_t);

mp_limb_t __gmpn_sec_add_1(mp_ptr, mp_srcptr, mp_size_t, mp_limb_t, mp_ptr);

mp_size_t __gmpn_sec_add_1_itch(mp_size_t) __attribute__((__pure__));

mp_limb_t __gmpn_sec_sub_1(mp_ptr, mp_srcptr, mp_size_t, mp_limb_t, mp_ptr);

mp_size_t __gmpn_sec_sub_1_itch(mp_size_t) __attribute__((__pure__));

void __gmpn_cnd_swap(mp_limb_t, volatile mp_limb_t *, volatile mp_limb_t *,
                     mp_size_t);

void __gmpn_sec_mul(mp_ptr, mp_srcptr, mp_size_t, mp_srcptr, mp_size_t, mp_ptr);

mp_size_t __gmpn_sec_mul_itch(mp_size_t, mp_size_t) __attribute__((__pure__));

void __gmpn_sec_sqr(mp_ptr, mp_srcptr, mp_size_t, mp_ptr);

mp_size_t __gmpn_sec_sqr_itch(mp_size_t) __attribute__((__pure__));

void __gmpn_sec_powm(mp_ptr, mp_srcptr, mp_size_t, mp_srcptr, mp_bitcnt_t,
                     mp_srcptr, mp_size_t, mp_ptr);

mp_size_t __gmpn_sec_powm_itch(mp_size_t, mp_bitcnt_t, mp_size_t)
    __attribute__((__pure__));

void __gmpn_sec_tabselect(volatile mp_limb_t *, volatile const mp_limb_t *,
                          mp_size_t, mp_size_t, mp_size_t);

mp_limb_t __gmpn_sec_div_qr(mp_ptr, mp_ptr, mp_size_t, mp_srcptr, mp_size_t,
                            mp_ptr);

mp_size_t __gmpn_sec_div_qr_itch(mp_size_t, mp_size_t)
    __attribute__((__pure__));

void __gmpn_sec_div_r(mp_ptr, mp_size_t, mp_srcptr, mp_size_t, mp_ptr);

mp_size_t __gmpn_sec_div_r_itch(mp_size_t, mp_size_t) __attribute__((__pure__));

int __gmpn_sec_invert(mp_ptr, mp_ptr, mp_srcptr, mp_size_t, mp_bitcnt_t,
                      mp_ptr);

mp_size_t __gmpn_sec_invert_itch(mp_size_t) __attribute__((__pure__));
extern __inline__ __attribute__((__gnu_inline__)) void
__gmpz_abs(mpz_ptr __gmp_w, mpz_srcptr __gmp_u) {
  if (__gmp_w != __gmp_u)
    __gmpz_set(__gmp_w, __gmp_u);
  __gmp_w->_mp_size =
      ((__gmp_w->_mp_size) >= 0 ? (__gmp_w->_mp_size) : -(__gmp_w->_mp_size));
}
extern __inline__
    __attribute__((__gnu_inline__))

    int
    __gmpz_fits_uint_p(mpz_srcptr __gmp_z) {
  mp_size_t __gmp_n = __gmp_z->_mp_size;
  mp_ptr __gmp_p = __gmp_z->_mp_d;
  return (__gmp_n == 0 ||
          (__gmp_n == 1 && __gmp_p[0] <= (0x7fffffff * 2U + 1U)));
  ;
}

extern __inline__
    __attribute__((__gnu_inline__))

    int
    __gmpz_fits_ulong_p(mpz_srcptr __gmp_z) {
  mp_size_t __gmp_n = __gmp_z->_mp_size;
  mp_ptr __gmp_p = __gmp_z->_mp_d;
  return (__gmp_n == 0 ||
          (__gmp_n == 1 && __gmp_p[0] <= (0x7fffffffffffffffL * 2UL + 1UL)));
  ;
}

extern __inline__
    __attribute__((__gnu_inline__))

    int
    __gmpz_fits_ushort_p(mpz_srcptr __gmp_z) {
  mp_size_t __gmp_n = __gmp_z->_mp_size;
  mp_ptr __gmp_p = __gmp_z->_mp_d;
  return (__gmp_n == 0 || (__gmp_n == 1 && __gmp_p[0] <= (0x7fff * 2 + 1)));
  ;
}

extern __inline__ __attribute__((__gnu_inline__))

unsigned long
__gmpz_get_ui(mpz_srcptr __gmp_z) {
  mp_ptr __gmp_p = __gmp_z->_mp_d;
  mp_size_t __gmp_n = __gmp_z->_mp_size;
  mp_limb_t __gmp_l = __gmp_p[0];

  return (__gmp_n != 0 ? __gmp_l : 0);
}

extern __inline__ __attribute__((__gnu_inline__))

mp_limb_t
__gmpz_getlimbn(mpz_srcptr __gmp_z, mp_size_t __gmp_n) {
  mp_limb_t __gmp_result = 0;
  if (__builtin_expect(
          (__gmp_n >= 0 &&
           __gmp_n < ((__gmp_z->_mp_size) >= 0 ? (__gmp_z->_mp_size)
                                               : -(__gmp_z->_mp_size))) != 0,
          1))
    __gmp_result = __gmp_z->_mp_d[__gmp_n];
  return __gmp_result;
}

extern __inline__ __attribute__((__gnu_inline__)) void
__gmpz_neg(mpz_ptr __gmp_w, mpz_srcptr __gmp_u) {
  if (__gmp_w != __gmp_u)
    __gmpz_set(__gmp_w, __gmp_u);
  __gmp_w->_mp_size = -__gmp_w->_mp_size;
}

extern __inline__
    __attribute__((__gnu_inline__))

    int
    __gmpz_perfect_square_p(mpz_srcptr __gmp_a) {
  mp_size_t __gmp_asize;
  int __gmp_result;

  __gmp_asize = __gmp_a->_mp_size;
  __gmp_result = (__gmp_asize >= 0);
  if (__builtin_expect((__gmp_asize > 0) != 0, 1))
    __gmp_result = __gmpn_perfect_square_p(__gmp_a->_mp_d, __gmp_asize);
  return __gmp_result;
}

extern __inline__ __attribute__((__gnu_inline__))

mp_bitcnt_t
__gmpz_popcount(mpz_srcptr __gmp_u) {
  mp_size_t __gmp_usize;
  mp_bitcnt_t __gmp_result;

  __gmp_usize = __gmp_u->_mp_size;
  __gmp_result = (__gmp_usize < 0 ? ~((mp_bitcnt_t)(0)) : ((mp_bitcnt_t)(0)));
  if (__builtin_expect((__gmp_usize > 0) != 0, 1))
    __gmp_result = __gmpn_popcount(__gmp_u->_mp_d, __gmp_usize);
  return __gmp_result;
}

extern __inline__
    __attribute__((__gnu_inline__))

    void
    __gmpz_set_q(mpz_ptr __gmp_w, mpq_srcptr __gmp_u) {
  __gmpz_tdiv_q(__gmp_w, (&((__gmp_u)->_mp_num)), (&((__gmp_u)->_mp_den)));
}

extern __inline__ __attribute__((__gnu_inline__))

size_t
__gmpz_size(mpz_srcptr __gmp_z) {
  return ((__gmp_z->_mp_size) >= 0 ? (__gmp_z->_mp_size)
                                   : -(__gmp_z->_mp_size));
}

extern __inline__ __attribute__((__gnu_inline__)) void
__gmpq_abs(mpq_ptr __gmp_w, mpq_srcptr __gmp_u) {
  if (__gmp_w != __gmp_u)
    __gmpq_set(__gmp_w, __gmp_u);
  __gmp_w->_mp_num._mp_size =
      ((__gmp_w->_mp_num._mp_size) >= 0 ? (__gmp_w->_mp_num._mp_size)
                                        : -(__gmp_w->_mp_num._mp_size));
}

extern __inline__ __attribute__((__gnu_inline__)) void
__gmpq_neg(mpq_ptr __gmp_w, mpq_srcptr __gmp_u) {
  if (__gmp_w != __gmp_u)
    __gmpq_set(__gmp_w, __gmp_u);
  __gmp_w->_mp_num._mp_size = -__gmp_w->_mp_num._mp_size;
}
extern __inline__ __attribute__((__gnu_inline__))

mp_limb_t
__gmpn_add(mp_ptr __gmp_wp, mp_srcptr __gmp_xp, mp_size_t __gmp_xsize,
           mp_srcptr __gmp_yp, mp_size_t __gmp_ysize) {
  mp_limb_t __gmp_c;
  do {
    mp_size_t __gmp_i;
    mp_limb_t __gmp_x;
    __gmp_i = (__gmp_ysize);
    if (__gmp_i != 0) {
      if (__gmpn_add_n(__gmp_wp, __gmp_xp, __gmp_yp, __gmp_i)) {
        do {
          if (__gmp_i >= (__gmp_xsize)) {
            (__gmp_c) = 1;
            goto __gmp_done;
          }
          __gmp_x = (__gmp_xp)[__gmp_i];
        } while ((((__gmp_wp)[__gmp_i++] =
                       (__gmp_x + 1) & ((~((mp_limb_t)(0))) >> 0)) == 0));
      }
    }
    if ((__gmp_wp) != (__gmp_xp))
      do {
        mp_size_t __gmp_j;
        ;
        for (__gmp_j = (__gmp_i); __gmp_j < (__gmp_xsize); __gmp_j++)
          (__gmp_wp)[__gmp_j] = (__gmp_xp)[__gmp_j];
      } while (0);
    (__gmp_c) = 0;
  __gmp_done:;
  } while (0);
  return __gmp_c;
}

extern __inline__ __attribute__((__gnu_inline__))

mp_limb_t
__gmpn_add_1(mp_ptr __gmp_dst, mp_srcptr __gmp_src, mp_size_t __gmp_size,
             mp_limb_t __gmp_n) {
  mp_limb_t __gmp_c;
  do {
    mp_size_t __gmp_i;
    mp_limb_t __gmp_x, __gmp_r;
    __gmp_x = (__gmp_src)[0];
    __gmp_r = __gmp_x + (__gmp_n);
    (__gmp_dst)[0] = __gmp_r;
    if (((__gmp_r) < ((__gmp_n)))) {
      (__gmp_c) = 1;
      for (__gmp_i = 1; __gmp_i < (__gmp_size);) {
        __gmp_x = (__gmp_src)[__gmp_i];
        __gmp_r = __gmp_x + 1;
        (__gmp_dst)[__gmp_i] = __gmp_r;
        ++__gmp_i;
        if (!((__gmp_r) < (1))) {
          if ((__gmp_src) != (__gmp_dst))
            do {
              mp_size_t __gmp_j;
              ;
              for (__gmp_j = (__gmp_i); __gmp_j < (__gmp_size); __gmp_j++)
                (__gmp_dst)[__gmp_j] = (__gmp_src)[__gmp_j];
            } while (0);
          (__gmp_c) = 0;
          break;
        }
      }
    } else {
      if ((__gmp_src) != (__gmp_dst))
        do {
          mp_size_t __gmp_j;
          ;
          for (__gmp_j = (1); __gmp_j < (__gmp_size); __gmp_j++)
            (__gmp_dst)[__gmp_j] = (__gmp_src)[__gmp_j];
        } while (0);
      (__gmp_c) = 0;
    }
  } while (0);
  return __gmp_c;
}

extern __inline__
    __attribute__((__gnu_inline__))

    int
    __gmpn_cmp(mp_srcptr __gmp_xp, mp_srcptr __gmp_yp, mp_size_t __gmp_size) {
  int __gmp_result;
  do {
    mp_size_t __gmp_i;
    mp_limb_t __gmp_x, __gmp_y;
    (__gmp_result) = 0;
    __gmp_i = (__gmp_size);
    while (--__gmp_i >= 0) {
      __gmp_x = (__gmp_xp)[__gmp_i];
      __gmp_y = (__gmp_yp)[__gmp_i];
      if (__gmp_x != __gmp_y) {
        (__gmp_result) = (__gmp_x > __gmp_y ? 1 : -1);
        break;
      }
    }
  } while (0);
  return __gmp_result;
}

extern __inline__
    __attribute__((__gnu_inline__))

    int
    __gmpn_zero_p(mp_srcptr __gmp_p, mp_size_t __gmp_n) {

  do {
    if (__gmp_p[--__gmp_n] != 0)
      return 0;
  } while (__gmp_n != 0);
  return 1;
}

extern __inline__ __attribute__((__gnu_inline__))

mp_limb_t
__gmpn_sub(mp_ptr __gmp_wp, mp_srcptr __gmp_xp, mp_size_t __gmp_xsize,
           mp_srcptr __gmp_yp, mp_size_t __gmp_ysize) {
  mp_limb_t __gmp_c;
  do {
    mp_size_t __gmp_i;
    mp_limb_t __gmp_x;
    __gmp_i = (__gmp_ysize);
    if (__gmp_i != 0) {
      if (__gmpn_sub_n(__gmp_wp, __gmp_xp, __gmp_yp, __gmp_i)) {
        do {
          if (__gmp_i >= (__gmp_xsize)) {
            (__gmp_c) = 1;
            goto __gmp_done;
          }
          __gmp_x = (__gmp_xp)[__gmp_i];
        } while ((((__gmp_wp)[__gmp_i++] =
                       (__gmp_x - 1) & ((~((mp_limb_t)(0))) >> 0)),
                  __gmp_x == 0));
      }
    }
    if ((__gmp_wp) != (__gmp_xp))
      do {
        mp_size_t __gmp_j;
        ;
        for (__gmp_j = (__gmp_i); __gmp_j < (__gmp_xsize); __gmp_j++)
          (__gmp_wp)[__gmp_j] = (__gmp_xp)[__gmp_j];
      } while (0);
    (__gmp_c) = 0;
  __gmp_done:;
  } while (0);
  return __gmp_c;
}

extern __inline__ __attribute__((__gnu_inline__))

mp_limb_t
__gmpn_sub_1(mp_ptr __gmp_dst, mp_srcptr __gmp_src, mp_size_t __gmp_size,
             mp_limb_t __gmp_n) {
  mp_limb_t __gmp_c;
  do {
    mp_size_t __gmp_i;
    mp_limb_t __gmp_x, __gmp_r;
    __gmp_x = (__gmp_src)[0];
    __gmp_r = __gmp_x - (__gmp_n);
    (__gmp_dst)[0] = __gmp_r;
    if (((__gmp_x) < ((__gmp_n)))) {
      (__gmp_c) = 1;
      for (__gmp_i = 1; __gmp_i < (__gmp_size);) {
        __gmp_x = (__gmp_src)[__gmp_i];
        __gmp_r = __gmp_x - 1;
        (__gmp_dst)[__gmp_i] = __gmp_r;
        ++__gmp_i;
        if (!((__gmp_x) < (1))) {
          if ((__gmp_src) != (__gmp_dst))
            do {
              mp_size_t __gmp_j;
              ;
              for (__gmp_j = (__gmp_i); __gmp_j < (__gmp_size); __gmp_j++)
                (__gmp_dst)[__gmp_j] = (__gmp_src)[__gmp_j];
            } while (0);
          (__gmp_c) = 0;
          break;
        }
      }
    } else {
      if ((__gmp_src) != (__gmp_dst))
        do {
          mp_size_t __gmp_j;
          ;
          for (__gmp_j = (1); __gmp_j < (__gmp_size); __gmp_j++)
            (__gmp_dst)[__gmp_j] = (__gmp_src)[__gmp_j];
        } while (0);
      (__gmp_c) = 0;
    }
  } while (0);
  return __gmp_c;
}

extern __inline__ __attribute__((__gnu_inline__))

mp_limb_t
__gmpn_neg(mp_ptr __gmp_rp, mp_srcptr __gmp_up, mp_size_t __gmp_n) {
  while (*__gmp_up == 0) {
    *__gmp_rp = 0;
    if (!--__gmp_n)
      return 0;
    ++__gmp_up;
    ++__gmp_rp;
  }

  *__gmp_rp = (-*__gmp_up) & ((~((mp_limb_t)(0))) >> 0);

  if (--__gmp_n)
    __gmpn_com(++__gmp_rp, ++__gmp_up, __gmp_n);

  return 1;
}
enum {
  GMP_ERROR_NONE = 0,
  GMP_ERROR_UNSUPPORTED_ARGUMENT = 1,
  GMP_ERROR_DIVISION_BY_ZERO = 2,
  GMP_ERROR_SQRT_OF_NEGATIVE = 4,
  GMP_ERROR_INVALID_ARGUMENT = 8
};

extern void __assert_fail(const char *__assertion, const char *__file,
                          unsigned int __line, const char *__function)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

extern void __assert_perror_fail(int __errnum, const char *__file,
                                 unsigned int __line, const char *__function)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

extern void __assert(const char *__assertion, const char *__file, int __line)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

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
struct __locale_struct {

  struct __locale_data *__locales[13];

  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;

  const char *__names[13];
};

typedef struct __locale_struct *__locale_t;

typedef __locale_t locale_t;

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

extern size_t full_write(int fd, const void *buf, size_t count);

extern struct quoting_options quote_quoting_options;

char const *quote_n_mem(int n, char const *arg, size_t argsize);

char const *quote_mem(char const *arg, size_t argsize);

char const *quote_n(int n, char const *arg);

char const *quote(char const *arg);

struct tokenbuffer {
  size_t size;
  char *buffer;
};
typedef struct tokenbuffer token_buffer;

void init_tokenbuffer(token_buffer *tokenbuffer);

size_t readtoken(FILE *stream, const char *delim, size_t n_delim,
                 token_buffer *tokenbuffer);
size_t readtokens(FILE *stream, size_t projected_n_tokens, const char *delim,
                  size_t n_delim, char ***tokens_out, size_t **token_lengths);
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
typedef unsigned char UQItype;
typedef long SItype;
typedef unsigned long int USItype;

typedef long long int DItype;
typedef unsigned long long int UDItype;

extern uintmax_t __gmpn_umul_ppmm(uintmax_t *, uintmax_t, uintmax_t);
extern uintmax_t __gmpn_umul_ppmm_r(uintmax_t, uintmax_t, uintmax_t *);
extern uintmax_t __gmpn_udiv_qrnnd(uintmax_t *, uintmax_t, uintmax_t,
                                   uintmax_t);
extern uintmax_t __gmpn_udiv_qrnnd_r(uintmax_t, uintmax_t, uintmax_t,
                                     uintmax_t *);
enum { DEV_DEBUG_OPTION = 0x7f + 1 };

static struct option const long_options[] = {
    {"-debug", 0, ((void *)0), DEV_DEBUG_OPTION},
    {"help", 0, ((void *)0), GETOPT_HELP_CHAR},
    {"version", 0, ((void *)0), GETOPT_VERSION_CHAR},
    {((void *)0), 0, ((void *)0), 0}};

struct factors {
  uintmax_t plarge[2];
  uintmax_t p[26];
  unsigned char e[26];
  unsigned char nfactors;
};

struct mp_factors {
  mpz_t *p;
  unsigned long int *e;
  unsigned long int nfactors;
};

static void factor(uintmax_t, uintmax_t, struct factors *);
static uintmax_t mod2(uintmax_t *r1, uintmax_t a1, uintmax_t a0, uintmax_t d1,
                      uintmax_t d0) {
  int cntd, cnta;

  ((void)sizeof((d1 != 0) ? 1 : 0), __extension__({
     if (d1 != 0)
       ;
     else
       __assert_fail("d1 != 0", "src/factor.c", 411,
                     __extension__ __PRETTY_FUNCTION__);
   }));

  if (a1 == 0) {
    *r1 = 0;
    return a0;
  }

  do {
    UDItype __cbtmp;
    ;
    __asm__("bsr\t%1,%0" : "=r"(__cbtmp) : "rm"((UDItype)(d1)));
    (cntd) = __cbtmp ^ 63;
  } while (0);
  do {
    UDItype __cbtmp;
    ;
    __asm__("bsr\t%1,%0" : "=r"(__cbtmp) : "rm"((UDItype)(a1)));
    (cnta) = __cbtmp ^ 63;
  } while (0);
  int cnt = cntd - cnta;
  do {
    (d1) = ((d1) << cnt) | ((d0) >> (64 - (cnt)));
    (d0) = (d0) << (cnt);
  } while (0);
  for (int i = 0; i < cnt; i++) {
    if (((a1) > (d1) || ((a1) == (d1) && (a0) >= (d0))))
      __asm__("subq %5,%q1\n\tsbbq %3,%q0"
              : "=r"(a1), "=&r"(a0)
              : "0"((UDItype)(a1)), "rme"((UDItype)(d1)), "1"((UDItype)(a0)),
                "rme"((UDItype)(d0)));
    do {
      (d0) = ((d1) << (64 - (1))) | ((d0) >> (1));
      (d1) = (d1) >> (1);
    } while (0);
  }

  *r1 = a1;
  return a0;
}

__attribute__((__const__)) static uintmax_t gcd_odd(uintmax_t a, uintmax_t b) {
  if ((b & 1) == 0) {
    uintmax_t t = b;
    b = a;
    a = t;
  }
  if (a == 0)
    return b;

  b >>= 1;

  for (;;) {
    uintmax_t t;
    uintmax_t bgta;

    while ((a & 1) == 0)
      a >>= 1;
    a >>= 1;

    t = a - b;
    if (t == 0)
      return (a << 1) + 1;

    bgta = (((intmax_t)-1 >> 1) < 0
                ? (uintmax_t)((intmax_t)(t) >> (64 - 1))
                : ((t) & ((uintmax_t)1 << (64 - 1)) ? (18446744073709551615UL)
                                                    : (uintmax_t)0));

    b += (bgta & t);

    a = (t ^ bgta) - bgta;
  }
}

static uintmax_t gcd2_odd(uintmax_t *r1, uintmax_t a1, uintmax_t a0,
                          uintmax_t b1, uintmax_t b0) {

  ((void)sizeof((b0 & 1) ? 1 : 0), __extension__({
     if (b0 & 1)
       ;
     else
       __assert_fail("b0 & 1", "src/factor.c", 476,
                     __extension__ __PRETTY_FUNCTION__);
   }));

  if ((a0 | a1) == 0) {
    *r1 = b1;
    return b0;
  }

  while ((a0 & 1) == 0)
    do {
      (a0) = ((a1) << (64 - (1))) | ((a0) >> (1));
      (a1) = (a1) >> (1);
    } while (0);

  for (;;) {
    if ((b1 | a1) == 0) {
      *r1 = 0;
      return gcd_odd(b0, a0);
    }

    if (((a1) > (b1) || ((a1) == (b1) && (a0) > (b0)))) {
      __asm__("subq %5,%q1\n\tsbbq %3,%q0"
              : "=r"(a1), "=&r"(a0)
              : "0"((UDItype)(a1)), "rme"((UDItype)(b1)), "1"((UDItype)(a0)),
                "rme"((UDItype)(b0)));
      do
        do {
          (a0) = ((a1) << (64 - (1))) | ((a0) >> (1));
          (a1) = (a1) >> (1);
        } while (0);
      while ((a0 & 1) == 0);
    } else if (((b1) > (a1) || ((b1) == (a1) && (b0) > (a0)))) {
      __asm__("subq %5,%q1\n\tsbbq %3,%q0"
              : "=r"(b1), "=&r"(b0)
              : "0"((UDItype)(b1)), "rme"((UDItype)(a1)), "1"((UDItype)(b0)),
                "rme"((UDItype)(a0)));
      do
        do {
          (b0) = ((b1) << (64 - (1))) | ((b0) >> (1));
          (b1) = (b1) >> (1);
        } while (0);
      while ((b0 & 1) == 0);
    } else
      break;
  }

  *r1 = a1;
  return a0;
}

static void factor_insert_multiplicity(struct factors *factors, uintmax_t prime,
                                       unsigned int m) {
  unsigned int nfactors = factors->nfactors;
  uintmax_t *p = factors->p;
  unsigned char *e = factors->e;

  int i;
  for (i = nfactors - 1; i >= 0; i--) {
    if (p[i] <= prime)
      break;
  }

  if (i < 0 || p[i] != prime) {
    for (int j = nfactors - 1; j > i; j--) {
      p[j + 1] = p[j];
      e[j + 1] = e[j];
    }
    p[i + 1] = prime;
    e[i + 1] = m;
    factors->nfactors = nfactors + 1;
  } else {
    e[i] += m;
  }
}

static void factor_insert_large(struct factors *factors, uintmax_t p1,
                                uintmax_t p0) {
  if (p1 > 0) {

    ((void)sizeof((factors->plarge[1] == 0) ? 1 : 0), __extension__({
       if (factors->plarge[1] == 0)
         ;
       else
         __assert_fail("factors->plarge[1] == 0", "src/factor.c", 558,
                       __extension__ __PRETTY_FUNCTION__);
     }));
    factors->plarge[0] = p0;
    factors->plarge[1] = p1;
  } else
    factor_insert_multiplicity(factors, p0, 1);
}
static void mp_factor(mpz_t, struct mp_factors *);

static void mp_factor_init(struct mp_factors *factors) {
  factors->p = ((void *)0);
  factors->e = ((void *)0);
  factors->nfactors = 0;
}

static void mp_factor_clear(struct mp_factors *factors) {
  for (unsigned int i = 0; i < factors->nfactors; i++)

    __gmpz_clear(factors->p[i]);

  free(factors->p);
  free(factors->e);
}

static void mp_factor_insert(struct mp_factors *factors, mpz_t prime) {
  unsigned long int nfactors = factors->nfactors;
  mpz_t *p = factors->p;
  unsigned long int *e = factors->e;
  long i;

  for (i = nfactors - 1; i >= 0; i--) {
    if (__gmpz_cmp(p[i], prime) <= 0)
      break;
  }

  if (i < 0 || __gmpz_cmp(p[i], prime) != 0) {
    p = xrealloc(p, (nfactors + 1) * sizeof p[0]);
    e = xrealloc(e, (nfactors + 1) * sizeof e[0]);

    __gmpz_init(p[nfactors]);
    for (long j = nfactors - 1; j > i; j--) {

      __gmpz_set(p[j + 1], p[j]);
      e[j + 1] = e[j];
    }

    __gmpz_set(p[i + 1], prime);
    e[i + 1] = 1;

    factors->p = p;
    factors->e = e;
    factors->nfactors = nfactors + 1;
  } else {
    e[i] += 1;
  }
}

static void mp_factor_insert_ui(struct mp_factors *factors,
                                unsigned long int prime) {
  mpz_t pz;

  __gmpz_init_set_ui(pz, prime);
  mp_factor_insert(factors, pz);

  __gmpz_clear(pz);
}

enum { W = sizeof(uintmax_t) * 8 };

_Static_assert((18446744073709551615UL) >> (W - 1) == 1,
               "verify ("
               "UINTMAX_MAX >> (W - 1) == 1"
               ")");

static const unsigned char primes_diff[] = {

    1,

    2,

    2,

    4,

    2,

    4,

    2,

    4,

    6,

    2,

    6,

    4,

    2,

    4,

    6,

    6,

    2,

    6,

    4,

    2,

    6,

    4,

    6,

    8,

    4,

    2,

    4,

    2,

    4,

    14,

    4,

    6,

    2,

    10,

    2,

    6,

    6,

    4,

    6,

    6,

    2,

    10,

    2,

    4,

    2,

    12,

    12,

    4,

    2,

    4,

    6,

    2,

    10,

    6,

    6,

    6,

    2,

    6,

    4,

    2,

    10,

    14,

    4,

    2,

    4,

    14,

    6,

    10,

    2,

    4,

    6,

    8,

    6,

    6,

    4,

    6,

    8,

    4,

    8,

    10,

    2,

    10,

    2,

    6,

    4,

    6,

    8,

    4,

    2,

    4,

    12,

    8,

    4,

    8,

    4,

    6,

    12,

    2,

    18,

    6,

    10,

    6,

    6,

    2,

    6,

    10,

    6,

    6,

    2,

    6,

    6,

    4,

    2,

    12,

    10,

    2,

    4,

    6,

    6,

    2,

    12,

    4,

    6,

    8,

    10,

    8,

    10,

    8,

    6,

    6,

    4,

    8,

    6,

    4,

    8,

    4,

    14,

    10,

    12,

    2,

    10,

    2,

    4,

    2,

    10,

    14,

    4,

    2,

    4,

    14,

    4,

    2,

    4,

    20,

    4,

    8,

    10,

    8,

    4,

    6,

    6,

    14,

    4,

    6,

    6,

    8,

    6,

    12,

    4,

    6,

    2,

    10,

    2,

    6,

    10,

    2,

    10,

    2,

    6,

    18,

    4,

    2,

    4,

    6,

    6,

    8,

    6,

    6,

    22,

    2,

    10,

    8,

    10,

    6,

    6,

    8,

    12,

    4,

    6,

    6,

    2,

    6,

    12,

    10,

    18,

    2,

    4,

    6,

    2,

    6,

    4,

    2,

    4,

    12,

    2,

    6,

    34,

    6,

    6,

    8,

    18,

    10,

    14,

    4,

    2,

    4,

    6,

    8,

    4,

    2,

    6,

    12,

    10,

    2,

    4,

    2,

    4,

    6,

    12,

    12,

    8,

    12,

    6,

    4,

    6,

    8,

    4,

    8,

    4,

    14,

    4,

    6,

    2,

    4,

    6,

    2,

    6,

    10,

    20,

    6,

    4,

    2,

    24,

    4,

    2,

    10,

    12,

    2,

    10,

    8,

    6,

    6,

    6,

    18,

    6,

    4,

    2,

    12,

    10,

    12,

    8,

    16,

    14,

    6,

    4,

    2,

    4,

    2,

    10,

    12,

    6,

    6,

    18,

    2,

    16,

    2,

    22,

    6,

    8,

    6,

    4,

    2,

    4,

    8,

    6,

    10,

    2,

    10,

    14,

    10,

    6,

    12,

    2,

    4,

    2,

    10,

    12,

    2,

    16,

    2,

    6,

    4,

    2,

    10,

    8,

    18,

    24,

    4,

    6,

    8,

    16,

    2,

    4,

    8,

    16,

    2,

    4,

    8,

    6,

    6,

    4,

    12,

    2,

    22,

    6,

    2,

    6,

    4,

    6,

    14,

    6,

    4,

    2,

    6,

    4,

    6,

    12,

    6,

    6,

    14,

    4,

    6,

    12,

    8,

    6,

    4,

    26,

    18,

    10,

    8,

    4,

    6,

    2,

    6,

    22,

    12,

    2,

    16,

    8,

    4,

    12,

    14,

    10,

    2,

    4,

    8,

    6,

    6,

    4,

    2,

    4,

    6,

    8,

    4,

    2,

    6,

    10,

    2,

    10,

    8,

    4,

    14,

    10,

    12,

    2,

    6,

    4,

    2,

    16,

    14,

    4,

    6,

    8,

    6,

    4,

    18,

    8,

    10,

    6,

    6,

    8,

    10,

    12,

    14,

    4,

    6,

    6,

    2,

    28,

    2,

    10,

    8,

    4,

    14,

    4,

    8,

    12,

    6,

    12,

    4,

    6,

    20,

    10,

    2,

    16,

    26,

    4,

    2,

    12,

    6,

    4,

    12,

    6,

    8,

    4,

    8,

    22,

    2,

    4,

    2,

    12,

    28,

    2,

    6,

    6,

    6,

    4,

    6,

    2,

    12,

    4,

    12,

    2,

    10,

    2,

    16,

    2,

    16,

    6,

    20,

    16,

    8,

    4,

    2,

    4,

    2,

    22,

    8,

    12,

    6,

    10,

    2,

    4,

    6,

    2,

    6,

    10,

    2,

    12,

    10,

    2,

    10,

    14,

    6,

    4,

    6,

    8,

    6,

    6,

    16,

    12,

    2,

    4,

    14,

    6,

    4,

    8,

    10,

    8,

    6,

    6,

    22,

    6,

    2,

    10,

    14,

    4,

    6,

    18,

    2,

    10,

    14,

    4,

    2,

    10,

    14,

    4,

    8,

    18,

    4,

    6,

    2,

    4,

    6,

    2,

    12,

    4,

    20,

    22,

    12,

    2,

    4,

    6,

    6,

    2,

    6,

    22,

    2,

    6,

    16,

    6,

    12,

    2,

    6,

    12,

    16,

    2,

    4,

    6,

    14,

    4,

    2,

    18,

    24,

    10,

    6,

    2,

    10,

    2,

    10,

    2,

    10,

    6,

    2,

    10,

    2,

    10,

    6,

    8,

    30,

    10,

    2,

    10,

    8,

    6,

    10,

    18,

    6,

    12,

    12,

    2,

    18,

    6,

    4,

    6,

    6,

    18,

    2,

    10,

    14,

    6,

    4,

    2,

    4,

    24,

    2,

    12,

    6,

    16,

    8,

    6,

    6,

    18,

    16,

    2,

    4,

    6,

    2,

    6,

    6,

    10,

    6,

    12,

    12,

    18,

    2,

    6,

    4,

    18,

    8,

    24,

    4,

    2,

    4,

    6,

    2,

    12,

    4,

    14,

    30,

    10,

    6,

    12,

    14,

    6,

    10,

    12,

    2,

    4,

    6,

    8,

    6,

    10,

    2,

    4,

    14,

    6,

    6,  0, 0, 0, 0, 0, 0, 0};

static const unsigned char primes_diff8[] = {

    26,

    26,

    30,

    30,

    30,

    30,

    34,

    36,

    32,

    36,

    34,

    32,

    36,

    36,

    36,

    38,

    40,

    36,

    36,

    36,

    34,

    44,

    42,

    40,

    38,

    46,

    44,

    48,

    50,

    40,

    42,

    42,

    42,

    42,

    42,

    40,

    36,

    44,

    50,

    48,

    48,

    42,

    46,

    44,

    52,

    46,

    40,

    42,

    42,

    44,

    42,

    42,

    42,

    50,

    48,

    44,

    46,

    54,

    56,

    64,

    56,

    46,

    48,

    54,

    56,

    48,

    46,

    42,

    48,

    48,

    50,

    52,

    48,

    52,

    50,

    50,

    46,

    48,

    48,

    42,

    42,

    36,

    46,

    48,

    48,

    50,

    46,

    48,

    58,

    56,

    62,

    60,

    66,

    64,

    66,

    62,

    56,

    64,

    52,

    52,

    44,

    44,

    44,

    46,

    42,

    44,

    48,

    44,

    46,

    46,

    46,

    44,

    54,

    46,

    42,

    48,

    54,

    56,

    60,

    66,

    60,

    62,

    60,

    60,

    56,

    52,

    50,

    46,

    54,

    58,

    66,

    60,

    64,

    62,

    58,

    56,

    52,

    56,

    48,

    48,

    42,

    54,

    54,

    54,

    48,

    54,

    54,

    60,

    66,

    60,

    60,

    64,

    66,

    60,

    60,

    58,

    54,

    54,

    56,

    62,

    60,

    52,

    50,

    54,

    50,

    48,

    52,

    42,

    48,

    44,

    48,

    56,

    58,

    54,

    48,

    52,

    48,

    54,

    54,

    42,

    60,

    60,

    66,

    68,

    72,

    70,

    70,

    72,

    62,

    64,

    60,

    58,

    50,

    50,

    56,

    58,

    64,

    62,

    60,

    60,

    60,

    60,

    52,

    44,

    30,

    40,

    38,

    38,

    70,

    70,

    72,

    78,

    92,

    90,

    102,

    100,

    68,

    66,

    66,

    66,

    52,

    44,

    36,

    44,

    52,

    50,

    48,

    42,

    42,

    46,

    52,

    52,

    50,

    60,

    62,

    64,

    66,

    68,

    60,

    56,

    52,

    54,

    52,

    54,

    50,

    46,

    48,

    42,

    44,

    40,

    56,

    56,

    58,

    56,

    74,

    76,

    72,

    72,

    64,

    60,

    66,

    72,

    54,

    56,

    60,

    68,

    62,

    64,

    56,

    60,

    64,

    70,

    72,

    70,

    78,

    80,

    82,

    72,

    66,

    56,

    58,

    54,

    46,

    46,

    60,

    60,

    72,

    72,

    84,

    78,

    80,

    80,

    66,

    66,

    54,

    60,

    44,

    48,

    42,

    46,

    56,

    64,

    66,

    70,

    66,

    60,

    60,

    60,

    58,

    50,

    60,

    50,

    54,

    54,

    54,

    54,

    50,

    66,

    74,

    76,

    76,

    80,

    94,

    86,

    82,

    72,

    64,

    62,

    60,

    60,

    50,

    54,

    54,

    58,

    44,

    64,

    66,

    60,

    60,

    58,

    60,

    62,

    66,

    48,

    44,

    48,

    46,

    48,

    54,

    46,

    46,

    56,

    58,

    58,

    66,

    68,

    62,

    60,

    80,

    84,

    90,

    92,

    84,

    82,

    78,

    80,

    76,

    70,

    62,

    70,

    74,

    72,

    82,

    90,

    78,

    68,

    70,

    62,

    60,

    62,

    54,

    42,

    36,

    40,

    44,

    40,

    36,

    36,

    42,

    42,

    48,

    50,

    46,

    56,

    64,

    70,

    62,

    66,

    60,

    54,

    66,

    66,

    60,

    54,

    60,

    60,

    60,

    76,

    68,

    64,

    66,

    66,

    66,

    70,

    78,

    74,

    70,

    66,

    66,

    62,

    82,

    74,

    72,

    66,

    66,

    74,

    72,

    78,

    62,

    66,

    68,

    64,

    66,

    72,

    78,

    72,

    76,

    96,

    88,

    86,

    92,

    78,

    72,

    82,

    72,

    54,

    54,

    60,

    70,

    66,

    66,

    56,

    62,

    82,

    80,

    78,

    62,

    66,

    66,

    70,

    60,

    44,

    46,

    52,

    48,

    52,

    50,

    60,

    60,

    64,

    66,

    74,

    88,

    86,

    88,

    74,

    76,

    62,

    78,

    66,

    62,

    60,

    66,

    66,

    66,

    70,

    50,

    48,

    46,

    42,

    44,

    52,

    50,

    54,

    66,

    66,

    60,

    64,

    60,

    56,

    60,

    66,

    64,

    60,

    60,

    68,

    66,

    64,

    66,

    60,

    56,

    60,

    62,

    70,

    70,

    68,

    70,

    74,

    70,

    70,

    82,

    62,

    66,

    78,

    72,

    60,

    66,

    74,

    60,

    66,

    74,

    64,

    66,

    66,

    60,

    52,

    50,

    54,

    40,

    56,

    72,

    82,

    80,

    78,

    82,

    76,

    74,

    60,

    60,

    50,

    54,

    66,

    66,

    72,

    72,

    72,

    62,

    76,

    72,

    60,

    60,

    62,

    64,

    60,

    66,

    74,

    82,

    84,

    80,

    76,

    74,

    82,

    66,

    52,

    48,

    44,

    52,

    44,

    52,

    48,

    54,

    74,

    78,

    78,

    78,

    84,

    80,

    84,

    94,

    70,

    72,

    82,

    74,

    84,

    84,

    78,

    66,

    66,

    72,

    62,

    70,

    66,

    66,

    66,

    62,

    60,

    66,

    66,

    68,

    60,

    70,

    74,

    78,

    80,

    74,

    88,

    78,

    76,

    66,

    60,

    60,

    60,

    52,

    42,

    52,

    60,

    72,

    72,

    72,

    70,

    78,

    80,

    92,

    84,

    68,

    70,

    70,

    68,

    62,

    58,

    48,

    74,

    82,

    84,

    90,

    102,

    96,

    102,

    100,

    72,

    66,

    66,

    62,

    54,

    58,

    50,

    42,

    54,

    56,

    56,

    255,

    255,

    255,

    255,

    255,

    255,

    255,

    255, 0, 0, 0, 0, 0, 0, 0};

struct primes_dtab {
  uintmax_t binv, lim;
};

static const struct primes_dtab primes_dtab[] = {

    {(((((uintmax_t)0xaaaaU << 28 | 0xaaaaaaaU) << 28 | 0xaaaaaaaU) << 28 |
       0xaaaaaaaU)
          << 28 |
      0xaaaaaabU),
     (18446744073709551615UL) / 3},

    {(((((uintmax_t)0xccccU << 28 | 0xcccccccU) << 28 | 0xcccccccU) << 28 |
       0xcccccccU)
          << 28 |
      0xccccccdU),
     (18446744073709551615UL) / 5},

    {(((((uintmax_t)0xb6dbU << 28 | 0x6db6db6U) << 28 | 0xdb6db6dU) << 28 |
       0xb6db6dbU)
          << 28 |
      0x6db6db7U),
     (18446744073709551615UL) / 7},

    {(((((uintmax_t)0xa2e8U << 28 | 0xba2e8baU) << 28 | 0x2e8ba2eU) << 28 |
       0x8ba2e8bU)
          << 28 |
      0xa2e8ba3U),
     (18446744073709551615UL) / 11},

    {(((((uintmax_t)0xc4ecU << 28 | 0x4ec4ec4U) << 28 | 0xec4ec4eU) << 28 |
       0xc4ec4ecU)
          << 28 |
      0x4ec4ec5U),
     (18446744073709551615UL) / 13},

    {(((((uintmax_t)0xf0f0U << 28 | 0xf0f0f0fU) << 28 | 0x0f0f0f0U) << 28 |
       0xf0f0f0fU)
          << 28 |
      0x0f0f0f1U),
     (18446744073709551615UL) / 17},

    {(((((uintmax_t)0xbca1U << 28 | 0xaf286bcU) << 28 | 0xa1af286U) << 28 |
       0xbca1af2U)
          << 28 |
      0x86bca1bU),
     (18446744073709551615UL) / 19},

    {(((((uintmax_t)0x4de9U << 28 | 0xbd37a6fU) << 28 | 0x4de9bd3U) << 28 |
       0x7a6f4deU)
          << 28 |
      0x9bd37a7U),
     (18446744073709551615UL) / 23},

    {(((((uintmax_t)0xc234U << 28 | 0xf72c234U) << 28 | 0xf72c234U) << 28 |
       0xf72c234U)
          << 28 |
      0xf72c235U),
     (18446744073709551615UL) / 29},

    {(((((uintmax_t)0xdef7U << 28 | 0xbdef7bdU) << 28 | 0xef7bdefU) << 28 |
       0x7bdef7bU)
          << 28 |
      0xdef7bdfU),
     (18446744073709551615UL) / 31},

    {(((((uintmax_t)0xc1baU << 28 | 0xcf914c1U) << 28 | 0xbacf914U) << 28 |
       0xc1bacf9U)
          << 28 |
      0x14c1badU),
     (18446744073709551615UL) / 37},

    {(((((uintmax_t)0x18f9U << 28 | 0xc18f9c1U) << 28 | 0x8f9c18fU) << 28 |
       0x9c18f9cU)
          << 28 |
      0x18f9c19U),
     (18446744073709551615UL) / 41},

    {(((((uintmax_t)0xbe82U << 28 | 0xfa0be82U) << 28 | 0xfa0be82U) << 28 |
       0xfa0be82U)
          << 28 |
      0xfa0be83U),
     (18446744073709551615UL) / 43},

    {(((((uintmax_t)0x3677U << 28 | 0xd46cefaU) << 28 | 0x8d9df51U) << 28 |
       0xb3bea36U)
          << 28 |
      0x77d46cfU),
     (18446744073709551615UL) / 47},

    {(((((uintmax_t)0x1352U << 28 | 0x1cfb2b7U) << 28 | 0x8c13521U) << 28 |
       0xcfb2b78U)
          << 28 |
      0xc13521dU),
     (18446744073709551615UL) / 53},

    {(((((uintmax_t)0x8f2fU << 28 | 0xba93868U) << 28 | 0x22b63cbU) << 28 |
       0xeea4e1aU)
          << 28 |
      0x08ad8f3U),
     (18446744073709551615UL) / 59},

    {(((((uintmax_t)0x14fbU << 28 | 0xcda3ac1U) << 28 | 0x0c9714fU) << 28 |
       0xbcda3acU)
          << 28 |
      0x10c9715U),
     (18446744073709551615UL) / 61},

    {(((((uintmax_t)0xc2ddU << 28 | 0x9ca81e9U) << 28 | 0x131abf0U) << 28 |
       0xb7672a0U)
          << 28 |
      0x7a44c6bU),
     (18446744073709551615UL) / 67},

    {(((((uintmax_t)0x4f52U << 28 | 0xedf8c9eU) << 28 | 0xa5dbf19U) << 28 |
       0x3d4bb7eU)
          << 28 |
      0x327a977U),
     (18446744073709551615UL) / 71},

    {(((((uintmax_t)0x3f1fU << 28 | 0x8fc7e3fU) << 28 | 0x1f8fc7eU) << 28 |
       0x3f1f8fcU)
          << 28 |
      0x7e3f1f9U),
     (18446744073709551615UL) / 73},

    {(((((uintmax_t)0xd5dfU << 28 | 0x984dc5aU) << 28 | 0xbbf309bU) << 28 |
       0x8b577e6U)
          << 28 |
      0x13716afU),
     (18446744073709551615UL) / 79},

    {(((((uintmax_t)0x2818U << 28 | 0xacb90f6U) << 28 | 0xbf3a9a3U) << 28 |
       0x784a062U)
          << 28 |
      0xb2e43dbU),
     (18446744073709551615UL) / 83},

    {(((((uintmax_t)0xd1faU << 28 | 0x3f47e8fU) << 28 | 0xd1fa3f4U) << 28 |
       0x7e8fd1fU)
          << 28 |
      0xa3f47e9U),
     (18446744073709551615UL) / 89},

    {(((((uintmax_t)0x5f02U << 28 | 0xa3a0fd5U) << 28 | 0xc5f02a3U) << 28 |
       0xa0fd5c5U)
          << 28 |
      0xf02a3a1U),
     (18446744073709551615UL) / 97},

    {(((((uintmax_t)0xc32bU << 28 | 0x16cfd77U) << 28 | 0x20f353aU) << 28 |
       0x4c0a237U)
          << 28 |
      0xc32b16dU),
     (18446744073709551615UL) / 101},

    {(((((uintmax_t)0xd0c6U << 28 | 0xd5bf60eU) << 28 | 0xe9a18daU) << 28 |
       0xb7ec1ddU)
          << 28 |
      0x3431b57U),
     (18446744073709551615UL) / 103},

    {(((((uintmax_t)0xa2b1U << 28 | 0x0bf66e0U) << 28 | 0xe5aea77U) << 28 |
       0xa04c8f8U)
          << 28 |
      0xd28ac43U),
     (18446744073709551615UL) / 107},

    {(((((uintmax_t)0xc096U << 28 | 0x4fda6c0U) << 28 | 0x964fda6U) << 28 |
       0xc0964fdU)
          << 28 |
      0xa6c0965U),
     (18446744073709551615UL) / 109},

    {(((((uintmax_t)0xc090U << 28 | 0xfdbc090U) << 28 | 0xfdbc090U) << 28 |
       0xfdbc090U)
          << 28 |
      0xfdbc091U),
     (18446744073709551615UL) / 113},

    {(((((uintmax_t)0xbf7eU << 28 | 0xfdfbf7eU) << 28 | 0xfdfbf7eU) << 28 |
       0xfdfbf7eU)
          << 28 |
      0xfdfbf7fU),
     (18446744073709551615UL) / 127},

    {(((((uintmax_t)0xf82eU << 28 | 0xe6986d6U) << 28 | 0xf63aa03U) << 28 |
       0xe88cb3cU)
          << 28 |
      0x9484e2bU),
     (18446744073709551615UL) / 131},

    {(((((uintmax_t)0x21a2U << 28 | 0x91c0779U) << 28 | 0x75b8fe2U) << 28 |
       0x1a291c0U)
          << 28 |
      0x77975b9U),
     (18446744073709551615UL) / 137},

    {(((((uintmax_t)0xa212U << 28 | 0x6ad1f4fU) << 28 | 0x31ba03aU) << 28 |
       0xef6ca97U)
          << 28 |
      0x0586723U),
     (18446744073709551615UL) / 139},

    {(((((uintmax_t)0x93c2U << 28 | 0x25cc74dU) << 28 | 0x50c06dfU) << 28 |
       0x5b0f768U)
          << 28 |
      0xce2cabdU),
     (18446744073709551615UL) / 149},

    {(((((uintmax_t)0x26feU << 28 | 0x4dfc9bfU) << 28 | 0x937f26fU) << 28 |
       0xe4dfc9bU)
          << 28 |
      0xf937f27U),
     (18446744073709551615UL) / 151},

    {(((((uintmax_t)0x0685U << 28 | 0xb4fe5e9U) << 28 | 0x2c0685bU) << 28 |
       0x4fe5e92U)
          << 28 |
      0xc0685b5U),
     (18446744073709551615UL) / 157},

    {(((((uintmax_t)0x8bc7U << 28 | 0x75ca99eU) << 28 | 0xa03241fU) << 28 |
       0x693a1c4U)
          << 28 |
      0x51ab30bU),
     (18446744073709551615UL) / 163},

    {(((((uintmax_t)0x513eU << 28 | 0xd9ad38bU) << 28 | 0x7f3bc8dU) << 28 |
       0x07aa27dU)
          << 28 |
      0xb35a717U),
     (18446744073709551615UL) / 167},

    {(((((uintmax_t)0x133cU << 28 | 0xaba736cU) << 28 | 0x05eb488U) << 28 |
       0x2383b30U)
          << 28 |
      0xd516325U),
     (18446744073709551615UL) / 173},

    {(((((uintmax_t)0x0e4dU << 28 | 0x3aa30a0U) << 28 | 0x2dc3eedU) << 28 |
       0x6866f8dU)
          << 28 |
      0x962ae7bU),
     (18446744073709551615UL) / 179},

    {(((((uintmax_t)0x6fbcU << 28 | 0x1c498c0U) << 28 | 0x5a84f34U) << 28 |
       0x54dca41U)
          << 28 |
      0x0f8ed9dU),
     (18446744073709551615UL) / 181},

    {(((((uintmax_t)0x7749U << 28 | 0xb79f7f5U) << 28 | 0x470961dU) << 28 |
       0x7ca632eU)
          << 28 |
      0xe936f3fU),
     (18446744073709551615UL) / 191},

    {(((((uintmax_t)0x9094U << 28 | 0x8f40feaU) << 28 | 0xc6f6b70U) << 28 |
       0xbf01539U)
          << 28 |
      0x0948f41U),
     (18446744073709551615UL) / 193},

    {(((((uintmax_t)0x0bb2U << 28 | 0x07cc053U) << 28 | 0x2ae21c9U) << 28 |
       0x6bdb9d3U)
          << 28 |
      0xd137e0dU),
     (18446744073709551615UL) / 197},

    {(((((uintmax_t)0x7a36U << 28 | 0x07b7f5bU) << 28 | 0x5630e26U) << 28 |
       0x97cc8aeU)
          << 28 |
      0xf46c0f7U),
     (18446744073709551615UL) / 199},

    {(((((uintmax_t)0x2f51U << 28 | 0x4a026d3U) << 28 | 0x1be7bc0U) << 28 |
       0xe8f2a76U)
          << 28 |
      0xe68575bU),
     (18446744073709551615UL) / 211},

    {(((((uintmax_t)0xdd8fU << 28 | 0x7f6d0eeU) << 28 | 0xc7bfb68U) << 28 |
       0x7763dfdU)
          << 28 |
      0xb43bb1fU),
     (18446744073709551615UL) / 223},

    {(((((uintmax_t)0x766aU << 28 | 0x024168eU) << 28 | 0x18cf81bU) << 28 |
       0x10ea929U)
          << 28 |
      0xba144cbU),
     (18446744073709551615UL) / 227},

    {(((((uintmax_t)0x0c4cU << 28 | 0x0478bbcU) << 28 | 0xecfee1dU) << 28 |
       0x10c4c04U)
          << 28 |
      0x78bbcedU),
     (18446744073709551615UL) / 229},

    {(((((uintmax_t)0x758fU << 28 | 0xee6bac7U) << 28 | 0xf735d63U) << 28 |
       0xfb9aeb1U)
          << 28 |
      0xfdcd759U),
     (18446744073709551615UL) / 233},

    {(((((uintmax_t)0x077fU << 28 | 0x76e538cU) << 28 | 0x5167e64U) << 28 |
       0xafaa4f4U)
          << 28 |
      0x37b2e0fU),
     (18446744073709551615UL) / 239},

    {(((((uintmax_t)0x10feU << 28 | 0xf010fefU) << 28 | 0x010fef0U) << 28 |
       0x10fef01U)
          << 28 |
      0x0fef011U),
     (18446744073709551615UL) / 241},

    {(((((uintmax_t)0xa020U << 28 | 0xa32fefaU) << 28 | 0xe680828U) << 28 |
       0xcbfbeb9U)
          << 28 |
      0xa020a33U),
     (18446744073709551615UL) / 251},

    {(((((uintmax_t)0xff00U << 28 | 0xff00ff0U) << 28 | 0x0ff00ffU) << 28 |
       0x00ff00fU)
          << 28 |
      0xf00ff01U),
     (18446744073709551615UL) / 257},

    {(((((uintmax_t)0xf836U << 28 | 0x826ef73U) << 28 | 0xd52bcd6U) << 28 |
       0x24fd147U)
          << 28 |
      0x0e99cb7U),
     (18446744073709551615UL) / 263},

    {(((((uintmax_t)0x3ce8U << 28 | 0x354b2eaU) << 28 | 0x1c8cd8fU) << 28 |
       0xb3ddbd6U)
          << 28 |
      0x205b5c5U),
     (18446744073709551615UL) / 269},

    {(((((uintmax_t)0x8715U << 28 | 0xba188f9U) << 28 | 0x63302d5U) << 28 |
       0x7da36caU)
          << 28 |
      0x27acdefU),
     (18446744073709551615UL) / 271},

    {(((((uintmax_t)0xb25eU << 28 | 0x4463cffU) << 28 | 0x13686eeU) << 28 |
       0x70c03b2U)
          << 28 |
      0x5e4463dU),
     (18446744073709551615UL) / 277},

    {(((((uintmax_t)0x6c69U << 28 | 0xae01d27U) << 28 | 0x2ca3fc5U) << 28 |
       0xb1a6b80U)
          << 28 |
      0x749cb29U),
     (18446744073709551615UL) / 281},

    {(((((uintmax_t)0xf26eU << 28 | 0x5c44bfcU) << 28 | 0x61b2347U) << 28 |
       0x768073cU)
          << 28 |
      0x9b97113U),
     (18446744073709551615UL) / 283},

    {(((((uintmax_t)0xb07dU << 28 | 0xd0d1b15U) << 28 | 0xd7cf125U) << 28 |
       0x91e9488U)
          << 28 |
      0x4ce32adU),
     (18446744073709551615UL) / 293},

    {(((((uintmax_t)0xd2f8U << 28 | 0x7ebfcaaU) << 28 | 0x1c5a0f0U) << 28 |
       0x2806abcU)
          << 28 |
      0x74be1fbU),
     (18446744073709551615UL) / 307},

    {(((((uintmax_t)0xbe25U << 28 | 0xdd6d7aaU) << 28 | 0x646ca7eU) << 28 |
       0xc3e8f3aU)
          << 28 |
      0x7198487U),
     (18446744073709551615UL) / 311},

    {(((((uintmax_t)0xbc1dU << 28 | 0x71afd8bU) << 28 | 0xdc03458U) << 28 |
       0x550f8a3U)
          << 28 |
      0x9409d09U),
     (18446744073709551615UL) / 313},

    {(((((uintmax_t)0x2ed6U << 28 | 0xd05a72aU) << 28 | 0xcd1f7ecU) << 28 |
       0x9e48ae6U)
          << 28 |
      0xf71de15U),
     (18446744073709551615UL) / 317},

    {(((((uintmax_t)0x62ffU << 28 | 0x3a018bfU) << 28 | 0xce8062fU) << 28 |
       0xf3a018bU)
          << 28 |
      0xfce8063U),
     (18446744073709551615UL) / 331},

    {(((((uintmax_t)0x3fcfU << 28 | 0x61fe7b0U) << 28 | 0xff3d87fU) << 28 |
       0x9ec3fcfU)
          << 28 |
      0x61fe7b1U),
     (18446744073709551615UL) / 337},

    {(((((uintmax_t)0x398bU << 28 | 0x6f668c2U) << 28 | 0xc43df89U) << 28 |
       0xf5abe57U)
          << 28 |
      0x0e046d3U),
     (18446744073709551615UL) / 347},

    {(((((uintmax_t)0x8c1aU << 28 | 0x682913cU) << 28 | 0xe1ecedaU) << 28 |
       0x971b23fU)
          << 28 |
      0x1545af5U),
     (18446744073709551615UL) / 349},

    {(((((uintmax_t)0x0b9aU << 28 | 0x7862a0fU) << 28 | 0xf465879U) << 28 |
       0xd5f00b9U)
          << 28 |
      0xa7862a1U),
     (18446744073709551615UL) / 353},

    {(((((uintmax_t)0xe7c1U << 28 | 0x3f77161U) << 28 | 0xb18f54dU) << 28 |
       0xba1df32U)
          << 28 |
      0xa128a57U),
     (18446744073709551615UL) / 359},

    {(((((uintmax_t)0x7318U << 28 | 0x6a06f9bU) << 28 | 0x8d9a287U) << 28 |
       0x530217bU)
          << 28 |
      0x7747d8fU),
     (18446744073709551615UL) / 367},

    {(((((uintmax_t)0x7c39U << 28 | 0xa6c708eU) << 28 | 0xc18b530U) << 28 |
       0xbaae53bU)
          << 28 |
      0xb5e06ddU),
     (18446744073709551615UL) / 373},

    {(((((uintmax_t)0x3763U << 28 | 0x4af9ebbU) << 28 | 0xc742deeU) << 28 |
       0x70206c1U)
          << 28 |
      0x2e9b5b3U),
     (18446744073709551615UL) / 379},

    {(((((uintmax_t)0x5035U << 28 | 0x78fb523U) << 28 | 0x6cf34cdU) << 28 |
       0xde9462eU)
          << 28 |
      0xc9dbe7fU),
     (18446744073709551615UL) / 383},

    {(((((uintmax_t)0xbcdfU << 28 | 0xc0d2975U) << 28 | 0xccab1afU) << 28 |
       0xb64b05eU)
          << 28 |
      0xc41cf4dU),
     (18446744073709551615UL) / 389},

    {(((((uintmax_t)0xf5aeU << 28 | 0xc02944fU) << 28 | 0xf5aec02U) << 28 |
       0x944ff5aU)
          << 28 |
      0xec02945U),
     (18446744073709551615UL) / 397},

    {(((((uintmax_t)0xc7d2U << 28 | 0x08f00a3U) << 28 | 0x6e71a2cU) << 28 |
       0xb033128U)
          << 28 |
      0x382df71U),
     (18446744073709551615UL) / 401},

    {(((((uintmax_t)0xd38fU << 28 | 0x55c0280U) << 28 | 0xf05a21cU) << 28 |
       0xcacc0c8U)
          << 28 |
      0x4b1c2a9U),
     (18446744073709551615UL) / 409},

    {(((((uintmax_t)0xca3bU << 28 | 0xe03aa76U) << 28 | 0x87a3219U) << 28 |
       0xa93db57U)
          << 28 |
      0x5eb3a0bU),
     (18446744073709551615UL) / 419},

    {(((((uintmax_t)0x6a69U << 28 | 0xce2344bU) << 28 | 0x66c3cceU) << 28 |
       0xbeef94fU)
          << 28 |
      0xa86fe2dU),
     (18446744073709551615UL) / 421},

    {(((((uintmax_t)0xfecfU << 28 | 0xe37d53bU) << 28 | 0xfd9fc6fU) << 28 |
       0xaa77fb3U)
          << 28 |
      0xf8df54fU),
     (18446744073709551615UL) / 431},

    {(((((uintmax_t)0xa58aU << 28 | 0xf00975aU) << 28 | 0x750ff68U) << 28 |
       0xa58af00U)
          << 28 |
      0x975a751U),
     (18446744073709551615UL) / 433},

    {(((((uintmax_t)0xdc6dU << 28 | 0xa187df5U) << 28 | 0x80dfed5U) << 28 |
       0x6e36d0cU)
          << 28 |
      0x3efac07U),
     (18446744073709551615UL) / 439},

    {(((((uintmax_t)0x8fe4U << 28 | 0x4308ab0U) << 28 | 0xd4a8bd8U) << 28 |
       0xb44c47aU)
          << 28 |
      0x8299b73U),
     (18446744073709551615UL) / 443},

    {(((((uintmax_t)0xf1bfU << 28 | 0x0091f5bU) << 28 | 0xcb8bb02U) << 28 |
       0xd9ccaf9U)
          << 28 |
      0xba70e41U),
     (18446744073709551615UL) / 449},

    {(((((uintmax_t)0x5e1cU << 28 | 0x023d9e8U) << 28 | 0x78ff709U) << 28 |
       0x85e1c02U)
          << 28 |
      0x3d9e879U),
     (18446744073709551615UL) / 457},

    {(((((uintmax_t)0x7880U << 28 | 0xd53da3dU) << 28 | 0x15a842aU) << 28 |
       0x343316cU)
          << 28 |
      0x494d305U),
     (18446744073709551615UL) / 461},

    {(((((uintmax_t)0x1ddbU << 28 | 0x81ef699U) << 28 | 0xb5e8c70U) << 28 |
       0xcb7916aU)
          << 28 |
      0xb67652fU),
     (18446744073709551615UL) / 463},

    {(((((uintmax_t)0xf364U << 28 | 0x5121706U) << 28 | 0x07acad3U) << 28 |
       0x98f132fU)
          << 28 |
      0xb10fe5bU),
     (18446744073709551615UL) / 467},

    {(((((uintmax_t)0xadb1U << 28 | 0xf8848afU) << 28 | 0x4c6d06fU) << 28 |
       0x2a38a6bU)
          << 28 |
      0xf54fa1fU),
     (18446744073709551615UL) / 479},

    {(((((uintmax_t)0xd9a0U << 28 | 0x541b55aU) << 28 | 0xf0c1721U) << 28 |
       0x1df689bU)
          << 28 |
      0x98f81d7U),
     (18446744073709551615UL) / 487},

    {(((((uintmax_t)0x673bU << 28 | 0xf592825U) << 28 | 0x8a2ac0eU) << 28 |
       0x994983eU)
          << 28 |
      0x90f1ec3U),
     (18446744073709551615UL) / 491},

    {(((((uintmax_t)0x0ddaU << 28 | 0x093c062U) << 28 | 0x8041aadU) << 28 |
       0x671e44bU)
          << 28 |
      0xed87f3bU),
     (18446744073709551615UL) / 499},

    {(((((uintmax_t)0xa9fcU << 28 | 0xf24229bU) << 28 | 0xbcd1af9U) << 28 |
       0x623a051U)
          << 28 |
      0x6e70fc7U),
     (18446744073709551615UL) / 503},

    {(((((uintmax_t)0xcbb1U << 28 | 0x8a4f773U) << 28 | 0x2cc324bU) << 28 |
       0x7129be9U)
          << 28 |
      0xdece355U),
     (18446744073709551615UL) / 509},

    {(((((uintmax_t)0x01f7U << 28 | 0x27cce5fU) << 28 | 0x530a519U) << 28 |
       0x0f3b747U)
          << 28 |
      0x3f62c39U),
     (18446744073709551615UL) / 521},

    {(((((uintmax_t)0x6da4U << 28 | 0xf4bdeb7U) << 28 | 0x1121c63U) << 28 |
       0xdacc9aaU)
          << 28 |
      0xd46f9a3U),
     (18446744073709551615UL) / 523},

    {(((((uintmax_t)0x4d9aU << 28 | 0xbc552cfU) << 28 | 0x42b88c1U) << 28 |
       0x108fda2U)
          << 28 |
      0x4e8d035U),
     (18446744073709551615UL) / 541},

    {(((((uintmax_t)0x141fU << 28 | 0xd312409U) << 28 | 0x5c328b7U) << 28 |
       0x7578472U)
          << 28 |
      0x319bd8bU),
     (18446744073709551615UL) / 547},

    {(((((uintmax_t)0xddfdU << 28 | 0x3e0bf32U) << 28 | 0x18d1947U) << 28 |
       0x3d20a1cU)
          << 28 |
      0x7ed9da5U),
     (18446744073709551615UL) / 557},

    {(((((uintmax_t)0xdb2bU << 28 | 0x3278f3bU) << 28 | 0x910d2fbU) << 28 |
       0xe85af0fU)
          << 28 |
      0xea2c8fbU),
     (18446744073709551615UL) / 563},

    {(((((uintmax_t)0xcb5cU << 28 | 0x3b636e3U) << 28 | 0xa7d1358U) << 28 |
       0xa1f7e6cU)
          << 28 |
      0xe0f4c09U),
     (18446744073709551615UL) / 569},

    {(((((uintmax_t)0x1bcbU << 28 | 0xfe34e75U) << 28 | 0x76cf21aU) << 28 |
       0x00e58c5U)
          << 28 |
      0x44986f3U),
     (18446744073709551615UL) / 571},

    {(((((uintmax_t)0x6b5eU << 28 | 0x80aa5efU) << 28 | 0x23f0071U) << 28 |
       0x94a17f5U)
          << 28 |
      0x5a10dc1U),
     (18446744073709551615UL) / 577},

    {(((((uintmax_t)0x9a62U << 28 | 0x8feb110U) << 28 | 0x22e3a70U) << 28 |
       0x8494478U)
          << 28 |
      0x5e33763U),
     (18446744073709551615UL) / 587},

    {(((((uintmax_t)0xbe61U << 28 | 0x909eddeU) << 28 | 0x53c01baU) << 28 |
       0x10679bdU)
          << 28 |
      0x84886b1U),
     (18446744073709551615UL) / 593},

    {(((((uintmax_t)0x4febU << 28 | 0x7c5e05fU) << 28 | 0xbb9e8ebU) << 28 |
       0xe9c6bb3U)
          << 28 |
      0x1260967U),
     (18446744073709551615UL) / 599},

    {(((((uintmax_t)0x1ff2U << 28 | 0x5e8ff92U) << 28 | 0xf47fc97U) << 28 |
       0xa3fe4bdU)
          << 28 |
      0x1ff25e9U),
     (18446744073709551615UL) / 601},

    {(((((uintmax_t)0x3014U << 28 | 0x3e6b1faU) << 28 | 0x187616cU) << 28 |
       0x6388395U)
          << 28 |
      0xb84d99fU),
     (18446744073709551615UL) / 607},

    {(((((uintmax_t)0xd491U << 28 | 0x54c6c94U) << 28 | 0xac0f08cU) << 28 |
       0x51da6a1U)
          << 28 |
      0x335df6dU),
     (18446744073709551615UL) / 613},

    {(((((uintmax_t)0x9b97U << 28 | 0x71454a4U) << 28 | 0x4e00d46U) << 28 |
       0xf323447U)
          << 28 |
      0x5d5add9U),
     (18446744073709551615UL) / 617},

    {(((((uintmax_t)0x3abaU << 28 | 0x1b4baefU) << 28 | 0x0b2a990U) << 28 |
       0x5605ca3U)
          << 28 |
      0xc619a43U),
     (18446744073709551615UL) / 619},

    {(((((uintmax_t)0xcc11U << 28 | 0xd9dd1bfU) << 28 | 0xe608eceU) << 28 |
       0xe8dff30U)
          << 28 |
      0x4767747U),
     (18446744073709551615UL) / 631},

    {(((((uintmax_t)0xff99U << 28 | 0xc27f006U) << 28 | 0x63d80ffU) << 28 |
       0x99c27f0U)
          << 28 |
      0x0663d81U),
     (18446744073709551615UL) / 641},

    {(((((uintmax_t)0x111eU << 28 | 0xa8032f6U) << 28 | 0x0bf1aacU) << 28 |
       0xca407f6U)
          << 28 |
      0x71ddc2bU),
     (18446744073709551615UL) / 643},

    {(((((uintmax_t)0xdd93U << 28 | 0x95f5b66U) << 28 | 0x7aa88e7U) << 28 |
       0x1298bacU)
          << 28 |
      0x1e12337U),
     (18446744073709551615UL) / 647},

    {(((((uintmax_t)0xa7caU << 28 | 0xaed9303U) << 28 | 0x8740afaU) << 28 |
       0x1e94309U)
          << 28 |
      0xcd09045U),
     (18446744073709551615UL) / 653},

    {(((((uintmax_t)0x2be5U << 28 | 0x958f582U) << 28 | 0xe9db7beU) << 28 |
       0xbccb8e9U)
          << 28 |
      0x1496b9bU),
     (18446744073709551615UL) / 659},

    {(((((uintmax_t)0x995eU << 28 | 0x1ca8dbfU) << 28 | 0xb5a3d31U) << 28 |
       0x2fa30ccU)
          << 28 |
      0x7d7b8bdU),
     (18446744073709551615UL) / 661},

    {(((((uintmax_t)0x9f00U << 28 | 0x6160ff9U) << 28 | 0xe9f0061U) << 28 |
       0x60ff9e9U)
          << 28 |
      0xf006161U),
     (18446744073709551615UL) / 673},

    {(((((uintmax_t)0xb33cU << 28 | 0xe15ee9bU) << 28 | 0x097416bU) << 28 |
       0x03673b5U)
          << 28 |
      0xe28152dU),
     (18446744073709551615UL) / 677},

    {(((((uintmax_t)0xfa00U << 28 | 0xbfe802fU) << 28 | 0xfa00bfeU) << 28 |
       0x802ffa0U)
          << 28 |
      0x0bfe803U),
     (18446744073709551615UL) / 683},

    {(((((uintmax_t)0x1c28U << 28 | 0x02f6bcfU) << 28 | 0x18d26e6U) << 28 |
       0x6fe25c9U)
          << 28 |
      0xe907c7bU),
     (18446744073709551615UL) / 691},

    {(((((uintmax_t)0xcf6dU << 28 | 0xec4793eU) << 28 | 0x72aba3fU) << 28 |
       0x8b236c7U)
          << 28 |
      0x6528895U),
     (18446744073709551615UL) / 701},

    {(((((uintmax_t)0x1e54U << 28 | 0x7da72d2U) << 28 | 0x24d44f6U) << 28 |
       0xf923bf0U)
          << 28 |
      0x1ce2c0dU),
     (18446744073709551615UL) / 709},

    {(((((uintmax_t)0x7746U << 28 | 0xda9d5fcU) << 28 | 0x708306cU) << 28 |
       0x3d3d98bU)
          << 28 |
      0xed7c42fU),
     (18446744073709551615UL) / 719},

    {(((((uintmax_t)0xcdffU << 28 | 0x4bb5591U) << 28 | 0x6e37a30U) << 28 |
       0x981efcdU)
          << 28 |
      0x4b010e7U),
     (18446744073709551615UL) / 727},

    {(((((uintmax_t)0x2c01U << 28 | 0x65a1b3dU) << 28 | 0xd13356fU) << 28 |
       0x691fc81U)
          << 28 |
      0xebbe575U),
     (18446744073709551615UL) / 733},

    {(((((uintmax_t)0xa802U << 28 | 0xc574bddU) << 28 | 0x5bccbb1U) << 28 |
       0x0480ddbU)
          << 28 |
      0x47b52cbU),
     (18446744073709551615UL) / 739},

    {(((((uintmax_t)0x5411U << 28 | 0xeaa350fU) << 28 | 0x8134b74U) << 28 |
       0xcd59ed6U)
          << 28 |
      0x4f3f0d7U),
     (18446744073709551615UL) / 743},

    {(((((uintmax_t)0xfceeU << 28 | 0x9d7c6bbU) << 28 | 0x7bbd301U) << 28 |
       0x05cb813U)
          << 28 |
      0x16d6c0fU),
     (18446744073709551615UL) / 751},

    {(((((uintmax_t)0x4248U << 28 | 0x5eb0874U) << 28 | 0x553879bU) << 28 |
       0xe64c6d9U)
          << 28 |
      0x1c1195dU),
     (18446744073709551615UL) / 757},

    {(((((uintmax_t)0xe060U << 28 | 0xe20f797U) << 28 | 0x0b19e71U) << 28 |
       0xb3f945aU)
          << 28 |
      0x27b1f49U),
     (18446744073709551615UL) / 761},

    {(((((uintmax_t)0x782dU << 28 | 0x463deb5U) << 28 | 0xc369877U) << 28 |
       0xd80d50eU)
          << 28 |
      0x508fd01U),
     (18446744073709551615UL) / 769},

    {(((((uintmax_t)0x4a2fU << 28 | 0x06f468aU) << 28 | 0x6e9cfa5U) << 28 |
       0xeb778e1U)
          << 28 |
      0x33551cdU),
     (18446744073709551615UL) / 773},

    {(((((uintmax_t)0xda44U << 28 | 0x4f5ea87U) << 28 | 0xf831718U) << 28 |
       0x657d3c2U)
          << 28 |
      0xd8a3f1bU),
     (18446744073709551615UL) / 787},

    {(((((uintmax_t)0xfb80U << 28 | 0xcd9225eU) << 28 | 0x6f2302eU) << 28 |
       0x40e220cU)
          << 28 |
      0x34ad735U),
     (18446744073709551615UL) / 797},

    {(((((uintmax_t)0x1719U << 28 | 0xa1b36beU) << 28 | 0x7f357a7U) << 28 |
       0x6593c70U)
          << 28 |
      0xa714919U),
     (18446744073709551615UL) / 809},

    {(((((uintmax_t)0x2867U << 28 | 0x894fdcaU) << 28 | 0x567da1eU) << 28 |
       0xef45212U)
          << 28 |
      0x4eea383U),
     (18446744073709551615UL) / 811},

    {(((((uintmax_t)0x8932U << 28 | 0xd36914eU) << 28 | 0x43f9c38U) << 28 |
       0x206dc24U)
          << 28 |
      0x2ba771dU),
     (18446744073709551615UL) / 821},

    {(((((uintmax_t)0xdeb7U << 28 | 0x8610cc0U) << 28 | 0xdafbf4cU) << 28 |
       0xd4c3580U)
          << 28 |
      0x7772287U),
     (18446744073709551615UL) / 823},

    {(((((uintmax_t)0x8fa1U << 28 | 0xe560e3dU) << 28 | 0x4a9a283U) << 28 |
       0xde917d5U)
          << 28 |
      0xe69ddf3U),
     (18446744073709551615UL) / 827},

    {(((((uintmax_t)0x6724U << 28 | 0x2159dccU) << 28 | 0xbcfd388U) << 28 |
       0x2ef0403U)
          << 28 |
      0xb4a6c15U),
     (18446744073709551615UL) / 829},

    {(((((uintmax_t)0x5e96U << 28 | 0xbb58ca9U) << 28 | 0xa64b0f8U) << 28 |
       0xfb6c51cU)
          << 28 |
      0x606b677U),
     (18446744073709551615UL) / 839},

    {(((((uintmax_t)0x2450U << 28 | 0x6e7171bU) << 28 | 0xe930eb4U) << 28 |
       0xabaac44U)
          << 28 |
      0x6d3e1fdU),
     (18446744073709551615UL) / 853},

    {(((((uintmax_t)0x3743U << 28 | 0x3611535U) << 28 | 0x7861fa9U) << 28 |
       0xf83bbe4U)
          << 28 |
      0x84a14e9U),
     (18446744073709551615UL) / 857},

    {(((((uintmax_t)0x232aU << 28 | 0x9df37baU) << 28 | 0xdbf080bU) << 28 |
       0xebbc0d1U)
          << 28 |
      0xce874d3U),
     (18446744073709551615UL) / 859},

    {(((((uintmax_t)0x569eU << 28 | 0x67d2e92U) << 28 | 0x8a3bebdU) << 28 |
       0x418eaf0U)
          << 28 |
      0x473189fU),
     (18446744073709551615UL) / 863},

    {(((((uintmax_t)0x7e1aU << 28 | 0x457923eU) << 28 | 0x77ae444U) << 28 |
       0xe3af6f3U)
          << 28 |
      0x72b7e65U),
     (18446744073709551615UL) / 877},

    {(((((uintmax_t)0x9764U << 28 | 0x3fed672U) << 28 | 0x7cf2ec8U) << 28 |
       0x7fdace4U)
          << 28 |
      0xf9e5d91U),
     (18446744073709551615UL) / 881},

    {(((((uintmax_t)0xea8bU << 28 | 0xbde5e83U) << 28 | 0x9fbf0ecU) << 28 |
       0x93479c4U)
          << 28 |
      0x46bd9bbU),
     (18446744073709551615UL) / 883},

    {(((((uintmax_t)0x3d2fU << 28 | 0x9f06a35U) << 28 | 0xae9c6daU) << 28 |
       0xc4d592eU)
          << 28 |
      0x777c647U),
     (18446744073709551615UL) / 887},

    {(((((uintmax_t)0x81d5U << 28 | 0xa9a1ba9U) << 28 | 0x11379a6U) << 28 |
       0x3ea8c8fU)
          << 28 |
      0x61f0c23U),
     (18446744073709551615UL) / 907},

    {(((((uintmax_t)0x752eU << 28 | 0x5ddb77fU) << 28 | 0xdc07de4U) << 28 |
       0x76062eaU)
          << 28 |
      0x5cbbb6fU),
     (18446744073709551615UL) / 911},

    {(((((uintmax_t)0x1abdU << 28 | 0xfafc60fU) << 28 | 0x0add2dfU) << 28 |
       0x68761c6U)
          << 28 |
      0x9daac27U),
     (18446744073709551615UL) / 919},

    {(((((uintmax_t)0xac3aU << 28 | 0x6b786c0U) << 28 | 0x582e4b8U) << 28 |
       0x13d7376U)
          << 28 |
      0x37aa061U),
     (18446744073709551615UL) / 929},

    {(((((uintmax_t)0x131fU << 28 | 0xf741d81U) << 28 | 0xc6a01a3U) << 28 |
       0xa77aac1U)
          << 28 |
      0xfb15099U),
     (18446744073709551615UL) / 937},

    {(((((uintmax_t)0xc53cU << 28 | 0xaad918cU) << 28 | 0x1b34817U) << 28 |
       0xf0c3e07U)
          << 28 |
      0x12c5825U),
     (18446744073709551615UL) / 941},

    {(((((uintmax_t)0xea1aU << 28 | 0x7df8f8bU) << 28 | 0x37f52fdU) << 28 |
       0x912a70fU)
          << 28 |
      0xf30637bU),
     (18446744073709551615UL) / 947},

    {(((((uintmax_t)0xbb3bU << 28 | 0x5dc0113U) << 28 | 0x1288ffbU) << 28 |
       0xb3b5dc0U)
          << 28 |
      0x1131289U),
     (18446744073709551615UL) / 953},

    {(((((uintmax_t)0x50beU << 28 | 0x9c31c53U) << 28 | 0xa81b885U) << 28 |
       0x6d560a0U)
          << 28 |
      0xf5acdf7U),
     (18446744073709551615UL) / 967},

    {(((((uintmax_t)0x6580U << 28 | 0xec3a008U) << 28 | 0x6fc9296U) << 28 |
       0x472f314U)
          << 28 |
      0xd3f89e3U),
     (18446744073709551615UL) / 971},

    {(((((uintmax_t)0x1108U << 28 | 0x1f71752U) << 28 | 0x03ab1a7U) << 28 |
       0x6f5c7edU)
          << 28 |
      0x2253531U),
     (18446744073709551615UL) / 977},

    {(((((uintmax_t)0xb81fU << 28 | 0x4053563U) << 28 | 0x3908981U) << 28 |
       0x6eae7c7U)
          << 28 |
      0xbf69fe7U),
     (18446744073709551615UL) / 983},

    {(((((uintmax_t)0x9c8bU << 28 | 0x7ed668eU) << 28 | 0x14263b6U) << 28 |
       0xa2bea4cU)
          << 28 |
      0xfb1781fU),
     (18446744073709551615UL) / 991},

    {(((((uintmax_t)0x0291U << 28 | 0x54fdb06U) << 28 | 0x6b547a3U) << 28 |
       0x900c533U)
          << 28 |
      0x18e81edU),
     (18446744073709551615UL) / 997},

    {(((((uintmax_t)0x2240U << 28 | 0x71aa3e6U) << 28 | 0xa0db360U) << 28 |
       0xaa7f5d9U)
          << 28 |
      0xf148d11U),
     (18446744073709551615UL) / 1009},

    {(((((uintmax_t)0x02c7U << 28 | 0xa505cffU) << 28 | 0xbf4e16bU) << 28 |
       0xe8c0102U)
          << 28 |
      0xc7a505dU),
     (18446744073709551615UL) / 1013},

    {(((((uintmax_t)0xcafdU << 28 | 0xbd2c779U) << 28 | 0x57ad98fU) << 28 |
       0xf3f0ed2U)
          << 28 |
      0x8728f33U),
     (18446744073709551615UL) / 1019},

    {(((((uintmax_t)0x513cU << 28 | 0xedb245bU) << 28 | 0x4473568U) << 28 |
       0x0e0a87eU)
          << 28 |
      0x5ec7155U),
     (18446744073709551615UL) / 1021},

    {(((((uintmax_t)0x2e6eU << 28 | 0xbe33267U) << 28 | 0xca5ddbbU) << 28 |
       0xf70fa49U)
          << 28 |
      0xfe829b7U),
     (18446744073709551615UL) / 1031},

    {(((((uintmax_t)0x007eU << 28 | 0xe2825abU) << 28 | 0x3eb2ed6U) << 28 |
       0x9d1e7b6U)
          << 28 |
      0xa50ca39U),
     (18446744073709551615UL) / 1033},

    {(((((uintmax_t)0x2f8dU << 28 | 0xacb84cdU) << 28 | 0xfb90a1aU) << 28 |
       0x1e0f46bU)
          << 28 |
      0x6d26aefU),
     (18446744073709551615UL) / 1039},

    {(((((uintmax_t)0x01f3U << 28 | 0xcc435b0U) << 28 | 0x713c474U) << 28 |
       0x29f9a7aU)
          << 28 |
      0x8251829U),
     (18446744073709551615UL) / 1049},

    {(((((uintmax_t)0x8c0eU << 28 | 0x9d59e14U) << 28 | 0xf29a6d9U) << 28 |
       0xc2219d1U)
          << 28 |
      0xb863613U),
     (18446744073709551615UL) / 1051},

    {(((((uintmax_t)0x6e81U << 28 | 0xcf42d5cU) << 28 | 0x6932e91U) << 28 |
       0x406c182U)
          << 28 |
      0x0d077adU),
     (18446744073709551615UL) / 1061},

    {(((((uintmax_t)0x9c4cU << 28 | 0x1a02688U) << 28 | 0x4efdd52U) << 28 |
       0x1f4ec02U)
          << 28 |
      0xe3d2b97U),
     (18446744073709551615UL) / 1063},

    {(((((uintmax_t)0x7bcfU << 28 | 0x2599067U) << 28 | 0x74255bbU) << 28 |
       0x8283b63U)
          << 28 |
      0xdc8eba5U),
     (18446744073709551615UL) / 1069},

    {(((((uintmax_t)0x46a7U << 28 | 0x3667275U) << 28 | 0x48c5d43U) << 28 |
       0x1eda153U)
          << 28 |
      0x229ebbfU),
     (18446744073709551615UL) / 1087},

    {(((((uintmax_t)0xe720U << 28 | 0x9daecfeU) << 28 | 0x5b832afU) << 28 |
       0x0bf78d7U)
          << 28 |
      0xe01686bU),
     (18446744073709551615UL) / 1091},

    {(((((uintmax_t)0x194bU << 28 | 0xa6ff4c1U) << 28 | 0xeeaafa9U) << 28 |
       0xced0742U)
          << 28 |
      0xc086e8dU),
     (18446744073709551615UL) / 1093},

    {(((((uintmax_t)0x777bU << 28 | 0x730c5e4U) << 28 | 0x768c7c2U) << 28 |
       0x6458ad9U)
          << 28 |
      0xf632df9U),
     (18446744073709551615UL) / 1097},

    {(((((uintmax_t)0x2aefU << 28 | 0xfc49577U) << 28 | 0xfe24abbU) << 28 |
       0xff1255dU)
          << 28 |
      0xff892afU),
     (18446744073709551615UL) / 1103},

    {(((((uintmax_t)0xf1b0U << 28 | 0x213da24U) << 28 | 0x78f59cbU) << 28 |
       0xd49a333U)
          << 28 |
      0xf04d8fdU),
     (18446744073709551615UL) / 1109},

    {(((((uintmax_t)0x8822U << 28 | 0xd60f205U) << 28 | 0x0ac58ecU) << 28 |
       0x84ed6f9U)
          << 28 |
      0xcfdeff5U),
     (18446744073709551615UL) / 1117},

    {(((((uintmax_t)0x3606U << 28 | 0xd6bd351U) << 28 | 0xd682d97U) << 28 |
       0x980cc40U)
          << 28 |
      0xbda9d4bU),
     (18446744073709551615UL) / 1123},

    {(((((uintmax_t)0x0122U << 28 | 0x3d38ea0U) << 28 | 0x15c4977U) << 28 |
       0x7f34d52U)
          << 28 |
      0x4f5cbd9U),
     (18446744073709551615UL) / 1129},

    {(((((uintmax_t)0x78feU << 28 | 0x716e8a5U) << 28 | 0x7a1b227U) << 28 |
       0x97051d9U)
          << 28 |
      0x4cbbb7fU),
     (18446744073709551615UL) / 1151},

    {(((((uintmax_t)0xd6ecU << 28 | 0xaef5908U) << 28 | 0xa8be0eaU) << 28 |
       0x769051bU)
          << 28 |
      0x4f43b81U),
     (18446744073709551615UL) / 1153},

    {(((((uintmax_t)0x7867U << 28 | 0xe595e6eU) << 28 | 0x801c2ceU) << 28 |
       0x7910f30U)
          << 28 |
      0x34d4323U),
     (18446744073709551615UL) / 1163},

    {(((((uintmax_t)0xa705U << 28 | 0xe713e4eU) << 28 | 0x43c5692U) << 28 |
       0x791d137U)
          << 28 |
      0x4f5b99bU),
     (18446744073709551615UL) / 1171},

    {(((((uintmax_t)0x92c0U << 28 | 0x0ddf7c3U) << 28 | 0x4e40989U) << 28 |
       0xa5645ccU)
          << 28 |
      0x68ea1b5U),
     (18446744073709551615UL) / 1181},

    {(((((uintmax_t)0xab06U << 28 | 0xaf8e205U) << 28 | 0x9b7f75fU) << 28 |
       0x8aacf79U)
          << 28 |
      0x6c0cf0bU),
     (18446744073709551615UL) / 1187},

    {(((((uintmax_t)0xe187U << 28 | 0x673725fU) << 28 | 0xb4774f2U) << 28 |
       0xe90a15eU)
          << 28 |
      0x33edf99U),
     (18446744073709551615UL) / 1193},

    {(((((uintmax_t)0x57d1U << 28 | 0xf5579b6U) << 28 | 0x3f8538eU) << 28 |
       0x99e5febU)
          << 28 |
      0x897c451U),
     (18446744073709551615UL) / 1201},

    {(((((uintmax_t)0x5f64U << 28 | 0xab5ec29U) << 28 | 0x5d7e6acU) << 28 |
       0xa2eda38U)
          << 28 |
      0xfb91695U),
     (18446744073709551615UL) / 1213},

    {(((((uintmax_t)0x48c8U << 28 | 0x41a1574U) << 28 | 0xbf0035dU) << 28 |
       0x9b737beU)
          << 28 |
      0x5ea8b41U),
     (18446744073709551615UL) / 1217},

    {(((((uintmax_t)0x348aU << 28 | 0x26ef0b8U) << 28 | 0x33e964aU) << 28 |
       0xefe1db9U)
          << 28 |
      0x3fd7cf7U),
     (18446744073709551615UL) / 1223},

    {(((((uintmax_t)0x5247U << 28 | 0x3d081faU) << 28 | 0x958f1a0U) << 28 |
       0x994ef20U)
          << 28 |
      0xb3f8805U),
     (18446744073709551615UL) / 1229},

    {(((((uintmax_t)0x0ec3U << 28 | 0xe6367c5U) << 28 | 0xc55ae10U) << 28 |
       0x3890bdaU)
          << 28 |
      0x912822fU),
     (18446744073709551615UL) / 1231},

    {(((((uintmax_t)0xb57fU << 28 | 0x46921bbU) << 28 | 0xb4ab5b4U) << 28 |
       0x41659d1U)
          << 28 |
      0x3a9147dU),
     (18446744073709551615UL) / 1237},

    {(((((uintmax_t)0xb2eeU << 28 | 0xfcecf03U) << 28 | 0x7c00d1eU) << 28 |
       0x2134440U)
          << 28 |
      0xc4c3f21U),
     (18446744073709551615UL) / 1249},

    {(((((uintmax_t)0xed4bU << 28 | 0x07ee1b3U) << 28 | 0xf3ccc26U) << 28 |
       0x3a27727U)
          << 28 |
      0xa6883c3U),
     (18446744073709551615UL) / 1259},

    {(((((uintmax_t)0x435bU << 28 | 0x9d5e6bdU) << 28 | 0xa4fc978U) << 28 |
       0xe221472U)
          << 28 |
      0xab33855U),
     (18446744073709551615UL) / 1277},

    {(((((uintmax_t)0x6013U << 28 | 0x370b023U) << 28 | 0x3a3ed95U) << 28 |
       0xeac88e8U)
          << 28 |
      0x2e6faffU),
     (18446744073709551615UL) / 1279},

    {(((((uintmax_t)0x3447U << 28 | 0x089473bU) << 28 | 0xa900ff6U) << 28 |
       0x6c25831U)
          << 28 |
      0x7be8dabU),
     (18446744073709551615UL) / 1283},

    {(((((uintmax_t)0x0f7dU << 28 | 0xb74fa3dU) << 28 | 0x912de09U) << 28 |
       0xee202c7U)
          << 28 |
      0xcb91939U),
     (18446744073709551615UL) / 1289},

    {(((((uintmax_t)0x5316U << 28 | 0x02c6b14U) << 28 | 0x6caa88dU) << 28 |
       0x2fca104U)
          << 28 |
      0x2a09ea3U),
     (18446744073709551615UL) / 1291},

    {(((((uintmax_t)0x2128U << 28 | 0xdb7c26aU) << 28 | 0xfaabb82U) << 28 |
       0x779c856U)
          << 28 |
      0xd8b8bf1U),
     (18446744073709551615UL) / 1297},

    {(((((uintmax_t)0xb01cU << 28 | 0x55cadf2U) << 28 | 0x39d9d38U) << 28 |
       0x79361cbU)
          << 28 |
      0xa8a223dU),
     (18446744073709551615UL) / 1301},

    {(((((uintmax_t)0x3d4cU << 28 | 0x6d3cb58U) << 28 | 0x9b9a9f2U) << 28 |
       0x3f43639U)
          << 28 |
      0xc3182a7U),
     (18446744073709551615UL) / 1303},

    {(((((uintmax_t)0x0bc0U << 28 | 0x89e42fcU) << 28 | 0xab94aa0U) << 28 |
       0x3868fc4U)
          << 28 |
      0x74bcd13U),
     (18446744073709551615UL) / 1307},

    {(((((uintmax_t)0x34fcU << 28 | 0x4ff6af1U) << 28 | 0x0e2b165U) << 28 |
       0x1e78b8cU)
          << 28 |
      0x5311a97U),
     (18446744073709551615UL) / 1319},

    {(((((uintmax_t)0x18ffU << 28 | 0xce639c0U) << 28 | 0x0c6718fU) << 28 |
       0xfce639cU)
          << 28 |
      0x00c6719U),
     (18446744073709551615UL) / 1321},

    {(((((uintmax_t)0x9b4cU << 28 | 0x33b39aeU) << 28 | 0x96dc4f7U) << 28 |
       0xb460754U)
          << 28 |
      0xb0b61cfU),
     (18446744073709551615UL) / 1327},

    {(((((uintmax_t)0xbbe8U << 28 | 0xad0c9a3U) << 28 | 0xd51d27bU) << 28 |
       0x03f3359U)
          << 28 |
      0xb8e63b1U),
     (18446744073709551615UL) / 1361},

    {(((((uintmax_t)0xa28dU << 28 | 0x33dfca1U) << 28 | 0x0dabba5U) << 28 |
       0x5c53260U)
          << 28 |
      0x41eb667U),
     (18446744073709551615UL) / 1367},

    {(((((uintmax_t)0x677bU << 28 | 0x3ed5acdU) << 28 | 0x78a2964U) << 28 |
       0x7f88ab8U)
          << 28 |
      0x96a76f5U),
     (18446744073709551615UL) / 1373},

    {(((((uintmax_t)0xf4e0U << 28 | 0xac06ac6U) << 28 | 0x595988fU) << 28 |
       0xd971434U)
          << 28 |
      0xa55a46dU),
     (18446744073709551615UL) / 1381},

    {(((((uintmax_t)0x3ba7U << 28 | 0x6f12d90U) << 28 | 0x609e19fU) << 28 |
       0xbf96995U)
          << 28 |
      0x8046447U),
     (18446744073709551615UL) / 1399},

    {(((((uintmax_t)0x3d69U << 28 | 0x32b0f71U) << 28 | 0x8e43399U) << 28 |
       0x86feba6U)
          << 28 |
      0x9be3a81U),
     (18446744073709551615UL) / 1409},

    {(((((uintmax_t)0xb7adU << 28 | 0xf701426U) << 28 | 0x239eda6U) << 28 |
       0x68b3e6dU)
          << 28 |
      0x053796fU),
     (18446744073709551615UL) / 1423},

    {(((((uintmax_t)0xd0d1U << 28 | 0x893d2caU) << 28 | 0xb80fc97U) << 28 |
       0x694e658U)
          << 28 |
      0x9f4e09bU),
     (18446744073709551615UL) / 1427},

    {(((((uintmax_t)0xc00bU << 28 | 0x7721dbcU) << 28 | 0xffd2237U) << 28 |
       0x890c00bU)
          << 28 |
      0x7721dbdU),
     (18446744073709551615UL) / 1429},

    {(((((uintmax_t)0xe9d9U << 28 | 0x0e1cf0dU) << 28 | 0x0a8a45aU) << 28 |
       0xc094a23U)
          << 28 |
      0x5f37ea9U),
     (18446744073709551615UL) / 1433},

    {(((((uintmax_t)0x8489U << 28 | 0x56fe661U) << 28 | 0xd881831U) << 28 |
       0xcff775fU)
          << 28 |
      0x2d5d65fU),
     (18446744073709551615UL) / 1439},

    {(((((uintmax_t)0xfd85U << 28 | 0xed3f28dU) << 28 | 0xe356dddU) << 28 |
       0xad8e6b3U)
          << 28 |
      0x6505217U),
     (18446744073709551615UL) / 1447},

    {(((((uintmax_t)0x0a68U << 28 | 0xcca8aacU) << 28 | 0x8c7035aU) << 28 |
       0x27df897U)
          << 28 |
      0x062cd03U),
     (18446744073709551615UL) / 1451},

    {(((((uintmax_t)0x57eaU << 28 | 0xdb877ceU) << 28 | 0xaae6ce2U) << 28 |
       0x396fe0fU)
          << 28 |
      0xdb5a625U),
     (18446744073709551615UL) / 1453},

    {(((((uintmax_t)0x1c12U << 28 | 0xf330f43U) << 28 | 0xe76f6b3U) << 28 |
       0x52a4957U)
          << 28 |
      0xe82317bU),
     (18446744073709551615UL) / 1459},

    {(((((uintmax_t)0x472dU << 28 | 0xc52d6c1U) << 28 | 0x2cb9dd8U) << 28 |
       0xab3f2c6U)
          << 28 |
      0x0c2ea3fU),
     (18446744073709551615UL) / 1471},

    {(((((uintmax_t)0xda51U << 28 | 0x3e0e2c9U) << 28 | 0x8ce0b68U) << 28 |
       0x93f702fU)
          << 28 |
      0x0452479U),
     (18446744073709551615UL) / 1481},

    {(((((uintmax_t)0x442fU << 28 | 0xa4dae2dU) << 28 | 0x3a2c896U) << 28 |
       0x86fdc18U)
          << 28 |
      0x2acf7e3U),
     (18446744073709551615UL) / 1483},

    {(((((uintmax_t)0x091fU << 28 | 0xd96fbb2U) << 28 | 0x2f2be68U) << 28 |
       0x5403717U)
          << 28 |
      0x3dce12fU),
     (18446744073709551615UL) / 1487},

    {(((((uintmax_t)0x3accU << 28 | 0x97fbdfaU) << 28 | 0xd798d7fU) << 28 |
       0x0ded168U)
          << 28 |
      0x5c27331U),
     (18446744073709551615UL) / 1489},

    {(((((uintmax_t)0x4d54U << 28 | 0xe047548U) << 28 | 0x87cd3eeU) << 28 |
       0xda72e1fU)
          << 28 |
      0xe490b7dU),
     (18446744073709551615UL) / 1493},

    {(((((uintmax_t)0x7e8cU << 28 | 0x61afbbbU) << 28 | 0x013209eU) << 28 |
       0x7bfc959U)
          << 28 |
      0xa8e6e53U),
     (18446744073709551615UL) / 1499},

    {(((((uintmax_t)0xc4b3U << 28 | 0x96f4fccU) << 28 | 0x7ebab49U) << 28 |
       0xb314d6dU)
          << 28 |
      0x4753dd7U),
     (18446744073709551615UL) / 1511},

    {(((((uintmax_t)0x9eadU << 28 | 0x21c933fU) << 28 | 0x089292eU) << 28 |
       0x8f8c5acU)
          << 28 |
      0x4aa1b3bU),
     (18446744073709551615UL) / 1523},

    {(((((uintmax_t)0x0584U << 28 | 0x992a4deU) << 28 | 0xb99aab8U) << 28 |
       0xef72348U)
          << 28 |
      0x1163d33U),
     (18446744073709551615UL) / 1531},

    {(((((uintmax_t)0x8b08U << 28 | 0x7620d9aU) << 28 | 0xcb6806aU) << 28 |
       0x2ec96a5U)
          << 28 |
      0x94287b7U),
     (18446744073709551615UL) / 1543},

    {(((((uintmax_t)0xc108U << 28 | 0x6dbce6bU) << 28 | 0x6c94bdbU) << 28 |
       0xa41c6d1U)
          << 28 |
      0x3aab8c5U),
     (18446744073709551615UL) / 1549},

    {(((((uintmax_t)0xe478U << 28 | 0xaa1e005U) << 28 | 0x46633c2U) << 28 |
       0xadbe648U)
          << 28 |
      0xdc3aaf1U),
     (18446744073709551615UL) / 1553},

    {(((((uintmax_t)0x5cf1U << 28 | 0x0e9d4faU) << 28 | 0x40b2a87U) << 28 |
       0xa2bade5U)
          << 28 |
      0x65f91a7U),
     (18446744073709551615UL) / 1559},

    {(((((uintmax_t)0x9ecbU << 28 | 0x8ef2c45U) << 28 | 0xec11a4dU) << 28 |
       0x6fe8798U)
          << 28 |
      0xc01f5dfU),
     (18446744073709551615UL) / 1567},

    {(((((uintmax_t)0xfb99U << 28 | 0xaa49543U) << 28 | 0xf39d937U) << 28 |
       0x91310c8U)
          << 28 |
      0xc23d98bU),
     (18446744073709551615UL) / 1571},

    {(((((uintmax_t)0x7abbU << 28 | 0x187b379U) << 28 | 0xc2112f8U) << 28 |
       0x0e446b0U)
          << 28 |
      0x1228883U),
     (18446744073709551615UL) / 1579},

    {(((((uintmax_t)0x3cceU << 28 | 0x5a3d212U) << 28 | 0x6f95e9aU) << 28 |
       0xed1436fU)
          << 28 |
      0xbf500cfU),
     (18446744073709551615UL) / 1583},

    {(((((uintmax_t)0xc6eeU << 28 | 0xd90c05cU) << 28 | 0x5547a78U) << 28 |
       0x39b54ccU)
          << 28 |
      0x8b24115U),
     (18446744073709551615UL) / 1597},

    {(((((uintmax_t)0x8798U << 28 | 0x627f99aU) << 28 | 0x9f948c1U) << 28 |
       0x28c646aU)
          << 28 |
      0xd0309c1U),
     (18446744073709551615UL) / 1601},

    {(((((uintmax_t)0x5233U << 28 | 0x4bab403U) << 28 | 0x2fa1b14U) << 28 |
       0xde63162U)
          << 28 |
      0x4a3c377U),
     (18446744073709551615UL) / 1607},

    {(((((uintmax_t)0x0e51U << 28 | 0xc7ad43fU) << 28 | 0x016e93fU) << 28 |
       0x7b9fe68U)
          << 28 |
      0xb0ecbf9U),
     (18446744073709551615UL) / 1609},

    {(((((uintmax_t)0x00a2U << 28 | 0x84ffd75U) << 28 | 0xec00a28U) << 28 |
       0x4ffd75eU)
          << 28 |
      0xc00a285U),
     (18446744073709551615UL) / 1613},

    {(((((uintmax_t)0xe72cU << 28 | 0xbfa4ebeU) << 28 | 0xb20bb37U) << 28 |
       0x803cb80U)
          << 28 |
      0xdea2ddbU),
     (18446744073709551615UL) / 1619},

    {(((((uintmax_t)0x22beU << 28 | 0x75d04e5U) << 28 | 0x4f6ff86U) << 28 |
       0xb63f7c9U)
          << 28 |
      0xac4c6fdU),
     (18446744073709551615UL) / 1621},

    {(((((uintmax_t)0x84f4U << 28 | 0xd419cdfU) << 28 | 0x6dfbe8bU) << 28 |
       0x6851d1bU)
          << 28 |
      0xd99b9d3U),
     (18446744073709551615UL) / 1627},

    {(((((uintmax_t)0xe83aU << 28 | 0xccdcd04U) << 28 | 0xd90f7b6U) << 28 |
       0x2fda77cU)
          << 28 |
      0xa343b6dU),
     (18446744073709551615UL) / 1637},

    {(((((uintmax_t)0x9e34U << 28 | 0x383c8ffU) << 28 | 0xd872f1fU) << 28 |
       0x0dc009eU)
          << 28 |
      0x34383c9U),
     (18446744073709551615UL) / 1657},

    {(((((uintmax_t)0x2e7dU << 28 | 0x4e5ad2eU) << 28 | 0x55e5d49U) << 28 |
       0x6dc21ddU)
          << 28 |
      0xd35b97fU),
     (18446744073709551615UL) / 1663},

    {(((((uintmax_t)0xe596U << 28 | 0x098573aU) << 28 | 0x33e80b0U) << 28 |
       0xe96ce17U)
          << 28 |
      0x090f82bU),
     (18446744073709551615UL) / 1667},

    {(((((uintmax_t)0x7181U << 28 | 0x4dc42e0U) << 28 | 0x3fceeaaU) << 28 |
       0xdf05acdU)
          << 28 |
      0xd7d024dU),
     (18446744073709551615UL) / 1669},

    {(((((uintmax_t)0xa4abU << 28 | 0x2bb32f5U) << 28 | 0x43975cbU) << 28 |
       0x1381967U)
          << 28 |
      0x46eafb5U),
     (18446744073709551615UL) / 1693},

    {(((((uintmax_t)0xa2ecU << 28 | 0x3cf1f87U) << 28 | 0x5102434U) << 28 |
       0x7f52373U)
          << 28 |
      0x6755d61U),
     (18446744073709551615UL) / 1697},

    {(((((uintmax_t)0x6ff3U << 28 | 0xf223422U) << 28 | 0x5ab51d1U) << 28 |
       0x4a48a05U)
          << 28 |
      0x1f7dd0bU),
     (18446744073709551615UL) / 1699},

    {(((((uintmax_t)0x6c00U << 28 | 0x9963e9dU) << 28 | 0x48f3447U) << 28 |
       0x4d71b1cU)
          << 28 |
      0xe914d25U),
     (18446744073709551615UL) / 1709},

    {(((((uintmax_t)0x894cU << 28 | 0x02f99a8U) << 28 | 0xd502d38U) << 28 |
       0x6063f5eU)
          << 28 |
      0x28c1f89U),
     (18446744073709551615UL) / 1721},

    {(((((uintmax_t)0xc8e0U << 28 | 0xa6684d4U) << 28 | 0x2b6281dU) << 28 |
       0xb7325e3U)
          << 28 |
      0x2d04e73U),
     (18446744073709551615UL) / 1723},

    {(((((uintmax_t)0xf8c2U << 28 | 0xfdc8c0aU) << 28 | 0x0b85afeU) << 28 |
       0xf748d38U)
          << 28 |
      0x93b880dU),
     (18446744073709551615UL) / 1733},

    {(((((uintmax_t)0xd0a7U << 28 | 0x0a25594U) << 28 | 0x123bb2fU) << 28 |
       0x3351506U)
          << 28 |
      0xe935605U),
     (18446744073709551615UL) / 1741},

    {(((((uintmax_t)0xdb5dU << 28 | 0xa31878bU) << 28 | 0xf158a7aU) << 28 |
       0x3637fa2U)
          << 28 |
      0x376415bU),
     (18446744073709551615UL) / 1747},

    {(((((uintmax_t)0x75b4U << 28 | 0x5a8abbcU) << 28 | 0xd2e004aU) << 28 |
       0xc525d2bU)
          << 28 |
      0xaa21969U),
     (18446744073709551615UL) / 1753},

    {(((((uintmax_t)0x7e53U << 28 | 0x89d2e22U) << 28 | 0xa34af3aU) << 28 |
       0x11c16b4U)
          << 28 |
      0x2cd351fU),
     (18446744073709551615UL) / 1759},

    {(((((uintmax_t)0xeaf7U << 28 | 0x801270aU) << 28 | 0x843ff6cU) << 28 |
       0x7abde00U)
          << 28 |
      0x49c2a11U),
     (18446744073709551615UL) / 1777},

    {(((((uintmax_t)0x1ad9U << 28 | 0x60a0cecU) << 28 | 0x0ae9754U) << 28 |
       0xdad0303U)
          << 28 |
      0xe069ac7U),
     (18446744073709551615UL) / 1783},

    {(((((uintmax_t)0x082aU << 28 | 0x676e737U) << 28 | 0x70be3ebU) << 28 |
       0xf1ac9fdU)
          << 28 |
      0xfe91433U),
     (18446744073709551615UL) / 1787},

    {(((((uintmax_t)0x50b4U << 28 | 0xdfcda14U) << 28 | 0x51d9efaU) << 28 |
       0xfdda823U)
          << 28 |
      0x7cec655U),
     (18446744073709551615UL) / 1789},

    {(((((uintmax_t)0x1ffbU << 28 | 0x738ffdbU) << 28 | 0x9c7fedcU) << 28 |
       0xe3ff6e7U)
          << 28 |
      0x1ffb739U),
     (18446744073709551615UL) / 1801},

    {(((((uintmax_t)0xa660U << 28 | 0xf8ca6cdU) << 28 | 0x88f9ebeU) << 28 |
       0xd5737d6U)
          << 28 |
      0x286db1bU),
     (18446744073709551615UL) / 1811},

    {(((((uintmax_t)0xed52U << 28 | 0xb6467eaU) << 28 | 0xa7abbe4U) << 28 |
       0x79e431fU)
          << 28 |
      0xe08b4dfU),
     (18446744073709551615UL) / 1823},

    {(((((uintmax_t)0xdaf2U << 28 | 0xff4d09aU) << 28 | 0x5ae119dU) << 28 |
       0xd9b0dd7U)
          << 28 |
      0x742f897U),
     (18446744073709551615UL) / 1831},

    {(((((uintmax_t)0x6054U << 28 | 0x454d33bU) << 28 | 0x2efc88fU) << 28 |
       0x09d7402U)
          << 28 |
      0xc5a5e87U),
     (18446744073709551615UL) / 1847},

    {(((((uintmax_t)0xf545U << 28 | 0x31625b1U) << 28 | 0x0a51292U) << 28 |
       0x16d5c4dU)
          << 28 |
      0x958738dU),
     (18446744073709551615UL) / 1861},

    {(((((uintmax_t)0x6df8U << 28 | 0x0c1100aU) << 28 | 0xf82f2b3U) << 28 |
       0x139ba11U)
          << 28 |
      0xd34ca63U),
     (18446744073709551615UL) / 1867},

    {(((((uintmax_t)0xaf8bU << 28 | 0xf8e2952U) << 28 | 0x3b61d47U) << 28 |
       0xd54f7edU)
          << 28 |
      0x644afafU),
     (18446744073709551615UL) / 1871},

    {(((((uintmax_t)0x4d5cU << 28 | 0x4227171U) << 28 | 0x9491f92U) << 28 |
       0xa81d85cU)
          << 28 |
      0xf11a1b1U),
     (18446744073709551615UL) / 1873},

    {(((((uintmax_t)0xf78bU << 28 | 0x4082eeaU) << 28 | 0xdc21475U) << 28 |
       0x4b26533U)
          << 28 |
      0x253bdfdU),
     (18446744073709551615UL) / 1877},

    {(((((uintmax_t)0xf354U << 28 | 0x558f76aU) << 28 | 0xad92bbbU) << 28 |
       0xe0efc98U)
          << 28 |
      0x0bfd467U),
     (18446744073709551615UL) / 1879},

    {(((((uintmax_t)0x0ab4U << 28 | 0xc91d231U) << 28 | 0x99d11c0U) << 28 |
       0xd8d594fU)
          << 28 |
      0x024dca1U),
     (18446744073709551615UL) / 1889},

    {(((((uintmax_t)0x1b56U << 28 | 0x52256feU) << 28 | 0x84c7d82U) << 28 |
       0x38d43bcU)
          << 28 |
      0xaac1a65U),
     (18446744073709551615UL) / 1901},

    {(((((uintmax_t)0xaca2U << 28 | 0xb39dbc1U) << 28 | 0x2cb3e27U) << 28 |
       0x779c1faU)
          << 28 |
      0xe6175bbU),
     (18446744073709551615UL) / 1907},

    {(((((uintmax_t)0x3856U << 28 | 0xb755c78U) << 28 | 0x7068ea7U) << 28 |
       0x46ca9afU)
          << 28 |
      0x708b2c9U),
     (18446744073709551615UL) / 1913},

    {(((((uintmax_t)0x052bU << 28 | 0x9de5385U) << 28 | 0x8076c93U) << 28 |
       0xf3cd9f3U)
          << 28 |
      0x89be823U),
     (18446744073709551615UL) / 1931},

    {(((((uintmax_t)0x820dU << 28 | 0x822f698U) << 28 | 0xd4f545cU) << 28 |
       0xb4a4c04U)
          << 28 |
      0xc489345U),
     (18446744073709551615UL) / 1933},

    {(((((uintmax_t)0xcd09U << 28 | 0x536828fU) << 28 | 0xb23dbbfU) << 28 |
       0x6047743U)
          << 28 |
      0xe85b6b5U),
     (18446744073709551615UL) / 1949},

    {(((((uintmax_t)0x8486U << 28 | 0xe386c1eU) << 28 | 0xf778961U) << 28 |
       0xc147831U)
          << 28 |
      0x563545fU),
     (18446744073709551615UL) / 1951},

    {(((((uintmax_t)0xec68U << 28 | 0x5200c74U) << 28 | 0xc6c78edU) << 28 |
       0xb47c0aeU)
          << 28 |
      0x62dee9dU),
     (18446744073709551615UL) / 1973},

    {(((((uintmax_t)0xd8acU << 28 | 0xd298624U) << 28 | 0xff1830aU) << 28 |
       0x3824386U)
          << 28 |
      0x673a573U),
     (18446744073709551615UL) / 1979},

    {(((((uintmax_t)0x03ddU << 28 | 0x78b87ecU) << 28 | 0x6aad6a4U) << 28 |
       0xa77d19eU)
          << 28 |
      0x575a0ebU),
     (18446744073709551615UL) / 1987},

    {(((((uintmax_t)0x8950U << 28 | 0x062a636U) << 28 | 0xb8325a2U) << 28 |
       0xbee045eU)
          << 28 |
      0x066c279U),
     (18446744073709551615UL) / 1993},

    {(((((uintmax_t)0xa9daU << 28 | 0xd301275U) << 28 | 0xae369c2U) << 28 |
       0x3618de8U)
          << 28 |
      0xab43d05U),
     (18446744073709551615UL) / 1997},

    {(((((uintmax_t)0xfa3cU << 28 | 0xb3cd496U) << 28 | 0x174ec26U) << 28 |
       0x6b51521U)
          << 28 |
      0x6cb9f2fU),
     (18446744073709551615UL) / 1999},

    {(((((uintmax_t)0x5c05U << 28 | 0x9fa1eedU) << 28 | 0xfaa1ce2U) << 28 |
       0x79edd9eU)
          << 28 |
      0x9c2e85bU),
     (18446744073709551615UL) / 2003},

    {(((((uintmax_t)0x8e52U << 28 | 0x3c5712bU) << 28 | 0x68c48d0U) << 28 |
       0xc591c22U)
          << 28 |
      0x1dc9c53U),
     (18446744073709551615UL) / 2011},

    {(((((uintmax_t)0x8de5U << 28 | 0xdaaf67bU) << 28 | 0x1d10a06U) << 28 |
       0xda8ee9cU)
          << 28 |
      0x9ee7c21U),
     (18446744073709551615UL) / 2017},

    {(((((uintmax_t)0xec2bU << 28 | 0xf35ed8fU) << 28 | 0x98f179dU) << 28 |
       0xfebcaf4U)
          << 28 |
      0xc27e8c3U),
     (18446744073709551615UL) / 2027},

    {(((((uintmax_t)0xe8c8U << 28 | 0xdd0cfedU) << 28 | 0xd4d9849U) << 28 |
       0xaeff9f1U)
          << 28 |
      0x9dd6de5U),
     (18446744073709551615UL) / 2029},

    {(((((uintmax_t)0x65f2U << 28 | 0xb107280U) << 28 | 0xd0eb086U) << 28 |
       0x976a57aU)
          << 28 |
      0x296e9c7U),
     (18446744073709551615UL) / 2039},

    {(((((uintmax_t)0x44b5U << 28 | 0x0ed6b9cU) << 28 | 0xbe093a3U) << 28 |
       0xb9abf48U)
          << 28 |
      0x72b84cdU),
     (18446744073709551615UL) / 2053},

    {(((((uintmax_t)0x9e96U << 28 | 0xa5899dfU) << 28 | 0x7cf5b34U) << 28 |
       0xfca6483U)
          << 28 |
      0x895e6efU),
     (18446744073709551615UL) / 2063},

    {(((((uintmax_t)0x49beU << 28 | 0x6c24212U) << 28 | 0x8f47e34U) << 28 |
       0xb5a3339U)
          << 28 |
      0x88f873dU),
     (18446744073709551615UL) / 2069},

    {(((((uintmax_t)0xd1fdU << 28 | 0xc922526U) << 28 | 0xc0275d9U) << 28 |
       0xdd4f19bU)
          << 28 |
      0x5f17be1U),
     (18446744073709551615UL) / 2081},

    {(((((uintmax_t)0xb8d7U << 28 | 0x51f95d0U) << 28 | 0x8f8bfb9U) << 28 |
       0x35b507fU)
          << 28 |
      0xd0ce78bU),
     (18446744073709551615UL) / 2083},

    {(((((uintmax_t)0x971fU << 28 | 0x47835f8U) << 28 | 0xe2aeeb4U) << 28 |
       0x50f5540U)
          << 28 |
      0x660e797U),
     (18446744073709551615UL) / 2087},

    {(((((uintmax_t)0x418fU << 28 | 0xfe0a0c7U) << 28 | 0xff05063U) << 28 |
       0xff82831U)
          << 28 |
      0xffc1419U),
     (18446744073709551615UL) / 2089},

    {(((((uintmax_t)0xd06fU << 28 | 0x3ae8760U) << 28 | 0xf5e0889U) << 28 |
       0x92f718cU)
          << 28 |
      0x22a32fbU),
     (18446744073709551615UL) / 2099},

    {(((((uintmax_t)0x16adU << 28 | 0x6a5a779U) << 28 | 0x25f515fU) << 28 |
       0x3253ad0U)
          << 28 |
      0xd37e7bfU),
     (18446744073709551615UL) / 2111},

    {(((((uintmax_t)0xfe0fU << 28 | 0xc007c0fU) << 28 | 0xfe0fc00U) << 28 |
       0x7c0ffe0U)
          << 28 |
      0xfc007c1U),
     (18446744073709551615UL) / 2113},

    {(((((uintmax_t)0x9763U << 28 | 0x3395b43U) << 28 | 0xf020b4dU) << 28 |
       0x8ebadc0U)
          << 28 |
      0xc0640b1U),
     (18446744073709551615UL) / 2129},

    {(((((uintmax_t)0x9a20U << 28 | 0xea7f195U) << 28 | 0x90471e2U) << 28 |
       0x729af83U)
          << 28 |
      0x1037bdbU),
     (18446744073709551615UL) / 2131},

    {(((((uintmax_t)0x7285U << 28 | 0xee07e80U) << 28 | 0xa8ab8b8U) << 28 |
       0xf64bf30U)
          << 28 |
      0xfeebfe9U),
     (18446744073709551615UL) / 2137},

    {(((((uintmax_t)0x3dd1U << 28 | 0x5e1a10fU) << 28 | 0xa9e8cdaU) << 28 |
       0x93124b5U)
          << 28 |
      0x44c0bf5U),
     (18446744073709551615UL) / 2141},

    {(((((uintmax_t)0x4f14U << 28 | 0xe7bff85U) << 28 | 0xac9e29cU) << 28 |
       0xf7ff0b5U)
          << 28 |
      0x93c539fU),
     (18446744073709551615UL) / 2143},

    {(((((uintmax_t)0x12e7U << 28 | 0xdccdf10U) << 28 | 0x4a322d6U) << 28 |
       0xbd8861fU)
          << 28 |
      0xa0e07d9U),
     (18446744073709551615UL) / 2153},

    {(((((uintmax_t)0xd7b8U << 28 | 0xebfac9aU) << 28 | 0x00b5f5cU) << 28 |
       0xfe75c0bU)
          << 28 |
      0xd8ab891U),
     (18446744073709551615UL) / 2161},

    {(((((uintmax_t)0xae1cU << 28 | 0xe6bd9efU) << 28 | 0x512ea43U) << 28 |
       0xe808757U)
          << 28 |
      0xc2e862bU),
     (18446744073709551615UL) / 2179},

    {(((((uintmax_t)0x459bU << 28 | 0x5dc70f3U) << 28 | 0x90e8690U) << 28 |
       0xcaa96d5U)
          << 28 |
      0x95c9d93U),
     (18446744073709551615UL) / 2203},

    {(((((uintmax_t)0x4ec2U << 28 | 0xa38d65bU) << 28 | 0xa2bd88fU) << 28 |
       0xd550625U)
          << 28 |
      0xd07135fU),
     (18446744073709551615UL) / 2207},

    {(((((uintmax_t)0x525dU << 28 | 0x3cf6a14U) << 28 | 0x20da676U) << 28 |
       0xb010a86U)
          << 28 |
      0xe209f2dU),
     (18446744073709551615UL) / 2213},

    {(((((uintmax_t)0x716bU << 28 | 0x4f6a9e5U) << 28 | 0xf3522ecU) << 28 |
       0xc042644U)
          << 28 |
      0x7769b25U),
     (18446744073709551615UL) / 2221},

    {(((((uintmax_t)0x48abU << 28 | 0x336212fU) << 28 | 0xf32ece3U) << 28 |
       0x81339caU)
          << 28 |
      0xabe3295U),
     (18446744073709551615UL) / 2237},

    {(((((uintmax_t)0xbde9U << 28 | 0xd1944b7U) << 28 | 0x656aad1U) << 28 |
       0xb190a2dU)
          << 28 |
      0x0c7673fU),
     (18446744073709551615UL) / 2239},

    {(((((uintmax_t)0xb595U << 28 | 0xdb3fccdU) << 28 | 0xe54afc3U) << 28 |
       0xbce3cf2U)
          << 28 |
      0x6b0e7ebU),
     (18446744073709551615UL) / 2243},

    {(((((uintmax_t)0x8a10U << 28 | 0x9aab45fU) << 28 | 0x137285fU) << 28 |
       0x87e76f5U)
          << 28 |
      0x6c61ce3U),
     (18446744073709551615UL) / 2251},

    {(((((uintmax_t)0x2e69U << 28 | 0x78b763bU) << 28 | 0x65f88c0U) << 28 |
       0x6c6857aU)
          << 28 |
      0x124b353U),
     (18446744073709551615UL) / 2267},

    {(((((uintmax_t)0x7e40U << 28 | 0x4f6dc75U) << 28 | 0xca11d38U) << 28 |
       0xc040fcbU)
          << 28 |
      0xa630f75U),
     (18446744073709551615UL) / 2269},

    {(((((uintmax_t)0xa706U << 28 | 0x6b72173U) << 28 | 0x37865d0U) << 28 |
       0x78bc4fbU)
          << 28 |
      0xd533b21U),
     (18446744073709551615UL) / 2273},

    {(((((uintmax_t)0x1165U << 28 | 0x5853800U) << 28 | 0xe5d99deU) << 28 |
       0x8e15c5dU)
          << 28 |
      0xd354f59U),
     (18446744073709551615UL) / 2281},

    {(((((uintmax_t)0xad0dU << 28 | 0xfdfc31bU) << 28 | 0x33610caU) << 28 |
       0x61d53d7U)
          << 28 |
      0x414260fU),
     (18446744073709551615UL) / 2287},

    {(((((uintmax_t)0x65b5U << 28 | 0x32cc4f0U) << 28 | 0xb46abb5U) << 28 |
       0x6bf5ba8U)
          << 28 |
      0xeae635dU),
     (18446744073709551615UL) / 2293},

    {(((((uintmax_t)0xcdbcU << 28 | 0x7622fecU) << 28 | 0x6285844U) << 28 |
       0xa72cb0fU)
          << 28 |
      0xb6e3949U),
     (18446744073709551615UL) / 2297},

    {(((((uintmax_t)0x37c4U << 28 | 0x92cae49U) << 28 | 0xd6fa587U) << 28 |
       0x9839a71U)
          << 28 |
      0x4f45bcdU),
     (18446744073709551615UL) / 2309},

    {(((((uintmax_t)0xc031U << 28 | 0xa083283U) << 28 | 0x60ed802U) << 28 |
       0xa8994fdU)
          << 28 |
      0xe5314b7U),
     (18446744073709551615UL) / 2311},

    {(((((uintmax_t)0xc841U << 28 | 0xd685a6aU) << 28 | 0xe081eb9U) << 28 |
       0x71920cfU)
          << 28 |
      0x2b90135U),
     (18446744073709551615UL) / 2333},

    {(((((uintmax_t)0xc4c9U << 28 | 0xd2b0364U) << 28 | 0x9549a8aU) << 28 |
       0x8fd0b7dU)
          << 28 |
      0xf9a6e8bU),
     (18446744073709551615UL) / 2339},

    {(((((uintmax_t)0xe3c9U << 28 | 0x5290213U) << 28 | 0xe7112b3U) << 28 |
       0x1f9a84cU)
          << 28 |
      0x1c6eaadU),
     (18446744073709551615UL) / 2341},

    {(((((uintmax_t)0xf02fU << 28 | 0x1ede4bbU) << 28 | 0x2c64c92U) << 28 |
       0x293b028U)
          << 28 |
      0x23c6d83U),
     (18446744073709551615UL) / 2347},

    {(((((uintmax_t)0x83f9U << 28 | 0x7773bffU) << 28 | 0x907f2eeU) << 28 |
       0xe77ff20U)
          << 28 |
      0xfe5ddcfU),
     (18446744073709551615UL) / 2351},

    {(((((uintmax_t)0xd472U << 28 | 0x42b02b7U) << 28 | 0x1ef460eU) << 28 |
       0x1ea0f6cU)
          << 28 |
      0x496c11dU),
     (18446744073709551615UL) / 2357},

    {(((((uintmax_t)0xd905U << 28 | 0xb8f4727U) << 28 | 0x318f0fdU) << 28 |
       0xf2d3d6fU)
          << 28 |
      0x88ccb6bU),
     (18446744073709551615UL) / 2371},

    {(((((uintmax_t)0xf2c0U << 28 | 0xc7e3914U) << 28 | 0x920a1faU) << 28 |
       0x9d74a34U)
          << 28 |
      0x57738f9U),
     (18446744073709551615UL) / 2377},

    {(((((uintmax_t)0x6c7cU << 28 | 0x4a67008U) << 28 | 0x99f72efU) << 28 |
       0xc3ca3dbU)
          << 28 |
      0x71a5785U),
     (18446744073709551615UL) / 2381},

    {(((((uintmax_t)0x7e55U << 28 | 0xba2c0b9U) << 28 | 0xa289b8eU) << 28 |
       0x2071718U)
          << 28 |
      0xd0d6dafU),
     (18446744073709551615UL) / 2383},

    {(((((uintmax_t)0xbf46U << 28 | 0xd4d0be4U) << 28 | 0xff091bcU) << 28 |
       0x0fdbfebU)
          << 28 |
      0x6cfabfdU),
     (18446744073709551615UL) / 2389},

    {(((((uintmax_t)0x1908U << 28 | 0x738977bU) << 28 | 0x58af71eU) << 28 |
       0xeab613eU)
          << 28 |
      0x5e5aee9U),
     (18446744073709551615UL) / 2393},

    {(((((uintmax_t)0x6a48U << 28 | 0xc6e8d7fU) << 28 | 0xbbb472dU) << 28 |
       0x2388e90U)
          << 28 |
      0xe9e929fU),
     (18446744073709551615UL) / 2399},

    {(((((uintmax_t)0x9f7bU << 28 | 0x7cc2f24U) << 28 | 0xd82eb81U) << 28 |
       0xdbafba5U)
          << 28 |
      0x88ddb43U),
     (18446744073709551615UL) / 2411},

    {(((((uintmax_t)0x57ceU << 28 | 0x01e8101U) << 28 | 0x96b8152U) << 28 |
       0xeebc51cU)
          << 28 |
      0x4799791U),
     (18446744073709551615UL) / 2417},

    {(((((uintmax_t)0x22c2U << 28 | 0x9d6cb7dU) << 28 | 0x695651cU) << 28 |
       0x6bc4693U)
          << 28 |
      0xb45a047U),
     (18446744073709551615UL) / 2423},

    {(((((uintmax_t)0x366aU << 28 | 0x190050aU) << 28 | 0xd1e2606U) << 28 |
       0xeee0974U)
          << 28 |
      0x498874dU),
     (18446744073709551615UL) / 2437},

    {(((((uintmax_t)0x7708U << 28 | 0x7eb0665U) << 28 | 0xba929d8U) << 28 |
       0x5b7377aU)
          << 28 |
      0x9953cb9U),
     (18446744073709551615UL) / 2441},

    {(((((uintmax_t)0x8f53U << 28 | 0x96f6b06U) << 28 | 0x2c2614bU) << 28 |
       0x6df412dU)
          << 28 |
      0x4caf56fU),
     (18446744073709551615UL) / 2447},

    {(((((uintmax_t)0x0c2eU << 28 | 0x394250fU) << 28 | 0xedad56bU) << 28 |
       0x8afbbb4U)
          << 28 |
      0xa053493U),
     (18446744073709551615UL) / 2459},

    {(((((uintmax_t)0x78afU << 28 | 0x29d1b7fU) << 28 | 0xbd965ccU) << 28 |
       0x5299c96U)
          << 28 |
      0xac7720bU),
     (18446744073709551615UL) / 2467},

    {(((((uintmax_t)0x1287U << 28 | 0x9bcb69bU) << 28 | 0x11e89adU) << 28 |
       0xce84b5cU)
          << 28 |
      0x710aa99U),
     (18446744073709551615UL) / 2473},

    {(((((uintmax_t)0x92c2U << 28 | 0x17c54bfU) << 28 | 0x67de19dU) << 28 |
       0x673f5aaU)
          << 28 |
      0x3804225U),
     (18446744073709551615UL) / 2477},

    {(((((uintmax_t)0xd46eU << 28 | 0x0ce30e3U) << 28 | 0x76f2ce6U) << 28 |
       0x541268eU)
          << 28 |
      0xfbce7f7U),
     (18446744073709551615UL) / 2503},

    {(((((uintmax_t)0xa49bU << 28 | 0x91ec4ccU) << 28 | 0x5004dfcU) << 28 |
       0xf41e76cU)
          << 28 |
      0xf5be669U),
     (18446744073709551615UL) / 2521},

    {(((((uintmax_t)0x6098U << 28 | 0x1f8eb77U) << 28 | 0xa7cd05cU) << 28 |
       0x3eb5dc3U)
          << 28 |
      0x1c383cbU),
     (18446744073709551615UL) / 2531},

    {(((((uintmax_t)0x62e9U << 28 | 0x505bf44U) << 28 | 0xdd6a930U) << 28 |
       0x1832d11U)
          << 28 |
      0xd8ad6c3U),
     (18446744073709551615UL) / 2539},

    {(((((uintmax_t)0xb3cbU << 28 | 0x3fecabfU) << 28 | 0x119df2eU) << 28 |
       0x9c0942fU)
          << 28 |
      0x1ce450fU),
     (18446744073709551615UL) / 2543},

    {(((((uintmax_t)0xef3aU << 28 | 0x59c92a1U) << 28 | 0x4b05b97U) << 28 |
       0xf3f2be3U)
          << 28 |
      0x7a39a5dU),
     (18446744073709551615UL) / 2549},

    {(((((uintmax_t)0xe69cU << 28 | 0x5983c36U) << 28 | 0x30c57e8U) << 28 |
       0xb7d8a96U)
          << 28 |
      0x54187c7U),
     (18446744073709551615UL) / 2551},

    {(((((uintmax_t)0x437aU << 28 | 0xa4cb09bU) << 28 | 0x61d08b5U) << 28 |
       0xd024d7dU)
          << 28 |
      0xa5b1b55U),
     (18446744073709551615UL) / 2557},

    {(((((uintmax_t)0x1b65U << 28 | 0x8bdca98U) << 28 | 0xaabb9b8U) << 28 |
       0xba9d6e7U)
          << 28 |
      0xae3501bU),
     (18446744073709551615UL) / 2579},

    {(((((uintmax_t)0x3ea4U << 28 | 0x3624f3dU) << 28 | 0x8dfb0f5U) << 28 |
       0x0865f71U)
          << 28 |
      0xb90f1dfU),
     (18446744073709551615UL) / 2591},

    {(((((uintmax_t)0x2d05U << 28 | 0x08fbf3cU) << 28 | 0x1ffcd73U) << 28 |
       0x9c16828U)
          << 28 |
      0x47df9e1U),
     (18446744073709551615UL) / 2593},

    {(((((uintmax_t)0xc716U << 28 | 0xdcc634cU) << 28 | 0xa218ec4U) << 28 |
       0x70a4d84U)
          << 28 |
      0x2b90ed1U),
     (18446744073709551615UL) / 2609},

    {(((((uintmax_t)0xe30bU << 28 | 0x71f669dU) << 28 | 0x7e49c1fU) << 28 |
       0xb1be116U)
          << 28 |
      0x98cc409U),
     (18446744073709551615UL) / 2617},

    {(((((uintmax_t)0xa624U << 28 | 0x238d871U) << 28 | 0x4cde4d8U) << 28 |
       0xd5512a7U)
          << 28 |
      0xcd35d15U),
     (18446744073709551615UL) / 2621},

    {(((((uintmax_t)0x6488U << 28 | 0x81e55c1U) << 28 | 0x30e7ca5U) << 28 |
       0x4968217U)
          << 28 |
      0x23e07f9U),
     (18446744073709551615UL) / 2633},

    {(((((uintmax_t)0x8513U << 28 | 0xd3830beU) << 28 | 0x54ea0bcU) << 28 |
       0xc8c6d7aU)
          << 28 |
      0xbaa8167U),
     (18446744073709551615UL) / 2647},

    {(((((uintmax_t)0x49b5U << 28 | 0x0a4f32fU) << 28 | 0x800c552U) << 28 |
       0xc396c95U)
          << 28 |
      0xeb619a1U),
     (18446744073709551615UL) / 2657},

    {(((((uintmax_t)0xa1f0U << 28 | 0x049f0c9U) << 28 | 0xcbd166eU) << 28 |
       0xb7e3808U)
          << 28 |
      0x78ec74bU),
     (18446744073709551615UL) / 2659},

    {(((((uintmax_t)0x25f8U << 28 | 0xe2df380U) << 28 | 0xb892e3dU) << 28 |
       0x5513b50U)
          << 28 |
      0x4537157U),
     (18446744073709551615UL) / 2663},

    {(((((uintmax_t)0x1654U << 28 | 0xeb02967U) << 28 | 0x9b8e231U) << 28 |
       0x4391f88U)
          << 28 |
      0x62e948fU),
     (18446744073709551615UL) / 2671},

    {(((((uintmax_t)0x304aU << 28 | 0xf935d6eU) << 28 | 0x11c97dcU) << 28 |
       0x0b17cfcU)
          << 28 |
      0xd81f5ddU),
     (18446744073709551615UL) / 2677},

    {(((((uintmax_t)0xef7eU << 28 | 0x3c1c9feU) << 28 | 0xaa07d2fU) << 28 |
       0x6bea3ecU)
          << 28 |
      0x89044b3U),
     (18446744073709551615UL) / 2683},

    {(((((uintmax_t)0xd02cU << 28 | 0x34f8dabU) << 28 | 0xf7ff3ceU) << 28 |
       0x13a0586U)
          << 28 |
      0x9f1b57fU),
     (18446744073709551615UL) / 2687},

    {(((((uintmax_t)0xca7fU << 28 | 0x00185f3U) << 28 | 0x3e2ad75U) << 28 |
       0x93474e8U)
          << 28 |
      0xace3581U),
     (18446744073709551615UL) / 2689},

    {(((((uintmax_t)0x613fU << 28 | 0x67e6e76U) << 28 | 0x10ebc07U) << 28 |
       0xfc32929U)
          << 28 |
      0x5a05e4dU),
     (18446744073709551615UL) / 2693},

    {(((((uintmax_t)0x91e1U << 28 | 0x1433fa4U) << 28 | 0xf1ad7b0U) << 28 |
       0x5377cbaU)
          << 28 |
      0x4908d23U),
     (18446744073709551615UL) / 2699},

    {(((((uintmax_t)0x99c5U << 28 | 0x2d7ced2U) << 28 | 0xe3e9ae7U) << 28 |
       0xb2131a6U)
          << 28 |
      0x28aa39bU),
     (18446744073709551615UL) / 2707},

    {(((((uintmax_t)0xe699U << 28 | 0x2a662c6U) << 28 | 0x1d45f90U) << 28 |
       0x31dbed7U)
          << 28 |
      0xde01527U),
     (18446744073709551615UL) / 2711},

    {(((((uintmax_t)0x86efU << 28 | 0x7ca673aU) << 28 | 0xf9ad876U) << 28 |
       0x844b1c6U)
          << 28 |
      0x70aa9a9U),
     (18446744073709551615UL) / 2713},

    {(((((uintmax_t)0xb29bU << 28 | 0x59ea585U) << 28 | 0x098266aU) << 28 |
       0x03f4533U)
          << 28 |
      0xb08915fU),
     (18446744073709551615UL) / 2719},

    {(((((uintmax_t)0x2d67U << 28 | 0x181bc45U) << 28 | 0x6ad8b1dU) << 28 |
       0xbca579dU)
          << 28 |
      0xb0a3999U),
     (18446744073709551615UL) / 2729},

    {(((((uintmax_t)0xffa0U << 28 | 0x02ffe80U) << 28 | 0x0bffa00U) << 28 |
       0x2ffe800U)
          << 28 |
      0xbffa003U),
     (18446744073709551615UL) / 2731},

    {(((((uintmax_t)0xef00U << 28 | 0x778c303U) << 28 | 0x1503a47U) << 28 |
       0x8ab1a3eU)
          << 28 |
      0x936139dU),
     (18446744073709551615UL) / 2741},

    {(((((uintmax_t)0xd453U << 28 | 0x113a63aU) << 28 | 0x4bcdb66U) << 28 |
       0xe722bc4U)
          << 28 |
      0xc5cc095U),
     (18446744073709551615UL) / 2749},

    {(((((uintmax_t)0x01c4U << 28 | 0x4cfeca8U) << 28 | 0x7f35a7aU) << 28 |
       0x8f63c71U)
          << 28 |
      0x7278541U),
     (18446744073709551615UL) / 2753},

    {(((((uintmax_t)0x3887U << 28 | 0x72a189cU) << 28 | 0x2c09fdfU) << 28 |
       0x6eee24dU)
          << 28 |
      0x292bc2fU),
     (18446744073709551615UL) / 2767},

    {(((((uintmax_t)0x835dU << 28 | 0x625cbd2U) << 28 | 0xa50339fU) << 28 |
       0xc20d172U)
          << 28 |
      0x37dd569U),
     (18446744073709551615UL) / 2777},

    {(((((uintmax_t)0x8052U << 28 | 0x3e3ba9bU) << 28 | 0x7da8ccdU) << 28 |
       0xf993235U)
          << 28 |
      0x6bda2edU),
     (18446744073709551615UL) / 2789},

    {(((((uintmax_t)0xced6U << 28 | 0x1518ac7U) << 28 | 0x0a2e697U) << 28 |
       0xb5e332eU)
          << 28 |
      0x80f68d7U),
     (18446744073709551615UL) / 2791},

    {(((((uintmax_t)0x42d0U << 28 | 0x7f67b31U) << 28 | 0xe1cbd46U) << 28 |
       0xeee26fdU)
          << 28 |
      0x875e2e5U),
     (18446744073709551615UL) / 2797},

    {(((((uintmax_t)0xa787U << 28 | 0x5b7cc16U) << 28 | 0x4cf4935U) << 28 |
       0x48a8e65U)
          << 28 |
      0x157a611U),
     (18446744073709551615UL) / 2801},

    {(((((uintmax_t)0x69abU << 28 | 0x6d816a6U) << 28 | 0x6791ac2U) << 28 |
       0x88d03beU)
          << 28 |
      0x9b71e3bU),
     (18446744073709551615UL) / 2803},

    {(((((uintmax_t)0xace8U << 28 | 0x1dc954bU) << 28 | 0xa58d081U) << 28 |
       0x51186dbU)
          << 28 |
      0x38937abU),
     (18446744073709551615UL) / 2819},

    {(((((uintmax_t)0x7c3fU << 28 | 0xfa377bbU) << 28 | 0x52dd078U) << 28 |
       0x00b9108U)
          << 28 |
      0x95a45f1U),
     (18446744073709551615UL) / 2833},

    {(((((uintmax_t)0x1f0aU << 28 | 0x8ec0eccU) << 28 | 0x79a36aeU) << 28 |
       0xe0b0241U)
          << 28 |
      0x82eec3dU),
     (18446744073709551615UL) / 2837},

    {(((((uintmax_t)0x609eU << 28 | 0x7b00a15U) << 28 | 0xca83496U) << 28 |
       0x323eda1U)
          << 28 |
      0x73b5713U),
     (18446744073709551615UL) / 2843},

    {(((((uintmax_t)0x7362U << 28 | 0x52ca08cU) << 28 | 0xcba690eU) << 28 |
       0xd0dbd03U)
          << 28 |
      0xae77c8bU),
     (18446744073709551615UL) / 2851},

    {(((((uintmax_t)0xa370U << 28 | 0x463ffa4U) << 28 | 0x3eb91f7U) << 28 |
       0x3800b78U)
          << 28 |
      0x28dc119U),
     (18446744073709551615UL) / 2857},

    {(((((uintmax_t)0x4586U << 28 | 0x7cbbe80U) << 28 | 0x502c61bU) << 28 |
       0x61715ecU)
          << 28 |
      0x22b7ca5U),
     (18446744073709551615UL) / 2861},

    {(((((uintmax_t)0x508fU << 28 | 0xb1c027dU) << 28 | 0x607a5a8U) << 28 |
       0x533a991U)
          << 28 |
      0xead64bfU),
     (18446744073709551615UL) / 2879},

    {(((((uintmax_t)0xbc40U << 28 | 0xe8adccbU) << 28 | 0xf2e057fU) << 28 |
       0x6c7290eU)
          << 28 |
      0x46c2e77U),
     (18446744073709551615UL) / 2887},

    {(((((uintmax_t)0x73d9U << 28 | 0x78cc4e1U) << 28 | 0xdde3e63U) << 28 |
       0x25e8d90U)
          << 28 |
      0x7b01db1U),
     (18446744073709551615UL) / 2897},

    {(((((uintmax_t)0x1c21U << 28 | 0x8299f86U) << 28 | 0xa86ec28U) << 28 |
       0x909f701U)
          << 28 |
      0x52a1067U),
     (18446744073709551615UL) / 2903},

    {(((((uintmax_t)0x5da2U << 28 | 0x8a842e1U) << 28 | 0xd0a78eaU) << 28 |
       0x7077af0U)
          << 28 |
      0x997a0f5U),
     (18446744073709551615UL) / 2909},

    {(((((uintmax_t)0x21f6U << 28 | 0xb281b61U) << 28 | 0xadae07eU) << 28 |
       0x605cad1U)
          << 28 |
      0x0c32e6dU),
     (18446744073709551615UL) / 2917},

    {(((((uintmax_t)0x2e9dU << 28 | 0xf4a1477U) << 28 | 0x4c2dd47U) << 28 |
       0x1b33570U)
          << 28 |
      0x635b38fU),
     (18446744073709551615UL) / 2927},

    {(((((uintmax_t)0x891aU << 28 | 0x37ebcabU) << 28 | 0x12ba3abU) << 28 |
       0x559fa99U)
          << 28 |
      0x7a61bb3U),
     (18446744073709551615UL) / 2939},

    {(((((uintmax_t)0xccadU << 28 | 0xbad1f78U) << 28 | 0x11569adU) << 28 |
       0x4bdae56U)
          << 28 |
      0x2bddab9U),
     (18446744073709551615UL) / 2953},

    {(((((uintmax_t)0xb335U << 28 | 0x6a92a82U) << 28 | 0x08d4a05U) << 28 |
       0x5e1b2f2U)
          << 28 |
      0xed62f45U),
     (18446744073709551615UL) / 2957},

    {(((((uintmax_t)0x58bbU << 28 | 0x5017802U) << 28 | 0x12d5c03U) << 28 |
       0xcd328b1U)
          << 28 |
      0xa2dca9bU),
     (18446744073709551615UL) / 2963},

    {(((((uintmax_t)0x7501U << 28 | 0xa365242U) << 28 | 0x0c3e6d2U) << 28 |
       0x8f4e087U)
          << 28 |
      0x33218a9U),
     (18446744073709551615UL) / 2969},

    {(((((uintmax_t)0x18a4U << 28 | 0xbffa7c4U) << 28 | 0x073ceb6U) << 28 |
       0x800b077U)
          << 28 |
      0xf186293U),
     (18446744073709551615UL) / 2971},

    {(((((uintmax_t)0xa633U << 28 | 0x0bdd838U) << 28 | 0xae2356fU) << 28 |
       0xbd138c3U)
          << 28 |
      0xfd9c207U),
     (18446744073709551615UL) / 2999},

    {(((((uintmax_t)0xe2ffU << 28 | 0x0fc80a3U) << 28 | 0xc9104b1U) << 28 |
       0x17ccd12U)
          << 28 |
      0xae88a89U),
     (18446744073709551615UL) / 3001},

    {(((((uintmax_t)0x1183U << 28 | 0xb2cce6eU) << 28 | 0xb2b722fU) << 28 |
       0x1a1a044U)
          << 28 |
      0x046bcebU),
     (18446744073709551615UL) / 3011},

    {(((((uintmax_t)0xbfb9U << 28 | 0x73118d8U) << 28 | 0x666f154U) << 28 |
       0x8aba0b0U)
          << 28 |
      0x60541e3U),
     (18446744073709551615UL) / 3019},

    {(((((uintmax_t)0xa152U << 28 | 0xbc81bc6U) << 28 | 0xc0e90cfU) << 28 |
       0x4e808ceU)
          << 28 |
      0xa111b2fU),
     (18446744073709551615UL) / 3023},

    {(((((uintmax_t)0xaebdU << 28 | 0xa92d6f2U) << 28 | 0xef39bdbU) << 28 |
       0xec1b4faU)
          << 28 |
      0x855a475U),
     (18446744073709551615UL) / 3037},

    {(((((uintmax_t)0x890cU << 28 | 0xb62bf18U) << 28 | 0x542ece3U) << 28 |
       0xf794eb6U)
          << 28 |
      0x00d7821U),
     (18446744073709551615UL) / 3041},

    {(((((uintmax_t)0x699fU << 28 | 0xc793db6U) << 28 | 0x480a134U) << 28 |
       0xfae0d9aU)
          << 28 |
      0x11f7c59U),
     (18446744073709551615UL) / 3049},

    {(((((uintmax_t)0x14fdU << 28 | 0xe8c0055U) << 28 | 0xa3d62f0U) << 28 |
       0x06b0ccbU)
          << 28 |
      0xbac085dU),
     (18446744073709551615UL) / 3061},

    {(((((uintmax_t)0xa99cU << 28 | 0x01006adU) << 28 | 0x72efe3fU) << 28 |
       0x45076dcU)
          << 28 |
      0x3114733U),
     (18446744073709551615UL) / 3067},

    {(((((uintmax_t)0x59e0U << 28 | 0xe778f96U) << 28 | 0xe7f8aeeU) << 28 |
       0xf49bfa5U)
          << 28 |
      0x8a1a1b7U),
     (18446744073709551615UL) / 3079},

    {(((((uintmax_t)0x6edaU << 28 | 0x627b0f3U) << 28 | 0x2121a12U) << 28 |
       0xc4218beU)
          << 28 |
      0xa691fa3U),
     (18446744073709551615UL) / 3083},

    {(((((uintmax_t)0xf88aU << 28 | 0x9107df8U) << 28 | 0x35b3ebcU) << 28 |
       0x7504e3bU)
          << 28 |
      0xd5e64f1U),
     (18446744073709551615UL) / 3089},

    {(((((uintmax_t)0xcddaU << 28 | 0x9dee60fU) << 28 | 0xf969a4eU) << 28 |
       0xe21c292U)
          << 28 |
      0xbb92fadU),
     (18446744073709551615UL) / 3109},

    {(((((uintmax_t)0x4ff1U << 28 | 0x8de982bU) << 28 | 0xfe5bc34U) << 28 |
       0x338b732U)
          << 28 |
      0x7a4bacfU),
     (18446744073709551615UL) / 3119},

    {(((((uintmax_t)0x8fdfU << 28 | 0x30a40ccU) << 28 | 0xbc0053fU) << 28 |
       0xe5c0833U)
          << 28 |
      0xd6fccd1U),
     (18446744073709551615UL) / 3121},

    {(((((uintmax_t)0x0ca6U << 28 | 0x26ae799U) << 28 | 0x8087cb1U) << 28 |
       0xe707435U)
          << 28 |
      0x35203c1U),
     (18446744073709551615UL) / 3137},

    {(((((uintmax_t)0x3a1cU << 28 | 0xa6ba507U) << 28 | 0x340aaefU) << 28 |
       0xbb5dcdfU)
          << 28 |
      0xb4e43d3U),
     (18446744073709551615UL) / 3163},

    {(((((uintmax_t)0x340eU << 28 | 0x8ccfe76U) << 28 | 0xd34c8caU) << 28 |
       0x68467caU)
          << 28 |
      0x5394f9fU),
     (18446744073709551615UL) / 3167},

    {(((((uintmax_t)0xe94cU << 28 | 0xd3010cdU) << 28 | 0x82c978cU) << 28 |
       0x51c0814U)
          << 28 |
      0x08b97a1U),
     (18446744073709551615UL) / 3169},

    {(((((uintmax_t)0x69d4U << 28 | 0x0f213ccU) << 28 | 0x2c1a132U) << 28 |
       0x75a899dU)
          << 28 |
      0xfa5dd65U),
     (18446744073709551615UL) / 3181},

    {(((((uintmax_t)0xcc45U << 28 | 0x14a4d46U) << 28 | 0x1ff849eU) << 28 |
       0x674cb62U)
          << 28 |
      0xe1b78bbU),
     (18446744073709551615UL) / 3187},

    {(((((uintmax_t)0x6351U << 28 | 0xbffadd9U) << 28 | 0x54cc6a3U) << 28 |
       0x7ff5bb2U)
          << 28 |
      0xa998d47U),
     (18446744073709551615UL) / 3191},

    {(((((uintmax_t)0x77baU << 28 | 0x4e2aae1U) << 28 | 0x3a95c79U) << 28 |
       0x2a999dbU)
          << 28 |
      0x131a22bU),
     (18446744073709551615UL) / 3203},

    {(((((uintmax_t)0x8d1fU << 28 | 0x82e96c6U) << 28 | 0xa42da1bU) << 28 |
       0x48841bcU)
          << 28 |
      0x30d29b9U),
     (18446744073709551615UL) / 3209},

    {(((((uintmax_t)0x0ef5U << 28 | 0xe4c8da5U) << 28 | 0xc2683f0U) << 28 |
       0x6721d20U)
          << 28 |
      0x11d3471U),
     (18446744073709551615UL) / 3217},

    {(((((uintmax_t)0x9ccfU << 28 | 0x98fef77U) << 28 | 0xeed5293U) << 28 |
       0xfd2386dU)
          << 28 |
      0xff85ebdU),
     (18446744073709551615UL) / 3221},

    {(((((uintmax_t)0x9c06U << 28 | 0xa8de9f5U) << 28 | 0xb182e4cU) << 28 |
       0xe72f54cU)
          << 28 |
      0x07ed9b5U),
     (18446744073709551615UL) / 3229},

    {(((((uintmax_t)0xdcf5U << 28 | 0x5e929f8U) << 28 | 0x99148d6U) << 28 |
       0xd0fd3e7U)
          << 28 |
      0x1dd827bU),
     (18446744073709551615UL) / 3251},

    {(((((uintmax_t)0xcebcU << 28 | 0x664e397U) << 28 | 0x2d17d85U) << 28 |
       0x6405fb1U)
          << 28 |
      0xeed819dU),
     (18446744073709551615UL) / 3253},

    {(((((uintmax_t)0x921eU << 28 | 0x0671f84U) << 28 | 0xc15b18eU) << 28 |
       0xa8aceb7U)
          << 28 |
      0xc443989U),
     (18446744073709551615UL) / 3257},

    {(((((uintmax_t)0x4223U << 28 | 0xfa07b2bU) << 28 | 0x4830634U) << 28 |
       0xa13026fU)
          << 28 |
      0x62e5873U),
     (18446744073709551615UL) / 3259},

    {(((((uintmax_t)0x4ceeU << 28 | 0xdc3bcb1U) << 28 | 0x806e31eU) << 28 |
       0xea0208eU)
          << 28 |
      0xc0af4f7U),
     (18446744073709551615UL) / 3271},

    {(((((uintmax_t)0x969eU << 28 | 0xc4a2f55U) << 28 | 0xe703563U) << 28 |
       0x679853cU)
          << 28 |
      0xea598cbU),
     (18446744073709551615UL) / 3299},

    {(((((uintmax_t)0xd886U << 28 | 0xa176bb8U) << 28 | 0x577a9c3U) << 28 |
       0x0b3ebd6U)
          << 28 |
      0x1f2d0edU),
     (18446744073709551615UL) / 3301},

    {(((((uintmax_t)0xaaecU << 28 | 0xb97a633U) << 28 | 0xdda117eU) << 28 |
       0xb9037bcU)
          << 28 |
      0x7f43bc3U),
     (18446744073709551615UL) / 3307},

    {(((((uintmax_t)0x1a59U << 28 | 0x7af0505U) << 28 | 0xcb9c2a5U) << 28 |
       0x83e6f6cU)
          << 28 |
      0xe016411U),
     (18446744073709551615UL) / 3313},

    {(((((uintmax_t)0x76c8U << 28 | 0x6358785U) << 28 | 0x34d5cf1U) << 28 |
       0x938d895U)
          << 28 |
      0xf1a74c7U),
     (18446744073709551615UL) / 3319},

    {(((((uintmax_t)0xb781U << 28 | 0xa8058bfU) << 28 | 0xac2e880U) << 28 |
       0xcf1491cU)
          << 28 |
      0x1e81e33U),
     (18446744073709551615UL) / 3323},

    {(((((uintmax_t)0xc604U << 28 | 0x75cf8d9U) << 28 | 0x2a5f33cU) << 28 |
       0x0f12886U)
          << 28 |
      0xba8f301U),
     (18446744073709551615UL) / 3329},

    {(((((uintmax_t)0x9d2aU << 28 | 0x8009d65U) << 28 | 0x861c20eU) << 28 |
       0x4b786e0U)
          << 28 |
      0xdfcc5abU),
     (18446744073709551615UL) / 3331},

    {(((((uintmax_t)0x4053U << 28 | 0x511894dU) << 28 | 0xe137367U) << 28 |
       0x2684c93U)
          << 28 |
      0xf2d41efU),
     (18446744073709551615UL) / 3343},

    {(((((uintmax_t)0xcbfdU << 28 | 0x3f19edcU) << 28 | 0xbd615e0U) << 28 |
       0x0757badU)
          << 28 |
      0xb35c51bU),
     (18446744073709551615UL) / 3347},

    {(((((uintmax_t)0x303eU << 28 | 0x309fbe2U) << 28 | 0x6de63d6U) << 28 |
       0xd84afe6U)
          << 28 |
      0x6472edfU),
     (18446744073709551615UL) / 3359},

    {(((((uintmax_t)0x1123U << 28 | 0x440491fU) << 28 | 0x00137fbU) << 28 |
       0xbc0eedcU)
          << 28 |
      0xbbfb6e1U),
     (18446744073709551615UL) / 3361},

    {(((((uintmax_t)0x5ae7U << 28 | 0x03df7f3U) << 28 | 0x3de4825U) << 28 |
       0x0f43aa0U)
          << 28 |
      0x8a84983U),
     (18446744073709551615UL) / 3371},

    {(((((uintmax_t)0x11fcU << 28 | 0xcff5122U) << 28 | 0x3abe804U) << 28 |
       0x400e927U)
          << 28 |
      0xb1acaa5U),
     (18446744073709551615UL) / 3373},

    {(((((uintmax_t)0x80cbU << 28 | 0x0c29652U) << 28 | 0x5643d56U) << 28 |
       0x572be34U)
          << 28 |
      0xb9d3215U),
     (18446744073709551615UL) / 3389},

    {(((((uintmax_t)0xc57dU << 28 | 0xffd958dU) << 28 | 0xb3c0487U) << 28 |
       0x964ef77U)
          << 28 |
      0x81c62bfU),
     (18446744073709551615UL) / 3391},

    {(((((uintmax_t)0x9c4aU << 28 | 0x3cdce8eU) << 28 | 0xea48e29U) << 28 |
       0xed84051U)
          << 28 |
      0xc06e9afU),
     (18446744073709551615UL) / 3407},

    {(((((uintmax_t)0x0cf9U << 28 | 0xeca5ea8U) << 28 | 0xc4381b0U) << 28 |
       0x0acd11eU)
          << 28 |
      0xd3f87fdU),
     (18446744073709551615UL) / 3413},

    {(((((uintmax_t)0xfe48U << 28 | 0xee074edU) << 28 | 0x223a506U) << 28 |
       0x3078817U)
          << 28 |
      0x44152d9U),
     (18446744073709551615UL) / 3433},

    {(((((uintmax_t)0xa409U << 28 | 0x342e04eU) << 28 | 0x6187e7aU) << 28 |
       0x786459fU)
          << 28 |
      0x5c1ccc9U),
     (18446744073709551615UL) / 3449},

    {(((((uintmax_t)0xe4e5U << 28 | 0x902e357U) << 28 | 0x74c7f13U) << 28 |
       0x08125d7U)
          << 28 |
      0x4563281U),
     (18446744073709551615UL) / 3457},

    {(((((uintmax_t)0x7588U << 28 | 0x9dfe5f6U) << 28 | 0xae1e539U) << 28 |
       0x5310a48U)
          << 28 |
      0x0b3e34dU),
     (18446744073709551615UL) / 3461},

    {(((((uintmax_t)0x3784U << 28 | 0x6603fdeU) << 28 | 0xe1c3d35U) << 28 |
       0x985baa8U)
          << 28 |
      0xb202837U),
     (18446744073709551615UL) / 3463},

    {(((((uintmax_t)0xb450U << 28 | 0xa1daeecU) << 28 | 0xba5ea96U) << 28 |
       0x304a6e0U)
          << 28 |
      0x52b3223U),
     (18446744073709551615UL) / 3467},

    {(((((uintmax_t)0xfbf0U << 28 | 0xf20d6e5U) << 28 | 0x363d8bdU) << 28 |
       0x8265fc9U)
          << 28 |
      0xaf8fd45U),
     (18446744073709551615UL) / 3469},

    {(((((uintmax_t)0xeeb1U << 28 | 0x9bd44b6U) << 28 | 0x27bee1bU) << 28 |
       0x6d0b383U)
          << 28 |
      0xec58e0bU),
     (18446744073709551615UL) / 3491},

    {(((((uintmax_t)0x7386U << 28 | 0x8c53fdfU) << 28 | 0x38fe9c2U) << 28 |
       0x1a7c3b6U)
          << 28 |
      0x8b28503U),
     (18446744073709551615UL) / 3499},

    {(((((uintmax_t)0xba13U << 28 | 0x65219cfU) << 28 | 0xbb2b623U) << 28 |
       0x6fa180fU)
          << 28 |
      0xbfd6007U),
     (18446744073709551615UL) / 3511},

    {(((((uintmax_t)0xe16dU << 28 | 0xb1887adU) << 28 | 0xe4c6dc4U) << 28 |
       0x2accd44U)
          << 28 |
      0x0ed9595U),
     (18446744073709551615UL) / 3517},

    {(((((uintmax_t)0x4cf0U << 28 | 0x1ab5e49U) << 28 | 0x04b7c7aU) << 28 |
       0xcf71282U)
          << 28 |
      0x36ba3f7U),
     (18446744073709551615UL) / 3527},

    {(((((uintmax_t)0x6374U << 28 | 0x6df92e5U) << 28 | 0xaad5ff9U) << 28 |
       0x09367a9U)
          << 28 |
      0x87b9c79U),
     (18446744073709551615UL) / 3529},

    {(((((uintmax_t)0x3fc3U << 28 | 0xb6abbabU) << 28 | 0xa82dcb6U) << 28 |
       0x4efb252U)
          << 28 |
      0xbfba705U),
     (18446744073709551615UL) / 3533},

    {(((((uintmax_t)0x82b6U << 28 | 0x6ef6f53U) << 28 | 0x8c8ce98U) << 28 |
       0x0d4f5a7U)
          << 28 |
      0xe4cd25bU),
     (18446744073709551615UL) / 3539},

    {(((((uintmax_t)0x20c0U << 28 | 0x04a07f3U) << 28 | 0xdab1fe1U) << 28 |
       0xecc4ef2U)
          << 28 |
      0x7b0c37dU),
     (18446744073709551615UL) / 3541},

    {(((((uintmax_t)0xfb2aU << 28 | 0x13c68cbU) << 28 | 0xd185291U) << 28 |
       0x11aebb8U)
          << 28 |
      0x1d72653U),
     (18446744073709551615UL) / 3547},

    {(((((uintmax_t)0x8908U << 28 | 0x46d1b90U) << 28 | 0x96d9c89U) << 28 |
       0x51f985cU)
          << 28 |
      0xb2c67edU),
     (18446744073709551615UL) / 3557},

    {(((((uintmax_t)0xf7baU << 28 | 0x5f17856U) << 28 | 0xe44e8c4U) << 28 |
       0x39d4fc5U)
          << 28 |
      0x4e0b5d7U),
     (18446744073709551615UL) / 3559},

    {(((((uintmax_t)0x811cU << 28 | 0x75db26eU) << 28 | 0xd4a0de8U) << 28 |
       0x57bf318U)
          << 28 |
      0x96d533bU),
     (18446744073709551615UL) / 3571},

    {(((((uintmax_t)0x6fbcU << 28 | 0x83d31afU) << 28 | 0x37d51b6U) << 28 |
       0x14bb4cbU)
          << 28 |
      0x5023755U),
     (18446744073709551615UL) / 3581},

    {(((((uintmax_t)0xdf7dU << 28 | 0xad8c657U) << 28 | 0x4f61193U) << 28 |
       0x8a89e54U)
          << 28 |
      0x73bf1ffU),
     (18446744073709551615UL) / 3583},

    {(((((uintmax_t)0x48beU << 28 | 0xf2f618aU) << 28 | 0x70259eaU) << 28 |
       0xc481acaU)
          << 28 |
      0x34de039U),
     (18446744073709551615UL) / 3593},

    {(((((uintmax_t)0x5c8cU << 28 | 0x86d951dU) << 28 | 0x4fd8414U) << 28 |
       0xb961badU)
          << 28 |
      0xf4809a7U),
     (18446744073709551615UL) / 3607},

    {(((((uintmax_t)0x3e35U << 28 | 0xfddfd4eU) << 28 | 0xb85d876U) << 28 |
       0x784fecbU)
          << 28 |
      0xa352435U),
     (18446744073709551615UL) / 3613},

    {(((((uintmax_t)0x3f46U << 28 | 0x480d05dU) << 28 | 0xfde06efU) << 28 |
       0xa689bb5U)
          << 28 |
      0x8aef5e1U),
     (18446744073709551615UL) / 3617},

    {(((((uintmax_t)0xa7f5U << 28 | 0x427da20U) << 28 | 0x5cb49b2U) << 28 |
       0xb2c4db9U)
          << 28 |
      0xc3a8197U),
     (18446744073709551615UL) / 3623},

    {(((((uintmax_t)0x1756U << 28 | 0x39f44bdU) << 28 | 0xcbf7d25U) << 28 |
       0x03bc992U)
          << 28 |
      0x279f8cfU),
     (18446744073709551615UL) / 3631},

    {(((((uintmax_t)0xf7b1U << 28 | 0xba9905dU) << 28 | 0x798f3d2U) << 28 |
       0xab9aec5U)
          << 28 |
      0xca1541dU),
     (18446744073709551615UL) / 3637},

    {(((((uintmax_t)0x0ec1U << 28 | 0xcf3b3d3U) << 28 | 0x4ea253eU) << 28 |
       0x78ba146U)
          << 28 |
      0x0f99af3U),
     (18446744073709551615UL) / 3643},

    {(((((uintmax_t)0x694bU << 28 | 0xe954ddeU) << 28 | 0xd63b30aU) << 28 |
       0x0142657U)
          << 28 |
      0x2cfcb63U),
     (18446744073709551615UL) / 3659},

    {(((((uintmax_t)0xd628U << 28 | 0x9612455U) << 28 | 0x13dfebeU) << 28 |
       0xa857968U)
          << 28 |
      0xf3cbd67U),
     (18446744073709551615UL) / 3671},

    {(((((uintmax_t)0x63bcU << 28 | 0xcfb30dbU) << 28 | 0xaffca78U) << 28 |
       0xdb213eeU)
          << 28 |
      0xfe659e9U),
     (18446744073709551615UL) / 3673},

    {(((((uintmax_t)0x7cf8U << 28 | 0xb08fb32U) << 28 | 0x328ba96U) << 28 |
       0x3e8541aU)
          << 28 |
      0x74d35f5U),
     (18446744073709551615UL) / 3677},

    {(((((uintmax_t)0x99e7U << 28 | 0xb98849cU) << 28 | 0xbfb489eU) << 28 |
       0x22d1527U)
          << 28 |
      0x76f2e43U),
     (18446744073709551615UL) / 3691},

    {(((((uintmax_t)0x1767U << 28 | 0xa90721dU) << 28 | 0xc686c05U) << 28 |
       0xd10d39dU)
          << 28 |
      0x1e1f291U),
     (18446744073709551615UL) / 3697},

    {(((((uintmax_t)0x817cU << 28 | 0xb6e3047U) << 28 | 0xeff3d37U) << 28 |
       0x4468dccU)
          << 28 |
      0xaced1ddU),
     (18446744073709551615UL) / 3701},

    {(((((uintmax_t)0x916dU << 28 | 0x896be15U) << 28 | 0xac3548dU) << 28 |
       0x145c7d1U)
          << 28 |
      0x10c5ad5U),
     (18446744073709551615UL) / 3709},

    {(((((uintmax_t)0x50e1U << 28 | 0xc7f7bd5U) << 28 | 0xdf5f332U) << 28 |
       0x51a39f5U)
          << 28 |
      0xacb5737U),
     (18446744073709551615UL) / 3719},

    {(((((uintmax_t)0xc1e7U << 28 | 0xf58f36eU) << 28 | 0x1b567a6U) << 28 |
       0x6e50171U)
          << 28 |
      0x443506fU),
     (18446744073709551615UL) / 3727},

    {(((((uintmax_t)0xe72cU << 28 | 0xc7f8de3U) << 28 | 0x0f6e112U) << 28 |
       0x4f69ad9U)
          << 28 |
      0x1dd4cbdU),
     (18446744073709551615UL) / 3733},

    {(((((uintmax_t)0x81e2U << 28 | 0x02e029aU) << 28 | 0x0d485ecU) << 28 |
       0x24f8f2aU)
          << 28 |
      0x61a2793U),
     (18446744073709551615UL) / 3739},

    {(((((uintmax_t)0x66a5U << 28 | 0x216bc00U) << 28 | 0x45b35b4U) << 28 |
       0x72148e6U)
          << 28 |
      0x56b7a51U),
     (18446744073709551615UL) / 3761},

    {(((((uintmax_t)0x3442U << 28 | 0x9973536U) << 28 | 0x29ba00aU) << 28 |
       0xdf9570eU)
          << 28 |
      0x1142f07U),
     (18446744073709551615UL) / 3767},

    {(((((uintmax_t)0xc952U << 28 | 0x869f58aU) << 28 | 0x38eb489U) << 28 |
       0xbf33b06U)
          << 28 |
      0x5119789U),
     (18446744073709551615UL) / 3769},

    {(((((uintmax_t)0xc462U << 28 | 0xe78b7b7U) << 28 | 0xebf2b8fU) << 28 |
       0x0149803U)
          << 28 |
      0xcb291ebU),
     (18446744073709551615UL) / 3779},

    {(((((uintmax_t)0xa7b8U << 28 | 0x300e09dU) << 28 | 0xa9be883U) << 28 |
       0x34b63afU)
          << 28 |
      0xd190a31U),
     (18446744073709551615UL) / 3793},

    {(((((uintmax_t)0x678fU << 28 | 0x45607afU) << 28 | 0xa226292U) << 28 |
       0x0908d50U)
          << 28 |
      0xd6aba7dU),
     (18446744073709551615UL) / 3797},

    {(((((uintmax_t)0x3066U << 28 | 0x51b882dU) << 28 | 0xc63e557U) << 28 |
       0xd8b018cU)
          << 28 |
      0x5a33d53U),
     (18446744073709551615UL) / 3803},

    {(((((uintmax_t)0x03f3U << 28 | 0xf0b9737U) << 28 | 0x01682eaU) << 28 |
       0x1773092U)
          << 28 |
      0xdc27ee5U),
     (18446744073709551615UL) / 3821},

    {(((((uintmax_t)0x824fU << 28 | 0x6b12f35U) << 28 | 0x80e76caU) << 28 |
       0xe5f38b7U)
          << 28 |
      0xbf2e00fU),
     (18446744073709551615UL) / 3823},

    {(((((uintmax_t)0xba8aU << 28 | 0x4084821U) << 28 | 0xa94f02bU) << 28 |
       0xd02df34U)
          << 28 |
      0xf695349U),
     (18446744073709551615UL) / 3833},

    {(((((uintmax_t)0x1f9bU << 28 | 0xea70762U) << 28 | 0xf3f48ddU) << 28 |
       0xfecd5beU)
          << 28 |
      0x62e2eb7U),
     (18446744073709551615UL) / 3847},

    {(((((uintmax_t)0xb7acU << 28 | 0x817ee73U) << 28 | 0x45119dbU) << 28 |
       0xf849ebeU)
          << 28 |
      0xc96c4a3U),
     (18446744073709551615UL) / 3851},

    {(((((uintmax_t)0xf8c2U << 28 | 0x0286585U) << 28 | 0xe14dcdaU) << 28 |
       0x31d4d01U)
          << 28 |
      0x87357c5U),
     (18446744073709551615UL) / 3853},

    {(((((uintmax_t)0x7727U << 28 | 0x2a58ab3U) << 28 | 0xdb276e3U) << 28 |
       0x4e21cc2U)
          << 28 |
      0xd5418a7U),
     (18446744073709551615UL) / 3863},

    {(((((uintmax_t)0x61caU << 28 | 0x83edc68U) << 28 | 0xdb38968U) << 28 |
       0xca5137aU)
          << 28 |
      0x9e574adU),
     (18446744073709551615UL) / 3877},

    {(((((uintmax_t)0x74f3U << 28 | 0x8879e60U) << 28 | 0x2c53a3eU) << 28 |
       0xaa0d0f8U)
          << 28 |
      0x04bfd19U),
     (18446744073709551615UL) / 3881},

    {(((((uintmax_t)0x1c6fU << 28 | 0xe7c6996U) << 28 | 0x04df055U) << 28 |
       0x4fb753cU)
          << 28 |
      0xc20e9d1U),
     (18446744073709551615UL) / 3889},

    {(((((uintmax_t)0x374dU << 28 | 0x408a62aU) << 28 | 0xda31679U) << 28 |
       0x7afcca1U)
          << 28 |
      0x300756bU),
     (18446744073709551615UL) / 3907},

    {(((((uintmax_t)0xc8e2U << 28 | 0xbdb1524U) << 28 | 0x758f48bU) << 28 |
       0x8d950b5U)
          << 28 |
      0x2eeea77U),
     (18446744073709551615UL) / 3911},

    {(((((uintmax_t)0xbfc1U << 28 | 0x421336fU) << 28 | 0x6ea5dfbU) << 28 |
       0x6cd166aU)
          << 28 |
      0xcabc185U),
     (18446744073709551615UL) / 3917},

    {(((((uintmax_t)0x7daeU << 28 | 0x58b5560U) << 28 | 0x7b5454eU) << 28 |
       0xb6c5ed9U)
          << 28 |
      0x437a7afU),
     (18446744073709551615UL) / 3919},

    {(((((uintmax_t)0xf1f8U << 28 | 0x4cbdc3dU) << 28 | 0x573f5d1U) << 28 |
       0xeddbd91U)
          << 28 |
      0xb790cdbU),
     (18446744073709551615UL) / 3923},

    {(((((uintmax_t)0xa6abU << 28 | 0x9f4ec63U) << 28 | 0x4c6db93U) << 28 |
       0xd714ea4U)
          << 28 |
      0xd8948e9U),
     (18446744073709551615UL) / 3929},

    {(((((uintmax_t)0x8198U << 28 | 0x742e1b7U) << 28 | 0xb68a73cU) << 28 |
       0xa13ed81U)
          << 28 |
      0x45188d3U),
     (18446744073709551615UL) / 3931},

    {(((((uintmax_t)0x5ab3U << 28 | 0x52c7947U) << 28 | 0xbe09382U) << 28 |
       0x9086016U)
          << 28 |
      0xda89c57U),
     (18446744073709551615UL) / 3943},

    {(((((uintmax_t)0xec69U << 28 | 0x9751239U) << 28 | 0xb9900d7U) << 28 |
       0xda1f432U)
          << 28 |
      0x124a543U),
     (18446744073709551615UL) / 3947},

    {(((((uintmax_t)0xa4e1U << 28 | 0x58dc715U) << 28 | 0x1a22b7eU) << 28 |
       0xad55816U)
          << 28 |
      0x32fb07fU),
     (18446744073709551615UL) / 3967},

    {(((((uintmax_t)0x4cd1U << 28 | 0xba8fa08U) << 28 | 0x1613a35U) << 28 |
       0x443837fU)
          << 28 |
      0x63ec3bdU),
     (18446744073709551615UL) / 3989},

    {(((((uintmax_t)0x48afU << 28 | 0x92759a4U) << 28 | 0x3f37589U) << 28 |
       0xe2b200eU)
          << 28 |
      0x5519461U),
     (18446744073709551615UL) / 4001},

    {(((((uintmax_t)0x9293U << 28 | 0xfc29b25U) << 28 | 0xcbafee9U) << 28 |
       0xae44f0bU)
          << 28 |
      0x7289c0bU),
     (18446744073709551615UL) / 4003},

    {(((((uintmax_t)0xc02cU << 28 | 0xfa2fa91U) << 28 | 0xcaf9094U) << 28 |
       0x387a277U)
          << 28 |
      0xb9fa817U),
     (18446744073709551615UL) / 4007},

    {(((((uintmax_t)0x15c0U << 28 | 0xd8627efU) << 28 | 0x28a2cc8U) << 28 |
       0x4f1a58aU)
          << 28 |
      0xbfc2c25U),
     (18446744073709551615UL) / 4013},

    {(((((uintmax_t)0x1143U << 28 | 0x12ca6e3U) << 28 | 0x2522b71U) << 28 |
       0x101d8e3U)
          << 28 |
      0xc83377bU),
     (18446744073709551615UL) / 4019},

    {(((((uintmax_t)0xcfadU << 28 | 0x7d3b04aU) << 28 | 0x5c91ec0U) << 28 |
       0x24abe5cU)
          << 28 |
      0x50ba69dU),
     (18446744073709551615UL) / 4021},

    {(((((uintmax_t)0x9d46U << 28 | 0x3eef687U) << 28 | 0x26d7815U) << 28 |
       0xde4eb36U)
          << 28 |
      0x5a65d73U),
     (18446744073709551615UL) / 4027},

    {(((((uintmax_t)0xe98eU << 28 | 0x1152e37U) << 28 | 0xc3cf309U) << 28 |
       0xed28a76U)
          << 28 |
      0xbcca931U),
     (18446744073709551615UL) / 4049},

    {(((((uintmax_t)0xa002U << 28 | 0x05affefU) << 28 | 0xd280081U) << 28 |
       0x6bffbf4U)
          << 28 |
      0xa00205bU),
     (18446744073709551615UL) / 4051},

    {(((((uintmax_t)0x1d87U << 28 | 0xfb74ed0U) << 28 | 0x1b4271fU) << 28 |
       0x5c71543U)
          << 28 |
      0xd558069U),
     (18446744073709551615UL) / 4057},

    {(((((uintmax_t)0x7051U << 28 | 0x751852fU) << 28 | 0x74370f2U) << 28 |
       0x5c64d0eU)
          << 28 |
      0xc53b859U),
     (18446744073709551615UL) / 4073},

    {(((((uintmax_t)0x88e1U << 28 | 0x6f867eeU) << 28 | 0x6d54296U) << 28 |
       0xc02c2efU)
          << 28 |
      0x1e0ff0fU),
     (18446744073709551615UL) / 4079},

    {(((((uintmax_t)0xe8e8U << 28 | 0xc8bebb9U) << 28 | 0xaa05219U) << 28 |
       0xa804816U)
          << 28 |
      0x870a333U),
     (18446744073709551615UL) / 4091},

    {(((((uintmax_t)0xc605U << 28 | 0x20f62e2U) << 28 | 0x8a79f6dU) << 28 |
       0xe49add0U)
          << 28 |
      0x971c555U),
     (18446744073709551615UL) / 4093},

    {(((((uintmax_t)0x46c2U << 28 | 0xbb7cd89U) << 28 | 0x7639d52U) << 28 |
       0x8087e68U)
          << 28 |
      0x4c71aabU),
     (18446744073709551615UL) / 4099},

    {(((((uintmax_t)0xfc73U << 28 | 0x53e15cbU) << 28 | 0x9127ea9U) << 28 |
       0x4152c26U)
          << 28 |
      0x9bcdeefU),
     (18446744073709551615UL) / 4111},

    {(((((uintmax_t)0x3d78U << 28 | 0xe5c2d68U) << 28 | 0x0673803U) << 28 |
       0x79450a3U)
          << 28 |
      0xc2b6bdfU),
     (18446744073709551615UL) / 4127},

    {(((((uintmax_t)0x4a66U << 28 | 0x8c7e3baU) << 28 | 0x4fbb8d2U) << 28 |
       0xcd38bafU)
          << 28 |
      0xe5373e1U),
     (18446744073709551615UL) / 4129},

    {(((((uintmax_t)0x616eU << 28 | 0xb008eb5U) << 28 | 0xfb2b2c2U) << 28 |
       0x9df2beaU)
          << 28 |
      0x71d8badU),
     (18446744073709551615UL) / 4133},

    {(((((uintmax_t)0x12bdU << 28 | 0xa25ba9aU) << 28 | 0x80c5ec1U) << 28 |
       0x5862775U)
          << 28 |
      0xf302e83U),
     (18446744073709551615UL) / 4139},

    {(((((uintmax_t)0x98dfU << 28 | 0x642b264U) << 28 | 0x7a0d310U) << 28 |
       0x16af2feU)
          << 28 |
      0x55ede09U),
     (18446744073709551615UL) / 4153},

    {(((((uintmax_t)0xcc45U << 28 | 0x381a1c7U) << 28 | 0x3878b3dU) << 28 |
       0x26dbd9dU)
          << 28 |
      0x1910715U),
     (18446744073709551615UL) / 4157},

    {(((((uintmax_t)0x1344U << 28 | 0x23b36d8U) << 28 | 0x0d4ba62U) << 28 |
       0x1dab2dfU)
          << 28 |
      0xaf3dfbfU),
     (18446744073709551615UL) / 4159},

    {(((((uintmax_t)0xd614U << 28 | 0x399c587U) << 28 | 0xff827b6U) << 28 |
       0xf1d7ac2U)
          << 28 |
      0x87338b1U),
     (18446744073709551615UL) / 4177},

    {(((((uintmax_t)0x5c04U << 28 | 0x24ce751U) << 28 | 0xf620c8dU) << 28 |
       0x9e9f0c3U)
          << 28 |
      0xf9e7fd9U),
     (18446744073709551615UL) / 4201},

    {(((((uintmax_t)0xa4cfU << 28 | 0x6d1fac5U) << 28 | 0x93e8e60U) << 28 |
       0xa93f876U)
          << 28 |
      0x2e914bbU),
     (18446744073709551615UL) / 4211},

    {(((((uintmax_t)0x16b4U << 28 | 0x4c7d8a9U) << 28 | 0x7e358b1U) << 28 |
       0x4371f24U)
          << 28 |
      0x7c159c9U),
     (18446744073709551615UL) / 4217},

    {(((((uintmax_t)0x7d2dU << 28 | 0xb0c132cU) << 28 | 0x9926a6dU) << 28 |
       0xd3b4844U)
          << 28 |
      0x71d4eb3U),
     (18446744073709551615UL) / 4219},

    {(((((uintmax_t)0xc12aU << 28 | 0x5044c45U) << 28 | 0xfa4f4cdU) << 28 |
       0x172f470U)
          << 28 |
      0x1c1684dU),
     (18446744073709551615UL) / 4229},

    {(((((uintmax_t)0x3b6aU << 28 | 0xabf51beU) << 28 | 0x4a6c103U) << 28 |
       0x72e686eU)
          << 28 |
      0xd8bb537U),
     (18446744073709551615UL) / 4231},

    {(((((uintmax_t)0x0b0bU << 28 | 0xe43ba38U) << 28 | 0x61105bcU) << 28 |
       0x07f7ca6U)
          << 28 |
      0x5c5b071U),
     (18446744073709551615UL) / 4241},

    {(((((uintmax_t)0x1841U << 28 | 0x2954499U) << 28 | 0xbb949abU) << 28 |
       0x2b6170cU)
          << 28 |
      0x3f78d9bU),
     (18446744073709551615UL) / 4243},

    {(((((uintmax_t)0x67e4U << 28 | 0x8d552c3U) << 28 | 0xde0d1f3U) << 28 |
       0xd74f461U)
          << 28 |
      0xfe6f5b5U),
     (18446744073709551615UL) / 4253},

    {(((((uintmax_t)0xa030U << 28 | 0x161ea7bU) << 28 | 0x38ae8dbU) << 28 |
       0xc13f4b3U)
          << 28 |
      0x1f3230bU),
     (18446744073709551615UL) / 4259},

    {(((((uintmax_t)0xf2a9U << 28 | 0x8b90bb7U) << 28 | 0x2eec1d1U) << 28 |
       0x420716eU)
          << 28 |
      0x3f1572dU),
     (18446744073709551615UL) / 4261},

    {(((((uintmax_t)0xa0c1U << 28 | 0xb926e68U) << 28 | 0x69f8ed5U) << 28 |
       0xbe2fd4dU)
          << 28 |
      0x805464fU),
     (18446744073709551615UL) / 4271},

    {(((((uintmax_t)0xc4edU << 28 | 0x7ccb753U) << 28 | 0xef76ec6U) << 28 |
       0x8b97c13U)
          << 28 |
      0x6943851U),
     (18446744073709551615UL) / 4273},

    {(((((uintmax_t)0x5305U << 28 | 0xada2a32U) << 28 | 0xce35e9eU) << 28 |
       0x27918afU)
          << 28 |
      0x7cfb473U),
     (18446744073709551615UL) / 4283},

    {(((((uintmax_t)0x0b38U << 28 | 0xa4bcd9fU) << 28 | 0xaa0cc5eU) << 28 |
       0xc8ab6c3U)
          << 28 |
      0x6ac7f41U),
     (18446744073709551615UL) / 4289},

    {(((((uintmax_t)0xc8f3U << 28 | 0x8c6bf3dU) << 28 | 0x8adf696U) << 28 |
       0x4076331U)
          << 28 |
      0xdd90979U),
     (18446744073709551615UL) / 4297},

    {(((((uintmax_t)0x3ed4U << 28 | 0xdeb0e60U) << 28 | 0x6fb3530U) << 28 |
       0x198eff7U)
          << 28 |
      0x7b002d7U),
     (18446744073709551615UL) / 4327},

    {(((((uintmax_t)0xe304U << 28 | 0x8b8a2eaU) << 28 | 0x19da93aU) << 28 |
       0xf7cb958U)
          << 28 |
      0x3ece011U),
     (18446744073709551615UL) / 4337},

    {(((((uintmax_t)0x63b5U << 28 | 0xa908ca7U) << 28 | 0xcb9bb34U) << 28 |
       0xce06f64U)
          << 28 |
      0x3d9883bU),
     (18446744073709551615UL) / 4339},

    {(((((uintmax_t)0xd58fU << 28 | 0x1940b11U) << 28 | 0x0300879U) << 28 |
       0xf767e52U)
          << 28 |
      0x8708c55U),
     (18446744073709551615UL) / 4349},

    {(((((uintmax_t)0xa973U << 28 | 0xcee1454U) << 28 | 0x5fa7a18U) << 28 |
       0x5332d2eU)
          << 28 |
      0xf2313cdU),
     (18446744073709551615UL) / 4357},

    {(((((uintmax_t)0xc544U << 28 | 0x1f37189U) << 28 | 0x5bd3a43U) << 28 |
       0xb611b84U)
          << 28 |
      0xc8332a3U),
     (18446744073709551615UL) / 4363},

    {(((((uintmax_t)0xc201U << 28 | 0x49b4038U) << 28 | 0x330c3c2U) << 28 |
       0xe215e4fU)
          << 28 |
      0x43bb63dU),
     (18446744073709551615UL) / 4373},

    {(((((uintmax_t)0xfcf7U << 28 | 0xe56a2a8U) << 28 | 0xf4dd4f9U) << 28 |
       0x4b9dd22U)
          << 28 |
      0xce44e97U),
     (18446744073709551615UL) / 4391},

    {(((((uintmax_t)0xc364U << 28 | 0x3300862U) << 28 | 0x47258d8U) << 28 |
       0x95834a1U)
          << 28 |
      0xdb166a5U),
     (18446744073709551615UL) / 4397},

    {(((((uintmax_t)0xa5f1U << 28 | 0xb76bd2bU) << 28 | 0x5f83834U) << 28 |
       0x7d2f16dU)
          << 28 |
      0x19b8d09U),
     (18446744073709551615UL) / 4409},

    {(((((uintmax_t)0x9b97U << 28 | 0x89df750U) << 28 | 0x6e4081bU) << 28 |
       0x54d4dc4U)
          << 28 |
      0x5b7d98dU),
     (18446744073709551615UL) / 4421},

    {(((((uintmax_t)0x612dU << 28 | 0xe5f44efU) << 28 | 0x2839e11U) << 28 |
       0x7ac30d9U)
          << 28 |
      0xa044877U),
     (18446744073709551615UL) / 4423},

    {(((((uintmax_t)0x9811U << 28 | 0x1015369U) << 28 | 0x6e9ec0eU) << 28 |
       0x10b78a6U)
          << 28 |
      0x7a526e9U),
     (18446744073709551615UL) / 4441},

    {(((((uintmax_t)0xa197U << 28 | 0x1cf4c64U) << 28 | 0x2a99792U) << 28 |
       0xda68a81U)
          << 28 |
      0x8688a9fU),
     (18446744073709551615UL) / 4447},

    {(((((uintmax_t)0x0f02U << 28 | 0xeeeb01cU) << 28 | 0x870bacfU) << 28 |
       0x2b6c87fU)
          << 28 |
      0x741f84bU),
     (18446744073709551615UL) / 4451},

    {(((((uintmax_t)0x8d2eU << 28 | 0x94fe559U) << 28 | 0x50d09d2U) << 28 |
       0x64f9bd4U)
          << 28 |
      0x1e18ed9U),
     (18446744073709551615UL) / 4457},

    {(((((uintmax_t)0xa84bU << 28 | 0xb74450fU) << 28 | 0xe38c973U) << 28 |
       0x3cbeaa9U)
          << 28 |
      0x7166d8fU),
     (18446744073709551615UL) / 4463},

    {(((((uintmax_t)0x495aU << 28 | 0xe4dcfaaU) << 28 | 0xfd8b1c9U) << 28 |
       0xf475b02U)
          << 28 |
      0x1d22e81U),
     (18446744073709551615UL) / 4481},

    {(((((uintmax_t)0x6837U << 28 | 0x46fb256U) << 28 | 0x74d6073U) << 28 |
       0x1f76f2eU)
          << 28 |
      0xc4c852bU),
     (18446744073709551615UL) / 4483},

    {(((((uintmax_t)0xf6ffU << 28 | 0x5f8d222U) << 28 | 0x12931daU) << 28 |
       0xf6f0c97U)
          << 28 |
      0x8f69945U),
     (18446744073709551615UL) / 4493},

    {(((((uintmax_t)0xd49aU << 28 | 0xb982b2bU) << 28 | 0x1c92174U) << 28 |
       0x9c8ad20U)
          << 28 |
      0xc61ec93U),
     (18446744073709551615UL) / 4507},

    {(((((uintmax_t)0x2f4fU << 28 | 0x04983ffU) << 28 | 0xc5e9e09U) << 28 |
       0x307ff8bU)
          << 28 |
      0xd3c1261U),
     (18446744073709551615UL) / 4513},

    {(((((uintmax_t)0xadefU << 28 | 0x566dd5fU) << 28 | 0x282eb33U) << 28 |
       0x4a69fb5U)
          << 28 |
      0xa486e2dU),
     (18446744073709551615UL) / 4517},

    {(((((uintmax_t)0xd118U << 28 | 0x137ccc9U) << 28 | 0xe647f1fU) << 28 |
       0x36c7bf3U)
          << 28 |
      0x1578617U),
     (18446744073709551615UL) / 4519},

    {(((((uintmax_t)0x01cfU << 28 | 0xa9f7f67U) << 28 | 0xdc3aa31U) << 28 |
       0xebbcc27U)
          << 28 |
      0x9ea6103U),
     (18446744073709551615UL) / 4523},

    {(((((uintmax_t)0x9c1fU << 28 | 0x4da38ddU) << 28 | 0x2657442U) << 28 |
       0xe2aad11U)
          << 28 |
      0x9f466ebU),
     (18446744073709551615UL) / 4547},

    {(((((uintmax_t)0x41acU << 28 | 0x994bcdcU) << 28 | 0xd3d2c10U) << 28 |
       0x6ec05a0U)
          << 28 |
      0xab1450dU),
     (18446744073709551615UL) / 4549},

    {(((((uintmax_t)0x556dU << 28 | 0x480324aU) << 28 | 0x6d002b1U) << 28 |
       0xb38db92U)
          << 28 |
      0xa99e731U),
     (18446744073709551615UL) / 4561},

    {(((((uintmax_t)0x9c39U << 28 | 0x2ce6456U) << 28 | 0x52d9278U) << 28 |
       0x4ae377eU)
          << 28 |
      0x67071e7U),
     (18446744073709551615UL) / 4567},

    {(((((uintmax_t)0xcdc8U << 28 | 0x79fec56U) << 28 | 0x781893eU) << 28 |
       0x9e1471bU)
          << 28 |
      0xa6671d7U),
     (18446744073709551615UL) / 4583},

    {(((((uintmax_t)0x375eU << 28 | 0xf621586U) << 28 | 0x1b19982U) << 28 |
       0xc29b59dU)
          << 28 |
      0x4d73d0fU),
     (18446744073709551615UL) / 4591},

    {(((((uintmax_t)0x75c7U << 28 | 0xfa35597U) << 28 | 0xdcce0c2U) << 28 |
       0x3dd0712U)
          << 28 |
      0x8b5525dU),
     (18446744073709551615UL) / 4597},

    {(((((uintmax_t)0x4083U << 28 | 0xb2ce1ccU) << 28 | 0xf1d164dU) << 28 |
       0x4e5ce0eU)
          << 28 |
      0x9245133U),
     (18446744073709551615UL) / 4603},

    {(((((uintmax_t)0x9d9cU << 28 | 0x64622aeU) << 28 | 0x10824c8U) << 28 |
       0xfd1057cU)
          << 28 |
      0x09f8cc5U),
     (18446744073709551615UL) / 4621},

    {(((((uintmax_t)0x02b4U << 28 | 0x87cfdbcU) << 28 | 0x89230eaU) << 28 |
       0x1516e94U)
          << 28 |
      0xf394035U),
     (18446744073709551615UL) / 4637},

    {(((((uintmax_t)0x32e1U << 28 | 0x4328c7fU) << 28 | 0xce8e0b5U) << 28 |
       0xe3319c5U)
          << 28 |
      0x64ee9dfU),
     (18446744073709551615UL) / 4639},

    {(((((uintmax_t)0xf929U << 28 | 0xbd10602U) << 28 | 0x894a612U) << 28 |
       0x6a69f90U)
          << 28 |
      0xd822d8bU),
     (18446744073709551615UL) / 4643},

    {(((((uintmax_t)0xa0bcU << 28 | 0x8b6d15cU) << 28 | 0x03be950U) << 28 |
       0x1ed6348U)
          << 28 |
      0x857aa19U),
     (18446744073709551615UL) / 4649},

    {(((((uintmax_t)0xf169U << 28 | 0xf4a94f1U) << 28 | 0x86231deU) << 28 |
       0x344a324U)
          << 28 |
      0xeee1c83U),
     (18446744073709551615UL) / 4651},

    {(((((uintmax_t)0xafdaU << 28 | 0x2e10d23U) << 28 | 0x58ab11dU) << 28 |
       0xd9690cbU)
          << 28 |
      0x2c406d1U),
     (18446744073709551615UL) / 4657},

    {(((((uintmax_t)0x70eeU << 28 | 0x0c3017bU) << 28 | 0x7881908U) << 28 |
       0xd6c5178U)
          << 28 |
      0xd5e4387U),
     (18446744073709551615UL) / 4663},

    {(((((uintmax_t)0x2b47U << 28 | 0x45bd0e3U) << 28 | 0x051844cU) << 28 |
       0xea4050aU)
          << 28 |
      0x3e8fdc1U),
     (18446744073709551615UL) / 4673},

    {(((((uintmax_t)0x5aa8U << 28 | 0x9fc2b8dU) << 28 | 0x1a891c1U) << 28 |
       0x14a06acU)
          << 28 |
      0xc83f777U),
     (18446744073709551615UL) / 4679},

    {(((((uintmax_t)0x834dU << 28 | 0x385f9c7U) << 28 | 0x5a89320U) << 28 |
       0xb060ebcU)
          << 28 |
      0x0ea01dbU),
     (18446744073709551615UL) / 4691},

    {(((((uintmax_t)0xcbb0U << 28 | 0x86fea3aU) << 28 | 0x06a40feU) << 28 |
       0x50045acU)
          << 28 |
      0xb78c99fU),
     (18446744073709551615UL) / 4703},

    {(((((uintmax_t)0x4bceU << 28 | 0xc35242bU) << 28 | 0x29eaa29U) << 28 |
       0x1a68705U)
          << 28 |
      0xb196e91U),
     (18446744073709551615UL) / 4721},

    {(((((uintmax_t)0x1cf1U << 28 | 0xbea1a20U) << 28 | 0x324cdc1U) << 28 |
       0x042c724U)
          << 28 |
      0x273e2bbU),
     (18446744073709551615UL) / 4723},

    {(((((uintmax_t)0x530aU << 28 | 0xaa16d83U) << 28 | 0x622522cU) << 28 |
       0xee680bbU)
          << 28 |
      0x165b7c9U),
     (18446744073709551615UL) / 4729},

    {(((((uintmax_t)0x6dbeU << 28 | 0xc4fd598U) << 28 | 0x42343fdU) << 28 |
       0x2ff9f12U)
          << 28 |
      0xe0776d5U),
     (18446744073709551615UL) / 4733},

    {(((((uintmax_t)0x9327U << 28 | 0xd1e0357U) << 28 | 0x3cba016U) << 28 |
       0x6a5da63U)
          << 28 |
      0xaf2cc6fU),
     (18446744073709551615UL) / 4751},

    {(((((uintmax_t)0xfe7eU << 28 | 0x69c1b53U) << 28 | 0xa5d7dedU) << 28 |
       0xd16a593U)
          << 28 |
      0x0408d27U),
     (18446744073709551615UL) / 4759},

    {(((((uintmax_t)0xdba8U << 28 | 0x6fc17c3U) << 28 | 0xa04d12aU) << 28 |
       0xdf30c26U)
          << 28 |
      0x528844fU),
     (18446744073709551615UL) / 4783},

    {(((((uintmax_t)0x4928U << 28 | 0x7ba43b4U) << 28 | 0x0f9d99aU) << 28 |
       0x48d6572U)
          << 28 |
      0xb5eec7bU),
     (18446744073709551615UL) / 4787},

    {(((((uintmax_t)0xfd7cU << 28 | 0xd1c2bd5U) << 28 | 0x72fbc6eU) << 28 |
       0x8bf2877U)
          << 28 |
      0x503cb9dU),
     (18446744073709551615UL) / 4789},

    {(((((uintmax_t)0x1951U << 28 | 0x21b3d5eU) << 28 | 0x975e0eaU) << 28 |
       0x27a191aU)
          << 28 |
      0x7045389U),
     (18446744073709551615UL) / 4793},

    {(((((uintmax_t)0xced1U << 28 | 0x00e827bU) << 28 | 0x0325b6eU) << 28 |
       0xb091f34U)
          << 28 |
      0xdd45d3fU),
     (18446744073709551615UL) / 4799},

    {(((((uintmax_t)0xe394U << 28 | 0x4a02e12U) << 28 | 0x05dd8dcU) << 28 |
       0x8a6cabbU)
          << 28 |
      0x2937d41U),
     (18446744073709551615UL) / 4801},

    {(((((uintmax_t)0x3e2dU << 28 | 0xa2eb33fU) << 28 | 0x746e6bcU) << 28 |
       0x2f04f25U)
          << 28 |
      0x4922a05U),
     (18446744073709551615UL) / 4813},

    {(((((uintmax_t)0xf205U << 28 | 0xd890fadU) << 28 | 0x84cf441U) << 28 |
       0x431f4d6U)
          << 28 |
      0xeb38631U),
     (18446744073709551615UL) / 4817},

    {(((((uintmax_t)0x7974U << 28 | 0xa2271b8U) << 28 | 0x09c017bU) << 28 |
       0xd717435U)
          << 28 |
      0xa08291fU),
     (18446744073709551615UL) / 4831},

    {(((((uintmax_t)0xf434U << 28 | 0x0837312U) << 28 | 0x2b4a342U) << 28 |
       0x32df9c9U)
          << 28 |
      0x1fc1a55U),
     (18446744073709551615UL) / 4861},

    {(((((uintmax_t)0x4c78U << 28 | 0x09ab985U) << 28 | 0xc13f8a4U) << 28 |
       0x651e1d5U)
          << 28 |
      0x382eab7U),
     (18446744073709551615UL) / 4871},

    {(((((uintmax_t)0x9273U << 28 | 0x60376e4U) << 28 | 0x8c0bf7cU) << 28 |
       0xfb5409dU)
          << 28 |
      0xe4cf3c5U),
     (18446744073709551615UL) / 4877},

    {(((((uintmax_t)0x47a1U << 28 | 0xbf627e6U) << 28 | 0x7276dcdU) << 28 |
       0xd636fb0U)
          << 28 |
      0x68b9929U),
     (18446744073709551615UL) / 4889},

    {(((((uintmax_t)0x3f55U << 28 | 0x93b5db8U) << 28 | 0xe2d01eeU) << 28 |
       0x8f95e74U)
          << 28 |
      0x0462c97U),
     (18446744073709551615UL) / 4903},

    {(((((uintmax_t)0x29aaU << 28 | 0xc9d12b8U) << 28 | 0xb650349U) << 28 |
       0x0f97b3aU)
          << 28 |
      0x758b4a5U),
     (18446744073709551615UL) / 4909},

    {(((((uintmax_t)0x3c51U << 28 | 0x65394caU) << 28 | 0x8d3eb64U) << 28 |
       0x1431563U)
          << 28 |
      0xc441287U),
     (18446744073709551615UL) / 4919},

    {(((((uintmax_t)0xf258U << 28 | 0x91c808bU) << 28 | 0x8d292b7U) << 28 |
       0x43dad3eU)
          << 28 |
      0xc45916bU),
     (18446744073709551615UL) / 4931},

    {(((((uintmax_t)0x708fU << 28 | 0xa57e92aU) << 28 | 0x8098c7bU) << 28 |
       0x188be8fU)
          << 28 |
      0x55c878dU),
     (18446744073709551615UL) / 4933},

    {(((((uintmax_t)0x983dU << 28 | 0xcf2775dU) << 28 | 0xcd7ead8U) << 28 |
       0x05648b2U)
          << 28 |
      0xca54ef9U),
     (18446744073709551615UL) / 4937},

    {(((((uintmax_t)0x729cU << 28 | 0xb7c09bcU) << 28 | 0x91a2776U) << 28 |
       0xdbe6eefU)
          << 28 |
      0x60123afU),
     (18446744073709551615UL) / 4943},

    {(((((uintmax_t)0xe8f0U << 28 | 0x5536727U) << 28 | 0xa8b8137U) << 28 |
       0x11525e6U)
          << 28 |
      0xa9e8867U),
     (18446744073709551615UL) / 4951},

    {(((((uintmax_t)0xbdf2U << 28 | 0x781fd01U) << 28 | 0x3014a85U) << 28 |
       0xc2215cbU)
          << 28 |
      0x383d8f5U),
     (18446744073709551615UL) / 4957},

    {(((((uintmax_t)0x0439U << 28 | 0xee5f8e3U) << 28 | 0x30656e5U) << 28 |
       0x8f554c8U)
          << 28 |
      0x9825857U),
     (18446744073709551615UL) / 4967},

    {(((((uintmax_t)0x77adU << 28 | 0xfb283c9U) << 28 | 0x63b0a8fU) << 28 |
       0xbd3b17cU)
          << 28 |
      0x01dacd9U),
     (18446744073709551615UL) / 4969},

    {(((((uintmax_t)0x5d7bU << 28 | 0xe851f3fU) << 28 | 0x443554cU) << 28 |
       0x8c39dc7U)
          << 28 |
      0xaedee65U),
     (18446744073709551615UL) / 4973},

    {(((((uintmax_t)0x373cU << 28 | 0x1c8a99bU) << 28 | 0x1412465U) << 28 |
       0x3ac6ddaU)
          << 28 |
      0x86cd3b3U),
     (18446744073709551615UL) / 4987},

    {(((((uintmax_t)0x5b50U << 28 | 0xa687decU) << 28 | 0x6a07b0dU) << 28 |
       0x61c6791U)
          << 28 |
      0xa9c2c81U),
     (18446744073709551615UL) / 4993},

    {(((((uintmax_t)0x0b44U << 28 | 0x292c4bfU) << 28 | 0xef9cdb6U) << 28 |
       0x27a3009U)
          << 28 |
      0x0354237U),
     (18446744073709551615UL) / 4999},
    {1, 0},
    {1, 0},
    {1, 0},
    {1, 0},
    {1, 0},
    {1, 0},
    {1, 0}};

_Static_assert(W <= 128, "verify ("
                         "W <= WIDE_UINT_BITS"
                         ")");

static _Bool dev_debug = 0;

static _Bool flag_prove_primality = 1;

static void factor_insert_refind(struct factors *factors, uintmax_t p,
                                 unsigned int i, unsigned int off) {
  for (unsigned int j = 0; j < off; j++)
    p += primes_diff[i + j];
  factor_insert_multiplicity(factors, p, 1);
}
static uintmax_t factor_using_division(uintmax_t *t1p, uintmax_t t1,
                                       uintmax_t t0, struct factors *factors) {
  if (t0 % 2 == 0) {
    unsigned int cnt;

    if (t0 == 0) {
      do {
        ;
        __asm__("bsf\t%1, %q0" : "=r"(cnt) : "rm"((UDItype)(t1)));
      } while (0);
      t0 = t1 >> cnt;
      t1 = 0;
      cnt += 64;
    } else {
      do {
        ;
        __asm__("bsf\t%1, %q0" : "=r"(cnt) : "rm"((UDItype)(t0)));
      } while (0);
      do {
        (t0) = ((t1) << (64 - (cnt))) | ((t0) >> (cnt));
        (t1) = (t1) >> (cnt);
      } while (0);
    }

    factor_insert_multiplicity(factors, 2, cnt);
  }

  uintmax_t p = 3;
  unsigned int i;
  for (i = 0;
       t1 > 0 && i < (sizeof(primes_diff) / sizeof(primes_diff[0]) - 8 + 1);
       i++) {
    for (;;) {
      uintmax_t q1, q0, hi;
      uintmax_t lo;

      q0 = t0 * primes_dtab[i].binv;
      __asm__("mulq\t%3"
              : "=a"(lo), "=d"(hi)
              : "%0"((UDItype)(q0)), "rm"((UDItype)(p)));
      if (hi > t1)
        break;
      hi = t1 - hi;
      q1 = hi * primes_dtab[i].binv;
      if (__builtin_expect((q1 > primes_dtab[i].lim), 1))
        break;
      t1 = q1;
      t0 = q0;
      factor_insert_multiplicity(factors, p, 1);
    }
    p += primes_diff[i + 1];
  }
  if (t1p)
    *t1p = t1;
  for (; i < (sizeof(primes_diff) / sizeof(primes_diff[0]) - 8 + 1); i += 8) {
    uintmax_t q;
    const struct primes_dtab *pd = &primes_dtab[i];
    do {
      for (;;) {
        q = t0 * pd[0].binv;
        if (__builtin_expect((q > pd[0].lim), 1))
          break;
        t0 = q;
        factor_insert_refind(factors, p, i + 1, 0);
      }
    } while (0);
    do {
      for (;;) {
        q = t0 * pd[1].binv;
        if (__builtin_expect((q > pd[1].lim), 1))
          break;
        t0 = q;
        factor_insert_refind(factors, p, i + 1, 1);
      }
    } while (0);
    do {
      for (;;) {
        q = t0 * pd[2].binv;
        if (__builtin_expect((q > pd[2].lim), 1))
          break;
        t0 = q;
        factor_insert_refind(factors, p, i + 1, 2);
      }
    } while (0);
    do {
      for (;;) {
        q = t0 * pd[3].binv;
        if (__builtin_expect((q > pd[3].lim), 1))
          break;
        t0 = q;
        factor_insert_refind(factors, p, i + 1, 3);
      }
    } while (0);
    do {
      for (;;) {
        q = t0 * pd[4].binv;
        if (__builtin_expect((q > pd[4].lim), 1))
          break;
        t0 = q;
        factor_insert_refind(factors, p, i + 1, 4);
      }
    } while (0);
    do {
      for (;;) {
        q = t0 * pd[5].binv;
        if (__builtin_expect((q > pd[5].lim), 1))
          break;
        t0 = q;
        factor_insert_refind(factors, p, i + 1, 5);
      }
    } while (0);
    do {
      for (;;) {
        q = t0 * pd[6].binv;
        if (__builtin_expect((q > pd[6].lim), 1))
          break;
        t0 = q;
        factor_insert_refind(factors, p, i + 1, 6);
      }
    } while (0);
    do {
      for (;;) {
        q = t0 * pd[7].binv;
        if (__builtin_expect((q > pd[7].lim), 1))
          break;
        t0 = q;
        factor_insert_refind(factors, p, i + 1, 7);
      }
    } while (0);

    p += primes_diff8[i];
    if (p * p > t0)
      break;
  }

  return t0;
}

static void mp_factor_using_division(mpz_t t, struct mp_factors *factors) {
  mpz_t q;
  unsigned long int p;

  do {
    if (dev_debug)
      fprintf(stderr, "[trial division] ");
  } while (0);

  __gmpz_init(q);

  p = __gmpz_scan1(t, 0);

  __gmpz_fdiv_q_2exp(t, t, p);
  while (p) {
    mp_factor_insert_ui(factors, 2);
    --p;
  }

  p = 3;
  for (unsigned int i = 1;
       i <= (sizeof(primes_diff) / sizeof(primes_diff[0]) - 8 + 1);) {
    if (!__gmpz_divisible_ui_p(t, p)) {
      p += primes_diff[i++];
      if ((__builtin_constant_p(p * p) && (p * p) == 0
               ? ((t)->_mp_size < 0 ? -1 : (t)->_mp_size > 0)
               : __gmpz_cmp_ui(t, p * p)) < 0)
        break;
    } else {

      __gmpz_tdiv_q_ui(t, t, p);
      mp_factor_insert_ui(factors, p);
    }
  }

  __gmpz_clear(q);
}

static const unsigned char binvert_table[128] = {
    0x01, 0xAB, 0xCD, 0xB7, 0x39, 0xA3, 0xC5, 0xEF, 0xF1, 0x1B, 0x3D, 0xA7,
    0x29, 0x13, 0x35, 0xDF, 0xE1, 0x8B, 0xAD, 0x97, 0x19, 0x83, 0xA5, 0xCF,
    0xD1, 0xFB, 0x1D, 0x87, 0x09, 0xF3, 0x15, 0xBF, 0xC1, 0x6B, 0x8D, 0x77,
    0xF9, 0x63, 0x85, 0xAF, 0xB1, 0xDB, 0xFD, 0x67, 0xE9, 0xD3, 0xF5, 0x9F,
    0xA1, 0x4B, 0x6D, 0x57, 0xD9, 0x43, 0x65, 0x8F, 0x91, 0xBB, 0xDD, 0x47,
    0xC9, 0xB3, 0xD5, 0x7F, 0x81, 0x2B, 0x4D, 0x37, 0xB9, 0x23, 0x45, 0x6F,
    0x71, 0x9B, 0xBD, 0x27, 0xA9, 0x93, 0xB5, 0x5F, 0x61, 0x0B, 0x2D, 0x17,
    0x99, 0x03, 0x25, 0x4F, 0x51, 0x7B, 0x9D, 0x07, 0x89, 0x73, 0x95, 0x3F,
    0x41, 0xEB, 0x0D, 0xF7, 0x79, 0xE3, 0x05, 0x2F, 0x31, 0x5B, 0x7D, 0xE7,
    0x69, 0x53, 0x75, 0x1F, 0x21, 0xCB, 0xED, 0xD7, 0x59, 0xC3, 0xE5, 0x0F,
    0x11, 0x3B, 0x5D, 0xC7, 0x49, 0x33, 0x55, 0xFF};
static inline uintmax_t mulredc(uintmax_t a, uintmax_t b, uintmax_t m,
                                uintmax_t mi) {
  uintmax_t rh, rl, q, th, xh;
  uintmax_t tl;

  __asm__("mulq\t%3"
          : "=a"(rl), "=d"(rh)
          : "%0"((UDItype)(a)), "rm"((UDItype)(b)));
  q = rl * mi;
  __asm__("mulq\t%3"
          : "=a"(tl), "=d"(th)
          : "%0"((UDItype)(q)), "rm"((UDItype)(m)));
  xh = rh - th;
  if (rh < th)
    xh += m;

  return xh;
}

static uintmax_t mulredc2(uintmax_t *r1p, uintmax_t a1, uintmax_t a0,
                          uintmax_t b1, uintmax_t b0, uintmax_t m1,
                          uintmax_t m0, uintmax_t mi) {
  uintmax_t r1, r0, q, p1, t1, t0, s1, s0;
  uintmax_t p0;
  mi = -mi;

  ((void)sizeof(((a1 >> (64 - 1)) == 0) ? 1 : 0), __extension__({
     if ((a1 >> (64 - 1)) == 0)
       ;
     else
       __assert_fail("(a1 >> (W_TYPE_SIZE - 1)) == 0", "src/factor.c", 993,
                     __extension__ __PRETTY_FUNCTION__);
   }));

  ((void)sizeof(((b1 >> (64 - 1)) == 0) ? 1 : 0), __extension__({
     if ((b1 >> (64 - 1)) == 0)
       ;
     else
       __assert_fail("(b1 >> (W_TYPE_SIZE - 1)) == 0", "src/factor.c", 994,
                     __extension__ __PRETTY_FUNCTION__);
   }));

  ((void)sizeof(((m1 >> (64 - 1)) == 0) ? 1 : 0), __extension__({
     if ((m1 >> (64 - 1)) == 0)
       ;
     else
       __assert_fail("(m1 >> (W_TYPE_SIZE - 1)) == 0", "src/factor.c", 995,
                     __extension__ __PRETTY_FUNCTION__);
   }));
  __asm__("mulq\t%3"
          : "=a"(t0), "=d"(t1)
          : "%0"((UDItype)(a0)), "rm"((UDItype)(b0)));
  __asm__("mulq\t%3"
          : "=a"(r0), "=d"(r1)
          : "%0"((UDItype)(a0)), "rm"((UDItype)(b1)));
  q = mi * t0;
  __asm__("mulq\t%3"
          : "=a"(p0), "=d"(p1)
          : "%0"((UDItype)(q)), "rm"((UDItype)(m0)));
  __asm__("mulq\t%3"
          : "=a"(s0), "=d"(s1)
          : "%0"((UDItype)(q)), "rm"((UDItype)(m1)));
  r0 += (t0 != 0);
  __asm__("addq %5,%q1\n\tadcq %3,%q0"
          : "=r"(r1), "=&r"(r0)
          : "0"((UDItype)(r1)), "rme"((UDItype)(0)), "%1"((UDItype)(r0)),
            "rme"((UDItype)(p1)));
  __asm__("addq %5,%q1\n\tadcq %3,%q0"
          : "=r"(r1), "=&r"(r0)
          : "0"((UDItype)(r1)), "rme"((UDItype)(0)), "%1"((UDItype)(r0)),
            "rme"((UDItype)(t1)));
  __asm__("addq %5,%q1\n\tadcq %3,%q0"
          : "=r"(r1), "=&r"(r0)
          : "0"((UDItype)(r1)), "rme"((UDItype)(s1)), "%1"((UDItype)(r0)),
            "rme"((UDItype)(s0)));
  __asm__("mulq\t%3"
          : "=a"(t0), "=d"(t1)
          : "%0"((UDItype)(a1)), "rm"((UDItype)(b0)));
  __asm__("mulq\t%3"
          : "=a"(s0), "=d"(s1)
          : "%0"((UDItype)(a1)), "rm"((UDItype)(b1)));
  __asm__("addq %5,%q1\n\tadcq %3,%q0"
          : "=r"(t1), "=&r"(t0)
          : "0"((UDItype)(t1)), "rme"((UDItype)(0)), "%1"((UDItype)(t0)),
            "rme"((UDItype)(r0)));
  q = mi * t0;
  __asm__("addq %5,%q1\n\tadcq %3,%q0"
          : "=r"(r1), "=&r"(r0)
          : "0"((UDItype)(s1)), "rme"((UDItype)(0)), "%1"((UDItype)(s0)),
            "rme"((UDItype)(r1)));
  __asm__("mulq\t%3"
          : "=a"(p0), "=d"(p1)
          : "%0"((UDItype)(q)), "rm"((UDItype)(m0)));
  __asm__("mulq\t%3"
          : "=a"(s0), "=d"(s1)
          : "%0"((UDItype)(q)), "rm"((UDItype)(m1)));
  r0 += (t0 != 0);
  __asm__("addq %5,%q1\n\tadcq %3,%q0"
          : "=r"(r1), "=&r"(r0)
          : "0"((UDItype)(r1)), "rme"((UDItype)(0)), "%1"((UDItype)(r0)),
            "rme"((UDItype)(p1)));
  __asm__("addq %5,%q1\n\tadcq %3,%q0"
          : "=r"(r1), "=&r"(r0)
          : "0"((UDItype)(r1)), "rme"((UDItype)(0)), "%1"((UDItype)(r0)),
            "rme"((UDItype)(t1)));
  __asm__("addq %5,%q1\n\tadcq %3,%q0"
          : "=r"(r1), "=&r"(r0)
          : "0"((UDItype)(r1)), "rme"((UDItype)(s1)), "%1"((UDItype)(r0)),
            "rme"((UDItype)(s0)));

  if (((r1) > (m1) || ((r1) == (m1) && (r0) >= (m0))))
    __asm__("subq %5,%q1\n\tsbbq %3,%q0"
            : "=r"(r1), "=&r"(r0)
            : "0"((UDItype)(r1)), "rme"((UDItype)(m1)), "1"((UDItype)(r0)),
              "rme"((UDItype)(m0)));

  *r1p = r1;
  return r0;
}

__attribute__((__const__)) static uintmax_t
powm(uintmax_t b, uintmax_t e, uintmax_t n, uintmax_t ni, uintmax_t one) {
  uintmax_t y = one;

  if (e & 1)
    y = b;

  while (e != 0) {
    b = mulredc(b, b, n, ni);
    e >>= 1;

    if (e & 1)
      y = mulredc(y, b, n, ni);
  }

  return y;
}

static uintmax_t powm2(uintmax_t *r1m, const uintmax_t *bp, const uintmax_t *ep,
                       const uintmax_t *np, uintmax_t ni,
                       const uintmax_t *one) {
  uintmax_t r1, r0, b1, b0, n1, n0;
  unsigned int i;
  uintmax_t e;

  b0 = bp[0];
  b1 = bp[1];
  n0 = np[0];
  n1 = np[1];

  r0 = one[0];
  r1 = one[1];

  for (e = ep[0], i = 64; i > 0; i--, e >>= 1) {
    if (e & 1) {
      r0 = mulredc2(r1m, r1, r0, b1, b0, n1, n0, ni);
      r1 = *r1m;
    }
    b0 = mulredc2(r1m, b1, b0, b1, b0, n1, n0, ni);
    b1 = *r1m;
  }
  for (e = ep[1]; e > 0; e >>= 1) {
    if (e & 1) {
      r0 = mulredc2(r1m, r1, r0, b1, b0, n1, n0, ni);
      r1 = *r1m;
    }
    b0 = mulredc2(r1m, b1, b0, b1, b0, n1, n0, ni);
    b1 = *r1m;
  }
  *r1m = r1;
  return r0;
}

__attribute__((__const__)) static _Bool

millerrabin(uintmax_t n, uintmax_t ni, uintmax_t b, uintmax_t q, unsigned int k,
            uintmax_t one) {
  uintmax_t y = powm(b, q, n, ni, one);

  uintmax_t nm1 = n - one;

  if (y == one || y == nm1)
    return 1;

  for (unsigned int i = 1; i < k; i++) {
    y = mulredc(y, y, n, ni);

    if (y == nm1)
      return 1;
    if (y == one)
      return 0;
  }
  return 0;
}

__attribute__((__pure__)) static _Bool

millerrabin2(const uintmax_t *np, uintmax_t ni, const uintmax_t *bp,
             const uintmax_t *qp, unsigned int k, const uintmax_t *one) {
  uintmax_t y1, y0, nm1_1, nm1_0, r1m;

  y0 = powm2(&r1m, bp, qp, np, ni, one);
  y1 = r1m;

  if (y0 == one[0] && y1 == one[1])
    return 1;

  __asm__("subq %5,%q1\n\tsbbq %3,%q0"
          : "=r"(nm1_1), "=&r"(nm1_0)
          : "0"((UDItype)(np[1])), "rme"((UDItype)(one[1])),
            "1"((UDItype)(np[0])), "rme"((UDItype)(one[0])));

  if (y0 == nm1_0 && y1 == nm1_1)
    return 1;

  for (unsigned int i = 1; i < k; i++) {
    y0 = mulredc2(&r1m, y1, y0, y1, y0, np[1], np[0], ni);
    y1 = r1m;

    if (y0 == nm1_0 && y1 == nm1_1)
      return 1;
    if (y0 == one[0] && y1 == one[1])
      return 0;
  }
  return 0;
}

static _Bool

mp_millerrabin(mpz_srcptr n, mpz_srcptr nm1, mpz_ptr x, mpz_ptr y, mpz_srcptr q,
               unsigned long int k) {

  __gmpz_powm(y, x, q, n);

  if ((__builtin_constant_p(1) && (1) == 0
           ? ((y)->_mp_size < 0 ? -1 : (y)->_mp_size > 0)
           : __gmpz_cmp_ui(y, 1)) == 0 ||
      __gmpz_cmp(y, nm1) == 0)
    return 1;

  for (unsigned long int i = 1; i < k; i++) {

    __gmpz_powm_ui(y, y, 2, n);
    if (__gmpz_cmp(y, nm1) == 0)
      return 1;
    if ((__builtin_constant_p(1) && (1) == 0
             ? ((y)->_mp_size < 0 ? -1 : (y)->_mp_size > 0)
             : __gmpz_cmp_ui(y, 1)) == 0)
      return 0;
  }
  return 0;
}

static _Bool

prime_p(uintmax_t n) {
  int k;

  _Bool is_prime;
  uintmax_t a_prim, one, ni;
  struct factors factors;

  if (n <= 1)
    return 0;

  if (n < (uintmax_t)5003 * 5003)
    return 1;

  uintmax_t q = n - 1;
  for (k = 0; (q & 1) == 0; k++)
    q >>= 1;

  uintmax_t a = 2;
  do {
    uintmax_t __n = (n);
    uintmax_t __inv;
    __inv = binvert_table[(__n / 2) & 0x7F];
    if (64 > 8)
      __inv = 2 * __inv - __inv * __inv * __n;
    if (64 > 16)
      __inv = 2 * __inv - __inv * __inv * __n;
    if (64 > 32)
      __inv = 2 * __inv - __inv * __inv * __n;
    if (64 > 64) {
      int __invbits = 64;
      do {
        __inv = 2 * __inv - __inv * __inv * __n;
        __invbits *= 2;
      } while (__invbits < 64);
    }
    (ni) = __inv;
  } while (0);
  do {
    uintmax_t _redcify_q;
    do {
      uintmax_t __d1, __d0, __q, __r1, __r0;
      ((void)sizeof(((1) < (n)) ? 1 : 0), __extension__({
         if ((1) < (n))
           ;
         else
           __assert_fail("(1) < (n)", "src/factor.c", 1214,
                         __extension__ __PRETTY_FUNCTION__);
       }));
      __d1 = (n);
      __d0 = 0;
      __r1 = (1);
      __r0 = (0);
      __q = 0;
      for (unsigned int __i = 64; __i > 0; __i--) {
        do {
          (__d0) = ((__d1) << (64 - (1))) | ((__d0) >> (1));
          (__d1) = (__d1) >> (1);
        } while (0);
        __q <<= 1;
        if (((__r1) > (__d1) || ((__r1) == (__d1) && (__r0) >= (__d0)))) {
          __q++;
          __asm__("subq %5,%q1\n\tsbbq %3,%q0"
                  : "=r"(__r1), "=&r"(__r0)
                  : "0"((UDItype)(__r1)), "rme"((UDItype)(__d1)),
                    "1"((UDItype)(__r0)), "rme"((UDItype)(__d0)));
        }
      }
      (one) = __r0;
      (_redcify_q) = __q;
    } while (0);
  } while (0);
  do {
    uintmax_t _t = -(uintmax_t)((one) < ((n) - (one)));
    ((a_prim)) = (((n)) & _t) + ((one)) - (((n) - (one)));
  } while (0);

  if (!millerrabin(n, ni, a_prim, q, k, one))
    return 0;

  if (flag_prove_primality) {

    factor(0, n - 1, &factors);
  }

  for (unsigned int r = 0;
       r < (sizeof(primes_diff) / sizeof(primes_diff[0]) - 8 + 1); r++) {
    if (flag_prove_primality) {
      is_prime = 1;
      for (unsigned int i = 0; i < factors.nfactors && is_prime; i++) {
        is_prime = powm(a_prim, (n - 1) / factors.p[i], n, ni, one) != one;
      }
    } else {

      is_prime = (r == 25 - 1);
    }

    if (is_prime)
      return 1;

    a += primes_diff[r];

    {
      uintmax_t s1, s0;
      __asm__("mulq\t%3"
              : "=a"(s0), "=d"(s1)
              : "%0"((UDItype)(one)), "rm"((UDItype)(a)));
      if (__builtin_expect((s1 == 0), 1))
        a_prim = s0 % n;
      else {
        uintmax_t dummy;
        do {
          uintmax_t __d1, __d0, __q, __r1, __r0;
          ((void)sizeof(((s1) < (n)) ? 1 : 0), __extension__({
             if ((s1) < (n))
               ;
             else
               __assert_fail("(s1) < (n)", "src/factor.c", 1262,
                             __extension__ __PRETTY_FUNCTION__);
           }));
          __d1 = (n);
          __d0 = 0;
          __r1 = (s1);
          __r0 = (s0);
          __q = 0;
          for (unsigned int __i = 64; __i > 0; __i--) {
            do {
              (__d0) = ((__d1) << (64 - (1))) | ((__d0) >> (1));
              (__d1) = (__d1) >> (1);
            } while (0);
            __q <<= 1;
            if (((__r1) > (__d1) || ((__r1) == (__d1) && (__r0) >= (__d0)))) {
              __q++;
              __asm__("subq %5,%q1\n\tsbbq %3,%q0"
                      : "=r"(__r1), "=&r"(__r0)
                      : "0"((UDItype)(__r1)), "rme"((UDItype)(__d1)),
                        "1"((UDItype)(__r0)), "rme"((UDItype)(__d0)));
            }
          }
          (a_prim) = __r0;
          (dummy) = __q;
        } while (0);
      }
    }

    if (!millerrabin(n, ni, a_prim, q, k, one))
      return 0;
  }

  error(0, 0,
        dcgettext(((void *)0),
                  "Lucas prime test failure.  This should not happen", 5));
  abort();
}

static _Bool

prime2_p(uintmax_t n1, uintmax_t n0) {
  uintmax_t q[2], nm1[2];
  uintmax_t a_prim[2];
  uintmax_t one[2];
  uintmax_t na[2];
  uintmax_t ni;
  unsigned int k;
  struct factors factors;

  if (n1 == 0)
    return prime_p(n0);

  nm1[1] = n1 - (n0 == 0);
  nm1[0] = n0 - 1;
  if (nm1[0] == 0) {
    do {
      ;
      __asm__("bsf\t%1, %q0" : "=r"(k) : "rm"((UDItype)(nm1[1])));
    } while (0);

    q[0] = nm1[1] >> k;
    q[1] = 0;
    k += 64;
  } else {
    do {
      ;
      __asm__("bsf\t%1, %q0" : "=r"(k) : "rm"((UDItype)(nm1[0])));
    } while (0);
    do {
      (q[0]) = ((nm1[1]) << (64 - (k))) | ((nm1[0]) >> (k));
      (q[1]) = (nm1[1]) >> (k);
    } while (0);
  }

  uintmax_t a = 2;
  do {
    uintmax_t __n = (n0);
    uintmax_t __inv;
    __inv = binvert_table[(__n / 2) & 0x7F];
    if (64 > 8)
      __inv = 2 * __inv - __inv * __inv * __n;
    if (64 > 16)
      __inv = 2 * __inv - __inv * __inv * __n;
    if (64 > 32)
      __inv = 2 * __inv - __inv * __inv * __n;
    if (64 > 64) {
      int __invbits = 64;
      do {
        __inv = 2 * __inv - __inv * __inv * __n;
        __invbits *= 2;
      } while (__invbits < 64);
    }
    (ni) = __inv;
  } while (0);
  do {
    uintmax_t _r1, _r0, _i;
    if ((1) < (n1)) {
      _r1 = (1);
      _r0 = 0;
      _i = 64;
    } else {
      _r1 = 0;
      _r0 = (1);
      _i = 2 * 64;
    }
    while (_i-- > 0) {
      do {
        (_r1) = ((_r1) << 1) | ((_r0) >> (64 - (1)));
        (_r0) = (_r0) << (1);
      } while (0);
      if (((_r1) > ((n1)) || ((_r1) == ((n1)) && (_r0) >= ((n0)))))
        __asm__("subq %5,%q1\n\tsbbq %3,%q0"
                : "=r"(_r1), "=&r"(_r0)
                : "0"((UDItype)(_r1)), "rme"((UDItype)((n1))),
                  "1"((UDItype)(_r0)), "rme"((UDItype)((n0))));
    }
    (one[1]) = _r1;
    (one[0]) = _r0;
  } while (0);
  do {
    __asm__("addq %5,%q1\n\tadcq %3,%q0"
            : "=r"((a_prim[1])), "=&r"((a_prim[0]))
            : "0"((UDItype)((one[1]))), "rme"((UDItype)((one[1]))),
              "%1"((UDItype)((one[0]))), "rme"((UDItype)((one[0]))));
    if ((((a_prim[1])) > ((n1)) ||
         (((a_prim[1])) == ((n1)) && ((a_prim[0])) >= ((n0)))))
      __asm__("subq %5,%q1\n\tsbbq %3,%q0"
              : "=r"((a_prim[1])), "=&r"((a_prim[0]))
              : "0"((UDItype)((a_prim[1]))), "rme"((UDItype)((n1))),
                "1"((UDItype)((a_prim[0]))), "rme"((UDItype)((n0))));
  } while (0);

  na[0] = n0;
  na[1] = n1;

  if (!millerrabin2(na, ni, a_prim, q, k, one))
    return 0;

  if (flag_prove_primality) {

    factor(nm1[1], nm1[0], &factors);
  }

  for (unsigned int r = 0;
       r < (sizeof(primes_diff) / sizeof(primes_diff[0]) - 8 + 1); r++) {

    _Bool is_prime;
    uintmax_t e[2], y[2];

    if (flag_prove_primality) {
      is_prime = 1;
      if (factors.plarge[1]) {
        uintmax_t pi;
        do {
          uintmax_t __n = (factors.plarge[0]);
          uintmax_t __inv;
          __inv = binvert_table[(__n / 2) & 0x7F];
          if (64 > 8)
            __inv = 2 * __inv - __inv * __inv * __n;
          if (64 > 16)
            __inv = 2 * __inv - __inv * __inv * __n;
          if (64 > 32)
            __inv = 2 * __inv - __inv * __inv * __n;
          if (64 > 64) {
            int __invbits = 64;
            do {
              __inv = 2 * __inv - __inv * __inv * __n;
              __invbits *= 2;
            } while (__invbits < 64);
          }
          (pi) = __inv;
        } while (0);
        e[0] = pi * nm1[0];
        e[1] = 0;
        y[0] = powm2(&y[1], a_prim, e, na, ni, one);
        is_prime = (y[0] != one[0] || y[1] != one[1]);
      }
      for (unsigned int i = 0; i < factors.nfactors && is_prime; i++) {

        if (factors.p[i] == 2)
          do {
            (e[0]) = ((nm1[1]) << (64 - (1))) | ((nm1[0]) >> (1));
            (e[1]) = (nm1[1]) >> (1);
          } while (0);
        else
          do {
            uintmax_t _di, _q0;
            do {
              uintmax_t __n = ((factors.p[i]));
              uintmax_t __inv;
              __inv = binvert_table[(__n / 2) & 0x7F];
              if (64 > 8)
                __inv = 2 * __inv - __inv * __inv * __n;
              if (64 > 16)
                __inv = 2 * __inv - __inv * __inv * __n;
              if (64 > 32)
                __inv = 2 * __inv - __inv * __inv * __n;
              if (64 > 64) {
                int __invbits = 64;
                do {
                  __inv = 2 * __inv - __inv * __inv * __n;
                  __invbits *= 2;
                } while (__invbits < 64);
              }
              (_di) = __inv;
            } while (0);
            _q0 = (nm1[0]) * _di;
            if ((nm1[1]) >= (factors.p[i])) {
              uintmax_t _p1;
              intmax_t _p0;
              __asm__("mulq\t%3"
                      : "=a"(_p0), "=d"(_p1)
                      : "%0"((UDItype)(_q0)), "rm"((UDItype)(factors.p[i])));
              (e[1]) = ((nm1[1]) - _p1) * _di;
              (e[0]) = _q0;
            } else {
              (e[0]) = _q0;
              (e[1]) = 0;
            }
          } while (0);
        y[0] = powm2(&y[1], a_prim, e, na, ni, one);
        is_prime = (y[0] != one[0] || y[1] != one[1]);
      }
    } else {

      is_prime = (r == 25 - 1);
    }

    if (is_prime)
      return 1;

    a += primes_diff[r];
    do {
      uintmax_t _r1, _r0, _i;
      if ((a) < (n1)) {
        _r1 = (a);
        _r0 = 0;
        _i = 64;
      } else {
        _r1 = 0;
        _r0 = (a);
        _i = 2 * 64;
      }
      while (_i-- > 0) {
        do {
          (_r1) = ((_r1) << 1) | ((_r0) >> (64 - (1)));
          (_r0) = (_r0) << (1);
        } while (0);
        if (((_r1) > ((n1)) || ((_r1) == ((n1)) && (_r0) >= ((n0)))))
          __asm__("subq %5,%q1\n\tsbbq %3,%q0"
                  : "=r"(_r1), "=&r"(_r0)
                  : "0"((UDItype)(_r1)), "rme"((UDItype)((n1))),
                    "1"((UDItype)(_r0)), "rme"((UDItype)((n0))));
      }
      (a_prim[1]) = _r1;
      (a_prim[0]) = _r0;
    } while (0);

    if (!millerrabin2(na, ni, a_prim, q, k, one))
      return 0;
  }

  error(0, 0,
        dcgettext(((void *)0),
                  "Lucas prime test failure.  This should not happen", 5));
  abort();
}

static _Bool

mp_prime_p(mpz_t n) {

  _Bool is_prime;
  mpz_t q, a, nm1, tmp;
  struct mp_factors factors;

  if ((__builtin_constant_p(1) && (1) == 0
           ? ((n)->_mp_size < 0 ? -1 : (n)->_mp_size > 0)
           : __gmpz_cmp_ui(n, 1)) <= 0)
    return 0;

  if ((__builtin_constant_p((long)5003 * 5003) && ((long)5003 * 5003) == 0
           ? ((n)->_mp_size < 0 ? -1 : (n)->_mp_size > 0)
           : __gmpz_cmp_ui(n, (long)5003 * 5003)) < 0)
    return 1;

  __gmpz_inits(q, a, nm1, tmp, ((void *)0));

  __gmpz_sub_ui(nm1, n, 1);

  unsigned long int k = __gmpz_scan1(nm1, 0);

  __gmpz_tdiv_q_2exp(q, nm1, k);

  __gmpz_set_ui(a, 2);

  if (!mp_millerrabin(n, nm1, a, tmp, q, k)) {
    is_prime = 0;
    goto ret2;
  }

  if (flag_prove_primality) {

    __gmpz_set(tmp, nm1);
    mp_factor(tmp, &factors);
  }

  for (unsigned int r = 0;
       r < (sizeof(primes_diff) / sizeof(primes_diff[0]) - 8 + 1); r++) {
    if (flag_prove_primality) {
      is_prime = 1;
      for (unsigned long int i = 0; i < factors.nfactors && is_prime; i++) {

        __gmpz_divexact(tmp, nm1, factors.p[i]);

        __gmpz_powm(tmp, a, tmp, n);
        is_prime = (__builtin_constant_p(1) && (1) == 0
                        ? ((tmp)->_mp_size < 0 ? -1 : (tmp)->_mp_size > 0)
                        : __gmpz_cmp_ui(tmp, 1)) != 0;
      }
    } else {

      is_prime = (r == 25 - 1);
    }

    if (is_prime)
      goto ret1;

    __gmpz_add_ui(a, a, primes_diff[r]);

    if (!mp_millerrabin(n, nm1, a, tmp, q, k)) {
      is_prime = 0;
      goto ret1;
    }
  }

  error(0, 0,
        dcgettext(((void *)0),
                  "Lucas prime test failure.  This should not happen", 5));
  abort();

ret1:
  if (flag_prove_primality)
    mp_factor_clear(&factors);
ret2:

  __gmpz_clears(q, a, nm1, tmp, ((void *)0));

  return is_prime;
}

static void factor_using_pollard_rho(uintmax_t n, unsigned long int a,
                                     struct factors *factors) {
  uintmax_t x, z, y, P, t, ni, g;

  unsigned long int k = 1;
  unsigned long int l = 1;

  do {
    uintmax_t _redcify_q;
    do {
      uintmax_t __d1, __d0, __q, __r1, __r0;
      ((void)sizeof(((1) < (n)) ? 1 : 0), __extension__({
         if ((1) < (n))
           ;
         else
           __assert_fail("(1) < (n)", "src/factor.c", 1466,
                         __extension__ __PRETTY_FUNCTION__);
       }));
      __d1 = (n);
      __d0 = 0;
      __r1 = (1);
      __r0 = (0);
      __q = 0;
      for (unsigned int __i = 64; __i > 0; __i--) {
        do {
          (__d0) = ((__d1) << (64 - (1))) | ((__d0) >> (1));
          (__d1) = (__d1) >> (1);
        } while (0);
        __q <<= 1;
        if (((__r1) > (__d1) || ((__r1) == (__d1) && (__r0) >= (__d0)))) {
          __q++;
          __asm__("subq %5,%q1\n\tsbbq %3,%q0"
                  : "=r"(__r1), "=&r"(__r0)
                  : "0"((UDItype)(__r1)), "rme"((UDItype)(__d1)),
                    "1"((UDItype)(__r0)), "rme"((UDItype)(__d0)));
        }
      }
      (P) = __r0;
      (_redcify_q) = __q;
    } while (0);
  } while (0);
  do {
    uintmax_t _t = -(uintmax_t)((P) < ((n) - (P)));
    ((x)) = (((n)) & _t) + ((P)) - (((n) - (P)));
  } while (0);
  y = z = x;

  while (n != 1) {

    ((void)sizeof((a < n) ? 1 : 0), __extension__({
       if (a < n)
         ;
       else
         __assert_fail("a < n", "src/factor.c", 1472,
                       __extension__ __PRETTY_FUNCTION__);
     }));

    do {
      uintmax_t __n = (n);
      uintmax_t __inv;
      __inv = binvert_table[(__n / 2) & 0x7F];
      if (64 > 8)
        __inv = 2 * __inv - __inv * __inv * __n;
      if (64 > 16)
        __inv = 2 * __inv - __inv * __inv * __n;
      if (64 > 32)
        __inv = 2 * __inv - __inv * __inv * __n;
      if (64 > 64) {
        int __invbits = 64;
        do {
          __inv = 2 * __inv - __inv * __inv * __n;
          __invbits *= 2;
        } while (__invbits < 64);
      }
      (ni) = __inv;
    } while (0);

    for (;;) {
      do {
        x = mulredc(x, x, n, ni);
        do {
          uintmax_t _t = -(uintmax_t)((x) < ((n) - (a)));
          ((x)) = (((n)) & _t) + ((x)) - (((n) - (a)));
        } while (0);

        do {
          uintmax_t _t = -(uintmax_t)(z < x);
          (t) = ((n)&_t) + (z) - (x);
        } while (0);
        P = mulredc(P, t, n, ni);

        if (k % 32 == 1) {
          if (gcd_odd(P, n) != 1)
            goto factor_found;
          y = x;
        }
      } while (--k != 0);

      z = x;
      k = l;
      l = 2 * l;
      for (unsigned long int i = 0; i < k; i++) {
        x = mulredc(x, x, n, ni);
        do {
          uintmax_t _t = -(uintmax_t)((x) < ((n) - (a)));
          ((x)) = (((n)) & _t) + ((x)) - (((n) - (a)));
        } while (0);
      }
      y = x;
    }

  factor_found:
    do {
      y = mulredc(y, y, n, ni);
      do {
        uintmax_t _t = -(uintmax_t)((y) < ((n) - (a)));
        ((y)) = (((n)) & _t) + ((y)) - (((n) - (a)));
      } while (0);

      do {
        uintmax_t _t = -(uintmax_t)(z < y);
        (t) = ((n)&_t) + (z) - (y);
      } while (0);
      g = gcd_odd(t, n);
    } while (g == 1);

    if (n == g) {

      factor_using_pollard_rho(n, a + 1, factors);
      return;
    }

    n = n / g;

    if (!prime_p(g))
      factor_using_pollard_rho(g, a + 1, factors);
    else
      factor_insert_multiplicity(factors, g, 1);

    if (prime_p(n)) {
      factor_insert_multiplicity(factors, n, 1);
      break;
    }

    x = x % n;
    z = z % n;
    y = y % n;
  }
}

static void factor_using_pollard_rho2(uintmax_t n1, uintmax_t n0,
                                      unsigned long int a,
                                      struct factors *factors) {
  uintmax_t x1, x0, z1, z0, y1, y0, P1, P0, t1, t0, ni, g1, g0, r1m;

  unsigned long int k = 1;
  unsigned long int l = 1;

  do {
    uintmax_t _r1, _r0, _i;
    if ((1) < (n1)) {
      _r1 = (1);
      _r0 = 0;
      _i = 64;
    } else {
      _r1 = 0;
      _r0 = (1);
      _i = 2 * 64;
    }
    while (_i-- > 0) {
      do {
        (_r1) = ((_r1) << 1) | ((_r0) >> (64 - (1)));
        (_r0) = (_r0) << (1);
      } while (0);
      if (((_r1) > ((n1)) || ((_r1) == ((n1)) && (_r0) >= ((n0)))))
        __asm__("subq %5,%q1\n\tsbbq %3,%q0"
                : "=r"(_r1), "=&r"(_r0)
                : "0"((UDItype)(_r1)), "rme"((UDItype)((n1))),
                  "1"((UDItype)(_r0)), "rme"((UDItype)((n0))));
    }
    (P1) = _r1;
    (P0) = _r0;
  } while (0);
  do {
    __asm__("addq %5,%q1\n\tadcq %3,%q0"
            : "=r"((x1)), "=&r"((x0))
            : "0"((UDItype)((P1))), "rme"((UDItype)((P1))),
              "%1"((UDItype)((P0))), "rme"((UDItype)((P0))));
    if ((((x1)) > ((n1)) || (((x1)) == ((n1)) && ((x0)) >= ((n0)))))
      __asm__("subq %5,%q1\n\tsbbq %3,%q0"
              : "=r"((x1)), "=&r"((x0))
              : "0"((UDItype)((x1))), "rme"((UDItype)((n1))),
                "1"((UDItype)((x0))), "rme"((UDItype)((n0))));
  } while (0);
  y1 = z1 = x1;
  y0 = z0 = x0;

  while (n1 != 0 || n0 != 1) {
    do {
      uintmax_t __n = (n0);
      uintmax_t __inv;
      __inv = binvert_table[(__n / 2) & 0x7F];
      if (64 > 8)
        __inv = 2 * __inv - __inv * __inv * __n;
      if (64 > 16)
        __inv = 2 * __inv - __inv * __inv * __n;
      if (64 > 32)
        __inv = 2 * __inv - __inv * __inv * __n;
      if (64 > 64) {
        int __invbits = 64;
        do {
          __inv = 2 * __inv - __inv * __inv * __n;
          __invbits *= 2;
        } while (__invbits < 64);
      }
      (ni) = __inv;
    } while (0);

    for (;;) {
      do {
        x0 = mulredc2(&r1m, x1, x0, x1, x0, n1, n0, ni);
        x1 = r1m;
        do {
          __asm__("addq %5,%q1\n\tadcq %3,%q0"
                  : "=r"((x1)), "=&r"((x0))
                  : "0"((UDItype)((x1))), "rme"((UDItype)((0))),
                    "%1"((UDItype)((x0))), "rme"((UDItype)(((uintmax_t)a))));
          if ((((x1)) > ((n1)) || (((x1)) == ((n1)) && ((x0)) >= ((n0)))))
            __asm__("subq %5,%q1\n\tsbbq %3,%q0"
                    : "=r"((x1)), "=&r"((x0))
                    : "0"((UDItype)((x1))), "rme"((UDItype)((n1))),
                      "1"((UDItype)((x0))), "rme"((UDItype)((n0))));
        } while (0);

        do {
          __asm__("subq %5,%q1\n\tsbbq %3,%q0"
                  : "=r"((t1)), "=&r"((t0))
                  : "0"((UDItype)((z1))), "rme"((UDItype)((x1))),
                    "1"((UDItype)((z0))), "rme"((UDItype)((x0))));
          if ((intmax_t)(t1) < 0)
            __asm__("addq %5,%q1\n\tadcq %3,%q0"
                    : "=r"((t1)), "=&r"((t0))
                    : "0"((UDItype)((t1))), "rme"((UDItype)((n1))),
                      "%1"((UDItype)((t0))), "rme"((UDItype)((n0))));
        } while (0);
        P0 = mulredc2(&r1m, P1, P0, t1, t0, n1, n0, ni);
        P1 = r1m;

        if (k % 32 == 1) {
          g0 = gcd2_odd(&g1, P1, P0, n1, n0);
          if (g1 != 0 || g0 != 1)
            goto factor_found;
          y1 = x1;
          y0 = x0;
        }
      } while (--k != 0);

      z1 = x1;
      z0 = x0;
      k = l;
      l = 2 * l;
      for (unsigned long int i = 0; i < k; i++) {
        x0 = mulredc2(&r1m, x1, x0, x1, x0, n1, n0, ni);
        x1 = r1m;
        do {
          __asm__("addq %5,%q1\n\tadcq %3,%q0"
                  : "=r"((x1)), "=&r"((x0))
                  : "0"((UDItype)((x1))), "rme"((UDItype)((0))),
                    "%1"((UDItype)((x0))), "rme"((UDItype)(((uintmax_t)a))));
          if ((((x1)) > ((n1)) || (((x1)) == ((n1)) && ((x0)) >= ((n0)))))
            __asm__("subq %5,%q1\n\tsbbq %3,%q0"
                    : "=r"((x1)), "=&r"((x0))
                    : "0"((UDItype)((x1))), "rme"((UDItype)((n1))),
                      "1"((UDItype)((x0))), "rme"((UDItype)((n0))));
        } while (0);
      }
      y1 = x1;
      y0 = x0;
    }

  factor_found:
    do {
      y0 = mulredc2(&r1m, y1, y0, y1, y0, n1, n0, ni);
      y1 = r1m;
      do {
        __asm__("addq %5,%q1\n\tadcq %3,%q0"
                : "=r"((y1)), "=&r"((y0))
                : "0"((UDItype)((y1))), "rme"((UDItype)((0))),
                  "%1"((UDItype)((y0))), "rme"((UDItype)(((uintmax_t)a))));
        if ((((y1)) > ((n1)) || (((y1)) == ((n1)) && ((y0)) >= ((n0)))))
          __asm__("subq %5,%q1\n\tsbbq %3,%q0"
                  : "=r"((y1)), "=&r"((y0))
                  : "0"((UDItype)((y1))), "rme"((UDItype)((n1))),
                    "1"((UDItype)((y0))), "rme"((UDItype)((n0))));
      } while (0);

      do {
        __asm__("subq %5,%q1\n\tsbbq %3,%q0"
                : "=r"((t1)), "=&r"((t0))
                : "0"((UDItype)((z1))), "rme"((UDItype)((y1))),
                  "1"((UDItype)((z0))), "rme"((UDItype)((y0))));
        if ((intmax_t)(t1) < 0)
          __asm__("addq %5,%q1\n\tadcq %3,%q0"
                  : "=r"((t1)), "=&r"((t0))
                  : "0"((UDItype)((t1))), "rme"((UDItype)((n1))),
                    "%1"((UDItype)((t0))), "rme"((UDItype)((n0))));
      } while (0);
      g0 = gcd2_odd(&g1, t1, t0, n1, n0);
    } while (g1 == 0 && g0 == 1);

    if (g1 == 0) {

      do {
        uintmax_t _di, _q0;
        do {
          uintmax_t __n = ((g0));
          uintmax_t __inv;
          __inv = binvert_table[(__n / 2) & 0x7F];
          if (64 > 8)
            __inv = 2 * __inv - __inv * __inv * __n;
          if (64 > 16)
            __inv = 2 * __inv - __inv * __inv * __n;
          if (64 > 32)
            __inv = 2 * __inv - __inv * __inv * __n;
          if (64 > 64) {
            int __invbits = 64;
            do {
              __inv = 2 * __inv - __inv * __inv * __n;
              __invbits *= 2;
            } while (__invbits < 64);
          }
          (_di) = __inv;
        } while (0);
        _q0 = (n0)*_di;
        if ((n1) >= (g0)) {
          uintmax_t _p1;
          intmax_t _p0;
          __asm__("mulq\t%3"
                  : "=a"(_p0), "=d"(_p1)
                  : "%0"((UDItype)(_q0)), "rm"((UDItype)(g0)));
          (n1) = ((n1)-_p1) * _di;
          (n0) = _q0;
        } else {
          (n0) = _q0;
          (n1) = 0;
        }
      } while (0);

      if (!prime_p(g0))
        factor_using_pollard_rho(g0, a + 1, factors);
      else
        factor_insert_multiplicity(factors, g0, 1);
    } else {

      uintmax_t ginv;

      if (n1 == g1 && n0 == g0) {

        factor_using_pollard_rho2(n1, n0, a + 1, factors);
        return;
      }

      do {
        uintmax_t __n = (g0);
        uintmax_t __inv;
        __inv = binvert_table[(__n / 2) & 0x7F];
        if (64 > 8)
          __inv = 2 * __inv - __inv * __inv * __n;
        if (64 > 16)
          __inv = 2 * __inv - __inv * __inv * __n;
        if (64 > 32)
          __inv = 2 * __inv - __inv * __inv * __n;
        if (64 > 64) {
          int __invbits = 64;
          do {
            __inv = 2 * __inv - __inv * __inv * __n;
            __invbits *= 2;
          } while (__invbits < 64);
        }
        (ginv) = __inv;
      } while (0);
      n0 = ginv * n0;
      n1 = 0;

      if (!prime2_p(g1, g0))
        factor_using_pollard_rho2(g1, g0, a + 1, factors);
      else
        factor_insert_large(factors, g1, g0);
    }

    if (n1 == 0) {
      if (prime_p(n0)) {
        factor_insert_multiplicity(factors, n0, 1);
        break;
      }

      factor_using_pollard_rho(n0, a, factors);
      return;
    }

    if (prime2_p(n1, n0)) {
      factor_insert_large(factors, n1, n0);
      break;
    }

    x0 = mod2(&x1, x1, x0, n1, n0);
    z0 = mod2(&z1, z1, z0, n1, n0);
    y0 = mod2(&y1, y1, y0, n1, n0);
  }
}

static void mp_factor_using_pollard_rho(mpz_t n, unsigned long int a,
                                        struct mp_factors *factors) {
  mpz_t x, z, y, P;
  mpz_t t, t2;

  do {
    if (dev_debug)
      fprintf(stderr, "[pollard-rho (%lu)] ", a);
  } while (0);

  __gmpz_inits(t, t2, ((void *)0));

  __gmpz_init_set_si(y, 2);

  __gmpz_init_set_si(x, 2);

  __gmpz_init_set_si(z, 2);

  __gmpz_init_set_ui(P, 1);

  unsigned long long int k = 1;
  unsigned long long int l = 1;

  while ((__builtin_constant_p(1) && (1) == 0
              ? ((n)->_mp_size < 0 ? -1 : (n)->_mp_size > 0)
              : __gmpz_cmp_ui(n, 1)) != 0) {
    for (;;) {
      do {

        __gmpz_mul(t, x, x);

        __gmpz_mod(x, t, n);

        __gmpz_add_ui(x, x, a);

        __gmpz_sub(t, z, x);

        __gmpz_mul(t2, P, t);

        __gmpz_mod(P, t2, n);

        if (k % 32 == 1) {

          __gmpz_gcd(t, P, n);
          if ((__builtin_constant_p(1) && (1) == 0
                   ? ((t)->_mp_size < 0 ? -1 : (t)->_mp_size > 0)
                   : __gmpz_cmp_ui(t, 1)) != 0)
            goto factor_found;

          __gmpz_set(y, x);
        }
      } while (--k != 0);

      __gmpz_set(z, x);
      k = l;
      l = 2 * l;
      for (unsigned long long int i = 0; i < k; i++) {

        __gmpz_mul(t, x, x);

        __gmpz_mod(x, t, n);

        __gmpz_add_ui(x, x, a);
      }

      __gmpz_set(y, x);
    }

  factor_found:
    do {

      __gmpz_mul(t, y, y);

      __gmpz_mod(y, t, n);

      __gmpz_add_ui(y, y, a);

      __gmpz_sub(t, z, y);

      __gmpz_gcd(t, t, n);
    } while ((__builtin_constant_p(1) && (1) == 0
                  ? ((t)->_mp_size < 0 ? -1 : (t)->_mp_size > 0)
                  : __gmpz_cmp_ui(t, 1)) == 0);

    __gmpz_divexact(n, n, t);

    if (!mp_prime_p(t)) {
      do {
        if (dev_debug)
          fprintf(stderr, "[composite factor--restarting pollard-rho] ");
      } while (0);
      mp_factor_using_pollard_rho(t, a + 1, factors);
    } else {
      mp_factor_insert(factors, t);
    }

    if (mp_prime_p(n)) {
      mp_factor_insert(factors, n);
      break;
    }

    __gmpz_mod(x, x, n);

    __gmpz_mod(z, z, n);

    __gmpz_mod(y, y, n);
  }

  __gmpz_clears(P, t2, t, z, x, y, ((void *)0));
}
static void factor(uintmax_t t1, uintmax_t t0, struct factors *factors) {
  factors->nfactors = 0;
  factors->plarge[1] = 0;

  if (t1 == 0 && t0 < 2)
    return;

  t0 = factor_using_division(&t1, t1, t0, factors);

  if (t1 == 0 && t0 < 2)
    return;

  if (prime2_p(t1, t0))
    factor_insert_large(factors, t1, t0);
  else {

    if (t1 == 0)
      factor_using_pollard_rho(t0, 1, factors);
    else
      factor_using_pollard_rho2(t1, t0, 1, factors);
  }
}

static void mp_factor(mpz_t t, struct mp_factors *factors) {
  mp_factor_init(factors);

  if (((t)->_mp_size < 0 ? -1 : (t)->_mp_size > 0) != 0) {
    mp_factor_using_division(t, factors);

    if ((__builtin_constant_p(1) && (1) == 0
             ? ((t)->_mp_size < 0 ? -1 : (t)->_mp_size > 0)
             : __gmpz_cmp_ui(t, 1)) != 0) {
      do {
        if (dev_debug)
          fprintf(stderr, "[is number prime?] ");
      } while (0);
      if (mp_prime_p(t))
        mp_factor_insert(factors, t);
      else
        mp_factor_using_pollard_rho(t, 1, factors);
    }
  }
}

static strtol_error strto2uintmax(uintmax_t *hip, uintmax_t *lop,
                                  char const *s) {
  unsigned int lo_carry;
  uintmax_t hi = 0, lo = 0;

  strtol_error err = LONGINT_INVALID;

  char const *p = s;
  for (;;) {
    unsigned int c = *p++;
    if (c == 0)
      break;

    if (__builtin_expect((!((unsigned int)(c) - '0' <= 9)), 0)) {
      err = LONGINT_INVALID;
      break;
    }

    err = LONGINT_OK;
  }

  while (err == LONGINT_OK) {
    unsigned int c = *s++;
    if (c == 0)
      break;

    c -= '0';

    if (__builtin_expect((hi > ~(uintmax_t)0 / 10), 0)) {
      err = LONGINT_OVERFLOW;
      break;
    }
    hi = 10 * hi;

    lo_carry = (lo >> (64 - 3)) + (lo >> (64 - 1));
    lo_carry += 10 * lo < 2 * lo;

    lo = 10 * lo;
    lo += c;

    lo_carry += lo < c;
    hi += lo_carry;
    if (__builtin_expect((hi < lo_carry), 0)) {
      err = LONGINT_OVERFLOW;
      break;
    }
  }

  *hip = hi;
  *lop = lo;

  return err;
}

static struct lbuf_ {
  char *buf;
  char *end;
} lbuf;
static void lbuf_alloc(void) {
  if (lbuf.buf)
    return;

  lbuf.buf = xmalloc(512 * 2);
  lbuf.end = lbuf.buf;
}

static void lbuf_flush(void) {
  size_t size = lbuf.end - lbuf.buf;
  if (full_write(1, lbuf.buf, size) != size)
    ((!!sizeof(struct {
      _Static_assert(1, "verify_expr ("
                        "1"
                        ", "
                        "(error (1, (*__errno_location ()), \"%s\", dcgettext "
                        "(((void *)0), \"write error\", 5)), assume (false))"
                        ")");
      int _gl_dummy;
    }))
         ? ((error(1, (*__errno_location()), "%s",
                   dcgettext(((void *)0), "write error", 5)),
             ((0) ? (void)0 : __builtin_unreachable())))
         : ((error(1, (*__errno_location()), "%s",
                   dcgettext(((void *)0), "write error", 5)),
             ((0) ? (void)0 : __builtin_unreachable()))));
  lbuf.end = lbuf.buf;
}

static void lbuf_putc(char c) {
  *lbuf.end++ = c;

  if (c == '\n') {
    size_t buffered = lbuf.end - lbuf.buf;

    static int line_buffered = -1;
    if (line_buffered == -1)
      line_buffered = isatty(0) || isatty(1);
    if (line_buffered)
      lbuf_flush();
    else if (buffered >= 512) {

      char const *tend = lbuf.end;

      char *tlend = lbuf.buf + 512;
      while (*--tlend != '\n')
        ;
      tlend++;

      lbuf.end = tlend;
      lbuf_flush();

      memcpy(lbuf.buf, tlend, tend - tlend);
      lbuf.end = lbuf.buf + (tend - tlend);
    }
  }
}

static void lbuf_putint(uintmax_t i, size_t min_width) {
  char buf[((((((sizeof(uintmax_t) * 8) -
                (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) *
                   146 +
               484) /
              485) +
             (!((__typeof__(uintmax_t))0 < (__typeof__(uintmax_t))-1))) +
            1)];
  char const *umaxstr = umaxtostr(i, buf);
  size_t width = sizeof(buf) - (umaxstr - buf) - 1;
  size_t z = width;

  for (; z < min_width; z++)
    *lbuf.end++ = '0';

  memcpy(lbuf.end, umaxstr, width);
  lbuf.end += width;
}

static void print_uintmaxes(uintmax_t t1, uintmax_t t0) {
  uintmax_t q, r;

  if (t1 == 0)
    lbuf_putint(t0, 0);
  else {

    q = t1 / 1000000000;
    r = t1 % 1000000000;
    do {
      uintmax_t __d1, __d0, __q, __r1, __r0;
      ((void)sizeof(((r) < (1000000000)) ? 1 : 0), __extension__({
         if ((r) < (1000000000))
           ;
         else
           __assert_fail("(r) < (1000000000)", "src/factor.c", 2438,
                         __extension__ __PRETTY_FUNCTION__);
       }));
      __d1 = (1000000000);
      __d0 = 0;
      __r1 = (r);
      __r0 = (t0);
      __q = 0;
      for (unsigned int __i = 64; __i > 0; __i--) {
        do {
          (__d0) = ((__d1) << (64 - (1))) | ((__d0) >> (1));
          (__d1) = (__d1) >> (1);
        } while (0);
        __q <<= 1;
        if (((__r1) > (__d1) || ((__r1) == (__d1) && (__r0) >= (__d0)))) {
          __q++;
          __asm__("subq %5,%q1\n\tsbbq %3,%q0"
                  : "=r"(__r1), "=&r"(__r0)
                  : "0"((UDItype)(__r1)), "rme"((UDItype)(__d1)),
                    "1"((UDItype)(__r0)), "rme"((UDItype)(__d0)));
        }
      }
      (r) = __r0;
      (t0) = __q;
    } while (0);
    print_uintmaxes(q, t0);
    lbuf_putint(r, 9);
  }
}

static void print_factors_single(uintmax_t t1, uintmax_t t0) {
  struct factors factors;

  print_uintmaxes(t1, t0);
  lbuf_putc(':');

  factor(t1, t0, &factors);

  for (unsigned int j = 0; j < factors.nfactors; j++)
    for (unsigned int k = 0; k < factors.e[j]; k++) {
      lbuf_putc(' ');
      print_uintmaxes(0, factors.p[j]);
    }

  if (factors.plarge[1]) {
    lbuf_putc(' ');
    print_uintmaxes(factors.plarge[1], factors.plarge[0]);
  }

  lbuf_putc('\n');
}

static _Bool

print_factors(char const *input) {

  char const *str = input;
  while (*str == ' ')
    str++;
  str += *str == '+';

  uintmax_t t1, t0;

  strtol_error err = strto2uintmax(&t1, &t0, str);

  switch (err) {
  case LONGINT_OK:
    if (((t1 << 1) >> 1) == t1) {
      do {
        if (dev_debug)
          fprintf(stderr, "[using single-precision arithmetic] ");
      } while (0);
      print_factors_single(t1, t0);
      return 1;
    }
    break;

  case LONGINT_OVERFLOW:

    break;

  default:
    error(0, 0, dcgettext(((void *)0), "%s is not a valid positive integer", 5),
          quote(input));
    return 0;
  }

  do {
    if (dev_debug)
      fprintf(stderr, "[using arbitrary-precision arithmetic] ");
  } while (0);
  mpz_t t;
  struct mp_factors factors;

  __gmpz_init_set_str(t, str, 10);

  __gmpz_out_str(stdout, 10, t);
  putchar_unlocked(':');
  mp_factor(t, &factors);

  for (unsigned int j = 0; j < factors.nfactors; j++)
    for (unsigned int k = 0; k < factors.e[j]; k++) {
      putchar_unlocked(' ');

      __gmpz_out_str(stdout, 10, factors.p[j]);
    }

  mp_factor_clear(&factors);

  __gmpz_clear(t);
  putchar_unlocked('\n');
  fflush_unlocked(stdout);
  return 1;
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
    printf(
        dcgettext(((void *)0), "Usage: %s [NUMBER]...\n  or:  %s OPTION\n", 5)

            ,
        program_name, program_name);
    fputs_unlocked(dcgettext(((void *)0),
                             "Print the prime factors of each specified "
                             "integer NUMBER.  If none\nare specified on the "
                             "command line, read them from standard input.\n\n",
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
    emit_ancillary_info("factor");
  }
  exit(status);
}

static _Bool

do_stdin(void) {

  _Bool ok = 1;
  token_buffer tokenbuffer;

  init_tokenbuffer(&tokenbuffer);

  while (1) {
    size_t token_length =
        readtoken(stdin, "\n\t ", sizeof("\n\t ") - 1, &tokenbuffer);
    if (token_length == (size_t)-1)
      break;
    ok &= print_factors(tokenbuffer.buffer);
  }
  free(tokenbuffer.buffer);

  return ok;
}

int main(int argc, char **argv) {
  ;
  set_program_name(argv[0]);
  setlocale(6, "");
  bindtextdomain("coreutils", "/usr/local/share/locale");
  textdomain("coreutils");

  lbuf_alloc();
  atexit(close_stdout);
  atexit(lbuf_flush);

  int c;
  while ((c = getopt_long(argc, argv, "", long_options, ((void *)0))) != -1) {
    switch (c) {
    case DEV_DEBUG_OPTION:
      dev_debug = 1;
      break;

    case GETOPT_HELP_CHAR:
      usage(0);
      break;
      ;

    case GETOPT_VERSION_CHAR:
      version_etc(
          stdout, "factor", "GNU coreutils", Version, ("Paul Rubin"),
          proper_name_utf8("Torbjorn Granlund", "Torbj\303\266rn Granlund"),
          proper_name_utf8("Niels Moller", "Niels M\303\266ller"),
          (char *)((void *)0));
      exit(0);
      break;
      ;

    default:
      usage(1);
    }
  }

  _Bool ok;
  if (argc <= optind)
    ok = do_stdin();
  else {
    ok = 1;
    for (int i = optind; i < argc; i++)
      if (!print_factors(argv[i]))
        ok = 0;
  }
  return ok ? 0 : 1;
}

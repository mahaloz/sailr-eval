

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

extern void __assert_fail(const char *__assertion, const char *__file,
                          unsigned int __line, const char *__function)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

extern void __assert_perror_fail(int __errnum, const char *__file,
                                 unsigned int __line, const char *__function)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

extern void __assert(const char *__assertion, const char *__file, int __line)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

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

extern long int __sysconf(int __name) __attribute__((__nothrow__, __leaf__));

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

extern char *optarg;
extern int optind;

extern int opterr;

extern int optopt;
extern int getopt(int ___argc, char *const *___argv, const char *__shortopts)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));

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

_Bool acl_errno_valid(int) __attribute__((__const__));
int file_has_acl(char const *, struct stat const *);
int qset_acl(char const *, int, mode_t);
int set_acl(char const *, int, mode_t);
int qcopy_acl(char const *, int, char const *, int, mode_t);
int copy_acl(char const *, int, char const *, int, mode_t);
int chmod_or_fchmod(char const *, int, mode_t);

inline void alignfree(void *ptr) { free(ptr); }

inline __attribute__((__malloc__)) __attribute__((__alloc_size__(2)))

void *
alignalloc(idx_t alignment, idx_t size) {
  if ((size_t)-1 < alignment)
    alignment = (size_t)-1;
  if ((size_t)-1 < size)
    size = (size_t)-1;

  return aligned_alloc(alignment, size);
}
void *xalignalloc(idx_t, idx_t) __attribute__((__malloc__))
__attribute__((__alloc_size__(2))) __attribute__((__returns_nonnull__));

enum backup_type {

  no_backups,

  simple_backups,

  numbered_existing_backups,

  numbered_backups
};

extern char const *simple_backup_suffix;

void set_simple_backup_suffix(char const *);
char *backup_file_rename(int, char const *, enum backup_type)
    __attribute__((__malloc__)) __attribute__((__malloc__(free, 1)));
char *find_backup_file_name(int, char const *, enum backup_type)
    __attribute__((__malloc__)) __attribute__((__malloc__(free, 1)))
    __attribute__((__returns_nonnull__));
enum backup_type get_version(char const *context, char const *arg);
enum backup_type xget_version(char const *context, char const *arg);
size_t buffer_lcm(size_t, size_t, size_t) __attribute__((__const__));

enum canonicalize_mode_t {

  CAN_EXISTING = 0,

  CAN_ALL_BUT_LAST = 1,

  CAN_MISSING = 2,

  CAN_NOLINKS = 4
};
typedef enum canonicalize_mode_t canonicalize_mode_t;
char *canonicalize_filename_mode(const char *, canonicalize_mode_t)
    __attribute__((__malloc__)) __attribute__((__malloc__(free, 1)));

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

struct selabel_handle;

enum Sparse_type {
  SPARSE_UNUSED,

  SPARSE_NEVER,

  SPARSE_AUTO,

  SPARSE_ALWAYS
};

enum Reflink_type {

  REFLINK_NEVER,

  REFLINK_AUTO,

  REFLINK_ALWAYS
};

enum Interactive { I_ALWAYS_YES = 1, I_ALWAYS_NO, I_ASK_USER, I_UNSPECIFIED };

enum Dereference_symlink {
  DEREF_UNDEFINED = 1,

  DEREF_NEVER,

  DEREF_COMMAND_LINE_ARGUMENTS,

  DEREF_ALWAYS
};
struct cp_options {
  enum backup_type backup_type;

  enum Dereference_symlink dereference;

  enum Interactive interactive;

  enum Sparse_type sparse_mode;

  mode_t mode;

  _Bool copy_as_regular;

  _Bool unlink_dest_before_opening;

  _Bool unlink_dest_after_failed_open;

  _Bool hard_link;

  _Bool move_mode;

  _Bool install_mode;

  _Bool chown_privileges;

  _Bool owner_privileges;

  _Bool one_file_system;

  _Bool preserve_ownership;

  _Bool preserve_mode;

  _Bool preserve_timestamps;

  _Bool explicit_no_preserve_mode;

  struct selabel_handle *set_security_context;

  _Bool preserve_links;

  _Bool data_copy_required;

  _Bool require_preserve;

  _Bool preserve_security_context;

  _Bool require_preserve_context;

  _Bool preserve_xattr;

  _Bool require_preserve_xattr;

  _Bool reduce_diagnostics;

  _Bool recursive;

  _Bool set_mode;

  _Bool symbolic_link;

  _Bool update;

  _Bool verbose;

  _Bool stdin_tty;

  _Bool open_dangling_dest_symlink;

  _Bool last_file;

  int rename_errno;

  enum Reflink_type reflink_mode;
  Hash_table *dest_info;

  Hash_table *src_info;
};

_Bool copy(char const *src_name, char const *dst_name, int dst_dirfd,
           char const *dst_relname, int nonexistent_dst,
           const struct cp_options *options,

           _Bool *copy_into_self, _Bool *rename_succeeded)
    __attribute__((__nonnull__(1, 2, 4, 6, 7)));

extern _Bool set_process_security_ctx(char const *src_name,
                                      char const *dst_name, mode_t mode,
                                      _Bool new_dst, const struct cp_options *x)
    __attribute__((__nonnull__));

extern _Bool set_file_security_ctx(char const *dst_name,

                                   _Bool recurse, const struct cp_options *x)
    __attribute__((__nonnull__));

void dest_info_init(struct cp_options *) __attribute__((__nonnull__));
void dest_info_free(struct cp_options *) __attribute__((__nonnull__));
void src_info_init(struct cp_options *) __attribute__((__nonnull__));
void src_info_free(struct cp_options *) __attribute__((__nonnull__));

void cp_options_default(struct cp_options *) __attribute__((__nonnull__));

_Bool chown_failure_ok(struct cp_options const *) __attribute__((__nonnull__))
__attribute__((__pure__));
mode_t cached_umask(void);
void hash_init(void);
void forget_created(ino_t ino, dev_t dev);
char *remember_copied(char const *node, ino_t ino, dev_t dev)
    __attribute__((__nonnull__));
char *src_to_dest_lookup(ino_t ino, dev_t dev);

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

typedef enum {
  FADVISE_NORMAL = 0,
  FADVISE_SEQUENTIAL = 2,
  FADVISE_NOREUSE = 5,
  FADVISE_DONTNEED = 4,
  FADVISE_WILLNEED = 3,
  FADVISE_RANDOM = 1

} fadvice_t;
void fdadvise(int fd, off_t offset, off_t len, fadvice_t advice);
void fadvise(FILE *fp, fadvice_t advice);

int open_safer(char const *, int, ...);
int creat_safer(char const *, mode_t);

int openat_safer(int, char const *, int, ...);

extern void record_file(Hash_table *ht, char const *file,
                        struct stat const *stats)

    __attribute__((__nonnull__(2, 3)))

    ;

extern _Bool seen_file(Hash_table const *ht, char const *file,
                       struct stat const *stats);

extern void strmode(mode_t mode, char *str);

extern void filemodestring(struct stat const *statp, char *str);

char *file_name_concat(char const *dir, char const *base, char **base_in_result)
    __attribute__((__malloc__)) __attribute__((__malloc__(free, 1)))
    __attribute__((__returns_nonnull__));

char *mfile_name_concat(char const *dir, char const *base,
                        char **base_in_result) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1)));
extern int force_linkat(int, char const *, int, char const *, int, _Bool, int)
    __attribute__((__nonnull__));
extern int force_symlinkat(char const *, int, char const *, _Bool, int)
    __attribute__((__nonnull__));
extern size_t full_write(int fd, const void *buf, size_t count);

struct F_triple {
  char *name;
  ino_t st_ino;
  dev_t st_dev;
};

extern size_t triple_hash(void const *x, size_t table_size)
    __attribute__((__pure__));
extern _Bool triple_compare_ino_str(void const *x, void const *y)
    __attribute__((__pure__));
extern void triple_free(void *x);

extern size_t triple_hash_no_name(void const *x, size_t table_size)
    __attribute__((__pure__));
extern _Bool triple_compare(void const *x, void const *y);
enum { IO_BUFSIZE = 128 * 1024 };
static inline idx_t io_blksize(struct stat sb) {

  return (((((((9223372036854775807L)) < ((18446744073709551615UL)))
                 ? ((9223372036854775807L))
                 : ((18446744073709551615UL))) /
                2 +
            1) < ((((IO_BUFSIZE) > (((0 < (sb).st_blksize &&
                                      (sb).st_blksize <= ((size_t)-1) / 8 + 1)
                                         ? (sb).st_blksize
                                         : 512)))
                       ? (IO_BUFSIZE)
                       : (((0 < (sb).st_blksize &&
                            (sb).st_blksize <= ((size_t)-1) / 8 + 1)
                               ? (sb).st_blksize
                               : 512)))))
              ? (((((9223372036854775807L)) < ((18446744073709551615UL)))
                      ? ((9223372036854775807L))
                      : ((18446744073709551615UL))) /
                     2 +
                 1)
              : ((((IO_BUFSIZE) > (((0 < (sb).st_blksize &&
                                     (sb).st_blksize <= ((size_t)-1) / 8 + 1)
                                        ? (sb).st_blksize
                                        : 512)))
                      ? (IO_BUFSIZE)
                      : (((0 < (sb).st_blksize &&
                           (sb).st_blksize <= ((size_t)-1) / 8 + 1)
                              ? (sb).st_blksize
                              : 512)))))

      ;
}

extern struct quoting_options quote_quoting_options;

char const *quote_n_mem(int n, char const *arg, size_t argsize);

char const *quote_mem(char const *arg, size_t argsize);

char const *quote_n(int n, char const *arg);

char const *quote(char const *arg);

extern int renameatu(int, char const *, int, char const *, unsigned int);

_Bool same_name(const char *source, const char *dest);

_Bool same_nameat(int, char const *, int, char const *);

enum savedir_option {
  SAVEDIR_SORT_NONE,
  SAVEDIR_SORT_NAME,

  SAVEDIR_SORT_INODE,
  SAVEDIR_SORT_FASTREAD = SAVEDIR_SORT_INODE

};

char *streamsavedir(DIR *, enum savedir_option) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1)));
char *savedir(char const *, enum savedir_option) __attribute__((__malloc__))
__attribute__((__malloc__(free, 1)));

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

enum {

  UTIMECMP_TRUNCATE_SOURCE = 1
};

int utimecmp(char const *, struct stat const *, struct stat const *, int);
int utimecmpat(int, char const *, struct stat const *, struct stat const *,
               int);

int fdutimens(int, char const *, struct timespec const[2]);
int utimens(char const *, struct timespec const[2]);
int lutimens(char const *, struct timespec const[2]);

int fdutimensat(int fd, int dir, char const *name, struct timespec const[2],
                int atflag);

inline int lutimensat(int dir, char const *file,
                      struct timespec const times[2]) {
  return utimensat(dir, file, times, 0x100);
}

_Bool can_write_any_file(void);

extern char *areadlink(char const *filename)
    __attribute__((__malloc__(free, 1)));
extern char *areadlink_with_size(char const *filename, size_t size_hint)
    __attribute__((__malloc__(free, 1)));

extern char *areadlinkat(int fd, char const *filename)
    __attribute__((__malloc__(free, 1)));

extern char *areadlinkat_with_size(int fd, char const *filename,
                                   size_t size_hint)
    __attribute__((__malloc__(free, 1)));

_Bool yesno(void);
struct selabel_handle;

static inline _Bool

ignorable_ctx_err(int err) {
  return err == 95 || err == 61;
}

extern _Bool

restorecon(struct selabel_handle *selabel_handle, char const *path,
           _Bool recurse);
extern int defaultcon(struct selabel_handle *selabel_handle, char const *path,
                      mode_t mode);

struct error_context {

  void (*error)(struct error_context *, const char *, ...);

  const char *(*quote)(struct error_context *, const char *);

  void (*quote_free)(struct error_context *, const char *);
};
struct error_context;

extern int attr_copy_file(const char *, const char *,
                          int (*)(const char *, struct error_context *),
                          struct error_context *);
extern int attr_copy_fd(const char *, int, const char *, int,
                        int (*)(const char *, struct error_context *),
                        struct error_context *);

extern int attr_copy_check_permissions(const char *, struct error_context *);

extern int attr_copy_action(const char *, struct error_context *);

extern void verror(int __status, int __errnum, const char *__format,
                   va_list __args)
    __attribute__((__format__(__gnu_printf__, 3, 0)));
extern void verror_at_line(int __status, int __errnum, const char *__fname,
                           unsigned int __lineno, const char *__format,
                           va_list __args)
    __attribute__((__format__(__gnu_printf__, 5, 0)));

struct fscrypt_policy_v1 {
  __u8 version;
  __u8 contents_encryption_mode;
  __u8 filenames_encryption_mode;
  __u8 flags;
  __u8 master_key_descriptor[8];
};
struct fscrypt_key {
  __u32 mode;
  __u8 raw[64];
  __u32 size;
};

struct fscrypt_policy_v2 {
  __u8 version;
  __u8 contents_encryption_mode;
  __u8 filenames_encryption_mode;
  __u8 flags;
  __u8 __reserved[4];
  __u8 master_key_identifier[16];
};

struct fscrypt_get_policy_ex_arg {
  __u64 policy_size;
  union {
    __u8 version;
    struct fscrypt_policy_v1 v1;
    struct fscrypt_policy_v2 v2;
  } policy;
};
struct fscrypt_key_specifier {
  __u32 type;
  __u32 __reserved;
  union {
    __u8 __reserved[32];
    __u8 descriptor[8];
    __u8 identifier[16];
  } u;
};

struct fscrypt_provisioning_key_payload {
  __u32 type;
  __u32 __reserved;
  __u8 raw[];
};

struct fscrypt_add_key_arg {
  struct fscrypt_key_specifier key_spec;
  __u32 raw_size;
  __u32 key_id;
  __u32 __reserved[8];
  __u8 raw[];
};

struct fscrypt_remove_key_arg {
  struct fscrypt_key_specifier key_spec;

  __u32 removal_status_flags;
  __u32 __reserved[5];
};

struct fscrypt_get_key_status_arg {

  struct fscrypt_key_specifier key_spec;
  __u32 __reserved[6];

  __u32 status;

  __u32 status_flags;
  __u32 user_count;
  __u32 __out_reserved[13];
};

enum fsconfig_command {
  FSCONFIG_SET_FLAG = 0,
  FSCONFIG_SET_STRING = 1,
  FSCONFIG_SET_BINARY = 2,
  FSCONFIG_SET_PATH = 3,
  FSCONFIG_SET_PATH_EMPTY = 4,
  FSCONFIG_SET_FD = 5,
  FSCONFIG_CMD_CREATE = 6,
  FSCONFIG_CMD_RECONFIGURE = 7,
};
struct mount_attr {
  __u64 attr_set;
  __u64 attr_clr;
  __u64 propagation;
  __u64 userns_fd;
};
struct file_clone_range {
  __s64 src_fd;
  __u64 src_offset;
  __u64 src_length;
  __u64 dest_offset;
};

struct fstrim_range {
  __u64 start;
  __u64 len;
  __u64 minlen;
};

struct file_dedupe_range_info {
  __s64 dest_fd;
  __u64 dest_offset;
  __u64 bytes_deduped;

  __s32 status;
  __u32 reserved;
};

struct file_dedupe_range {
  __u64 src_offset;
  __u64 src_length;
  __u16 dest_count;
  __u16 reserved1;
  __u32 reserved2;
  struct file_dedupe_range_info info[0];
};

struct files_stat_struct {
  unsigned long nr_files;
  unsigned long nr_free_files;
  unsigned long max_files;
};

struct inodes_stat_t {
  long nr_inodes;
  long nr_unused;
  long dummy[5];
};

struct fsxattr {
  __u32 fsx_xflags;
  __u32 fsx_extsize;
  __u32 fsx_nextents;
  __u32 fsx_projid;
  __u32 fsx_cowextsize;
  unsigned char fsx_pad[8];
};
typedef int __kernel_rwf_t;

struct dir_list {
  struct dir_list *parent;
  ino_t ino;
  dev_t dev;
};

static _Bool copy_internal(char const *src_name, char const *dst_name,
                           int dst_dirfd, char const *dst_relname,
                           int nonexistent_dst, struct stat const *parent,
                           struct dir_list *ancestors,
                           const struct cp_options *x,

                           _Bool command_line_arg,

                           _Bool *first_dir_created_per_command_line_arg,

                           _Bool *copy_into_self,

                           _Bool *rename_succeeded);
static _Bool owner_failure_ok(struct cp_options const *x);

static char const *top_level_src_name;
static char const *top_level_dst_name;
static int follow_fstatat(int dirfd, char const *filename, struct stat *st,
                          int flags) {
  int result = fstatat(dirfd, filename, st, flags);

  if (0 && result == 0 && !(flags & 0x100) &&
      ((((st->st_mode)) & 0170000) == (0020000))) {
    static dev_t stdin_rdev;
    static signed char stdin_rdev_status;
    if (stdin_rdev_status == 0) {
      struct stat stdin_st;
      if (stat("/dev/stdin", &stdin_st) == 0 &&
          ((((stdin_st.st_mode)) & 0170000) == (0020000))

          && gnu_dev_minor(stdin_st.st_rdev) == 0) {
        stdin_rdev = stdin_st.st_rdev;
        stdin_rdev_status = 1;
      } else
        stdin_rdev_status = -1;
    }
    if (0 < stdin_rdev_status &&
        gnu_dev_major(stdin_rdev) == gnu_dev_major(st->st_rdev))
      result = fstat(gnu_dev_minor(st->st_rdev), st);
  }

  return result;
}

static int punch_hole(int fd, off_t offset, off_t length) {
  int ret = 0;

  ret = fallocate(fd, 0x02 | 0x01, offset, length);
  if (ret < 0 &&
      (is_ENOTSUP((*__errno_location())) || (*__errno_location()) == 38))
    ret = 0;

  return ret;
}

static _Bool

create_hole(int fd, char const *name, _Bool punch_holes, off_t size) {
  off_t file_end = lseek(fd, size, 1);

  if (file_end < 0) {
    error(0, (*__errno_location()),
          dcgettext(((void *)0), "cannot lseek %s", 5),
          quotearg_style(shell_escape_always_quoting_style, name));
    return 0;
  }

  if (punch_holes && punch_hole(fd, file_end - size, size) < 0) {
    error(0, (*__errno_location()),
          dcgettext(((void *)0), "error deallocating %s", 5),
          quotearg_style(shell_escape_always_quoting_style, name));
    return 0;
  }

  return 1;
}
static _Bool

sparse_copy(int src_fd, int dest_fd, char **abuf, size_t buf_size,
            size_t hole_size, _Bool punch_holes, _Bool allow_reflink,
            char const *src_name, char const *dst_name, uintmax_t max_n_read,
            off_t *total_n_read,

            _Bool *last_write_made_hole) {
  *last_write_made_hole = 0;
  *total_n_read = 0;

  if (!hole_size && allow_reflink)
    while (max_n_read) {

      ssize_t copy_max = (((0x7fffffffffffffffL) < ((18446744073709551615UL)))
                              ? (0x7fffffffffffffffL)
                              : ((18446744073709551615UL))) >>
                         30 << 30;
      ssize_t n_copied = copy_file_range(
          src_fd, ((void *)0), dest_fd, ((void *)0),

          (((max_n_read) < (copy_max)) ? (max_n_read) : (copy_max)), 0);
      if (n_copied == 0) {

        if (*total_n_read == 0)
          break;
        return 1;
      }
      if (n_copied < 0) {
        if ((*__errno_location()) == 38 || is_ENOTSUP((*__errno_location())) ||
            (*__errno_location()) == 22 || (*__errno_location()) == 9

            || (*__errno_location()) == 18 || (*__errno_location()) == 26)
          break;

        if ((*__errno_location()) == 1 && *total_n_read == 0)
          break;

        if ((*__errno_location()) == 4)
          n_copied = 0;
        else {
          error(
              0, (*__errno_location()),
              dcgettext(((void *)0), "error copying %s to %s", 5),
              quotearg_n_style(0, shell_escape_always_quoting_style, src_name),
              quotearg_n_style(1, shell_escape_always_quoting_style, dst_name));
          return 0;
        }
      }
      max_n_read -= n_copied;
      *total_n_read += n_copied;
    }

  _Bool make_hole = 0;
  off_t psize = 0;

  while (max_n_read) {
    if (!*abuf)
      *abuf = xalignalloc(getpagesize(), buf_size);
    char *buf = *abuf;
    ssize_t n_read = read(
        src_fd, buf, (((max_n_read) < (buf_size)) ? (max_n_read) : (buf_size)));
    if (n_read < 0) {
      if ((*__errno_location()) == 4)
        continue;
      error(0, (*__errno_location()),
            dcgettext(((void *)0), "error reading %s", 5),
            quotearg_style(shell_escape_always_quoting_style, src_name));
      return 0;
    }
    if (n_read == 0)
      break;
    max_n_read -= n_read;
    *total_n_read += n_read;

    size_t csize = hole_size ? hole_size : buf_size;
    char *cbuf = buf;
    char *pbuf = buf;

    while (n_read) {

      _Bool prev_hole = make_hole;
      csize = (((csize) < (n_read)) ? (csize) : (n_read));

      if (hole_size && csize)
        make_hole = is_nul(cbuf, csize);

      _Bool transition = (make_hole != prev_hole) && psize;

      _Bool last_chunk = (n_read == csize && !make_hole) || !csize;

      if (transition || last_chunk) {
        if (!transition)
          psize += csize;

        if (!prev_hole) {
          if (full_write(dest_fd, pbuf, psize) != psize) {
            error(0, (*__errno_location()),
                  dcgettext(((void *)0), "error writing %s", 5),
                  quotearg_style(shell_escape_always_quoting_style, dst_name));
            return 0;
          }
        } else {
          if (!create_hole(dest_fd, dst_name, punch_holes, psize))
            return 0;
        }

        pbuf = cbuf;
        psize = csize;

        if (last_chunk) {
          if (!csize)
            n_read = 0;

          if (transition)
            csize = 0;
          else
            psize = 0;
        }
      } else {
        if (__builtin_add_overflow(psize, csize, &psize)) {
          error(0, 0, dcgettext(((void *)0), "overflow reading %s", 5),
                quotearg_style(shell_escape_always_quoting_style, src_name));
          return 0;
        }
      }

      n_read -= csize;
      cbuf += csize;
    }

    *last_write_made_hole = make_hole;
  }

  if (make_hole && !create_hole(dest_fd, dst_name, punch_holes, psize))
    return 0;
  else
    return 1;
}

static inline int clone_file(int dest_fd, int src_fd) {

  return ioctl(dest_fd,
               (((1U) << (((0 + 8) + 8) + 14)) | (((0x94)) << (0 + 8)) |
                (((9)) << 0) | ((((sizeof(int)))) << ((0 + 8) + 8))),
               src_fd);
}

static _Bool

write_zeros(int fd, off_t n_bytes) {
  static char *zeros;
  static size_t nz = IO_BUFSIZE;

  if (zeros == ((void *)0)) {
    static char fallback[1024];
    zeros = calloc(nz, 1);
    if (zeros == ((void *)0)) {
      zeros = fallback;
      nz = sizeof fallback;
    }
  }

  while (n_bytes) {
    size_t n = (((nz) < (n_bytes)) ? (nz) : (n_bytes));
    if ((full_write(fd, zeros, n)) != n)
      return 0;
    n_bytes -= n;
  }

  return 1;
}
static _Bool

lseek_copy(int src_fd, int dest_fd, char **abuf, size_t buf_size,
           size_t hole_size, off_t ext_start, off_t src_total_size,
           enum Sparse_type sparse_mode,

           _Bool allow_reflink, char const *src_name, char const *dst_name) {
  off_t last_ext_start = 0;
  off_t last_ext_len = 0;
  off_t dest_pos = 0;

  _Bool wrote_hole_at_eof = 1;

  while (0 <= ext_start) {
    off_t ext_end = lseek(src_fd, ext_start, 4);
    if (ext_end < 0) {
      if ((*__errno_location()) != 6)
        goto cannot_lseek;
      ext_end = src_total_size;
      if (ext_end <= ext_start) {

        src_total_size = lseek(src_fd, 0, 2);
        if (src_total_size < 0)
          goto cannot_lseek;

        if (src_total_size <= ext_start)
          break;

        ext_end = src_total_size;
      }
    }

    if (src_total_size < ext_end)
      src_total_size = ext_end;

    if (lseek(src_fd, ext_start, 0) < 0)
      goto cannot_lseek;

    wrote_hole_at_eof = 0;
    off_t ext_hole_size = ext_start - last_ext_start - last_ext_len;

    if (ext_hole_size) {
      if (sparse_mode != SPARSE_NEVER) {
        if (!create_hole(dest_fd, dst_name, sparse_mode == SPARSE_ALWAYS,
                         ext_hole_size))
          return 0;
        wrote_hole_at_eof = 1;
      } else {

        if (!write_zeros(dest_fd, ext_hole_size)) {
          error(
              0, (*__errno_location()),
              dcgettext(((void *)0), "%s: write failed", 5),
              quotearg_n_style_colon(0, shell_escape_quoting_style, dst_name));
          return 0;
        }
      }
    }

    off_t ext_len = ext_end - ext_start;
    last_ext_start = ext_start;
    last_ext_len = ext_len;

    off_t n_read;

    _Bool read_hole;
    if (!sparse_copy(src_fd, dest_fd, abuf, buf_size,
                     sparse_mode == SPARSE_NEVER ? 0 : hole_size,

                     1, allow_reflink, src_name, dst_name, ext_len, &n_read,
                     &read_hole))
      return 0;

    dest_pos = ext_start + n_read;
    if (n_read)
      wrote_hole_at_eof = read_hole;
    if (n_read < ext_len) {

      src_total_size = dest_pos;
      break;
    }

    ext_start = lseek(src_fd, dest_pos, 3);
    if (ext_start < 0 && (*__errno_location()) != 6)
      goto cannot_lseek;
  }
  if ((dest_pos < src_total_size || wrote_hole_at_eof) &&
      !(sparse_mode == SPARSE_NEVER
            ? write_zeros(dest_fd, src_total_size - dest_pos)
            : ftruncate(dest_fd, src_total_size) == 0)) {
    error(0, (*__errno_location()),
          dcgettext(((void *)0), "failed to extend %s", 5),
          quotearg_style(shell_escape_always_quoting_style, dst_name));
    return 0;
  }

  if (sparse_mode == SPARSE_ALWAYS && dest_pos < src_total_size &&
      punch_hole(dest_fd, dest_pos, src_total_size - dest_pos) < 0) {
    error(0, (*__errno_location()),
          dcgettext(((void *)0), "error deallocating %s", 5),
          quotearg_style(shell_escape_always_quoting_style, dst_name));
    return 0;
  }

  return 1;

cannot_lseek:
  error(0, (*__errno_location()), dcgettext(((void *)0), "cannot lseek %s", 5),
        quotearg_style(shell_escape_always_quoting_style, src_name));
  return 0;
}

__attribute__((__pure__)) static _Bool

is_ancestor(const struct stat *sb, const struct dir_list *ancestors) {
  while (ancestors != 0) {
    if (ancestors->ino == sb->st_ino && ancestors->dev == sb->st_dev)
      return 1;
    ancestors = ancestors->parent;
  }
  return 0;
}

static _Bool

errno_unsupported(int err) {
  return err == 95 || err == 61;
}

__attribute__((__format__(printf, 2, 3))) static void
copy_attr_error(struct error_context *ctx, char const *fmt, ...) {
  if (!errno_unsupported((*__errno_location()))) {
    int err = (*__errno_location());
    va_list ap;

    __builtin_va_start(ap, fmt);
    verror(0, err, fmt, ap);

    __builtin_va_end(ap);
  }
}

__attribute__((__format__(printf, 2, 3))) static void
copy_attr_allerror(struct error_context *ctx, char const *fmt, ...) {
  int err = (*__errno_location());
  va_list ap;

  __builtin_va_start(ap, fmt);
  verror(0, err, fmt, ap);

  __builtin_va_end(ap);
}

static char const *copy_attr_quote(struct error_context *ctx, char const *str) {
  return quotearg_style(shell_escape_always_quoting_style, str);
}

static void copy_attr_free(struct error_context *ctx, char const *str) {}

static int check_selinux_attr(char const *name, struct error_context *ctx) {
  return strncmp(name,
                 ""
                 "security.selinux"
                 "",
                 sizeof("security.selinux") - 1) &&
         attr_copy_check_permissions(name, ctx);
}

static _Bool

copy_attr(char const *src_path, int src_fd, char const *dst_path, int dst_fd,
          struct cp_options const *x) {

  _Bool all_errors = (!x->data_copy_required || x->require_preserve_xattr);

  _Bool some_errors = (!all_errors && !x->reduce_diagnostics);
  int (*check)(char const *, struct error_context *) =
      (x->preserve_security_context || x->set_security_context
           ? check_selinux_attr
           : ((void *)0));

  struct error_context *ctx =
      (all_errors || some_errors
           ? (&(struct error_context){.error = all_errors ? copy_attr_allerror
                                                          : copy_attr_error,
                                      .quote = copy_attr_quote,
                                      .quote_free = copy_attr_free})
           : ((void *)0));

  return !(0 <= src_fd && 0 <= dst_fd
               ? attr_copy_fd(src_path, src_fd, dst_path, dst_fd, check, ctx)
               : attr_copy_file(src_path, dst_path, check, ctx));
}
static _Bool

copy_dir(char const *src_name_in, char const *dst_name_in, int dst_dirfd,
         char const *dst_relname_in, _Bool new_dst, const struct stat *src_sb,
         struct dir_list *ancestors, const struct cp_options *x,

         _Bool *first_dir_created_per_command_line_arg,

         _Bool *copy_into_self) {
  char *name_space;
  char *namep;
  struct cp_options non_command_line_options = *x;

  _Bool ok = 1;

  name_space = savedir(src_name_in, SAVEDIR_SORT_FASTREAD);
  if (name_space == ((void *)0)) {

    error(0, (*__errno_location()),
          dcgettext(((void *)0), "cannot access %s", 5),
          quotearg_style(shell_escape_always_quoting_style, src_name_in));
    return 0;
  }

  if (x->dereference == DEREF_COMMAND_LINE_ARGUMENTS)
    non_command_line_options.dereference = DEREF_NEVER;

  _Bool new_first_dir_created = 0;
  namep = name_space;
  while (*namep != '\0') {

    _Bool local_copy_into_self;
    char *src_name = file_name_concat(src_name_in, namep, ((void *)0));
    char *dst_name = file_name_concat(dst_name_in, namep, ((void *)0));

    _Bool first_dir_created = *first_dir_created_per_command_line_arg;

    _Bool rename_succeeded;

    ok &= copy_internal(src_name, dst_name, dst_dirfd,
                        dst_name + (dst_relname_in - dst_name_in), new_dst,
                        src_sb, ancestors, &non_command_line_options, 0,
                        &first_dir_created, &local_copy_into_self,
                        &rename_succeeded);
    *copy_into_self |= local_copy_into_self;

    free(dst_name);
    free(src_name);

    if (local_copy_into_self)
      break;

    new_first_dir_created |= first_dir_created;
    namep += strlen(namep) + 1;
  }
  free(name_space);
  *first_dir_created_per_command_line_arg = new_first_dir_created;

  return ok;
}
static int set_owner(const struct cp_options *x, char const *dst_name,
                     int dst_dirfd, char const *dst_relname, int dest_desc,
                     struct stat const *src_sb, _Bool new_dst,
                     struct stat const *dst_sb) {
  uid_t uid = src_sb->st_uid;
  gid_t gid = src_sb->st_gid;

  if (!new_dst && (x->preserve_mode || x->move_mode || x->set_mode)) {
    mode_t old_mode = dst_sb->st_mode;
    mode_t new_mode =
        (x->preserve_mode || x->move_mode ? src_sb->st_mode : x->mode);
    mode_t restrictive_temp_mode = old_mode & new_mode & (0400 | 0200 | 0100);

    if ((1 ||
         (old_mode &
          (04000 | 02000 | 01000 | (0400 | 0200 | 0100) |
           ((0400 | 0200 | 0100) >> 3) | (((0400 | 0200 | 0100) >> 3) >> 3)) &
          (~new_mode | 04000 | 02000 | 01000))) &&
        qset_acl(dst_name, dest_desc, restrictive_temp_mode) != 0) {
      if (!owner_failure_ok(x))
        error(0, (*__errno_location()),
              dcgettext(((void *)0), "clearing permissions for %s", 5),
              quotearg_style(shell_escape_always_quoting_style, dst_name));
      return -x->require_preserve;
    }
  }

  if (1 && dest_desc != -1) {
    if (fchown(dest_desc, uid, gid) == 0)
      return 1;
    if ((*__errno_location()) == 1 || (*__errno_location()) == 22) {

      int saved_errno = (*__errno_location());
      (__extension__({
        __typeof__(fchown(dest_desc, -1, gid)) __x =
            (fchown(dest_desc, -1, gid));
        (void)__x;
      }));

      (*__errno_location()) = saved_errno;
    }
  } else {
    if (lchownat(dst_dirfd, dst_relname, uid, gid) == 0)
      return 1;
    if ((*__errno_location()) == 1 || (*__errno_location()) == 22) {

      int saved_errno = (*__errno_location());
      (__extension__({
        __typeof__(lchownat(dst_dirfd, dst_relname, -1, gid)) __x =
            (lchownat(dst_dirfd, dst_relname, -1, gid));
        (void)__x;
      }));

      (*__errno_location()) = saved_errno;
    }
  }

  if (!chown_failure_ok(x)) {
    error(0, (*__errno_location()),
          dcgettext(((void *)0), "failed to preserve ownership for %s", 5),
          quotearg_style(shell_escape_always_quoting_style, dst_name));
    if (x->require_preserve)
      return -1;
  }

  return 0;
}

static void set_author(char const *dst_name, int dest_desc,
                       const struct stat *src_sb) {
  (void)dst_name;
  (void)dest_desc;
  (void)src_sb;
}

_Bool

set_process_security_ctx (char const *src_name, char const *dst_name,
                          mode_t mode, 
                                      _Bool 
                                           new_dst, const struct cp_options *x)
{
  if (x->preserve_security_context) {

    _Bool all_errors = !x->data_copy_required || x->require_preserve_context;

    _Bool some_errors = !all_errors && !x->reduce_diagnostics;
    char *con;

    if (0 <= rpl_lgetfilecon(src_name, &con)) {
      if (setfscreatecon(con) < 0) {
        if (all_errors ||
            (some_errors && !errno_unsupported((*__errno_location()))))
          error(0, (*__errno_location()),

                dcgettext(((void *)0),
                          "failed to set default file creation context to %s",
                          5),
                quote(con));
        if (x->require_preserve_context) {
          freecon(con);
          return 0;
        }
      }
      freecon(con);
    } else {
      if (all_errors ||
          (some_errors && !errno_unsupported((*__errno_location())))) {
        error(0, (*__errno_location()),

              dcgettext(((void *)0), "failed to get security context of %s", 5),
              quotearg_style(shell_escape_always_quoting_style, src_name));
      }
      if (x->require_preserve_context)
        return 0;
    }
  } else if (x->set_security_context) {

    if (new_dst && defaultcon(x->set_security_context, dst_name, mode) < 0 &&
        !ignorable_ctx_err((*__errno_location()))) {
      error(0, (*__errno_location()),

            dcgettext(((void *)0),
                      "failed to set default file creation context for %s", 5),
            quotearg_style(shell_escape_always_quoting_style, dst_name));
    }
  }

  return 1;
}

_Bool

set_file_security_ctx (char const *dst_name,
                       
                      _Bool 
                           recurse, const struct cp_options *x)
{

  _Bool all_errors = (!x->data_copy_required || x->require_preserve_context);

  _Bool some_errors = !all_errors && !x->reduce_diagnostics;

  if (!restorecon(x->set_security_context, dst_name, recurse)) {
    if (all_errors ||
        (some_errors && !errno_unsupported((*__errno_location()))))
      error(
          0, (*__errno_location()),
          dcgettext(((void *)0), "failed to set the security context of %s", 5),
          quotearg_n_style(0, shell_escape_always_quoting_style, dst_name));
    return 0;
  }

  return 1;
}

static int fchmod_or_lchmod(int desc, int dirfd, char const *name,
                            mode_t mode) {

  if (0 <= desc)
    return fchmod(desc, mode);

  return lchmodat(dirfd, name, mode);
}

enum scantype {

  ERROR_SCANTYPE,

  PLAIN_SCANTYPE,

  ZERO_SCANTYPE,

  LSEEK_SCANTYPE,
};

union scan_inference {

  off_t ext_start;
};

static enum scantype infer_scantype(int fd, struct stat const *sb,
                                    union scan_inference *scan_inference) {
  if (!(1 && ((((sb->st_mode)) & 0170000) == (0100000))

        && ((*sb).st_blocks) < sb->st_size / 512))
    return PLAIN_SCANTYPE;

  scan_inference->ext_start = lseek(fd, 0, 3);
  if (0 <= scan_inference->ext_start || (*__errno_location()) == 6)
    return LSEEK_SCANTYPE;
  else if ((*__errno_location()) != 22 && !is_ENOTSUP((*__errno_location())))
    return ERROR_SCANTYPE;

  return ZERO_SCANTYPE;
}
static _Bool

copy_reg(char const *src_name, char const *dst_name, int dst_dirfd,
         char const *dst_relname, const struct cp_options *x, mode_t dst_mode,
         mode_t omitted_permissions, _Bool *new_dst,
         struct stat const *src_sb) {
  char *buf = ((void *)0);
  int dest_desc;
  int dest_errno;
  int source_desc;
  mode_t src_mode = src_sb->st_mode;
  mode_t extra_permissions;
  struct stat sb;
  struct stat src_open_sb;
  union scan_inference scan_inference;

  _Bool return_val = 1;

  _Bool data_copy_required = x->data_copy_required;

  _Bool preserve_xattr = 1 & x->preserve_xattr;

  source_desc =
      open_safer(src_name, (00 | 0

                            | (x->dereference == DEREF_NEVER ? 0400000 : 0)));
  if (source_desc < 0) {
    error(0, (*__errno_location()),
          dcgettext(((void *)0), "cannot open %s for reading", 5),
          quotearg_style(shell_escape_always_quoting_style, src_name));
    return 0;
  }

  if (fstat(source_desc, &src_open_sb) != 0) {
    error(0, (*__errno_location()),
          dcgettext(((void *)0), "cannot fstat %s", 5),
          quotearg_style(shell_escape_always_quoting_style, src_name));
    return_val = 0;
    goto close_src_desc;
  }

  if (!((*src_sb).st_ino == (src_open_sb).st_ino &&
        (*src_sb).st_dev == (src_open_sb).st_dev)) {
    error(0, 0,

          dcgettext(((void *)0),
                    "skipping file %s, as it was replaced while being copied",
                    5),
          quotearg_style(shell_escape_always_quoting_style, src_name));
    return_val = 0;
    goto close_src_desc;
  }

  if (!*new_dst) {
    int open_flags =

        01 | 0 | (data_copy_required ? 01000 : 0);
    dest_desc = openat_safer(dst_dirfd, dst_relname, open_flags);
    dest_errno = (*__errno_location());
    if (0 <= dest_desc &&
        (x->set_security_context || x->preserve_security_context)) {
      if (!set_file_security_ctx(dst_name, 0, x)) {
        if (x->require_preserve_context) {
          return_val = 0;
          goto close_src_and_dst_desc;
        }
      }
    }

    if (dest_desc < 0 && dest_errno != 2

        && x->unlink_dest_after_failed_open) {
      if (unlinkat(dst_dirfd, dst_relname, 0) == 0) {
        if (x->verbose)
          printf(dcgettext(((void *)0), "removed %s\n", 5),
                 quotearg_style(shell_escape_always_quoting_style, dst_name));
      } else if ((*__errno_location()) != 2) {
        error(0, (*__errno_location()),
              dcgettext(((void *)0), "cannot remove %s", 5),
              quotearg_style(shell_escape_always_quoting_style, dst_name));
        return_val = 0;
        goto close_src_desc;
      }

      dest_errno = 2;
    }

    if (dest_desc < 0 && dest_errno == 2) {

      if (x->set_security_context) {
        if (!set_process_security_ctx(src_name, dst_name, dst_mode,

                                      1, x)) {
          return_val = 0;
          goto close_src_desc;
        }
      }

      *new_dst = 1;
    }
  }

  if (*new_dst) {
    mode_t open_mode = ((dst_mode & ~omitted_permissions) |
                        (preserve_xattr && !x->owner_privileges ? 0200 : 0));
    extra_permissions = open_mode & ~dst_mode;

    int open_flags = 01 | 0100 | 0;
    dest_desc =
        openat_safer(dst_dirfd, dst_relname, open_flags | 0200, open_mode);
    dest_errno = (*__errno_location());
    if (dest_desc < 0 && dest_errno == 17 && !x->move_mode) {
      char dummy[1];
      if (0 <= readlinkat(dst_dirfd, dst_relname, dummy, sizeof dummy)) {
        if (x->open_dangling_dest_symlink) {
          dest_desc =
              openat_safer(dst_dirfd, dst_relname, open_flags, open_mode);
          dest_errno = (*__errno_location());
        } else {
          error(0, 0,
                dcgettext(((void *)0),
                          "not writing through dangling symlink %s", 5),
                quotearg_style(shell_escape_always_quoting_style, dst_name));
          return_val = 0;
          goto close_src_desc;
        }
      }
    }

    if (dest_desc < 0 && dest_errno == 21

        && *dst_name && dst_name[strlen(dst_name) - 1] == '/')
      dest_errno = 20;
  } else {
    omitted_permissions = extra_permissions = 0;
  }

  if (dest_desc < 0) {
    error(0, dest_errno,
          dcgettext(((void *)0), "cannot create regular file %s", 5),
          quotearg_style(shell_escape_always_quoting_style, dst_name));
    return_val = 0;
    goto close_src_desc;
  }

  if (data_copy_required && x->reflink_mode) {
    if (clone_file(dest_desc, source_desc) == 0)
      data_copy_required = 0;
    else if (x->reflink_mode == REFLINK_ALWAYS) {
      error(0, (*__errno_location()),
            dcgettext(((void *)0), "failed to clone %s from %s", 5),
            quotearg_n_style(0, shell_escape_always_quoting_style, dst_name),
            quotearg_n_style(1, shell_escape_always_quoting_style, src_name));
      return_val = 0;
      goto close_src_and_dst_desc;
    }
  }

  if (!(data_copy_required | x->preserve_ownership | extra_permissions))
    sb.st_mode = 0;
  else if (fstat(dest_desc, &sb) != 0) {
    error(0, (*__errno_location()),
          dcgettext(((void *)0), "cannot fstat %s", 5),
          quotearg_style(shell_escape_always_quoting_style, dst_name));
    return_val = 0;
    goto close_src_and_dst_desc;
  }

  mode_t temporary_mode = sb.st_mode | extra_permissions;
  if (temporary_mode != sb.st_mode &&
      (fchmod_or_lchmod(dest_desc, dst_dirfd, dst_relname, temporary_mode) !=
       0))
    extra_permissions = 0;

  if (data_copy_required) {

    size_t buf_size = io_blksize(sb);
    size_t hole_size =
        ((0 < (sb).st_blksize && (sb).st_blksize <= ((size_t)-1) / 8 + 1)
             ? (sb).st_blksize
             : 512);

    enum scantype scantype =
        infer_scantype(source_desc, &src_open_sb, &scan_inference);
    if (scantype == ERROR_SCANTYPE) {
      error(0, (*__errno_location()),
            dcgettext(((void *)0), "cannot lseek %s", 5),
            quotearg_style(shell_escape_always_quoting_style, src_name));
      return_val = 0;
      goto close_src_and_dst_desc;
    }

    _Bool make_holes =
        (((((sb.st_mode)) & 0170000) == (0100000))

         && (x->sparse_mode == SPARSE_ALWAYS ||
             (x->sparse_mode == SPARSE_AUTO && scantype != PLAIN_SCANTYPE)));

    fdadvise(source_desc, 0, 0, FADVISE_SEQUENTIAL);

    if (!make_holes) {

      size_t blcm_max = ((((18446744073709551615UL)) < (0x7fffffffffffffffL))
                             ? ((18446744073709551615UL))
                             : (0x7fffffffffffffffL));
      size_t blcm = buffer_lcm(io_blksize(src_open_sb), buf_size, blcm_max);

      if (((((src_open_sb.st_mode)) & 0170000) == (0100000)) &&
          src_open_sb.st_size < buf_size)
        buf_size = src_open_sb.st_size + 1;

      buf_size += blcm - 1;
      buf_size -= buf_size % blcm;
      if (buf_size == 0 || blcm_max < buf_size)
        buf_size = blcm;
    }

    off_t n_read;

    _Bool wrote_hole_at_eof = 0;
    if (!(

            scantype == LSEEK_SCANTYPE
                ? lseek_copy(source_desc, dest_desc, &buf, buf_size, hole_size,
                             scan_inference.ext_start, src_open_sb.st_size,
                             make_holes ? x->sparse_mode : SPARSE_NEVER,
                             x->reflink_mode != REFLINK_NEVER, src_name,
                             dst_name)
                :

                sparse_copy(
                    source_desc, dest_desc, &buf, buf_size,
                    make_holes ? hole_size : 0, x->sparse_mode == SPARSE_ALWAYS,
                    x->reflink_mode != REFLINK_NEVER, src_name, dst_name,
                    (18446744073709551615UL), &n_read, &wrote_hole_at_eof))) {
      return_val = 0;
      goto close_src_and_dst_desc;
    } else if (wrote_hole_at_eof && ftruncate(dest_desc, n_read) < 0) {
      error(0, (*__errno_location()),
            dcgettext(((void *)0), "failed to extend %s", 5),
            quotearg_style(shell_escape_always_quoting_style, dst_name));
      return_val = 0;
      goto close_src_and_dst_desc;
    }
  }

  if (x->preserve_timestamps) {
    struct timespec timespec[2];
    timespec[0] = get_stat_atime(src_sb);
    timespec[1] = get_stat_mtime(src_sb);

    if (fdutimensat(dest_desc, dst_dirfd, dst_relname, timespec, 0) != 0) {
      error(0, (*__errno_location()),
            dcgettext(((void *)0), "preserving times for %s", 5),
            quotearg_style(shell_escape_always_quoting_style, dst_name));
      if (x->require_preserve) {
        return_val = 0;
        goto close_src_and_dst_desc;
      }
    }
  }

  if (x->preserve_ownership && !(((*src_sb).st_uid == (sb).st_uid) &&
                                 ((*src_sb).st_gid == (sb).st_gid))) {
    switch (set_owner(x, dst_name, dst_dirfd, dst_relname, dest_desc, src_sb,
                      *new_dst, &sb)) {
    case -1:
      return_val = 0;
      goto close_src_and_dst_desc;

    case 0:
      src_mode &= ~(04000 | 02000 | 01000);
      break;
    }
  }

  if (preserve_xattr) {
    if (!copy_attr(src_name, source_desc, dst_name, dest_desc, x) &&
        x->require_preserve_xattr)
      return_val = 0;
  }

  set_author(dst_name, dest_desc, src_sb);

  if (x->preserve_mode || x->move_mode) {
    if (copy_acl(src_name, source_desc, dst_name, dest_desc, src_mode) != 0 &&
        x->require_preserve)
      return_val = 0;
  } else if (x->set_mode) {
    if (set_acl(dst_name, dest_desc, x->mode) != 0)
      return_val = 0;
  } else if (x->explicit_no_preserve_mode && *new_dst) {
    if (set_acl(dst_name, dest_desc,
                (0400 | 0200 | (0400 >> 3) | (0200 >> 3) | ((0400 >> 3) >> 3) |
                 ((0200 >> 3) >> 3)) &
                    ~cached_umask()) != 0)
      return_val = 0;
  } else if (omitted_permissions | extra_permissions) {
    omitted_permissions &= ~cached_umask();
    if ((omitted_permissions | extra_permissions) &&
        (fchmod_or_lchmod(dest_desc, dst_dirfd, dst_relname,
                          dst_mode & ~cached_umask()) != 0)) {
      error(0, (*__errno_location()),
            dcgettext(((void *)0), "preserving permissions for %s", 5),
            quotearg_style(shell_escape_always_quoting_style, dst_name));
      if (x->require_preserve)
        return_val = 0;
    }
  }

close_src_and_dst_desc:
  if (close(dest_desc) < 0) {
    error(0, (*__errno_location()),
          dcgettext(((void *)0), "failed to close %s", 5),
          quotearg_style(shell_escape_always_quoting_style, dst_name));
    return_val = 0;
  }
close_src_desc:
  if (close(source_desc) < 0) {
    error(0, (*__errno_location()),
          dcgettext(((void *)0), "failed to close %s", 5),
          quotearg_style(shell_escape_always_quoting_style, src_name));
    return_val = 0;
  }

  alignfree(buf);
  return return_val;
}
static _Bool

same_file_ok(char const *src_name, struct stat const *src_sb, int dst_dirfd,
             char const *dst_relname, struct stat const *dst_sb,
             const struct cp_options *x, _Bool *return_now) {
  const struct stat *src_sb_link;
  const struct stat *dst_sb_link;
  struct stat tmp_dst_sb;
  struct stat tmp_src_sb;

  _Bool same_link;

  _Bool same = ((*src_sb).st_ino == (*dst_sb).st_ino &&
                (*src_sb).st_dev == (*dst_sb).st_dev);

  *return_now = 0;

  if (same && x->hard_link) {
    *return_now = 1;
    return 1;
  }

  if (x->dereference == DEREF_NEVER) {
    same_link = same;

    if (((((src_sb->st_mode)) & 0170000) == (0120000)) &&
        ((((dst_sb->st_mode)) & 0170000) == (0120000))) {

      _Bool sn = same_nameat(-100, src_name, dst_dirfd, dst_relname);
      if (!sn) {

        if (x->backup_type != no_backups)
          return 1;

        if (same_link) {
          *return_now = 1;
          return !x->move_mode;
        }
      }

      return !sn;
    }

    src_sb_link = src_sb;
    dst_sb_link = dst_sb;
  } else {
    if (!same)
      return 1;

    if (fstatat(dst_dirfd, dst_relname, &tmp_dst_sb,

                0x100) != 0 ||
        lstat(src_name, &tmp_src_sb) != 0)
      return 1;

    src_sb_link = &tmp_src_sb;
    dst_sb_link = &tmp_dst_sb;

    same_link = ((*src_sb_link).st_ino == (*dst_sb_link).st_ino &&
                 (*src_sb_link).st_dev == (*dst_sb_link).st_dev);

    if (((((src_sb_link->st_mode)) & 0170000) == (0120000)) &&
        ((((dst_sb_link->st_mode)) & 0170000) == (0120000))

        && x->unlink_dest_before_opening)
      return 1;
  }

  if (x->backup_type != no_backups) {
    if (!same_link) {
      if (!x->move_mode && x->dereference != DEREF_NEVER &&
          ((((src_sb_link->st_mode)) & 0170000) == (0120000))

          && !((((dst_sb_link->st_mode)) & 0170000) == (0120000)))
        return 0;

      return 1;
    }

    return !same_nameat(-100, src_name, dst_dirfd, dst_relname);
  }
  if (x->move_mode || x->unlink_dest_before_opening) {

    if (((((dst_sb_link->st_mode)) & 0170000) == (0120000)))
      return 1;

    if (same_link && 1 < dst_sb_link->st_nlink &&
        !same_nameat(-100, src_name, dst_dirfd, dst_relname))
      return !x->move_mode;
  }

  if (!((((src_sb_link->st_mode)) & 0170000) == (0120000)) &&
      !((((dst_sb_link->st_mode)) & 0170000) == (0120000))) {
    if (!((*src_sb_link).st_ino == (*dst_sb_link).st_ino &&
          (*src_sb_link).st_dev == (*dst_sb_link).st_dev))
      return 1;

    if (x->hard_link) {
      *return_now = 1;
      return 1;
    }
  }
  if (x->move_mode && ((((src_sb->st_mode)) & 0170000) == (0120000))

      && 1 < dst_sb_link->st_nlink) {
    char *abs_src = canonicalize_file_name(src_name);
    if (abs_src) {

      _Bool result = !same_nameat(-100, abs_src, dst_dirfd, dst_relname);
      free(abs_src);
      return result;
    }
  }

  if (x->symbolic_link && ((((dst_sb_link->st_mode)) & 0170000) == (0120000)))
    return 1;

  if (x->dereference == DEREF_NEVER) {
    if (!((((src_sb_link->st_mode)) & 0170000) == (0120000)))
      tmp_src_sb = *src_sb_link;
    else if (stat(src_name, &tmp_src_sb) != 0)
      return 1;

    if (!((((dst_sb_link->st_mode)) & 0170000) == (0120000)))
      tmp_dst_sb = *dst_sb_link;
    else if (fstatat(dst_dirfd, dst_relname, &tmp_dst_sb, 0) != 0)
      return 1;

    if (!((tmp_src_sb).st_ino == (tmp_dst_sb).st_ino &&
          (tmp_src_sb).st_dev == (tmp_dst_sb).st_dev))
      return 1;

    if (x->hard_link) {

      *return_now = !((((dst_sb_link->st_mode)) & 0170000) == (0120000));
      return 1;
    }
  }

  return 0;
}

static _Bool

writable_destination(int dst_dirfd, char const *dst_relname, mode_t mode) {
  return (((((mode)) & 0170000) == (0120000))

          || can_write_any_file() ||
          faccessat(dst_dirfd, dst_relname, 2, 0x200) == 0);
}

static _Bool

overwrite_ok(struct cp_options const *x, char const *dst_name, int dst_dirfd,
             char const *dst_relname, struct stat const *dst_sb) {
  if (!writable_destination(dst_dirfd, dst_relname, dst_sb->st_mode)) {
    char perms[12];
    strmode(dst_sb->st_mode, perms);
    perms[10] = '\0';
    fprintf(stderr,
            (x->move_mode || x->unlink_dest_before_opening ||
             x->unlink_dest_after_failed_open)
                ? dcgettext(((void *)0),
                            "%s: replace %s, overriding mode %04lo (%s)? ", 5)

                : dcgettext(((void *)0),
                            "%s: unwritable %s (mode %04lo, %s); try anyway? ",
                            5),
            program_name,
            quotearg_style(shell_escape_always_quoting_style, dst_name),
            (unsigned long int)(dst_sb->st_mode &
                                (04000 | 02000 | 01000 | (0400 | 0200 | 0100) |
                                 ((0400 | 0200 | 0100) >> 3) |
                                 (((0400 | 0200 | 0100) >> 3) >> 3))),
            &perms[1]);
  } else {
    fprintf(stderr, dcgettext(((void *)0), "%s: overwrite %s? ", 5),
            program_name,
            quotearg_style(shell_escape_always_quoting_style, dst_name));
  }

  return yesno();
}

extern void dest_info_init(struct cp_options *x) {
  x->dest_info =
      hash_initialize(61,

                      ((void *)0), triple_hash, triple_compare, triple_free);
  if (!x->dest_info)
    xalloc_die();
}

extern void src_info_init(struct cp_options *x) {
  x->src_info = hash_initialize(61,

                                ((void *)0), triple_hash_no_name,
                                triple_compare, triple_free);
  if (!x->src_info)
    xalloc_die();
}
static _Bool

abandon_move(const struct cp_options *x, char const *dst_name, int dst_dirfd,
             char const *dst_relname, struct stat const *dst_sb) {

  ((void)sizeof((x->move_mode) ? 1 : 0), __extension__({
     if (x->move_mode)
       ;
     else
       __assert_fail("x->move_mode", "src/copy.c", 1808,
                     __extension__ __PRETTY_FUNCTION__);
   }));
  return (x->interactive == I_ALWAYS_NO ||
          ((x->interactive == I_ASK_USER ||
            (x->interactive == I_UNSPECIFIED && x->stdin_tty &&
             !writable_destination(dst_dirfd, dst_relname, dst_sb->st_mode))) &&
           !overwrite_ok(x, dst_name, dst_dirfd, dst_relname, dst_sb)));
}

static void emit_verbose(char const *src, char const *dst,
                         char const *backup_dst_name) {
  printf("%s -> %s",
         quotearg_n_style(0, shell_escape_always_quoting_style, src),
         quotearg_n_style(1, shell_escape_always_quoting_style, dst));
  if (backup_dst_name)
    printf(dcgettext(((void *)0), " (backup: %s)", 5),
           quotearg_style(shell_escape_always_quoting_style, backup_dst_name));
  putchar_unlocked('\n');
}

static void restore_default_fscreatecon_or_die(void) {
  if (setfscreatecon(((void *)0)) != 0)
    ((!!sizeof(struct {
      _Static_assert(
          1,
          "verify_expr ("
          "1"
          ", "
          "(error (1, (*__errno_location ()), dcgettext (((void *)0), \"failed "
          "to restore the default file creation context\", 5)), assume (false))"
          ")");
      int _gl_dummy;
    }))
         ? ((error(1, (*__errno_location()),
                   dcgettext(
                       ((void *)0),
                       "failed to restore the default file creation context",
                       5)),
             ((0) ? (void)0 : __builtin_unreachable())))
         : ((error(1, (*__errno_location()),
                   dcgettext(
                       ((void *)0),
                       "failed to restore the default file creation context",
                       5)),
             ((0) ? (void)0 : __builtin_unreachable()))));
}

static char *subst_suffix(char const *str, char const *suffix,
                          char const *newsuffix) {
  idx_t prefixlen = suffix - str;
  idx_t newsuffixsize = strlen(newsuffix) + 1;
  char *r = ximalloc(prefixlen + newsuffixsize);
  memcpy(r + prefixlen, newsuffix, newsuffixsize);
  return memcpy(r, str, prefixlen);
}
static _Bool

create_hard_link(char const *src_name, int src_dirfd, char const *src_relname,
                 char const *dst_name, int dst_dirfd, char const *dst_relname,

                 _Bool replace, _Bool verbose, _Bool dereference) {
  int err = force_linkat(src_dirfd, src_relname, dst_dirfd, dst_relname,
                         dereference ? 0x400 : 0, replace, -1);
  if (0 < err) {

    char *a_src_name = ((void *)0);
    if (!src_name)
      src_name = a_src_name = subst_suffix(dst_name, dst_relname, src_relname);
    error(0, err, dcgettext(((void *)0), "cannot create hard link %s to %s", 5),
          quotearg_n_style(0, shell_escape_always_quoting_style, dst_name),
          quotearg_n_style(1, shell_escape_always_quoting_style, src_name));
    free(a_src_name);
    return 0;
  }
  if (err < 0 && verbose)
    printf(dcgettext(((void *)0), "removed %s\n", 5),
           quotearg_style(shell_escape_always_quoting_style, dst_name));
  return 1;
}

__attribute__((__pure__)) static inline _Bool

should_dereference(const struct cp_options *x, _Bool command_line_arg) {
  return x->dereference == DEREF_ALWAYS ||
         (x->dereference == DEREF_COMMAND_LINE_ARGUMENTS && command_line_arg);
}

static _Bool

source_is_dst_backup(char const *srcbase, struct stat const *src_st,
                     int dst_dirfd, char const *dst_relname) {
  size_t srcbaselen = strlen(srcbase);
  char const *dstbase = last_component(dst_relname);
  size_t dstbaselen = strlen(dstbase);
  size_t suffixlen = strlen(simple_backup_suffix);
  if (!(srcbaselen == dstbaselen + suffixlen &&
        memcmp(srcbase, dstbase, dstbaselen) == 0 &&
        (strcmp(srcbase + dstbaselen, simple_backup_suffix) == 0)))
    return 0;
  char *dst_back = subst_suffix(dst_relname, dst_relname + strlen(dst_relname),
                                simple_backup_suffix);
  struct stat dst_back_sb;
  int dst_back_status = fstatat(dst_dirfd, dst_back, &dst_back_sb, 0);
  free(dst_back);
  return dst_back_status == 0 && ((*src_st).st_ino == (dst_back_sb).st_ino &&
                                  (*src_st).st_dev == (dst_back_sb).st_dev);
}
static _Bool

copy_internal(char const *src_name, char const *dst_name, int dst_dirfd,
              char const *dst_relname, int nonexistent_dst,
              struct stat const *parent, struct dir_list *ancestors,
              const struct cp_options *x,

              _Bool command_line_arg,

              _Bool *first_dir_created_per_command_line_arg,

              _Bool *copy_into_self,

              _Bool *rename_succeeded) {
  struct stat src_sb;
  struct stat dst_sb;
  mode_t src_mode = 0;
  mode_t dst_mode = 0;
  mode_t dst_mode_bits;
  mode_t omitted_permissions;

  _Bool restore_dst_mode = 0;
  char *earlier_file = ((void *)0);
  char *dst_backup = ((void *)0);

  _Bool delayed_ok;

  _Bool copied_as_regular = 0;

  _Bool dest_is_symlink = 0;

  _Bool have_dst_lstat = 0;

  _Bool new_dst = 0 < nonexistent_dst;

  *copy_into_self = 0;

  int rename_errno = x->rename_errno;
  if (x->move_mode) {
    if (rename_errno < 0)
      rename_errno = (renameatu(-100, src_name, dst_dirfd, dst_relname,

                                (1 << 0))
                          ? (*__errno_location())
                          : 0);
    nonexistent_dst = *rename_succeeded = new_dst = rename_errno == 0;
  }

  if (rename_errno == 0 ? !x->last_file
                        : rename_errno != 17 || x->interactive != I_ALWAYS_NO) {
    char const *name = rename_errno == 0 ? dst_name : src_name;
    int dirfd = rename_errno == 0 ? dst_dirfd : -100;
    char const *relname = rename_errno == 0 ? dst_relname : src_name;
    int fstatat_flags = x->dereference == DEREF_NEVER ? 0x100 : 0;
    if (follow_fstatat(dirfd, relname, &src_sb, fstatat_flags) != 0) {
      error(0, (*__errno_location()),
            dcgettext(((void *)0), "cannot stat %s", 5),
            quotearg_style(shell_escape_always_quoting_style, name));
      return 0;
    }

    src_mode = src_sb.st_mode;

    if (((((src_mode)) & 0170000) == (0040000)) && !x->recursive) {
      error(0, 0,
            !x->install_mode
                ? dcgettext(((void *)0),
                            "-r not specified; omitting directory %s", 5)

                : dcgettext(((void *)0), "omitting directory %s", 5),
            quotearg_style(shell_escape_always_quoting_style, src_name));
      return 0;
    }
  } else {
  }

  if (command_line_arg && x->src_info) {
    if (!((((src_mode)) & 0170000) == (0040000))

        && x->backup_type == no_backups &&
        seen_file(x->src_info, src_name, &src_sb)) {
      error(0, 0,
            dcgettext(((void *)0),
                      "warning: source file %s specified more than once", 5),
            quotearg_style(shell_escape_always_quoting_style, src_name));
      return 1;
    }

    record_file(x->src_info, src_name, &src_sb);
  }

  _Bool dereference = should_dereference(x, command_line_arg);

  if (nonexistent_dst <= 0) {
    if (!(rename_errno == 17 && x->interactive == I_ALWAYS_NO)) {

      _Bool use_lstat =
          ((!((((src_mode)) & 0170000) == (0100000))

            &&
            (!x->copy_as_regular || ((((src_mode)) & 0170000) == (0040000)) ||
             ((((src_mode)) & 0170000) == (0120000)))) ||
           x->move_mode || x->symbolic_link || x->hard_link ||
           x->backup_type != no_backups || x->unlink_dest_before_opening);
      int fstatat_flags = use_lstat ? 0x100 : 0;
      if (!use_lstat && nonexistent_dst < 0)
        new_dst = 1;
      else if (follow_fstatat(dst_dirfd, dst_relname, &dst_sb, fstatat_flags) ==
               0) {
        have_dst_lstat = use_lstat;
        rename_errno = 17;
      } else {
        if ((*__errno_location()) == 40 && x->unlink_dest_after_failed_open)
          ;
        else if ((*__errno_location()) != 2) {
          error(0, (*__errno_location()),
                dcgettext(((void *)0), "cannot stat %s", 5),
                quotearg_style(shell_escape_always_quoting_style, dst_name));
          return 0;
        } else
          new_dst = 1;
      }
    }

    if (rename_errno == 17) {

      _Bool return_now = 0;

      if (x->interactive != I_ALWAYS_NO &&
          !same_file_ok(src_name, &src_sb, dst_dirfd, dst_relname, &dst_sb, x,
                        &return_now)) {
        error(0, 0, dcgettext(((void *)0), "%s and %s are the same file", 5),
              quotearg_n_style(0, shell_escape_always_quoting_style, src_name),
              quotearg_n_style(1, shell_escape_always_quoting_style, dst_name));
        return 0;
      }

      if (x->update && !((((src_mode)) & 0170000) == (0040000))) {

        int options = ((x->preserve_timestamps &&
                        !(x->move_mode && dst_sb.st_dev == src_sb.st_dev))
                           ? UTIMECMP_TRUNCATE_SOURCE
                           : 0);

        if (0 <=
            utimecmpat(dst_dirfd, dst_relname, &dst_sb, &src_sb, options)) {

          if (rename_succeeded)
            *rename_succeeded = 1;

          earlier_file =
              remember_copied(dst_relname, src_sb.st_ino, src_sb.st_dev);
          if (earlier_file) {

            if (!create_hard_link(((void *)0), dst_dirfd, earlier_file,
                                  dst_name, dst_dirfd, dst_relname,

                                  1, x->verbose, dereference)) {
              goto un_backup;
            }
          }

          return 1;
        }
      }
      if (x->move_mode) {
        if (abandon_move(x, dst_name, dst_dirfd, dst_relname, &dst_sb)) {

          if (rename_succeeded)
            *rename_succeeded = 1;
          return 1;
        }
      } else {
        if (!((((src_mode)) & 0170000) == (0040000))

            && (x->interactive == I_ALWAYS_NO ||
                (x->interactive == I_ASK_USER &&
                 !overwrite_ok(x, dst_name, dst_dirfd, dst_relname, &dst_sb))))
          return 1;
      }

      if (return_now)
        return 1;

      if (!((((dst_sb.st_mode)) & 0170000) == (0040000))) {
        if (((((src_mode)) & 0170000) == (0040000))) {
          if (x->move_mode && x->backup_type != no_backups) {

          } else {
            error(0, 0,

                  dcgettext(
                      ((void *)0),
                      "cannot overwrite non-directory %s with directory %s", 5),
                  quotearg_n_style(0, shell_escape_always_quoting_style,
                                   dst_name),
                  quotearg_n_style(1, shell_escape_always_quoting_style,
                                   src_name));
            return 0;
          }
        }
        if (command_line_arg && x->backup_type != numbered_backups &&
            seen_file(x->dest_info, dst_relname, &dst_sb)) {
          error(
              0, 0,

              dcgettext(((void *)0),
                        "will not overwrite just-created %s with %s", 5),
              quotearg_n_style(0, shell_escape_always_quoting_style, dst_name),
              quotearg_n_style(1, shell_escape_always_quoting_style, src_name));
          return 0;
        }
      }

      if (!((((src_mode)) & 0170000) == (0040000))) {
        if (((((dst_sb.st_mode)) & 0170000) == (0040000))) {
          if (x->move_mode && x->backup_type != no_backups) {

          } else {
            error(0, 0,

                  dcgettext(((void *)0),
                            "cannot overwrite directory %s with non-directory",
                            5),
                  quotearg_style(shell_escape_always_quoting_style, dst_name));
            return 0;
          }
        }
      }

      if (x->move_mode) {

        if (((((src_sb.st_mode)) & 0170000) == (0040000)) &&
            !((((dst_sb.st_mode)) & 0170000) == (0040000))

            && x->backup_type == no_backups) {
          error(
              0, 0,

              dcgettext(((void *)0),
                        "cannot move directory onto non-directory: %s -> %s",
                        5),
              quotearg_n_style_colon(0, shell_escape_quoting_style, src_name),
              quotearg_n_style_colon(0, shell_escape_quoting_style, dst_name));
          return 0;
        }
      }

      char const *srcbase;
      if (x->backup_type != no_backups

          && !dot_or_dotdot(srcbase = last_component(src_name))

          && (x->move_mode || !((((dst_sb.st_mode)) & 0170000) == (0040000)))) {

        if (x->backup_type != numbered_backups &&
            source_is_dst_backup(srcbase, &src_sb, dst_dirfd, dst_relname)) {
          char const *fmt;
          fmt =
              (x->move_mode
                   ? dcgettext(
                         ((void *)0),
                         "backing up %s might destroy source;  %s not moved", 5)

                   : dcgettext(
                         ((void *)0),
                         "backing up %s might destroy source;  %s not copied",
                         5));
          error(
              0, 0, fmt,
              quotearg_n_style(0, shell_escape_always_quoting_style, dst_name),
              quotearg_n_style(1, shell_escape_always_quoting_style, src_name));
          return 0;
        }

        char *tmp_backup =
            backup_file_rename(dst_dirfd, dst_relname, x->backup_type);

        if (tmp_backup) {
          idx_t dirlen = dst_relname - dst_name;
          idx_t backupsize = strlen(tmp_backup) + 1;
          dst_backup = __builtin_alloca(dirlen + backupsize);
          memcpy(mempcpy(dst_backup, dst_name, dirlen), tmp_backup, backupsize);
          free(tmp_backup);
        } else if ((*__errno_location()) != 2) {
          error(0, (*__errno_location()),
                dcgettext(((void *)0), "cannot backup %s", 5),
                quotearg_style(shell_escape_always_quoting_style, dst_name));
          return 0;
        }
        new_dst = 1;
      } else if (!((((dst_sb.st_mode)) & 0170000) == (0040000))

                 && !x->move_mode &&
                 (x->unlink_dest_before_opening ||
                  (x->data_copy_required &&
                   ((x->preserve_links && 1 < dst_sb.st_nlink) ||
                    (x->dereference == DEREF_NEVER &&
                     !((((src_sb.st_mode)) & 0170000) == (0100000))))))) {
        if (unlinkat(dst_dirfd, dst_relname, 0) != 0 &&
            (*__errno_location()) != 2) {
          error(0, (*__errno_location()),
                dcgettext(((void *)0), "cannot remove %s", 5),
                quotearg_style(shell_escape_always_quoting_style, dst_name));
          return 0;
        }
        new_dst = 1;
        if (x->verbose)
          printf(dcgettext(((void *)0), "removed %s\n", 5),
                 quotearg_style(shell_escape_always_quoting_style, dst_name));
      }
    }
  }

  if (command_line_arg && x->dest_info && !x->move_mode &&
      x->backup_type == no_backups) {

    _Bool lstat_ok = 1;
    struct stat tmp_buf;
    struct stat *dst_lstat_sb;

    if (have_dst_lstat)
      dst_lstat_sb = &dst_sb;
    else {
      if (fstatat(dst_dirfd, dst_relname, &tmp_buf,

                  0x100) == 0)
        dst_lstat_sb = &tmp_buf;
      else
        lstat_ok = 0;
    }

    if (lstat_ok && ((((dst_lstat_sb->st_mode)) & 0170000) == (0120000))

        && seen_file(x->dest_info, dst_relname, dst_lstat_sb)) {
      error(0, 0,

            dcgettext(((void *)0),
                      "will not copy %s through just-created symlink %s", 5),
            quotearg_n_style(0, shell_escape_always_quoting_style, src_name),
            quotearg_n_style(1, shell_escape_always_quoting_style, dst_name));
      return 0;
    }
  }

  if (x->verbose && !x->move_mode && !((((src_mode)) & 0170000) == (0040000)))
    emit_verbose(src_name, dst_name, dst_backup);
  if (rename_errno == 0)
    earlier_file = ((void *)0);
  else if (x->recursive && ((((src_mode)) & 0170000) == (0040000))) {
    if (command_line_arg)
      earlier_file = remember_copied(dst_relname, src_sb.st_ino, src_sb.st_dev);
    else
      earlier_file = src_to_dest_lookup(src_sb.st_ino, src_sb.st_dev);
  } else if (x->move_mode && src_sb.st_nlink == 1) {
    earlier_file = src_to_dest_lookup(src_sb.st_ino, src_sb.st_dev);
  } else if (x->preserve_links && !x->hard_link &&
             (1 < src_sb.st_nlink ||
              (command_line_arg &&
               x->dereference == DEREF_COMMAND_LINE_ARGUMENTS) ||
              x->dereference == DEREF_ALWAYS)) {
    earlier_file = remember_copied(dst_relname, src_sb.st_ino, src_sb.st_dev);
  }

  if (earlier_file) {

    if (((((src_mode)) & 0170000) == (0040000))) {

      if (same_nameat(-100, src_name, dst_dirfd, earlier_file)) {
        error(0, 0,
              dcgettext(((void *)0),
                        "cannot copy a directory, %s, into itself, %s", 5),
              quotearg_n_style(0, shell_escape_always_quoting_style,
                               top_level_src_name),
              quotearg_n_style(1, shell_escape_always_quoting_style,
                               top_level_dst_name));
        *copy_into_self = 1;
        goto un_backup;
      } else if (same_nameat(dst_dirfd, dst_relname, dst_dirfd, earlier_file)) {
        error(0, 0,
              dcgettext(((void *)0),
                        "warning: source directory %s "
                        "specified more than once",
                        5)

                  ,
              quotearg_style(shell_escape_always_quoting_style,
                             top_level_src_name));

        if (x->move_mode && rename_succeeded)
          *rename_succeeded = 1;

        return 1;
      } else if (x->dereference == DEREF_ALWAYS ||
                 (command_line_arg &&
                  x->dereference == DEREF_COMMAND_LINE_ARGUMENTS)) {

      } else {
        char *earlier = subst_suffix(dst_name, dst_relname, earlier_file);
        error(0, 0,
              dcgettext(((void *)0),
                        "will not create hard link %s to directory %s", 5),
              quotearg_n_style(0, shell_escape_always_quoting_style, dst_name),
              quotearg_n_style(1, shell_escape_always_quoting_style, earlier));
        free(earlier);
        goto un_backup;
      }
    } else {
      if (!create_hard_link(((void *)0), dst_dirfd, earlier_file, dst_name,
                            dst_dirfd, dst_relname,

                            1, x->verbose, dereference))
        goto un_backup;

      return 1;
    }
  }

  if (x->move_mode) {
    if (rename_errno == 17)
      rename_errno = ((renameat(-100, src_name, dst_dirfd, dst_relname) == 0)
                          ? 0
                          : (*__errno_location()));

    if (rename_errno == 0) {
      if (x->verbose) {
        printf(dcgettext(((void *)0), "renamed ", 5));
        emit_verbose(src_name, dst_name, dst_backup);
      }

      if (x->set_security_context) {

        (void)set_file_security_ctx(dst_name, 1, x);
      }

      if (rename_succeeded)
        *rename_succeeded = 1;

      if (command_line_arg && !x->last_file) {

        record_file(x->dest_info, dst_relname, &src_sb);
      }

      return 1;
    }

    if (rename_errno == 22) {

      error(0, 0,
            dcgettext(((void *)0),
                      "cannot move %s to a subdirectory of itself, %s", 5),
            quotearg_n_style(0, shell_escape_always_quoting_style,
                             top_level_src_name),
            quotearg_n_style(1, shell_escape_always_quoting_style,
                             top_level_dst_name));

      *copy_into_self = 1;

      return 1;
    }
    if (rename_errno != 18) {
      error(0, rename_errno,

            dcgettext(((void *)0), "cannot move %s to %s", 5),
            quotearg_n_style(0, shell_escape_always_quoting_style, src_name),
            quotearg_n_style(1, shell_escape_always_quoting_style, dst_name));
      forget_created(src_sb.st_ino, src_sb.st_dev);
      return 0;
    }

    if ((unlinkat(dst_dirfd, dst_relname,

                  ((((src_mode)) & 0170000) == (0040000)) ? 0x200 : 0) != 0) &&
        (*__errno_location()) != 2) {
      error(0, (*__errno_location()),

            dcgettext(
                ((void *)0),
                "inter-device move failed: %s to %s; unable to remove target",
                5),
            quotearg_n_style(0, shell_escape_always_quoting_style, src_name),
            quotearg_n_style(1, shell_escape_always_quoting_style, dst_name));
      forget_created(src_sb.st_ino, src_sb.st_dev);
      return 0;
    }

    if (x->verbose && !((((src_mode)) & 0170000) == (0040000))) {
      printf(dcgettext(((void *)0), "copied ", 5));
      emit_verbose(src_name, dst_name, dst_backup);
    }
    new_dst = 1;
  }

  dst_mode_bits =
      (x->set_mode ? x->mode : src_mode) &
      (04000 | 02000 | 01000 | (0400 | 0200 | 0100) |
       ((0400 | 0200 | 0100) >> 3) | (((0400 | 0200 | 0100) >> 3) >> 3));
  omitted_permissions =
      (dst_mode_bits &
       (x->preserve_ownership
            ? ((0400 | 0200 | 0100) >> 3) | (((0400 | 0200 | 0100) >> 3) >> 3)

        : ((((src_mode)) & 0170000) == (0040000))
            ? (0200 >> 3) | ((0200 >> 3) >> 3)

            : 0));

  delayed_ok = 1;

  if (!set_process_security_ctx(src_name, dst_name, src_mode, new_dst, x))
    return 0;

  if (((((src_mode)) & 0170000) == (0040000))) {
    struct dir_list *dir;

    if (is_ancestor(&src_sb, ancestors)) {
      error(0, 0,
            dcgettext(((void *)0), "cannot copy cyclic symbolic link %s", 5),
            quotearg_style(shell_escape_always_quoting_style, src_name));
      goto un_backup;
    }

    dir = __builtin_alloca(sizeof *dir);
    dir->parent = ancestors;
    dir->ino = src_sb.st_ino;
    dir->dev = src_sb.st_dev;

    if (new_dst || !((((dst_sb.st_mode)) & 0170000) == (0040000))) {

      mode_t mode = dst_mode_bits & ~omitted_permissions;
      if (mkdirat(dst_dirfd, dst_relname, mode) != 0) {
        error(0, (*__errno_location()),
              dcgettext(((void *)0), "cannot create directory %s", 5),
              quotearg_style(shell_escape_always_quoting_style, dst_name));
        goto un_backup;
      }

      if (fstatat(dst_dirfd, dst_relname, &dst_sb,

                  0x100) != 0) {
        error(0, (*__errno_location()),
              dcgettext(((void *)0), "cannot stat %s", 5),
              quotearg_style(shell_escape_always_quoting_style, dst_name));
        goto un_backup;
      } else if ((dst_sb.st_mode & (0400 | 0200 | 0100)) !=
                 (0400 | 0200 | 0100)) {

        dst_mode = dst_sb.st_mode;
        restore_dst_mode = 1;

        if (lchmodat(dst_dirfd, dst_relname, dst_mode | (0400 | 0200 | 0100)) !=
            0) {
          error(0, (*__errno_location()),
                dcgettext(((void *)0), "setting permissions for %s", 5),
                quotearg_style(shell_escape_always_quoting_style, dst_name));
          goto un_backup;
        }
      }

      if (!*first_dir_created_per_command_line_arg) {
        remember_copied(dst_relname, dst_sb.st_ino, dst_sb.st_dev);
        *first_dir_created_per_command_line_arg = 1;
      }

      if (x->verbose) {
        if (x->move_mode)
          printf(dcgettext(((void *)0), "created directory %s\n", 5),
                 quotearg_style(shell_escape_always_quoting_style, dst_name));
        else
          emit_verbose(src_name, dst_name, ((void *)0));
      }
    } else {
      omitted_permissions = 0;

      if (x->set_security_context || x->preserve_security_context)
        if (!set_file_security_ctx(dst_name, 0, x)) {
          if (x->require_preserve_context)
            goto un_backup;
        }
    }

    if (x->one_file_system && parent && parent->st_dev != src_sb.st_dev) {

    } else {

      delayed_ok = copy_dir(
          src_name, dst_name, dst_dirfd, dst_relname, new_dst, &src_sb, dir, x,
          first_dir_created_per_command_line_arg, copy_into_self);
    }
  } else if (x->symbolic_link) {
    dest_is_symlink = 1;
    if (*src_name != '/') {

      struct stat dot_sb;
      struct stat dst_parent_sb;
      char *dst_parent;

      _Bool in_current_dir;

      dst_parent = dir_name(dst_relname);

      in_current_dir =
          ((dst_dirfd == -100 && (strcmp(".", dst_parent) == 0))

           || stat(".", &dot_sb) != 0 ||
           (fstatat(dst_dirfd, dst_parent, &dst_parent_sb, 0) != 0) ||
           ((dot_sb).st_ino == (dst_parent_sb).st_ino &&
            (dot_sb).st_dev == (dst_parent_sb).st_dev));
      free(dst_parent);

      if (!in_current_dir) {
        error(0, 0,

              dcgettext(((void *)0),
                        "%s: can make relative symbolic links only in current "
                        "directory",
                        5),
              quotearg_n_style_colon(0, shell_escape_quoting_style, dst_name));
        goto un_backup;
      }
    }

    int err = force_symlinkat(src_name, dst_dirfd, dst_relname,
                              x->unlink_dest_after_failed_open, -1);
    if (0 < err) {
      error(0, err,
            dcgettext(((void *)0), "cannot create symbolic link %s to %s", 5),
            quotearg_n_style(0, shell_escape_always_quoting_style, dst_name),
            quotearg_n_style(1, shell_escape_always_quoting_style, src_name));
      goto un_backup;
    }
  } else if (x->hard_link && !(!1 && ((((src_mode)) & 0170000) == (0120000))

                               && x->dereference == DEREF_NEVER)) {

    _Bool replace =
        (x->unlink_dest_after_failed_open || x->interactive == I_ASK_USER);
    if (!create_hard_link(src_name, -100, src_name, dst_name, dst_dirfd,
                          dst_relname, replace, 0, dereference))
      goto un_backup;
  } else if (((((src_mode)) & 0170000) == (0100000))

             ||
             (x->copy_as_regular && !((((src_mode)) & 0170000) == (0120000)))) {
    copied_as_regular = 1;
    if (!copy_reg(src_name, dst_name, dst_dirfd, dst_relname, x,
                  dst_mode_bits &
                      ((0400 | 0200 | 0100) | ((0400 | 0200 | 0100) >> 3) |
                       (((0400 | 0200 | 0100) >> 3) >> 3)),
                  omitted_permissions, &new_dst, &src_sb))
      goto un_backup;
  } else if (((((src_mode)) & 0170000) == (0010000))) {

    mode_t mode = src_mode & ~omitted_permissions;
    if (mknodat(dst_dirfd, dst_relname, mode, 0) != 0)
      if (mkfifoat(dst_dirfd, dst_relname, mode & ~0010000) != 0) {
        error(0, (*__errno_location()),
              dcgettext(((void *)0), "cannot create fifo %s", 5),
              quotearg_style(shell_escape_always_quoting_style, dst_name));
        goto un_backup;
      }
  } else if (((((src_mode)) & 0170000) == (0060000)) ||
             ((((src_mode)) & 0170000) == (0020000)) ||
             ((((src_mode)) & 0170000) == (0140000))) {
    mode_t mode = src_mode & ~omitted_permissions;
    if (mknodat(dst_dirfd, dst_relname, mode, src_sb.st_rdev) != 0) {
      error(0, (*__errno_location()),
            dcgettext(((void *)0), "cannot create special file %s", 5),
            quotearg_style(shell_escape_always_quoting_style, dst_name));
      goto un_backup;
    }
  } else if (((((src_mode)) & 0170000) == (0120000))) {
    char *src_link_val = areadlink_with_size(src_name, src_sb.st_size);
    dest_is_symlink = 1;
    if (src_link_val == ((void *)0)) {
      error(0, (*__errno_location()),
            dcgettext(((void *)0), "cannot read symbolic link %s", 5),
            quotearg_style(shell_escape_always_quoting_style, src_name));
      goto un_backup;
    }

    int symlink_err = force_symlinkat(src_link_val, dst_dirfd, dst_relname,
                                      x->unlink_dest_after_failed_open, -1);
    if (0 < symlink_err && x->update && !new_dst &&
        ((((dst_sb.st_mode)) & 0170000) == (0120000))

        && dst_sb.st_size == strlen(src_link_val)) {

      char *dest_link_val =
          areadlinkat_with_size(dst_dirfd, dst_relname, dst_sb.st_size);
      if (dest_link_val) {
        if ((strcmp(dest_link_val, src_link_val) == 0))
          symlink_err = 0;
        free(dest_link_val);
      }
    }
    free(src_link_val);
    if (0 < symlink_err) {
      error(0, symlink_err,
            dcgettext(((void *)0), "cannot create symbolic link %s", 5),
            quotearg_style(shell_escape_always_quoting_style, dst_name));
      goto un_backup;
    }

    if (x->preserve_security_context)
      restore_default_fscreatecon_or_die();

    if (x->preserve_ownership) {

      if (1 &&
          (lchownat(dst_dirfd, dst_relname, src_sb.st_uid, src_sb.st_gid) !=
           0) &&
          !chown_failure_ok(x)) {
        error(0, (*__errno_location()),
              dcgettext(((void *)0), "failed to preserve ownership for %s", 5),
              dst_name);
        if (x->require_preserve)
          goto un_backup;
      } else {
      }
    }
  } else {
    error(0, 0, dcgettext(((void *)0), "%s has unknown file type", 5),
          quotearg_style(shell_escape_always_quoting_style, src_name));
    goto un_backup;
  }

  if (!new_dst && !x->copy_as_regular &&
      !((((src_mode)) & 0170000) == (0040000))

      && (x->set_security_context || x->preserve_security_context)) {
    if (!set_file_security_ctx(dst_name, 0, x)) {
      if (x->require_preserve_context)
        goto un_backup;
    }
  }

  if (command_line_arg && x->dest_info) {

    struct stat sb;
    if (fstatat(dst_dirfd, dst_relname, &sb, 0x100) == 0)
      record_file(x->dest_info, dst_relname, &sb);
  }

  if (x->hard_link && !((((src_mode)) & 0170000) == (0040000))

      && !(!1 && ((((src_mode)) & 0170000) == (0120000))

           && x->dereference == DEREF_NEVER))
    return delayed_ok;

  if (copied_as_regular)
    return delayed_ok;
  if (x->preserve_timestamps) {
    struct timespec timespec[2];
    timespec[0] = get_stat_atime(&src_sb);
    timespec[1] = get_stat_mtime(&src_sb);

    int utimensat_flags = dest_is_symlink ? 0x100 : 0;
    if (utimensat(dst_dirfd, dst_relname, timespec, utimensat_flags) != 0) {
      error(0, (*__errno_location()),
            dcgettext(((void *)0), "preserving times for %s", 5),
            quotearg_style(shell_escape_always_quoting_style, dst_name));
      if (x->require_preserve)
        return 0;
    }
  }

  if (!dest_is_symlink && x->preserve_ownership &&
      (new_dst || !(((src_sb).st_uid == (dst_sb).st_uid) &&
                    ((src_sb).st_gid == (dst_sb).st_gid)))) {
    switch (set_owner(x, dst_name, dst_dirfd, dst_relname, -1, &src_sb, new_dst,
                      &dst_sb)) {
    case -1:
      return 0;

    case 0:
      src_mode &= ~(04000 | 02000 | 01000);
      break;
    }
  }

  if (x->preserve_xattr && !copy_attr(src_name, -1, dst_name, -1, x) &&
      x->require_preserve_xattr)
    return 0;

  if (dest_is_symlink)
    return delayed_ok;

  set_author(dst_name, -1, &src_sb);

  if (x->preserve_mode || x->move_mode) {
    if (copy_acl(src_name, -1, dst_name, -1, src_mode) != 0 &&
        x->require_preserve)
      return 0;
  } else if (x->set_mode) {
    if (set_acl(dst_name, -1, x->mode) != 0)
      return 0;
  } else if (x->explicit_no_preserve_mode && new_dst) {
    int default_permissions =
        ((((src_mode)) & 0170000) == (0040000)) ||
                ((((src_mode)) & 0170000) == (0140000))

            ? ((0400 | 0200 | 0100) | ((0400 | 0200 | 0100) >> 3) |
               (((0400 | 0200 | 0100) >> 3) >> 3))
            : (0400 | 0200 | (0400 >> 3) | (0200 >> 3) | ((0400 >> 3) >> 3) |
               ((0200 >> 3) >> 3));
    if (set_acl(dst_name, -1, default_permissions & ~cached_umask()) != 0)
      return 0;
  } else {
    if (omitted_permissions) {
      omitted_permissions &= ~cached_umask();

      if (omitted_permissions && !restore_dst_mode) {

        if (new_dst && fstatat(dst_dirfd, dst_relname, &dst_sb,

                               0x100) != 0) {
          error(0, (*__errno_location()),
                dcgettext(((void *)0), "cannot stat %s", 5),
                quotearg_style(shell_escape_always_quoting_style, dst_name));
          return 0;
        }
        dst_mode = dst_sb.st_mode;
        if (omitted_permissions & ~dst_mode)
          restore_dst_mode = 1;
      }
    }

    if (restore_dst_mode) {
      if (lchmodat(dst_dirfd, dst_relname, dst_mode | omitted_permissions) !=
          0) {
        error(0, (*__errno_location()),
              dcgettext(((void *)0), "preserving permissions for %s", 5),
              quotearg_style(shell_escape_always_quoting_style, dst_name));
        if (x->require_preserve)
          return 0;
      }
    }
  }

  return delayed_ok;

un_backup:

  if (x->preserve_security_context)
    restore_default_fscreatecon_or_die();

  if (earlier_file == ((void *)0))
    forget_created(src_sb.st_ino, src_sb.st_dev);

  if (dst_backup) {
    char const *dst_relbackup = &dst_backup[dst_relname - dst_name];
    if (renameat(dst_dirfd, dst_relbackup, dst_dirfd, dst_relname) != 0)
      error(0, (*__errno_location()),
            dcgettext(((void *)0), "cannot un-backup %s", 5),
            quotearg_style(shell_escape_always_quoting_style, dst_name));
    else {
      if (x->verbose)
        printf(
            dcgettext(((void *)0), "%s -> %s (unbackup)\n", 5),
            quotearg_n_style(0, shell_escape_always_quoting_style, dst_backup),
            quotearg_n_style(1, shell_escape_always_quoting_style, dst_name));
    }
  }
  return 0;
}

__attribute__((__pure__)) static _Bool

valid_options(const struct cp_options *co) {

  ((void)sizeof((((unsigned int)(co->backup_type) <= numbered_backups)) ? 1
                                                                        : 0),
   __extension__({
     if (((unsigned int)(co->backup_type) <= numbered_backups))
       ;
     else
       __assert_fail("VALID_BACKUP_TYPE (co->backup_type)", "src/copy.c", 3087,
                     __extension__ __PRETTY_FUNCTION__);
   }));

  ((void)sizeof((((co->sparse_mode) == SPARSE_NEVER ||
                  (co->sparse_mode) == SPARSE_AUTO ||
                  (co->sparse_mode) == SPARSE_ALWAYS))
                    ? 1
                    : 0),
   __extension__({
     if (((co->sparse_mode) == SPARSE_NEVER ||
          (co->sparse_mode) == SPARSE_AUTO ||
          (co->sparse_mode) == SPARSE_ALWAYS))
       ;
     else
       __assert_fail("VALID_SPARSE_MODE (co->sparse_mode)", "src/copy.c", 3088,
                     __extension__ __PRETTY_FUNCTION__);
   }));

  ((void)sizeof((((co->reflink_mode) == REFLINK_NEVER ||
                  (co->reflink_mode) == REFLINK_AUTO ||
                  (co->reflink_mode) == REFLINK_ALWAYS))
                    ? 1
                    : 0),
   __extension__({
     if (((co->reflink_mode) == REFLINK_NEVER ||
          (co->reflink_mode) == REFLINK_AUTO ||
          (co->reflink_mode) == REFLINK_ALWAYS))
       ;
     else
       __assert_fail("VALID_REFLINK_MODE (co->reflink_mode)", "src/copy.c",
                     3089, __extension__ __PRETTY_FUNCTION__);
   }));

  ((void)sizeof((!(co->hard_link && co->symbolic_link)) ? 1 : 0),
   __extension__({
     if (!(co->hard_link && co->symbolic_link))
       ;
     else
       __assert_fail("!(co->hard_link && co->symbolic_link)", "src/copy.c",
                     3090, __extension__ __PRETTY_FUNCTION__);
   }));

  ((void)sizeof(
       (!(co->reflink_mode == REFLINK_ALWAYS && co->sparse_mode != SPARSE_AUTO))
           ? 1
           : 0),
   __extension__({
     if (!(co->reflink_mode == REFLINK_ALWAYS &&
           co->sparse_mode != SPARSE_AUTO))
       ;
     else
       __assert_fail("! (co->reflink_mode == REFLINK_ALWAYS && co->sparse_mode "
                     "!= SPARSE_AUTO)",
                     "src/copy.c", 3091, __extension__ __PRETTY_FUNCTION__);
   }))

      ;
  return 1;
}
extern _Bool

copy(char const *src_name, char const *dst_name, int dst_dirfd,
     char const *dst_relname, int nonexistent_dst,
     const struct cp_options *options,

     _Bool *copy_into_self, _Bool *rename_succeeded) {

  ((void)sizeof((valid_options(options)) ? 1 : 0), __extension__({
     if (valid_options(options))
       ;
     else
       __assert_fail("valid_options (options)", "src/copy.c", 3114,
                     __extension__ __PRETTY_FUNCTION__);
   }));
  top_level_src_name = src_name;
  top_level_dst_name = dst_name;

  _Bool first_dir_created_per_command_line_arg = 0;
  return copy_internal(src_name, dst_name, dst_dirfd, dst_relname,
                       nonexistent_dst, ((void *)0), ((void *)0), options, 1,
                       &first_dir_created_per_command_line_arg, copy_into_self,
                       rename_succeeded);
}

extern void cp_options_default(struct cp_options *x) {
  memset(x, 0, sizeof *x);
  x->chown_privileges = x->owner_privileges = (geteuid() == 0);

  x->rename_errno = -1;
}

extern _Bool

chown_failure_ok(struct cp_options const *x) {

  return (((*__errno_location()) == 1 || (*__errno_location()) == 22) &&
          !x->chown_privileges);
}

static _Bool

owner_failure_ok(struct cp_options const *x) {
  return (((*__errno_location()) == 1 || (*__errno_location()) == 22) &&
          !x->owner_privileges);
}

extern mode_t cached_umask(void) {
  static mode_t mask = (mode_t)-1;
  if (mask == (mode_t)-1) {
    mask = umask(0);
    umask(mask);
  }
  return mask;
}

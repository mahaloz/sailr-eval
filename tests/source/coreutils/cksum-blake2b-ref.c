

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

typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;

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
typedef long int intptr_t;

typedef unsigned long int uintptr_t;
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;

typedef long unsigned int size_t;
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

struct __locale_struct {

  struct __locale_data *__locales[13];

  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;

  const char *__names[13];
};

typedef struct __locale_struct *__locale_t;

typedef __locale_t locale_t;

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

typedef long int ptrdiff_t;
typedef int wchar_t;
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld
      __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
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

enum blake2s_constant {
  BLAKE2S_BLOCKBYTES = 64,
  BLAKE2S_OUTBYTES = 32,
  BLAKE2S_KEYBYTES = 32,
  BLAKE2S_SALTBYTES = 8,
  BLAKE2S_PERSONALBYTES = 8
};

enum blake2b_constant {
  BLAKE2B_BLOCKBYTES = 128,
  BLAKE2B_OUTBYTES = 64,
  BLAKE2B_KEYBYTES = 64,
  BLAKE2B_SALTBYTES = 16,
  BLAKE2B_PERSONALBYTES = 16
};

typedef struct blake2s_state__ {
  uint32_t h[8];
  uint32_t t[2];
  uint32_t f[2];
  uint8_t buf[BLAKE2S_BLOCKBYTES];
  size_t buflen;
  size_t outlen;
  uint8_t last_node;
} blake2s_state;

typedef struct blake2b_state__ {
  uint64_t h[8];
  uint64_t t[2];
  uint64_t f[2];
  uint8_t buf[BLAKE2B_BLOCKBYTES];
  size_t buflen;
  size_t outlen;
  uint8_t last_node;
} blake2b_state;

typedef struct blake2sp_state__ {
  blake2s_state S[8][1];
  blake2s_state R[1];
  uint8_t buf[8 * BLAKE2S_BLOCKBYTES];
  size_t buflen;
  size_t outlen;
} blake2sp_state;

typedef struct blake2bp_state__ {
  blake2b_state S[4][1];
  blake2b_state R[1];
  uint8_t buf[4 * BLAKE2B_BLOCKBYTES];
  size_t buflen;
  size_t outlen;
} blake2bp_state;

struct blake2s_param__ {
  uint8_t digest_length;
  uint8_t key_length;
  uint8_t fanout;
  uint8_t depth;
  uint32_t leaf_length;
  uint32_t node_offset;
  uint16_t xof_length;
  uint8_t node_depth;
  uint8_t inner_length;
  uint8_t salt[BLAKE2S_SALTBYTES];
  uint8_t personal[BLAKE2S_PERSONALBYTES];
} __attribute__((__packed__));

typedef struct blake2s_param__ blake2s_param;

struct blake2b_param__ {
  uint8_t digest_length;
  uint8_t key_length;
  uint8_t fanout;
  uint8_t depth;
  uint32_t leaf_length;
  uint32_t node_offset;
  uint32_t xof_length;
  uint8_t node_depth;
  uint8_t inner_length;
  uint8_t reserved[14];
  uint8_t salt[BLAKE2B_SALTBYTES];
  uint8_t personal[BLAKE2B_PERSONALBYTES];
} __attribute__((__packed__));

typedef struct blake2b_param__ blake2b_param;

typedef struct blake2xs_state__ {
  blake2s_state S[1];
  blake2s_param P[1];
} blake2xs_state;

typedef struct blake2xb_state__ {
  blake2b_state S[1];
  blake2b_param P[1];
} blake2xb_state;

enum {
  BLAKE2_DUMMY_1 = 1 / (sizeof(blake2s_param) == BLAKE2S_OUTBYTES),
  BLAKE2_DUMMY_2 = 1 / (sizeof(blake2b_param) == BLAKE2B_OUTBYTES)
};

int blake2s_init(blake2s_state *S, size_t outlen);
int blake2s_init_key(blake2s_state *S, size_t outlen, const void *key,
                     size_t keylen);
int blake2s_init_param(blake2s_state *S, const blake2s_param *P);
int blake2s_update(blake2s_state *S, const void *in, size_t inlen);
int blake2s_final(blake2s_state *S, void *out, size_t outlen);

int blake2b_init(blake2b_state *S, size_t outlen);
int blake2b_init_key(blake2b_state *S, size_t outlen, const void *key,
                     size_t keylen);
int blake2b_init_param(blake2b_state *S, const blake2b_param *P)
    __attribute__((__nonnull__));
int blake2b_update(blake2b_state *S, const void *in, size_t inlen);
int blake2b_final(blake2b_state *S, void *out, size_t outlen);

int blake2sp_init(blake2sp_state *S, size_t outlen);
int blake2sp_init_key(blake2sp_state *S, size_t outlen, const void *key,
                      size_t keylen);
int blake2sp_update(blake2sp_state *S, const void *in, size_t inlen);
int blake2sp_final(blake2sp_state *S, void *out, size_t outlen);

int blake2bp_init(blake2bp_state *S, size_t outlen);
int blake2bp_init_key(blake2bp_state *S, size_t outlen, const void *key,
                      size_t keylen);
int blake2bp_update(blake2bp_state *S, const void *in, size_t inlen);
int blake2bp_final(blake2bp_state *S, void *out, size_t outlen);

int blake2xs_init(blake2xs_state *S, const size_t outlen);
int blake2xs_init_key(blake2xs_state *S, const size_t outlen, const void *key,
                      size_t keylen);
int blake2xs_update(blake2xs_state *S, const void *in, size_t inlen);
int blake2xs_final(blake2xs_state *S, void *out, size_t outlen);

int blake2xb_init(blake2xb_state *S, const size_t outlen);
int blake2xb_init_key(blake2xb_state *S, const size_t outlen, const void *key,
                      size_t keylen);
int blake2xb_update(blake2xb_state *S, const void *in, size_t inlen);
int blake2xb_final(blake2xb_state *S, void *out, size_t outlen);

int blake2s(void *out, size_t outlen, const void *in, size_t inlen,
            const void *key, size_t keylen);
int blake2b(void *out, size_t outlen, const void *in, size_t inlen,
            const void *key, size_t keylen);

int blake2sp(void *out, size_t outlen, const void *in, size_t inlen,
             const void *key, size_t keylen);
int blake2bp(void *out, size_t outlen, const void *in, size_t inlen,
             const void *key, size_t keylen);

int blake2xs(void *out, size_t outlen, const void *in, size_t inlen,
             const void *key, size_t keylen);
int blake2xb(void *out, size_t outlen, const void *in, size_t inlen,
             const void *key, size_t keylen);

int blake2(void *out, size_t outlen, const void *in, size_t inlen,
           const void *key, size_t keylen);

static inline uint32_t load32(const void *src) {

  uint32_t w;
  memcpy(&w, src, sizeof w);
  return w;
}

static inline uint64_t load64(const void *src) {

  uint64_t w;
  memcpy(&w, src, sizeof w);
  return w;
}

static inline uint16_t load16(const void *src) {

  uint16_t w;
  memcpy(&w, src, sizeof w);
  return w;
}

static inline void store16(void *dst, uint16_t w) { memcpy(dst, &w, sizeof w); }

static inline void store32(void *dst, uint32_t w) { memcpy(dst, &w, sizeof w); }

static inline void store64(void *dst, uint64_t w) { memcpy(dst, &w, sizeof w); }

static inline uint64_t load48(const void *src) {
  const uint8_t *p = (const uint8_t *)src;
  return ((uint64_t)(p[0]) << 0) | ((uint64_t)(p[1]) << 8) |
         ((uint64_t)(p[2]) << 16) | ((uint64_t)(p[3]) << 24) |
         ((uint64_t)(p[4]) << 32) | ((uint64_t)(p[5]) << 40);
}

static inline void store48(void *dst, uint64_t w) {
  uint8_t *p = (uint8_t *)dst;
  p[0] = (uint8_t)(w >> 0);
  p[1] = (uint8_t)(w >> 8);
  p[2] = (uint8_t)(w >> 16);
  p[3] = (uint8_t)(w >> 24);
  p[4] = (uint8_t)(w >> 32);
  p[5] = (uint8_t)(w >> 40);
}

static inline uint32_t rotr32(const uint32_t w, const unsigned c) {
  return (w >> c) | (w << (32 - c));
}

static inline uint64_t rotr64(const uint64_t w, const unsigned c) {
  return (w >> c) | (w << (64 - c));
}

static inline void secure_zero_memory(void *v, size_t n) {
  static void *(*const volatile memset_v)(void *, int, size_t) = &memset;
  memset_v(v, 0, n);
}

static const uint64_t blake2b_IV[8] = {
    0x6a09e667f3bcc908ULL, 0xbb67ae8584caa73bULL, 0x3c6ef372fe94f82bULL,
    0xa54ff53a5f1d36f1ULL, 0x510e527fade682d1ULL, 0x9b05688c2b3e6c1fULL,
    0x1f83d9abfb41bd6bULL, 0x5be0cd19137e2179ULL};

static const uint8_t blake2b_sigma[12][16] = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
    {14, 10, 4, 8, 9, 15, 13, 6, 1, 12, 0, 2, 11, 7, 5, 3},
    {11, 8, 12, 0, 5, 2, 15, 13, 10, 14, 3, 6, 7, 1, 9, 4},
    {7, 9, 3, 1, 13, 12, 11, 14, 2, 6, 5, 10, 4, 0, 15, 8},
    {9, 0, 5, 7, 2, 4, 10, 15, 14, 1, 11, 12, 6, 8, 3, 13},
    {2, 12, 6, 10, 0, 11, 8, 3, 4, 13, 7, 5, 15, 14, 1, 9},
    {12, 5, 1, 15, 14, 13, 4, 10, 0, 7, 6, 3, 9, 2, 8, 11},
    {13, 11, 7, 14, 12, 1, 3, 9, 5, 0, 15, 4, 8, 6, 2, 10},
    {6, 15, 14, 9, 11, 3, 0, 8, 12, 2, 13, 7, 1, 4, 10, 5},
    {10, 2, 8, 4, 7, 6, 1, 5, 15, 11, 9, 14, 3, 12, 13, 0},
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
    {14, 10, 4, 8, 9, 15, 13, 6, 1, 12, 0, 2, 11, 7, 5, 3}};

static void blake2b_set_lastnode(blake2b_state *S) { S->f[1] = (uint64_t)-1; }

static int blake2b_is_lastblock(const blake2b_state *S) { return S->f[0] != 0; }

static void blake2b_set_lastblock(blake2b_state *S) {
  if (S->last_node)
    blake2b_set_lastnode(S);

  S->f[0] = (uint64_t)-1;
}

static void blake2b_increment_counter(blake2b_state *S, const uint64_t inc) {
  S->t[0] += inc;
  S->t[1] += (S->t[0] < inc);
}

static void blake2b_init0(blake2b_state *S) {
  size_t i;
  memset(S, 0, sizeof(blake2b_state));

  for (i = 0; i < 8; ++i)
    S->h[i] = blake2b_IV[i];
}

int blake2b_init_param(blake2b_state *S, const blake2b_param *P) {
  const uint8_t *p = (const uint8_t *)(P);
  size_t i;

  blake2b_init0(S);

  for (i = 0; i < 8; ++i)
    S->h[i] ^= load64(p + sizeof(S->h[i]) * i);

  S->outlen = P->digest_length;
  return 0;
}

int blake2b_init(blake2b_state *S, size_t outlen) {
  blake2b_param P[1];

  if ((!outlen) || (outlen > BLAKE2B_OUTBYTES))
    return -1;

  P->digest_length = (uint8_t)outlen;
  P->key_length = 0;
  P->fanout = 1;
  P->depth = 1;
  store32(&P->leaf_length, 0);
  store32(&P->node_offset, 0);
  store32(&P->xof_length, 0);
  P->node_depth = 0;
  P->inner_length = 0;
  memset(P->reserved, 0, sizeof(P->reserved));
  memset(P->salt, 0, sizeof(P->salt));
  memset(P->personal, 0, sizeof(P->personal));
  return blake2b_init_param(S, P);
}

int blake2b_init_key(blake2b_state *S, size_t outlen, const void *key,
                     size_t keylen) {
  blake2b_param P[1];

  if ((!outlen) || (outlen > BLAKE2B_OUTBYTES))
    return -1;

  if (!key || !keylen || keylen > BLAKE2B_KEYBYTES)
    return -1;

  P->digest_length = (uint8_t)outlen;
  P->key_length = (uint8_t)keylen;
  P->fanout = 1;
  P->depth = 1;
  store32(&P->leaf_length, 0);
  store32(&P->node_offset, 0);
  store32(&P->xof_length, 0);
  P->node_depth = 0;
  P->inner_length = 0;
  memset(P->reserved, 0, sizeof(P->reserved));
  memset(P->salt, 0, sizeof(P->salt));
  memset(P->personal, 0, sizeof(P->personal));

  if (blake2b_init_param(S, P) < 0)
    return -1;

  {
    uint8_t block[BLAKE2B_BLOCKBYTES];
    memset(block, 0, BLAKE2B_BLOCKBYTES);
    memcpy(block, key, keylen);
    blake2b_update(S, block, BLAKE2B_BLOCKBYTES);
    secure_zero_memory(block, BLAKE2B_BLOCKBYTES);
  }
  return 0;
}
static void blake2b_compress(blake2b_state *S,
                             const uint8_t block[BLAKE2B_BLOCKBYTES]) {
  uint64_t m[16];
  uint64_t v[16];
  size_t i;

  for (i = 0; i < 16; ++i) {
    m[i] = load64(block + i * sizeof(m[i]));
  }

  for (i = 0; i < 8; ++i) {
    v[i] = S->h[i];
  }

  v[8] = blake2b_IV[0];
  v[9] = blake2b_IV[1];
  v[10] = blake2b_IV[2];
  v[11] = blake2b_IV[3];
  v[12] = blake2b_IV[4] ^ S->t[0];
  v[13] = blake2b_IV[5] ^ S->t[1];
  v[14] = blake2b_IV[6] ^ S->f[0];
  v[15] = blake2b_IV[7] ^ S->f[1];

  do {
    do {
      v[0] = v[0] + v[4] + m[blake2b_sigma[0][2 * 0 + 0]];
      v[12] = rotr64(v[12] ^ v[0], 32);
      v[8] = v[8] + v[12];
      v[4] = rotr64(v[4] ^ v[8], 24);
      v[0] = v[0] + v[4] + m[blake2b_sigma[0][2 * 0 + 1]];
      v[12] = rotr64(v[12] ^ v[0], 16);
      v[8] = v[8] + v[12];
      v[4] = rotr64(v[4] ^ v[8], 63);
    } while (0);
    do {
      v[1] = v[1] + v[5] + m[blake2b_sigma[0][2 * 1 + 0]];
      v[13] = rotr64(v[13] ^ v[1], 32);
      v[9] = v[9] + v[13];
      v[5] = rotr64(v[5] ^ v[9], 24);
      v[1] = v[1] + v[5] + m[blake2b_sigma[0][2 * 1 + 1]];
      v[13] = rotr64(v[13] ^ v[1], 16);
      v[9] = v[9] + v[13];
      v[5] = rotr64(v[5] ^ v[9], 63);
    } while (0);
    do {
      v[2] = v[2] + v[6] + m[blake2b_sigma[0][2 * 2 + 0]];
      v[14] = rotr64(v[14] ^ v[2], 32);
      v[10] = v[10] + v[14];
      v[6] = rotr64(v[6] ^ v[10], 24);
      v[2] = v[2] + v[6] + m[blake2b_sigma[0][2 * 2 + 1]];
      v[14] = rotr64(v[14] ^ v[2], 16);
      v[10] = v[10] + v[14];
      v[6] = rotr64(v[6] ^ v[10], 63);
    } while (0);
    do {
      v[3] = v[3] + v[7] + m[blake2b_sigma[0][2 * 3 + 0]];
      v[15] = rotr64(v[15] ^ v[3], 32);
      v[11] = v[11] + v[15];
      v[7] = rotr64(v[7] ^ v[11], 24);
      v[3] = v[3] + v[7] + m[blake2b_sigma[0][2 * 3 + 1]];
      v[15] = rotr64(v[15] ^ v[3], 16);
      v[11] = v[11] + v[15];
      v[7] = rotr64(v[7] ^ v[11], 63);
    } while (0);
    do {
      v[0] = v[0] + v[5] + m[blake2b_sigma[0][2 * 4 + 0]];
      v[15] = rotr64(v[15] ^ v[0], 32);
      v[10] = v[10] + v[15];
      v[5] = rotr64(v[5] ^ v[10], 24);
      v[0] = v[0] + v[5] + m[blake2b_sigma[0][2 * 4 + 1]];
      v[15] = rotr64(v[15] ^ v[0], 16);
      v[10] = v[10] + v[15];
      v[5] = rotr64(v[5] ^ v[10], 63);
    } while (0);
    do {
      v[1] = v[1] + v[6] + m[blake2b_sigma[0][2 * 5 + 0]];
      v[12] = rotr64(v[12] ^ v[1], 32);
      v[11] = v[11] + v[12];
      v[6] = rotr64(v[6] ^ v[11], 24);
      v[1] = v[1] + v[6] + m[blake2b_sigma[0][2 * 5 + 1]];
      v[12] = rotr64(v[12] ^ v[1], 16);
      v[11] = v[11] + v[12];
      v[6] = rotr64(v[6] ^ v[11], 63);
    } while (0);
    do {
      v[2] = v[2] + v[7] + m[blake2b_sigma[0][2 * 6 + 0]];
      v[13] = rotr64(v[13] ^ v[2], 32);
      v[8] = v[8] + v[13];
      v[7] = rotr64(v[7] ^ v[8], 24);
      v[2] = v[2] + v[7] + m[blake2b_sigma[0][2 * 6 + 1]];
      v[13] = rotr64(v[13] ^ v[2], 16);
      v[8] = v[8] + v[13];
      v[7] = rotr64(v[7] ^ v[8], 63);
    } while (0);
    do {
      v[3] = v[3] + v[4] + m[blake2b_sigma[0][2 * 7 + 0]];
      v[14] = rotr64(v[14] ^ v[3], 32);
      v[9] = v[9] + v[14];
      v[4] = rotr64(v[4] ^ v[9], 24);
      v[3] = v[3] + v[4] + m[blake2b_sigma[0][2 * 7 + 1]];
      v[14] = rotr64(v[14] ^ v[3], 16);
      v[9] = v[9] + v[14];
      v[4] = rotr64(v[4] ^ v[9], 63);
    } while (0);
  } while (0);
  do {
    do {
      v[0] = v[0] + v[4] + m[blake2b_sigma[1][2 * 0 + 0]];
      v[12] = rotr64(v[12] ^ v[0], 32);
      v[8] = v[8] + v[12];
      v[4] = rotr64(v[4] ^ v[8], 24);
      v[0] = v[0] + v[4] + m[blake2b_sigma[1][2 * 0 + 1]];
      v[12] = rotr64(v[12] ^ v[0], 16);
      v[8] = v[8] + v[12];
      v[4] = rotr64(v[4] ^ v[8], 63);
    } while (0);
    do {
      v[1] = v[1] + v[5] + m[blake2b_sigma[1][2 * 1 + 0]];
      v[13] = rotr64(v[13] ^ v[1], 32);
      v[9] = v[9] + v[13];
      v[5] = rotr64(v[5] ^ v[9], 24);
      v[1] = v[1] + v[5] + m[blake2b_sigma[1][2 * 1 + 1]];
      v[13] = rotr64(v[13] ^ v[1], 16);
      v[9] = v[9] + v[13];
      v[5] = rotr64(v[5] ^ v[9], 63);
    } while (0);
    do {
      v[2] = v[2] + v[6] + m[blake2b_sigma[1][2 * 2 + 0]];
      v[14] = rotr64(v[14] ^ v[2], 32);
      v[10] = v[10] + v[14];
      v[6] = rotr64(v[6] ^ v[10], 24);
      v[2] = v[2] + v[6] + m[blake2b_sigma[1][2 * 2 + 1]];
      v[14] = rotr64(v[14] ^ v[2], 16);
      v[10] = v[10] + v[14];
      v[6] = rotr64(v[6] ^ v[10], 63);
    } while (0);
    do {
      v[3] = v[3] + v[7] + m[blake2b_sigma[1][2 * 3 + 0]];
      v[15] = rotr64(v[15] ^ v[3], 32);
      v[11] = v[11] + v[15];
      v[7] = rotr64(v[7] ^ v[11], 24);
      v[3] = v[3] + v[7] + m[blake2b_sigma[1][2 * 3 + 1]];
      v[15] = rotr64(v[15] ^ v[3], 16);
      v[11] = v[11] + v[15];
      v[7] = rotr64(v[7] ^ v[11], 63);
    } while (0);
    do {
      v[0] = v[0] + v[5] + m[blake2b_sigma[1][2 * 4 + 0]];
      v[15] = rotr64(v[15] ^ v[0], 32);
      v[10] = v[10] + v[15];
      v[5] = rotr64(v[5] ^ v[10], 24);
      v[0] = v[0] + v[5] + m[blake2b_sigma[1][2 * 4 + 1]];
      v[15] = rotr64(v[15] ^ v[0], 16);
      v[10] = v[10] + v[15];
      v[5] = rotr64(v[5] ^ v[10], 63);
    } while (0);
    do {
      v[1] = v[1] + v[6] + m[blake2b_sigma[1][2 * 5 + 0]];
      v[12] = rotr64(v[12] ^ v[1], 32);
      v[11] = v[11] + v[12];
      v[6] = rotr64(v[6] ^ v[11], 24);
      v[1] = v[1] + v[6] + m[blake2b_sigma[1][2 * 5 + 1]];
      v[12] = rotr64(v[12] ^ v[1], 16);
      v[11] = v[11] + v[12];
      v[6] = rotr64(v[6] ^ v[11], 63);
    } while (0);
    do {
      v[2] = v[2] + v[7] + m[blake2b_sigma[1][2 * 6 + 0]];
      v[13] = rotr64(v[13] ^ v[2], 32);
      v[8] = v[8] + v[13];
      v[7] = rotr64(v[7] ^ v[8], 24);
      v[2] = v[2] + v[7] + m[blake2b_sigma[1][2 * 6 + 1]];
      v[13] = rotr64(v[13] ^ v[2], 16);
      v[8] = v[8] + v[13];
      v[7] = rotr64(v[7] ^ v[8], 63);
    } while (0);
    do {
      v[3] = v[3] + v[4] + m[blake2b_sigma[1][2 * 7 + 0]];
      v[14] = rotr64(v[14] ^ v[3], 32);
      v[9] = v[9] + v[14];
      v[4] = rotr64(v[4] ^ v[9], 24);
      v[3] = v[3] + v[4] + m[blake2b_sigma[1][2 * 7 + 1]];
      v[14] = rotr64(v[14] ^ v[3], 16);
      v[9] = v[9] + v[14];
      v[4] = rotr64(v[4] ^ v[9], 63);
    } while (0);
  } while (0);
  do {
    do {
      v[0] = v[0] + v[4] + m[blake2b_sigma[2][2 * 0 + 0]];
      v[12] = rotr64(v[12] ^ v[0], 32);
      v[8] = v[8] + v[12];
      v[4] = rotr64(v[4] ^ v[8], 24);
      v[0] = v[0] + v[4] + m[blake2b_sigma[2][2 * 0 + 1]];
      v[12] = rotr64(v[12] ^ v[0], 16);
      v[8] = v[8] + v[12];
      v[4] = rotr64(v[4] ^ v[8], 63);
    } while (0);
    do {
      v[1] = v[1] + v[5] + m[blake2b_sigma[2][2 * 1 + 0]];
      v[13] = rotr64(v[13] ^ v[1], 32);
      v[9] = v[9] + v[13];
      v[5] = rotr64(v[5] ^ v[9], 24);
      v[1] = v[1] + v[5] + m[blake2b_sigma[2][2 * 1 + 1]];
      v[13] = rotr64(v[13] ^ v[1], 16);
      v[9] = v[9] + v[13];
      v[5] = rotr64(v[5] ^ v[9], 63);
    } while (0);
    do {
      v[2] = v[2] + v[6] + m[blake2b_sigma[2][2 * 2 + 0]];
      v[14] = rotr64(v[14] ^ v[2], 32);
      v[10] = v[10] + v[14];
      v[6] = rotr64(v[6] ^ v[10], 24);
      v[2] = v[2] + v[6] + m[blake2b_sigma[2][2 * 2 + 1]];
      v[14] = rotr64(v[14] ^ v[2], 16);
      v[10] = v[10] + v[14];
      v[6] = rotr64(v[6] ^ v[10], 63);
    } while (0);
    do {
      v[3] = v[3] + v[7] + m[blake2b_sigma[2][2 * 3 + 0]];
      v[15] = rotr64(v[15] ^ v[3], 32);
      v[11] = v[11] + v[15];
      v[7] = rotr64(v[7] ^ v[11], 24);
      v[3] = v[3] + v[7] + m[blake2b_sigma[2][2 * 3 + 1]];
      v[15] = rotr64(v[15] ^ v[3], 16);
      v[11] = v[11] + v[15];
      v[7] = rotr64(v[7] ^ v[11], 63);
    } while (0);
    do {
      v[0] = v[0] + v[5] + m[blake2b_sigma[2][2 * 4 + 0]];
      v[15] = rotr64(v[15] ^ v[0], 32);
      v[10] = v[10] + v[15];
      v[5] = rotr64(v[5] ^ v[10], 24);
      v[0] = v[0] + v[5] + m[blake2b_sigma[2][2 * 4 + 1]];
      v[15] = rotr64(v[15] ^ v[0], 16);
      v[10] = v[10] + v[15];
      v[5] = rotr64(v[5] ^ v[10], 63);
    } while (0);
    do {
      v[1] = v[1] + v[6] + m[blake2b_sigma[2][2 * 5 + 0]];
      v[12] = rotr64(v[12] ^ v[1], 32);
      v[11] = v[11] + v[12];
      v[6] = rotr64(v[6] ^ v[11], 24);
      v[1] = v[1] + v[6] + m[blake2b_sigma[2][2 * 5 + 1]];
      v[12] = rotr64(v[12] ^ v[1], 16);
      v[11] = v[11] + v[12];
      v[6] = rotr64(v[6] ^ v[11], 63);
    } while (0);
    do {
      v[2] = v[2] + v[7] + m[blake2b_sigma[2][2 * 6 + 0]];
      v[13] = rotr64(v[13] ^ v[2], 32);
      v[8] = v[8] + v[13];
      v[7] = rotr64(v[7] ^ v[8], 24);
      v[2] = v[2] + v[7] + m[blake2b_sigma[2][2 * 6 + 1]];
      v[13] = rotr64(v[13] ^ v[2], 16);
      v[8] = v[8] + v[13];
      v[7] = rotr64(v[7] ^ v[8], 63);
    } while (0);
    do {
      v[3] = v[3] + v[4] + m[blake2b_sigma[2][2 * 7 + 0]];
      v[14] = rotr64(v[14] ^ v[3], 32);
      v[9] = v[9] + v[14];
      v[4] = rotr64(v[4] ^ v[9], 24);
      v[3] = v[3] + v[4] + m[blake2b_sigma[2][2 * 7 + 1]];
      v[14] = rotr64(v[14] ^ v[3], 16);
      v[9] = v[9] + v[14];
      v[4] = rotr64(v[4] ^ v[9], 63);
    } while (0);
  } while (0);
  do {
    do {
      v[0] = v[0] + v[4] + m[blake2b_sigma[3][2 * 0 + 0]];
      v[12] = rotr64(v[12] ^ v[0], 32);
      v[8] = v[8] + v[12];
      v[4] = rotr64(v[4] ^ v[8], 24);
      v[0] = v[0] + v[4] + m[blake2b_sigma[3][2 * 0 + 1]];
      v[12] = rotr64(v[12] ^ v[0], 16);
      v[8] = v[8] + v[12];
      v[4] = rotr64(v[4] ^ v[8], 63);
    } while (0);
    do {
      v[1] = v[1] + v[5] + m[blake2b_sigma[3][2 * 1 + 0]];
      v[13] = rotr64(v[13] ^ v[1], 32);
      v[9] = v[9] + v[13];
      v[5] = rotr64(v[5] ^ v[9], 24);
      v[1] = v[1] + v[5] + m[blake2b_sigma[3][2 * 1 + 1]];
      v[13] = rotr64(v[13] ^ v[1], 16);
      v[9] = v[9] + v[13];
      v[5] = rotr64(v[5] ^ v[9], 63);
    } while (0);
    do {
      v[2] = v[2] + v[6] + m[blake2b_sigma[3][2 * 2 + 0]];
      v[14] = rotr64(v[14] ^ v[2], 32);
      v[10] = v[10] + v[14];
      v[6] = rotr64(v[6] ^ v[10], 24);
      v[2] = v[2] + v[6] + m[blake2b_sigma[3][2 * 2 + 1]];
      v[14] = rotr64(v[14] ^ v[2], 16);
      v[10] = v[10] + v[14];
      v[6] = rotr64(v[6] ^ v[10], 63);
    } while (0);
    do {
      v[3] = v[3] + v[7] + m[blake2b_sigma[3][2 * 3 + 0]];
      v[15] = rotr64(v[15] ^ v[3], 32);
      v[11] = v[11] + v[15];
      v[7] = rotr64(v[7] ^ v[11], 24);
      v[3] = v[3] + v[7] + m[blake2b_sigma[3][2 * 3 + 1]];
      v[15] = rotr64(v[15] ^ v[3], 16);
      v[11] = v[11] + v[15];
      v[7] = rotr64(v[7] ^ v[11], 63);
    } while (0);
    do {
      v[0] = v[0] + v[5] + m[blake2b_sigma[3][2 * 4 + 0]];
      v[15] = rotr64(v[15] ^ v[0], 32);
      v[10] = v[10] + v[15];
      v[5] = rotr64(v[5] ^ v[10], 24);
      v[0] = v[0] + v[5] + m[blake2b_sigma[3][2 * 4 + 1]];
      v[15] = rotr64(v[15] ^ v[0], 16);
      v[10] = v[10] + v[15];
      v[5] = rotr64(v[5] ^ v[10], 63);
    } while (0);
    do {
      v[1] = v[1] + v[6] + m[blake2b_sigma[3][2 * 5 + 0]];
      v[12] = rotr64(v[12] ^ v[1], 32);
      v[11] = v[11] + v[12];
      v[6] = rotr64(v[6] ^ v[11], 24);
      v[1] = v[1] + v[6] + m[blake2b_sigma[3][2 * 5 + 1]];
      v[12] = rotr64(v[12] ^ v[1], 16);
      v[11] = v[11] + v[12];
      v[6] = rotr64(v[6] ^ v[11], 63);
    } while (0);
    do {
      v[2] = v[2] + v[7] + m[blake2b_sigma[3][2 * 6 + 0]];
      v[13] = rotr64(v[13] ^ v[2], 32);
      v[8] = v[8] + v[13];
      v[7] = rotr64(v[7] ^ v[8], 24);
      v[2] = v[2] + v[7] + m[blake2b_sigma[3][2 * 6 + 1]];
      v[13] = rotr64(v[13] ^ v[2], 16);
      v[8] = v[8] + v[13];
      v[7] = rotr64(v[7] ^ v[8], 63);
    } while (0);
    do {
      v[3] = v[3] + v[4] + m[blake2b_sigma[3][2 * 7 + 0]];
      v[14] = rotr64(v[14] ^ v[3], 32);
      v[9] = v[9] + v[14];
      v[4] = rotr64(v[4] ^ v[9], 24);
      v[3] = v[3] + v[4] + m[blake2b_sigma[3][2 * 7 + 1]];
      v[14] = rotr64(v[14] ^ v[3], 16);
      v[9] = v[9] + v[14];
      v[4] = rotr64(v[4] ^ v[9], 63);
    } while (0);
  } while (0);
  do {
    do {
      v[0] = v[0] + v[4] + m[blake2b_sigma[4][2 * 0 + 0]];
      v[12] = rotr64(v[12] ^ v[0], 32);
      v[8] = v[8] + v[12];
      v[4] = rotr64(v[4] ^ v[8], 24);
      v[0] = v[0] + v[4] + m[blake2b_sigma[4][2 * 0 + 1]];
      v[12] = rotr64(v[12] ^ v[0], 16);
      v[8] = v[8] + v[12];
      v[4] = rotr64(v[4] ^ v[8], 63);
    } while (0);
    do {
      v[1] = v[1] + v[5] + m[blake2b_sigma[4][2 * 1 + 0]];
      v[13] = rotr64(v[13] ^ v[1], 32);
      v[9] = v[9] + v[13];
      v[5] = rotr64(v[5] ^ v[9], 24);
      v[1] = v[1] + v[5] + m[blake2b_sigma[4][2 * 1 + 1]];
      v[13] = rotr64(v[13] ^ v[1], 16);
      v[9] = v[9] + v[13];
      v[5] = rotr64(v[5] ^ v[9], 63);
    } while (0);
    do {
      v[2] = v[2] + v[6] + m[blake2b_sigma[4][2 * 2 + 0]];
      v[14] = rotr64(v[14] ^ v[2], 32);
      v[10] = v[10] + v[14];
      v[6] = rotr64(v[6] ^ v[10], 24);
      v[2] = v[2] + v[6] + m[blake2b_sigma[4][2 * 2 + 1]];
      v[14] = rotr64(v[14] ^ v[2], 16);
      v[10] = v[10] + v[14];
      v[6] = rotr64(v[6] ^ v[10], 63);
    } while (0);
    do {
      v[3] = v[3] + v[7] + m[blake2b_sigma[4][2 * 3 + 0]];
      v[15] = rotr64(v[15] ^ v[3], 32);
      v[11] = v[11] + v[15];
      v[7] = rotr64(v[7] ^ v[11], 24);
      v[3] = v[3] + v[7] + m[blake2b_sigma[4][2 * 3 + 1]];
      v[15] = rotr64(v[15] ^ v[3], 16);
      v[11] = v[11] + v[15];
      v[7] = rotr64(v[7] ^ v[11], 63);
    } while (0);
    do {
      v[0] = v[0] + v[5] + m[blake2b_sigma[4][2 * 4 + 0]];
      v[15] = rotr64(v[15] ^ v[0], 32);
      v[10] = v[10] + v[15];
      v[5] = rotr64(v[5] ^ v[10], 24);
      v[0] = v[0] + v[5] + m[blake2b_sigma[4][2 * 4 + 1]];
      v[15] = rotr64(v[15] ^ v[0], 16);
      v[10] = v[10] + v[15];
      v[5] = rotr64(v[5] ^ v[10], 63);
    } while (0);
    do {
      v[1] = v[1] + v[6] + m[blake2b_sigma[4][2 * 5 + 0]];
      v[12] = rotr64(v[12] ^ v[1], 32);
      v[11] = v[11] + v[12];
      v[6] = rotr64(v[6] ^ v[11], 24);
      v[1] = v[1] + v[6] + m[blake2b_sigma[4][2 * 5 + 1]];
      v[12] = rotr64(v[12] ^ v[1], 16);
      v[11] = v[11] + v[12];
      v[6] = rotr64(v[6] ^ v[11], 63);
    } while (0);
    do {
      v[2] = v[2] + v[7] + m[blake2b_sigma[4][2 * 6 + 0]];
      v[13] = rotr64(v[13] ^ v[2], 32);
      v[8] = v[8] + v[13];
      v[7] = rotr64(v[7] ^ v[8], 24);
      v[2] = v[2] + v[7] + m[blake2b_sigma[4][2 * 6 + 1]];
      v[13] = rotr64(v[13] ^ v[2], 16);
      v[8] = v[8] + v[13];
      v[7] = rotr64(v[7] ^ v[8], 63);
    } while (0);
    do {
      v[3] = v[3] + v[4] + m[blake2b_sigma[4][2 * 7 + 0]];
      v[14] = rotr64(v[14] ^ v[3], 32);
      v[9] = v[9] + v[14];
      v[4] = rotr64(v[4] ^ v[9], 24);
      v[3] = v[3] + v[4] + m[blake2b_sigma[4][2 * 7 + 1]];
      v[14] = rotr64(v[14] ^ v[3], 16);
      v[9] = v[9] + v[14];
      v[4] = rotr64(v[4] ^ v[9], 63);
    } while (0);
  } while (0);
  do {
    do {
      v[0] = v[0] + v[4] + m[blake2b_sigma[5][2 * 0 + 0]];
      v[12] = rotr64(v[12] ^ v[0], 32);
      v[8] = v[8] + v[12];
      v[4] = rotr64(v[4] ^ v[8], 24);
      v[0] = v[0] + v[4] + m[blake2b_sigma[5][2 * 0 + 1]];
      v[12] = rotr64(v[12] ^ v[0], 16);
      v[8] = v[8] + v[12];
      v[4] = rotr64(v[4] ^ v[8], 63);
    } while (0);
    do {
      v[1] = v[1] + v[5] + m[blake2b_sigma[5][2 * 1 + 0]];
      v[13] = rotr64(v[13] ^ v[1], 32);
      v[9] = v[9] + v[13];
      v[5] = rotr64(v[5] ^ v[9], 24);
      v[1] = v[1] + v[5] + m[blake2b_sigma[5][2 * 1 + 1]];
      v[13] = rotr64(v[13] ^ v[1], 16);
      v[9] = v[9] + v[13];
      v[5] = rotr64(v[5] ^ v[9], 63);
    } while (0);
    do {
      v[2] = v[2] + v[6] + m[blake2b_sigma[5][2 * 2 + 0]];
      v[14] = rotr64(v[14] ^ v[2], 32);
      v[10] = v[10] + v[14];
      v[6] = rotr64(v[6] ^ v[10], 24);
      v[2] = v[2] + v[6] + m[blake2b_sigma[5][2 * 2 + 1]];
      v[14] = rotr64(v[14] ^ v[2], 16);
      v[10] = v[10] + v[14];
      v[6] = rotr64(v[6] ^ v[10], 63);
    } while (0);
    do {
      v[3] = v[3] + v[7] + m[blake2b_sigma[5][2 * 3 + 0]];
      v[15] = rotr64(v[15] ^ v[3], 32);
      v[11] = v[11] + v[15];
      v[7] = rotr64(v[7] ^ v[11], 24);
      v[3] = v[3] + v[7] + m[blake2b_sigma[5][2 * 3 + 1]];
      v[15] = rotr64(v[15] ^ v[3], 16);
      v[11] = v[11] + v[15];
      v[7] = rotr64(v[7] ^ v[11], 63);
    } while (0);
    do {
      v[0] = v[0] + v[5] + m[blake2b_sigma[5][2 * 4 + 0]];
      v[15] = rotr64(v[15] ^ v[0], 32);
      v[10] = v[10] + v[15];
      v[5] = rotr64(v[5] ^ v[10], 24);
      v[0] = v[0] + v[5] + m[blake2b_sigma[5][2 * 4 + 1]];
      v[15] = rotr64(v[15] ^ v[0], 16);
      v[10] = v[10] + v[15];
      v[5] = rotr64(v[5] ^ v[10], 63);
    } while (0);
    do {
      v[1] = v[1] + v[6] + m[blake2b_sigma[5][2 * 5 + 0]];
      v[12] = rotr64(v[12] ^ v[1], 32);
      v[11] = v[11] + v[12];
      v[6] = rotr64(v[6] ^ v[11], 24);
      v[1] = v[1] + v[6] + m[blake2b_sigma[5][2 * 5 + 1]];
      v[12] = rotr64(v[12] ^ v[1], 16);
      v[11] = v[11] + v[12];
      v[6] = rotr64(v[6] ^ v[11], 63);
    } while (0);
    do {
      v[2] = v[2] + v[7] + m[blake2b_sigma[5][2 * 6 + 0]];
      v[13] = rotr64(v[13] ^ v[2], 32);
      v[8] = v[8] + v[13];
      v[7] = rotr64(v[7] ^ v[8], 24);
      v[2] = v[2] + v[7] + m[blake2b_sigma[5][2 * 6 + 1]];
      v[13] = rotr64(v[13] ^ v[2], 16);
      v[8] = v[8] + v[13];
      v[7] = rotr64(v[7] ^ v[8], 63);
    } while (0);
    do {
      v[3] = v[3] + v[4] + m[blake2b_sigma[5][2 * 7 + 0]];
      v[14] = rotr64(v[14] ^ v[3], 32);
      v[9] = v[9] + v[14];
      v[4] = rotr64(v[4] ^ v[9], 24);
      v[3] = v[3] + v[4] + m[blake2b_sigma[5][2 * 7 + 1]];
      v[14] = rotr64(v[14] ^ v[3], 16);
      v[9] = v[9] + v[14];
      v[4] = rotr64(v[4] ^ v[9], 63);
    } while (0);
  } while (0);
  do {
    do {
      v[0] = v[0] + v[4] + m[blake2b_sigma[6][2 * 0 + 0]];
      v[12] = rotr64(v[12] ^ v[0], 32);
      v[8] = v[8] + v[12];
      v[4] = rotr64(v[4] ^ v[8], 24);
      v[0] = v[0] + v[4] + m[blake2b_sigma[6][2 * 0 + 1]];
      v[12] = rotr64(v[12] ^ v[0], 16);
      v[8] = v[8] + v[12];
      v[4] = rotr64(v[4] ^ v[8], 63);
    } while (0);
    do {
      v[1] = v[1] + v[5] + m[blake2b_sigma[6][2 * 1 + 0]];
      v[13] = rotr64(v[13] ^ v[1], 32);
      v[9] = v[9] + v[13];
      v[5] = rotr64(v[5] ^ v[9], 24);
      v[1] = v[1] + v[5] + m[blake2b_sigma[6][2 * 1 + 1]];
      v[13] = rotr64(v[13] ^ v[1], 16);
      v[9] = v[9] + v[13];
      v[5] = rotr64(v[5] ^ v[9], 63);
    } while (0);
    do {
      v[2] = v[2] + v[6] + m[blake2b_sigma[6][2 * 2 + 0]];
      v[14] = rotr64(v[14] ^ v[2], 32);
      v[10] = v[10] + v[14];
      v[6] = rotr64(v[6] ^ v[10], 24);
      v[2] = v[2] + v[6] + m[blake2b_sigma[6][2 * 2 + 1]];
      v[14] = rotr64(v[14] ^ v[2], 16);
      v[10] = v[10] + v[14];
      v[6] = rotr64(v[6] ^ v[10], 63);
    } while (0);
    do {
      v[3] = v[3] + v[7] + m[blake2b_sigma[6][2 * 3 + 0]];
      v[15] = rotr64(v[15] ^ v[3], 32);
      v[11] = v[11] + v[15];
      v[7] = rotr64(v[7] ^ v[11], 24);
      v[3] = v[3] + v[7] + m[blake2b_sigma[6][2 * 3 + 1]];
      v[15] = rotr64(v[15] ^ v[3], 16);
      v[11] = v[11] + v[15];
      v[7] = rotr64(v[7] ^ v[11], 63);
    } while (0);
    do {
      v[0] = v[0] + v[5] + m[blake2b_sigma[6][2 * 4 + 0]];
      v[15] = rotr64(v[15] ^ v[0], 32);
      v[10] = v[10] + v[15];
      v[5] = rotr64(v[5] ^ v[10], 24);
      v[0] = v[0] + v[5] + m[blake2b_sigma[6][2 * 4 + 1]];
      v[15] = rotr64(v[15] ^ v[0], 16);
      v[10] = v[10] + v[15];
      v[5] = rotr64(v[5] ^ v[10], 63);
    } while (0);
    do {
      v[1] = v[1] + v[6] + m[blake2b_sigma[6][2 * 5 + 0]];
      v[12] = rotr64(v[12] ^ v[1], 32);
      v[11] = v[11] + v[12];
      v[6] = rotr64(v[6] ^ v[11], 24);
      v[1] = v[1] + v[6] + m[blake2b_sigma[6][2 * 5 + 1]];
      v[12] = rotr64(v[12] ^ v[1], 16);
      v[11] = v[11] + v[12];
      v[6] = rotr64(v[6] ^ v[11], 63);
    } while (0);
    do {
      v[2] = v[2] + v[7] + m[blake2b_sigma[6][2 * 6 + 0]];
      v[13] = rotr64(v[13] ^ v[2], 32);
      v[8] = v[8] + v[13];
      v[7] = rotr64(v[7] ^ v[8], 24);
      v[2] = v[2] + v[7] + m[blake2b_sigma[6][2 * 6 + 1]];
      v[13] = rotr64(v[13] ^ v[2], 16);
      v[8] = v[8] + v[13];
      v[7] = rotr64(v[7] ^ v[8], 63);
    } while (0);
    do {
      v[3] = v[3] + v[4] + m[blake2b_sigma[6][2 * 7 + 0]];
      v[14] = rotr64(v[14] ^ v[3], 32);
      v[9] = v[9] + v[14];
      v[4] = rotr64(v[4] ^ v[9], 24);
      v[3] = v[3] + v[4] + m[blake2b_sigma[6][2 * 7 + 1]];
      v[14] = rotr64(v[14] ^ v[3], 16);
      v[9] = v[9] + v[14];
      v[4] = rotr64(v[4] ^ v[9], 63);
    } while (0);
  } while (0);
  do {
    do {
      v[0] = v[0] + v[4] + m[blake2b_sigma[7][2 * 0 + 0]];
      v[12] = rotr64(v[12] ^ v[0], 32);
      v[8] = v[8] + v[12];
      v[4] = rotr64(v[4] ^ v[8], 24);
      v[0] = v[0] + v[4] + m[blake2b_sigma[7][2 * 0 + 1]];
      v[12] = rotr64(v[12] ^ v[0], 16);
      v[8] = v[8] + v[12];
      v[4] = rotr64(v[4] ^ v[8], 63);
    } while (0);
    do {
      v[1] = v[1] + v[5] + m[blake2b_sigma[7][2 * 1 + 0]];
      v[13] = rotr64(v[13] ^ v[1], 32);
      v[9] = v[9] + v[13];
      v[5] = rotr64(v[5] ^ v[9], 24);
      v[1] = v[1] + v[5] + m[blake2b_sigma[7][2 * 1 + 1]];
      v[13] = rotr64(v[13] ^ v[1], 16);
      v[9] = v[9] + v[13];
      v[5] = rotr64(v[5] ^ v[9], 63);
    } while (0);
    do {
      v[2] = v[2] + v[6] + m[blake2b_sigma[7][2 * 2 + 0]];
      v[14] = rotr64(v[14] ^ v[2], 32);
      v[10] = v[10] + v[14];
      v[6] = rotr64(v[6] ^ v[10], 24);
      v[2] = v[2] + v[6] + m[blake2b_sigma[7][2 * 2 + 1]];
      v[14] = rotr64(v[14] ^ v[2], 16);
      v[10] = v[10] + v[14];
      v[6] = rotr64(v[6] ^ v[10], 63);
    } while (0);
    do {
      v[3] = v[3] + v[7] + m[blake2b_sigma[7][2 * 3 + 0]];
      v[15] = rotr64(v[15] ^ v[3], 32);
      v[11] = v[11] + v[15];
      v[7] = rotr64(v[7] ^ v[11], 24);
      v[3] = v[3] + v[7] + m[blake2b_sigma[7][2 * 3 + 1]];
      v[15] = rotr64(v[15] ^ v[3], 16);
      v[11] = v[11] + v[15];
      v[7] = rotr64(v[7] ^ v[11], 63);
    } while (0);
    do {
      v[0] = v[0] + v[5] + m[blake2b_sigma[7][2 * 4 + 0]];
      v[15] = rotr64(v[15] ^ v[0], 32);
      v[10] = v[10] + v[15];
      v[5] = rotr64(v[5] ^ v[10], 24);
      v[0] = v[0] + v[5] + m[blake2b_sigma[7][2 * 4 + 1]];
      v[15] = rotr64(v[15] ^ v[0], 16);
      v[10] = v[10] + v[15];
      v[5] = rotr64(v[5] ^ v[10], 63);
    } while (0);
    do {
      v[1] = v[1] + v[6] + m[blake2b_sigma[7][2 * 5 + 0]];
      v[12] = rotr64(v[12] ^ v[1], 32);
      v[11] = v[11] + v[12];
      v[6] = rotr64(v[6] ^ v[11], 24);
      v[1] = v[1] + v[6] + m[blake2b_sigma[7][2 * 5 + 1]];
      v[12] = rotr64(v[12] ^ v[1], 16);
      v[11] = v[11] + v[12];
      v[6] = rotr64(v[6] ^ v[11], 63);
    } while (0);
    do {
      v[2] = v[2] + v[7] + m[blake2b_sigma[7][2 * 6 + 0]];
      v[13] = rotr64(v[13] ^ v[2], 32);
      v[8] = v[8] + v[13];
      v[7] = rotr64(v[7] ^ v[8], 24);
      v[2] = v[2] + v[7] + m[blake2b_sigma[7][2 * 6 + 1]];
      v[13] = rotr64(v[13] ^ v[2], 16);
      v[8] = v[8] + v[13];
      v[7] = rotr64(v[7] ^ v[8], 63);
    } while (0);
    do {
      v[3] = v[3] + v[4] + m[blake2b_sigma[7][2 * 7 + 0]];
      v[14] = rotr64(v[14] ^ v[3], 32);
      v[9] = v[9] + v[14];
      v[4] = rotr64(v[4] ^ v[9], 24);
      v[3] = v[3] + v[4] + m[blake2b_sigma[7][2 * 7 + 1]];
      v[14] = rotr64(v[14] ^ v[3], 16);
      v[9] = v[9] + v[14];
      v[4] = rotr64(v[4] ^ v[9], 63);
    } while (0);
  } while (0);
  do {
    do {
      v[0] = v[0] + v[4] + m[blake2b_sigma[8][2 * 0 + 0]];
      v[12] = rotr64(v[12] ^ v[0], 32);
      v[8] = v[8] + v[12];
      v[4] = rotr64(v[4] ^ v[8], 24);
      v[0] = v[0] + v[4] + m[blake2b_sigma[8][2 * 0 + 1]];
      v[12] = rotr64(v[12] ^ v[0], 16);
      v[8] = v[8] + v[12];
      v[4] = rotr64(v[4] ^ v[8], 63);
    } while (0);
    do {
      v[1] = v[1] + v[5] + m[blake2b_sigma[8][2 * 1 + 0]];
      v[13] = rotr64(v[13] ^ v[1], 32);
      v[9] = v[9] + v[13];
      v[5] = rotr64(v[5] ^ v[9], 24);
      v[1] = v[1] + v[5] + m[blake2b_sigma[8][2 * 1 + 1]];
      v[13] = rotr64(v[13] ^ v[1], 16);
      v[9] = v[9] + v[13];
      v[5] = rotr64(v[5] ^ v[9], 63);
    } while (0);
    do {
      v[2] = v[2] + v[6] + m[blake2b_sigma[8][2 * 2 + 0]];
      v[14] = rotr64(v[14] ^ v[2], 32);
      v[10] = v[10] + v[14];
      v[6] = rotr64(v[6] ^ v[10], 24);
      v[2] = v[2] + v[6] + m[blake2b_sigma[8][2 * 2 + 1]];
      v[14] = rotr64(v[14] ^ v[2], 16);
      v[10] = v[10] + v[14];
      v[6] = rotr64(v[6] ^ v[10], 63);
    } while (0);
    do {
      v[3] = v[3] + v[7] + m[blake2b_sigma[8][2 * 3 + 0]];
      v[15] = rotr64(v[15] ^ v[3], 32);
      v[11] = v[11] + v[15];
      v[7] = rotr64(v[7] ^ v[11], 24);
      v[3] = v[3] + v[7] + m[blake2b_sigma[8][2 * 3 + 1]];
      v[15] = rotr64(v[15] ^ v[3], 16);
      v[11] = v[11] + v[15];
      v[7] = rotr64(v[7] ^ v[11], 63);
    } while (0);
    do {
      v[0] = v[0] + v[5] + m[blake2b_sigma[8][2 * 4 + 0]];
      v[15] = rotr64(v[15] ^ v[0], 32);
      v[10] = v[10] + v[15];
      v[5] = rotr64(v[5] ^ v[10], 24);
      v[0] = v[0] + v[5] + m[blake2b_sigma[8][2 * 4 + 1]];
      v[15] = rotr64(v[15] ^ v[0], 16);
      v[10] = v[10] + v[15];
      v[5] = rotr64(v[5] ^ v[10], 63);
    } while (0);
    do {
      v[1] = v[1] + v[6] + m[blake2b_sigma[8][2 * 5 + 0]];
      v[12] = rotr64(v[12] ^ v[1], 32);
      v[11] = v[11] + v[12];
      v[6] = rotr64(v[6] ^ v[11], 24);
      v[1] = v[1] + v[6] + m[blake2b_sigma[8][2 * 5 + 1]];
      v[12] = rotr64(v[12] ^ v[1], 16);
      v[11] = v[11] + v[12];
      v[6] = rotr64(v[6] ^ v[11], 63);
    } while (0);
    do {
      v[2] = v[2] + v[7] + m[blake2b_sigma[8][2 * 6 + 0]];
      v[13] = rotr64(v[13] ^ v[2], 32);
      v[8] = v[8] + v[13];
      v[7] = rotr64(v[7] ^ v[8], 24);
      v[2] = v[2] + v[7] + m[blake2b_sigma[8][2 * 6 + 1]];
      v[13] = rotr64(v[13] ^ v[2], 16);
      v[8] = v[8] + v[13];
      v[7] = rotr64(v[7] ^ v[8], 63);
    } while (0);
    do {
      v[3] = v[3] + v[4] + m[blake2b_sigma[8][2 * 7 + 0]];
      v[14] = rotr64(v[14] ^ v[3], 32);
      v[9] = v[9] + v[14];
      v[4] = rotr64(v[4] ^ v[9], 24);
      v[3] = v[3] + v[4] + m[blake2b_sigma[8][2 * 7 + 1]];
      v[14] = rotr64(v[14] ^ v[3], 16);
      v[9] = v[9] + v[14];
      v[4] = rotr64(v[4] ^ v[9], 63);
    } while (0);
  } while (0);
  do {
    do {
      v[0] = v[0] + v[4] + m[blake2b_sigma[9][2 * 0 + 0]];
      v[12] = rotr64(v[12] ^ v[0], 32);
      v[8] = v[8] + v[12];
      v[4] = rotr64(v[4] ^ v[8], 24);
      v[0] = v[0] + v[4] + m[blake2b_sigma[9][2 * 0 + 1]];
      v[12] = rotr64(v[12] ^ v[0], 16);
      v[8] = v[8] + v[12];
      v[4] = rotr64(v[4] ^ v[8], 63);
    } while (0);
    do {
      v[1] = v[1] + v[5] + m[blake2b_sigma[9][2 * 1 + 0]];
      v[13] = rotr64(v[13] ^ v[1], 32);
      v[9] = v[9] + v[13];
      v[5] = rotr64(v[5] ^ v[9], 24);
      v[1] = v[1] + v[5] + m[blake2b_sigma[9][2 * 1 + 1]];
      v[13] = rotr64(v[13] ^ v[1], 16);
      v[9] = v[9] + v[13];
      v[5] = rotr64(v[5] ^ v[9], 63);
    } while (0);
    do {
      v[2] = v[2] + v[6] + m[blake2b_sigma[9][2 * 2 + 0]];
      v[14] = rotr64(v[14] ^ v[2], 32);
      v[10] = v[10] + v[14];
      v[6] = rotr64(v[6] ^ v[10], 24);
      v[2] = v[2] + v[6] + m[blake2b_sigma[9][2 * 2 + 1]];
      v[14] = rotr64(v[14] ^ v[2], 16);
      v[10] = v[10] + v[14];
      v[6] = rotr64(v[6] ^ v[10], 63);
    } while (0);
    do {
      v[3] = v[3] + v[7] + m[blake2b_sigma[9][2 * 3 + 0]];
      v[15] = rotr64(v[15] ^ v[3], 32);
      v[11] = v[11] + v[15];
      v[7] = rotr64(v[7] ^ v[11], 24);
      v[3] = v[3] + v[7] + m[blake2b_sigma[9][2 * 3 + 1]];
      v[15] = rotr64(v[15] ^ v[3], 16);
      v[11] = v[11] + v[15];
      v[7] = rotr64(v[7] ^ v[11], 63);
    } while (0);
    do {
      v[0] = v[0] + v[5] + m[blake2b_sigma[9][2 * 4 + 0]];
      v[15] = rotr64(v[15] ^ v[0], 32);
      v[10] = v[10] + v[15];
      v[5] = rotr64(v[5] ^ v[10], 24);
      v[0] = v[0] + v[5] + m[blake2b_sigma[9][2 * 4 + 1]];
      v[15] = rotr64(v[15] ^ v[0], 16);
      v[10] = v[10] + v[15];
      v[5] = rotr64(v[5] ^ v[10], 63);
    } while (0);
    do {
      v[1] = v[1] + v[6] + m[blake2b_sigma[9][2 * 5 + 0]];
      v[12] = rotr64(v[12] ^ v[1], 32);
      v[11] = v[11] + v[12];
      v[6] = rotr64(v[6] ^ v[11], 24);
      v[1] = v[1] + v[6] + m[blake2b_sigma[9][2 * 5 + 1]];
      v[12] = rotr64(v[12] ^ v[1], 16);
      v[11] = v[11] + v[12];
      v[6] = rotr64(v[6] ^ v[11], 63);
    } while (0);
    do {
      v[2] = v[2] + v[7] + m[blake2b_sigma[9][2 * 6 + 0]];
      v[13] = rotr64(v[13] ^ v[2], 32);
      v[8] = v[8] + v[13];
      v[7] = rotr64(v[7] ^ v[8], 24);
      v[2] = v[2] + v[7] + m[blake2b_sigma[9][2 * 6 + 1]];
      v[13] = rotr64(v[13] ^ v[2], 16);
      v[8] = v[8] + v[13];
      v[7] = rotr64(v[7] ^ v[8], 63);
    } while (0);
    do {
      v[3] = v[3] + v[4] + m[blake2b_sigma[9][2 * 7 + 0]];
      v[14] = rotr64(v[14] ^ v[3], 32);
      v[9] = v[9] + v[14];
      v[4] = rotr64(v[4] ^ v[9], 24);
      v[3] = v[3] + v[4] + m[blake2b_sigma[9][2 * 7 + 1]];
      v[14] = rotr64(v[14] ^ v[3], 16);
      v[9] = v[9] + v[14];
      v[4] = rotr64(v[4] ^ v[9], 63);
    } while (0);
  } while (0);
  do {
    do {
      v[0] = v[0] + v[4] + m[blake2b_sigma[10][2 * 0 + 0]];
      v[12] = rotr64(v[12] ^ v[0], 32);
      v[8] = v[8] + v[12];
      v[4] = rotr64(v[4] ^ v[8], 24);
      v[0] = v[0] + v[4] + m[blake2b_sigma[10][2 * 0 + 1]];
      v[12] = rotr64(v[12] ^ v[0], 16);
      v[8] = v[8] + v[12];
      v[4] = rotr64(v[4] ^ v[8], 63);
    } while (0);
    do {
      v[1] = v[1] + v[5] + m[blake2b_sigma[10][2 * 1 + 0]];
      v[13] = rotr64(v[13] ^ v[1], 32);
      v[9] = v[9] + v[13];
      v[5] = rotr64(v[5] ^ v[9], 24);
      v[1] = v[1] + v[5] + m[blake2b_sigma[10][2 * 1 + 1]];
      v[13] = rotr64(v[13] ^ v[1], 16);
      v[9] = v[9] + v[13];
      v[5] = rotr64(v[5] ^ v[9], 63);
    } while (0);
    do {
      v[2] = v[2] + v[6] + m[blake2b_sigma[10][2 * 2 + 0]];
      v[14] = rotr64(v[14] ^ v[2], 32);
      v[10] = v[10] + v[14];
      v[6] = rotr64(v[6] ^ v[10], 24);
      v[2] = v[2] + v[6] + m[blake2b_sigma[10][2 * 2 + 1]];
      v[14] = rotr64(v[14] ^ v[2], 16);
      v[10] = v[10] + v[14];
      v[6] = rotr64(v[6] ^ v[10], 63);
    } while (0);
    do {
      v[3] = v[3] + v[7] + m[blake2b_sigma[10][2 * 3 + 0]];
      v[15] = rotr64(v[15] ^ v[3], 32);
      v[11] = v[11] + v[15];
      v[7] = rotr64(v[7] ^ v[11], 24);
      v[3] = v[3] + v[7] + m[blake2b_sigma[10][2 * 3 + 1]];
      v[15] = rotr64(v[15] ^ v[3], 16);
      v[11] = v[11] + v[15];
      v[7] = rotr64(v[7] ^ v[11], 63);
    } while (0);
    do {
      v[0] = v[0] + v[5] + m[blake2b_sigma[10][2 * 4 + 0]];
      v[15] = rotr64(v[15] ^ v[0], 32);
      v[10] = v[10] + v[15];
      v[5] = rotr64(v[5] ^ v[10], 24);
      v[0] = v[0] + v[5] + m[blake2b_sigma[10][2 * 4 + 1]];
      v[15] = rotr64(v[15] ^ v[0], 16);
      v[10] = v[10] + v[15];
      v[5] = rotr64(v[5] ^ v[10], 63);
    } while (0);
    do {
      v[1] = v[1] + v[6] + m[blake2b_sigma[10][2 * 5 + 0]];
      v[12] = rotr64(v[12] ^ v[1], 32);
      v[11] = v[11] + v[12];
      v[6] = rotr64(v[6] ^ v[11], 24);
      v[1] = v[1] + v[6] + m[blake2b_sigma[10][2 * 5 + 1]];
      v[12] = rotr64(v[12] ^ v[1], 16);
      v[11] = v[11] + v[12];
      v[6] = rotr64(v[6] ^ v[11], 63);
    } while (0);
    do {
      v[2] = v[2] + v[7] + m[blake2b_sigma[10][2 * 6 + 0]];
      v[13] = rotr64(v[13] ^ v[2], 32);
      v[8] = v[8] + v[13];
      v[7] = rotr64(v[7] ^ v[8], 24);
      v[2] = v[2] + v[7] + m[blake2b_sigma[10][2 * 6 + 1]];
      v[13] = rotr64(v[13] ^ v[2], 16);
      v[8] = v[8] + v[13];
      v[7] = rotr64(v[7] ^ v[8], 63);
    } while (0);
    do {
      v[3] = v[3] + v[4] + m[blake2b_sigma[10][2 * 7 + 0]];
      v[14] = rotr64(v[14] ^ v[3], 32);
      v[9] = v[9] + v[14];
      v[4] = rotr64(v[4] ^ v[9], 24);
      v[3] = v[3] + v[4] + m[blake2b_sigma[10][2 * 7 + 1]];
      v[14] = rotr64(v[14] ^ v[3], 16);
      v[9] = v[9] + v[14];
      v[4] = rotr64(v[4] ^ v[9], 63);
    } while (0);
  } while (0);
  do {
    do {
      v[0] = v[0] + v[4] + m[blake2b_sigma[11][2 * 0 + 0]];
      v[12] = rotr64(v[12] ^ v[0], 32);
      v[8] = v[8] + v[12];
      v[4] = rotr64(v[4] ^ v[8], 24);
      v[0] = v[0] + v[4] + m[blake2b_sigma[11][2 * 0 + 1]];
      v[12] = rotr64(v[12] ^ v[0], 16);
      v[8] = v[8] + v[12];
      v[4] = rotr64(v[4] ^ v[8], 63);
    } while (0);
    do {
      v[1] = v[1] + v[5] + m[blake2b_sigma[11][2 * 1 + 0]];
      v[13] = rotr64(v[13] ^ v[1], 32);
      v[9] = v[9] + v[13];
      v[5] = rotr64(v[5] ^ v[9], 24);
      v[1] = v[1] + v[5] + m[blake2b_sigma[11][2 * 1 + 1]];
      v[13] = rotr64(v[13] ^ v[1], 16);
      v[9] = v[9] + v[13];
      v[5] = rotr64(v[5] ^ v[9], 63);
    } while (0);
    do {
      v[2] = v[2] + v[6] + m[blake2b_sigma[11][2 * 2 + 0]];
      v[14] = rotr64(v[14] ^ v[2], 32);
      v[10] = v[10] + v[14];
      v[6] = rotr64(v[6] ^ v[10], 24);
      v[2] = v[2] + v[6] + m[blake2b_sigma[11][2 * 2 + 1]];
      v[14] = rotr64(v[14] ^ v[2], 16);
      v[10] = v[10] + v[14];
      v[6] = rotr64(v[6] ^ v[10], 63);
    } while (0);
    do {
      v[3] = v[3] + v[7] + m[blake2b_sigma[11][2 * 3 + 0]];
      v[15] = rotr64(v[15] ^ v[3], 32);
      v[11] = v[11] + v[15];
      v[7] = rotr64(v[7] ^ v[11], 24);
      v[3] = v[3] + v[7] + m[blake2b_sigma[11][2 * 3 + 1]];
      v[15] = rotr64(v[15] ^ v[3], 16);
      v[11] = v[11] + v[15];
      v[7] = rotr64(v[7] ^ v[11], 63);
    } while (0);
    do {
      v[0] = v[0] + v[5] + m[blake2b_sigma[11][2 * 4 + 0]];
      v[15] = rotr64(v[15] ^ v[0], 32);
      v[10] = v[10] + v[15];
      v[5] = rotr64(v[5] ^ v[10], 24);
      v[0] = v[0] + v[5] + m[blake2b_sigma[11][2 * 4 + 1]];
      v[15] = rotr64(v[15] ^ v[0], 16);
      v[10] = v[10] + v[15];
      v[5] = rotr64(v[5] ^ v[10], 63);
    } while (0);
    do {
      v[1] = v[1] + v[6] + m[blake2b_sigma[11][2 * 5 + 0]];
      v[12] = rotr64(v[12] ^ v[1], 32);
      v[11] = v[11] + v[12];
      v[6] = rotr64(v[6] ^ v[11], 24);
      v[1] = v[1] + v[6] + m[blake2b_sigma[11][2 * 5 + 1]];
      v[12] = rotr64(v[12] ^ v[1], 16);
      v[11] = v[11] + v[12];
      v[6] = rotr64(v[6] ^ v[11], 63);
    } while (0);
    do {
      v[2] = v[2] + v[7] + m[blake2b_sigma[11][2 * 6 + 0]];
      v[13] = rotr64(v[13] ^ v[2], 32);
      v[8] = v[8] + v[13];
      v[7] = rotr64(v[7] ^ v[8], 24);
      v[2] = v[2] + v[7] + m[blake2b_sigma[11][2 * 6 + 1]];
      v[13] = rotr64(v[13] ^ v[2], 16);
      v[8] = v[8] + v[13];
      v[7] = rotr64(v[7] ^ v[8], 63);
    } while (0);
    do {
      v[3] = v[3] + v[4] + m[blake2b_sigma[11][2 * 7 + 0]];
      v[14] = rotr64(v[14] ^ v[3], 32);
      v[9] = v[9] + v[14];
      v[4] = rotr64(v[4] ^ v[9], 24);
      v[3] = v[3] + v[4] + m[blake2b_sigma[11][2 * 7 + 1]];
      v[14] = rotr64(v[14] ^ v[3], 16);
      v[9] = v[9] + v[14];
      v[4] = rotr64(v[4] ^ v[9], 63);
    } while (0);
  } while (0);

  for (i = 0; i < 8; ++i) {
    S->h[i] = S->h[i] ^ v[i] ^ v[i + 8];
  }
}

int blake2b_update(blake2b_state *S, const void *pin, size_t inlen) {
  const unsigned char *in = (const unsigned char *)pin;
  if (inlen > 0) {
    size_t left = S->buflen;
    size_t fill = BLAKE2B_BLOCKBYTES - left;
    if (inlen > fill) {
      S->buflen = 0;
      memcpy(S->buf + left, in, fill);
      blake2b_increment_counter(S, BLAKE2B_BLOCKBYTES);
      blake2b_compress(S, S->buf);
      in += fill;
      inlen -= fill;
      while (inlen > BLAKE2B_BLOCKBYTES) {
        blake2b_increment_counter(S, BLAKE2B_BLOCKBYTES);
        blake2b_compress(S, in);
        in += BLAKE2B_BLOCKBYTES;
        inlen -= BLAKE2B_BLOCKBYTES;
      }
    }
    memcpy(S->buf + S->buflen, in, inlen);
    S->buflen += inlen;
  }
  return 0;
}

int blake2b_final(blake2b_state *S, void *out, size_t outlen) {
  uint8_t buffer[BLAKE2B_OUTBYTES] = {0};
  size_t i;

  if (out == ((void *)0) || outlen < S->outlen)
    return -1;

  if (blake2b_is_lastblock(S))
    return -1;

  blake2b_increment_counter(S, S->buflen);
  blake2b_set_lastblock(S);
  memset(S->buf + S->buflen, 0, BLAKE2B_BLOCKBYTES - S->buflen);
  blake2b_compress(S, S->buf);

  for (i = 0; i < 8; ++i)
    store64(buffer + sizeof(S->h[i]) * i, S->h[i]);

  memcpy(out, buffer, S->outlen);
  secure_zero_memory(buffer, sizeof(buffer));
  return 0;
}

int blake2b(void *out, size_t outlen, const void *in, size_t inlen,
            const void *key, size_t keylen) {
  blake2b_state S[1];

  if (((void *)0) == in && inlen > 0)
    return -1;

  if (((void *)0) == out)
    return -1;

  if (((void *)0) == key && keylen > 0)
    return -1;

  if (!outlen || outlen > BLAKE2B_OUTBYTES)
    return -1;

  if (keylen > BLAKE2B_KEYBYTES)
    return -1;

  if (keylen > 0) {
    if (blake2b_init_key(S, outlen, key, keylen) < 0)
      return -1;
  } else {
    if (blake2b_init(S, outlen) < 0)
      return -1;
  }

  blake2b_update(S, (const uint8_t *)in, inlen);
  blake2b_final(S, out, outlen);
  return 0;
}

int blake2(void *out, size_t outlen, const void *in, size_t inlen,
           const void *key, size_t keylen) {
  return blake2b(out, outlen, in, inlen, key, keylen);
}

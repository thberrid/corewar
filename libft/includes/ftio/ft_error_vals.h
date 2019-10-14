/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_vals.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 04:24:22 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 14:15:29 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_VALS_H
# define FT_ERROR_VALS_H

# include <errno.h>
# include <stdlib.h>
# include "ftio/ft_error.h"

typedef struct	s_errinf
{
	int			value;
	const char	*name;
	const char	msg[ERROR_MSG_MAX_LEN + 11 + 1];
}				t_errinf;

static t_errinf	g_error_table[] =
{
# ifdef FT_ESUCCESS

	{FT_ESUCCESS, "SUCCESS", FT_ESUCCESS_MSG},
# endif
# ifdef FT_EUNDEFINED

	{FT_EUNDEFINED, "EUNDEFINED", FT_EUNDEF_MSG},
# endif
# ifdef EPERM

	{EPERM, "EPERM", "Operation not permitted"},
# endif
# ifdef ENOENT

	{ENOENT, "ENOENT", "No such file or directory"},
# endif
# ifdef ESRCH

	{ESRCH, "ESRCH", "No such process"},
# endif
# ifdef EINTR

	{EINTR, "EINTR", "Interrupted system call"},
# endif
# ifdef EIO

	{EIO, "EIO", "Input/output error"},
# endif
# ifdef ENXIO

	{ENXIO, "ENXIO", "Device not configured"},
# endif
# ifdef E2BIG

	{E2BIG, "E2BIG", "Argument list too long"},
# endif
# ifdef ENOEXEC

	{ENOEXEC, "ENOEXEC", "Exec format error"},
# endif
# ifdef EBADF

	{EBADF, "EBADF", "Bad file descriptor"},
# endif
# ifdef ECHILD

	{ECHILD, "ECHILD", "No child processes"},
# endif
# ifdef EDEADLK

	{EDEADLK, "EDEADLK", "Resource deadlock avoided"},
# endif
# ifdef ENOMEM

	{ENOMEM, "ENOMEM", "Cannot allocate memory"},
# endif
# ifdef EACCES

	{EACCES, "EACCES", "Permission denied"},
# endif
# ifdef EFAULT

	{EFAULT, "EFAULT", "Bad address"},
# endif
# ifdef ENOTBLK

	{ENOTBLK, "ENOTBLK", "Block device required"},
# endif
# ifdef EBUSY

	{EBUSY, "EBUSY", "Resource busy"},
# endif
# ifdef EEXIST

	{EEXIST, "EEXIST", "File exists"},
# endif
# ifdef EXDEV

	{EXDEV, "EXDEV", "Cross-device link"},
# endif
# ifdef ENODEV

	{ENODEV, "ENODEV", "Operation not supported by device"},
# endif
# ifdef ENOTDIR

	{ENOTDIR, "ENOTDIR", "Not a directory"},
# endif
# ifdef EISDIR

	{EISDIR, "EISDIR", "Is a directory"},
# endif
# ifdef EINVAL

	{EINVAL, "EINVAL", "Invalid argument"},
# endif
# ifdef ENFILE

	{ENFILE, "ENFILE", "Too many open files in system"},
# endif
# ifdef EMFILE

	{EMFILE, "EMFILE", "Too many open files"},
# endif
# ifdef ENOTTY

	{ENOTTY, "ENOTTY", "Inappropriate ioctl for device"},
# endif
# ifdef ETXTBSY

	{ETXTBSY, "ETXTBSY", "Text file busy"},
# endif
# ifdef EFBIG

	{EFBIG, "EFBIG", "File too large"},
# endif
# ifdef ENOSPC

	{ENOSPC, "ENOSPC", "No space left on device"},
# endif
# ifdef ESPIPE

	{ESPIPE, "ESPIPE", "Illegal seek"},
# endif
# ifdef EROFS

	{EROFS, "EROFS", "Read-only file system"},
# endif
# ifdef EMLINK

	{EMLINK, "EMLINK", "Too many links"},
# endif
# ifdef EPIPE

	{EPIPE, "EPIPE", "Broken pipe"},
# endif
# ifdef EDOM

	{EDOM, "EDOM", "Numerical argument out of domain"},
# endif
# ifdef ERANGE

	{ERANGE, "ERANGE", "Result too large"},
# endif
# ifdef EWOULDBLOCK

	{EWOULDBLOCK, "EWOULDBLOCK", "Resource temporarily unavailable"},
# endif
# ifdef EINPROGRESS

	{EINPROGRESS, "EINPROGRESS", "Operation now in progress"},
# endif
# ifdef EALREADY

	{EALREADY, "EALREADY", "Operation already in progress"},
# endif
# ifdef ENOTSOCK

	{ENOTSOCK, "ENOTSOCK", "Socket operation on non-socket"},
# endif
# ifdef EDESTADDRREQ

	{EDESTADDRREQ, "EDESTADDRREQ", "Destination address required"},
# endif
# ifdef EMSGSIZE

	{EMSGSIZE, "EMSGSIZE", "Message too long"},
# endif
# ifdef EPROTOTYPE

	{EPROTOTYPE, "EPROTOTYPE", "Protocol wrong type for socket"},
# endif
# ifdef ENOPROTOOPT

	{ENOPROTOOPT, "ENOPROTOOPT", "Protocol not available"},
# endif
# ifdef EPROTONOSUPPORT

	{EPROTONOSUPPORT, "EPROTONOSUPPORT", "Protocol not supported"},
# endif
# ifdef ESOCKTNOSUPPORT

	{ESOCKTNOSUPPORT, "ESOCKTNOSUPPORT", "Socket type not supported"},
# endif
# ifdef ENOTSUP

	{ENOTSUP, "ENOTSUP", "Operation not supported"},
# endif
# ifdef EPFNOSUPPORT

	{EPFNOSUPPORT, "EPFNOSUPPORT", "Protocol family not supported"},
# endif
# ifdef EAFNOSUPPORT

	{EAFNOSUPPORT, "EAFNOSUPPORT",
		"Address family not supported by protocol family"},
# endif
# ifdef EADDRINUSE

	{EADDRINUSE, "EADDRINUSE", "Address already in use"},
# endif
# ifdef EADDRNOTAVAIL

	{EADDRNOTAVAIL, "EADDRNOTAVAIL", "Can't assign requested address"},
# endif
# ifdef ENETDOWN

	{ENETDOWN, "ENETDOWN", "Network is down"},
# endif
# ifdef ENETUNREACH

	{ENETUNREACH, "ENETUNREACH", "Network is unreachable"},
# endif
# ifdef ENETRESET

	{ENETRESET, "ENETRESET", "Network dropped connection on reset"},
# endif
# ifdef ECONNABORTED

	{ECONNABORTED, "ECONNABORTED", "Software caused connection abort"},
# endif
# ifdef ECONNRESET

	{ECONNRESET, "ECONNRESET", "Connection reset by peer"},
# endif
# ifdef ENOBUFS

	{ENOBUFS, "ENOBUFS", "No buffer space available"},
# endif
# ifdef EISCONN

	{EISCONN, "EISCONN", "Socket is already connected"},
# endif
# ifdef ENOTCONN

	{ENOTCONN, "ENOTCONN", "Socket is not connected"},
# endif
# ifdef ESHUTDOWN

	{ESHUTDOWN, "ESHUTDOWN", "Can't send after socket shutdown"},
# endif
# ifdef ETOOMANYREFS

	{ETOOMANYREFS, "ETOOMANYREFS", "Too many references: can't splice"},
# endif
# ifdef ETIMEDOUT

	{ETIMEDOUT, "ETIMEDOUT", "Operation timed out"},
# endif
# ifdef ECONNREFUSED

	{ECONNREFUSED, "ECONNREFUSED", "Connection refused"},
# endif
# ifdef ELOOP

	{ELOOP, "ELOOP", "Too many levels of symbolic links"},
# endif
# ifdef ENAMETOOLONG

	{ENAMETOOLONG, "ENAMETOOLONG", "File name too long"},
# endif
# ifdef EHOSTDOWN

	{EHOSTDOWN, "EHOSTDOWN", "Host is down"},
# endif
# ifdef EHOSTUNREACH

	{EHOSTUNREACH, "EHOSTUNREACH", "No route to host"},
# endif
# ifdef ENOTEMPTY

	{ENOTEMPTY, "ENOTEMPTY", "Directory not empty"},
# endif
# ifdef EPROCLIM

	{EPROCLIM, "EPROCLIM", "Too many processes"},
# endif
# ifdef EUSERS

	{EUSERS, "EUSERS", "Too many users"},
# endif
# ifdef EDQUOT

	{EDQUOT, "EDQUOT", "Disc quota exceeded"},
# endif
# ifdef ESTALE

	{ESTALE, "ESTALE", "Stale NFS file handle"},
# endif
# ifdef EREMOTE

	{EREMOTE, "EREMOTE", "Too many levels of remote in path"},
# endif
# ifdef EBADRPC

	{EBADRPC, "EBADRPC", "RPC struct is bad"},
# endif
# ifdef ERPCMISMATCH

	{ERPCMISMATCH, "ERPCMISMATCH", "RPC version wrong"},
# endif
# ifdef EPROGUNAVAIL

	{EPROGUNAVAIL, "EPROGUNAVAIL", "RPC prog. not avail"},
# endif
# ifdef EPROGMISMATCH

	{EPROGMISMATCH, "EPROGMISMATCH", "Program version wrong"},
# endif
# ifdef EPROCUNAVAIL

	{EPROCUNAVAIL, "EPROCUNAVAIL", "Bad procedure for program"},
# endif
# ifdef ENOLCK

	{ENOLCK, "ENOLCK", "No locks available"},
# endif
# ifdef ENOSYS

	{ENOSYS, "ENOSYS", "Function not implemented"},
# endif
# ifdef EFTYPE

	{EFTYPE, "EFTYPE", "Inappropriate file type or format"},
# endif
# ifdef EAUTH

	{EAUTH, "EAUTH", "Authentication error"},
# endif
# ifdef ENEEDAUTH

	{ENEEDAUTH, "ENEEDAUTH", "Need authenticator"},
# endif
# ifdef EPWROFF

	{EPWROFF, "EPWROFF", "Device power is off"},
# endif
# ifdef EDEVERR

	{EDEVERR, "EDEVERR", "Device error"},
# endif
# ifdef EOVERFLOW

	{EOVERFLOW, "EOVERFLOW", "Value too large to be stored in data type"},
# endif
# ifdef EBADEXEC

	{EBADEXEC, "EBADEXEC", "Bad executable (or shared library)"},
# endif
# ifdef EBADARCH

	{EBADARCH, "EBADARCH", "Bad CPU type in executable"},
# endif
# ifdef ESHLIBVERS

	{ESHLIBVERS, "ESHLIBVERS", "Shared library version mismatch"},
# endif
# ifdef EBADMACHO

	{EBADMACHO, "EBADMACHO", "Malformed Mach-o file"},
# endif
# ifdef ECANCELED

	{ECANCELED, "ECANCELED", "Operation canceled"},
# endif
# ifdef EIDRM

	{EIDRM, "EIDRM", "Identifier removed"},
# endif
# ifdef ENOMSG

	{ENOMSG, "ENOMSG", "No message of desired type"},
# endif
# ifdef EILSEQ

	{EILSEQ, "EILSEQ", "Illegal byte sequence"},
# endif
# ifdef ENOATTR

	{ENOATTR, "ENOATTR", "Attribute not found"},
# endif
# ifdef EBADMSG

	{EBADMSG, "EBADMSG", "Bad message"},
# endif
# ifdef EMULTIHOP

	{EMULTIHOP, "EMULTIHOP", "EMULTIHOP (Reserved)"},
# endif
# ifdef ENODATA

	{ENODATA, "ENODATA", "No message available on STREAM"},
# endif
# ifdef ENOLINK

	{ENOLINK, "ENOLINK", "ENOLINK (Reserved)"},
# endif
# ifdef ENOSR

	{ENOSR, "ENOSR", "No STREAM resources"},
# endif
# ifdef ENOSTR

	{ENOSTR, "ENOSTR", "Not a STREAM"},
# endif
# ifdef EPROTO

	{EPROTO, "EPROTO", "Protocol error"},
# endif
# ifdef ETIME

	{ETIME, "ETIME", "STREAM ioctl timeout"},
# endif
# ifdef EOPNOTSUPP

	{EOPNOTSUPP, "EOPNOTSUPP", "Operation not supported on socket"},
# endif
# ifdef ENOPOLICY

	{ENOPOLICY, "ENOPOLICY", "Policy not found"},
# endif
# ifdef ENOTRECOVERABLE

	{ENOTRECOVERABLE, "ENOTRECOVERABLE", "State not recoverable"},
# endif
# ifdef EOWNERDEAD

	{EOWNERDEAD, "EOWNERDEAD", "Previous owner died"},
# endif
# ifdef EQFULL

	{EQFULL, "EQFULL", "Interface output queue is full"},
# endif

	{-1, NULL, FT_EUNKOWN_MSG}
};

int				get_errno_real(void) __attribute__((visibility("internal")));

static int		(*const g_get_errno[])(void) =
{
	get_errno_real,
	NULL
};

#endif

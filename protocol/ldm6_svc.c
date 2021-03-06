#include "config.h"
/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "ldm.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

void
ldmprog_6(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		feedpar_t feedme_6_arg;
		prod_class_t notifyme_6_arg;
		u_int is_alive_6_arg;
		prod_class_t hiya_6_arg;
		prod_info notification_6_arg;
		product hereis_6_arg;
		comingsoon_args comingsoon_6_arg;
		datapkt blkdata_6_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case FEEDME:
		_xdr_argument = (xdrproc_t) xdr_feedpar_t;
		_xdr_result = (xdrproc_t) xdr_fornme_reply_t;
		local = (char *(*)(char *, struct svc_req *)) feedme_6_svc;
		break;

	case NOTIFYME:
		_xdr_argument = (xdrproc_t) xdr_prod_class_t;
		_xdr_result = (xdrproc_t) xdr_fornme_reply_t;
		local = (char *(*)(char *, struct svc_req *)) notifyme_6_svc;
		break;

	case IS_ALIVE:
		_xdr_argument = (xdrproc_t) xdr_u_int;
		_xdr_result = (xdrproc_t) xdr_bool;
		local = (char *(*)(char *, struct svc_req *)) is_alive_6_svc;
		break;

	case HIYA:
		_xdr_argument = (xdrproc_t) xdr_prod_class_t;
		_xdr_result = (xdrproc_t) xdr_hiya_reply_t;
		local = (char *(*)(char *, struct svc_req *)) hiya_6_svc;
		break;

	case NOTIFICATION:
		_xdr_argument = (xdrproc_t) xdr_prod_info;
		_xdr_result = (xdrproc_t) xdr_void;
		local = (char *(*)(char *, struct svc_req *)) notification_6_svc;
		break;

	case HEREIS:
		_xdr_argument = (xdrproc_t) xdr_product;
		_xdr_result = (xdrproc_t) xdr_void;
		local = (char *(*)(char *, struct svc_req *)) hereis_6_svc;
		break;

	case COMINGSOON:
		_xdr_argument = (xdrproc_t) xdr_comingsoon_args;
		_xdr_result = (xdrproc_t) xdr_comingsoon_reply_t;
		local = (char *(*)(char *, struct svc_req *)) comingsoon_6_svc;
		break;

	case BLKDATA:
		_xdr_argument = (xdrproc_t) xdr_datapkt;
		_xdr_result = (xdrproc_t) xdr_void;
		local = (char *(*)(char *, struct svc_req *)) blkdata_6_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

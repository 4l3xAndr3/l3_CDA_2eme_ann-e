/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "etiquettable.h"
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

static void
etiquetableprog_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		compte inscription_1_arg;
		connect connexion_1_arg;
		char fiche_fruit_legume_1_arg;
		char fiche_poisson_1_arg;
		char fiche_recette_1_arg;
		char fiche_user_1_arg;
		ini ini_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case inscription:
		_xdr_argument = (xdrproc_t) xdr_compte;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) inscription_1_svc;
		break;

	case connexion:
		_xdr_argument = (xdrproc_t) xdr_connect;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) connexion_1_svc;
		break;

	case fiche_fruit_legume:
		_xdr_argument = (xdrproc_t) xdr_char;
		_xdr_result = (xdrproc_t) xdr_fruit_legume;
		local = (char *(*)(char *, struct svc_req *)) fiche_fruit_legume_1_svc;
		break;

	case fiche_poisson:
		_xdr_argument = (xdrproc_t) xdr_char;
		_xdr_result = (xdrproc_t) xdr_poisson;
		local = (char *(*)(char *, struct svc_req *)) fiche_poisson_1_svc;
		break;

	case fiche_recette:
		_xdr_argument = (xdrproc_t) xdr_char;
		_xdr_result = (xdrproc_t) xdr_recette;
		local = (char *(*)(char *, struct svc_req *)) fiche_recette_1_svc;
		break;

	case fiche_user:
		_xdr_argument = (xdrproc_t) xdr_char;
		_xdr_result = (xdrproc_t) xdr_compte;
		local = (char *(*)(char *, struct svc_req *)) fiche_user_1_svc;
		break;

	case deconnexion:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) deconnexion_1_svc;
		break;

	case ini:
		_xdr_argument = (xdrproc_t) xdr_ini;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) ini_1_svc;
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

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (ETIQUETABLEPROG, ETIQUETABLEVERS);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, ETIQUETABLEPROG, ETIQUETABLEVERS, etiquetableprog_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (ETIQUETABLEPROG, ETIQUETABLEVERS, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, ETIQUETABLEPROG, ETIQUETABLEVERS, etiquetableprog_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (ETIQUETABLEPROG, ETIQUETABLEVERS, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}

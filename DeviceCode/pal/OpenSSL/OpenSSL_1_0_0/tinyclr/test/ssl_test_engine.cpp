/* Written by Geoff Thorpe (geoff@geoffthorpe.net) for the OpenSSL
 * project 2000.
 */
/* ====================================================================
 * Copyright (c) 1999-2001 The OpenSSL Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer. 
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"
 *
 * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to
 *    endorse or promote products derived from this software without
 *    prior written permission. For written permission, please contact
 *    licensing@OpenSSL.org.
 *
 * 5. Products derived from this software may not be called "OpenSSL"
 *    nor may "OpenSSL" appear in their names without prior written
 *    permission of the OpenSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"
 *
 * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 *
 * This product includes cryptographic software written by Eric Young
 * (eay@cryptsoft.com).  This product includes software written by Tim
 * Hudson (tjh@cryptsoft.com).
 *
 */

#include <openssl/e_os2.h>
#include "ssl_tests.h"
#ifdef OPENSSL_SYS_WINDOWS
#include <stdio.h>
#include <string.h>
#endif

#ifdef OPENSSL_NO_ENGINE
int ssl_test_engine(int argc, char *argv[])
{
    TINYCLR_SSL_PRINTF("No ENGINE support\n");
    return(0);
}
#else
#include <openssl/buffer.h>
#include <openssl/crypto.h>
#include <openssl/engine.h>
#include <openssl/err.h>

static void display_engine_list(void)
	{
	ENGINE *h;
	int loop;

	h = ENGINE_get_first();
	loop = 0;
	TINYCLR_SSL_PRINTF("listing available engine types\n");
	while(h)
		{
		TINYCLR_SSL_PRINTF("engine %i, id = \"%s\", name = \"%s\"\n",
			loop++, ENGINE_get_id(h), ENGINE_get_name(h));
		h = ENGINE_get_next(h);
		}
	TINYCLR_SSL_PRINTF("end of list\n");
	/* ENGINE_get_first() increases the struct_ref counter, so we 
           must call ENGINE_free() to decrease it again */
	ENGINE_free(h);
	}

int ssl_test_engine(int argc, char *argv[])
	{
	ENGINE *block[512];
	char buf[256];
	const char *id, *name;
	ENGINE *ptr;
	int loop;
	int to_return = 1;
	ENGINE *new_h1 = NULL;
	ENGINE *new_h2 = NULL;
	ENGINE *new_h3 = NULL;
	ENGINE *new_h4 = NULL;

	/* enable memory leak checking unless explicitly disabled */
	if (!((TINYCLR_SSL_GETENV("OPENSSL_DEBUG_MEMORY") != NULL) && (0 == TINYCLR_SSL_STRCMP(TINYCLR_SSL_GETENV("OPENSSL_DEBUG_MEMORY"), "off"))))
		{
		CRYPTO_malloc_debug_init();
		CRYPTO_set_mem_debug_options(V_CRYPTO_MDEBUG_ALL);
		}
	else
		{
		/* OPENSSL_DEBUG_MEMORY=off */
		CRYPTO_set_mem_debug_functions(0, 0, 0, 0, 0);
		}
	CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ON);
	ERR_load_crypto_strings();

	TINYCLR_SSL_MEMSET(block, 0, 512 * sizeof(ENGINE *));
	if(((new_h1 = ENGINE_new()) == NULL) ||
			!ENGINE_set_id(new_h1, "test_id0") ||
			!ENGINE_set_name(new_h1, "First test item") ||
			((new_h2 = ENGINE_new()) == NULL) ||
			!ENGINE_set_id(new_h2, "test_id1") ||
			!ENGINE_set_name(new_h2, "Second test item") ||
			((new_h3 = ENGINE_new()) == NULL) ||
			!ENGINE_set_id(new_h3, "test_id2") ||
			!ENGINE_set_name(new_h3, "Third test item") ||
			((new_h4 = ENGINE_new()) == NULL) ||
			!ENGINE_set_id(new_h4, "test_id3") ||
			!ENGINE_set_name(new_h4, "Fourth test item"))
		{
		TINYCLR_SSL_PRINTF("Couldn't set up test ENGINE structures\n");
		goto end;
		}
	TINYCLR_SSL_PRINTF("\nenginetest beginning\n\n");
	display_engine_list();
	if(!ENGINE_add(new_h1))
		{
		TINYCLR_SSL_PRINTF("Add failed!\n");
		goto end;
		}
	display_engine_list();
	ptr = ENGINE_get_first();
	if(!ENGINE_remove(ptr))
		{
		TINYCLR_SSL_PRINTF("Remove failed!\n");
		goto end;
		}
	if (ptr)
		ENGINE_free(ptr);
	display_engine_list();
	if(!ENGINE_add(new_h3) || !ENGINE_add(new_h2))
		{
		TINYCLR_SSL_PRINTF("Add failed!\n");
		goto end;
		}
	display_engine_list();
	if(!ENGINE_remove(new_h2))
		{
		TINYCLR_SSL_PRINTF("Remove failed!\n");
		goto end;
		}
	display_engine_list();
	if(!ENGINE_add(new_h4))
		{
		TINYCLR_SSL_PRINTF("Add failed!\n");
		goto end;
		}
	display_engine_list();
	if(ENGINE_add(new_h3))
		{
		TINYCLR_SSL_PRINTF("Add *should* have failed but didn't!\n");
		goto end;
		}
	else
		TINYCLR_SSL_PRINTF("Add that should fail did.\n");
	ERR_clear_error();
	if(ENGINE_remove(new_h2))
		{
		TINYCLR_SSL_PRINTF("Remove *should* have failed but didn't!\n");
		goto end;
		}
	else
		TINYCLR_SSL_PRINTF("Remove that should fail did.\n");
	ERR_clear_error();
	if(!ENGINE_remove(new_h3))
		{
		TINYCLR_SSL_PRINTF("Remove failed!\n");
		goto end;
		}
	display_engine_list();
	if(!ENGINE_remove(new_h4))
		{
		TINYCLR_SSL_PRINTF("Remove failed!\n");
		goto end;
		}
	display_engine_list();
	/* Depending on whether there's any hardware support compiled
	 * in, this remove may be destined to fail. */
	ptr = ENGINE_get_first();
	if(ptr)
		if(!ENGINE_remove(ptr))
			TINYCLR_SSL_PRINTF("Remove failed!i - probably no hardware "
				"support present.\n");
	if (ptr)
		ENGINE_free(ptr);
	display_engine_list();
	if(!ENGINE_add(new_h1) || !ENGINE_remove(new_h1))
		{
		TINYCLR_SSL_PRINTF("Couldn't add and remove to an empty list!\n");
		goto end;
		}
	else
		TINYCLR_SSL_PRINTF("Successfully added and removed to an empty list!\n");
	TINYCLR_SSL_PRINTF("About to beef up the engine-type list\n");
	for(loop = 0; loop < 512; loop++)
		{
		TINYCLR_SSL_SPRINTF(buf, "id%i", loop);
		id = BUF_strdup(buf);
		TINYCLR_SSL_SPRINTF(buf, "Fake engine type %i", loop);
		name = BUF_strdup(buf);
		if(((block[loop] = ENGINE_new()) == NULL) ||
				!ENGINE_set_id(block[loop], id) ||
				!ENGINE_set_name(block[loop], name))
			{
			TINYCLR_SSL_PRINTF("Couldn't create block of ENGINE structures.\n"
				"I'll probably also core-dump now, damn.\n");
			goto end;
			}
		}
	for(loop = 0; loop < 512; loop++)
		{
		if(!ENGINE_add(block[loop]))
			{
			TINYCLR_SSL_PRINTF("\nAdding stopped at %i, (%s,%s)\n",
				loop, ENGINE_get_id(block[loop]),
				ENGINE_get_name(block[loop]));
			goto cleanup_loop;
			}
		else
			TINYCLR_SSL_PRINTF("."); TINYCLR_SSL_FFLUSH(OPENSSL_TYPE__FILE_STDOUT);
		}
cleanup_loop:
	TINYCLR_SSL_PRINTF("\nAbout to empty the engine-type list\n");
	while((ptr = ENGINE_get_first()) != NULL)
		{
		if(!ENGINE_remove(ptr))
			{
			TINYCLR_SSL_PRINTF("\nRemove failed!\n");
			goto end;
			}
		ENGINE_free(ptr);
		TINYCLR_SSL_PRINTF("."); TINYCLR_SSL_FFLUSH(OPENSSL_TYPE__FILE_STDOUT);
		}
	for(loop = 0; loop < 512; loop++)
		{
		OPENSSL_free((void *)ENGINE_get_id(block[loop]));
		OPENSSL_free((void *)ENGINE_get_name(block[loop]));
		}
	TINYCLR_SSL_PRINTF("\nTests completed happily\n");
	to_return = 0;
end:
	if(to_return)
		ERR_print_errors_fp(OPENSSL_TYPE__FILE_STDERR);
	if(new_h1) ENGINE_free(new_h1);
	if(new_h2) ENGINE_free(new_h2);
	if(new_h3) ENGINE_free(new_h3);
	if(new_h4) ENGINE_free(new_h4);
	for(loop = 0; loop < 512; loop++)
		if(block[loop])
			ENGINE_free(block[loop]);
	ENGINE_cleanup();
	CRYPTO_cleanup_all_ex_data();
	ERR_free_strings();
	ERR_remove_thread_state(NULL);
	CRYPTO_mem_leaks_fp(OPENSSL_TYPE__FILE_STDERR);
	return to_return;
	}
#endif


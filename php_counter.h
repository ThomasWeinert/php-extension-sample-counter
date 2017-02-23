#ifndef PHP_COUNTER_H
#define PHP_COUNTER_H

#define PHP_COUNTER_EXTNAME  "counter"
#define PHP_COUNTER_EXTVER   "1.0"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif /* HAVE_CONFIG_H */

#include "php.h"

/*
  Define/register global module variables
*/
ZEND_BEGIN_MODULE_GLOBALS(counter)
	long basic_counter_value;
ZEND_END_MODULE_GLOBALS(counter)

/*
  Define a template to access the global module variables
*/
#define COUNTER_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(counter, v)

#ifdef ZTS
#include "TSRM.h"
#endif

#if defined(ZTS) && defined(COMPILE_DL_SAMPLE)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif /* PHP_COUNTER_H */

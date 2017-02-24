#include "php_counter.h"

#define COUNTER_NS "Counter"

/* Declare global module variable */
ZEND_DECLARE_MODULE_GLOBALS(counter)


/* START: function implementations */

PHP_FUNCTION(counter_get)
{
    /* COUNTER_G() template is defined in php_counter.h */
	RETURN_LONG(COUNTER_G(basic_counter_value));
}

PHP_FUNCTION(counter_bump)
{
	COUNTER_G(basic_counter_value)++;
}

PHP_FUNCTION(counter_clear)
{
	COUNTER_G(basic_counter_value) = 0;
}

/* END: function implementations */

/* Create module function list */
const zend_function_entry php_counter_functions[] = {
	ZEND_NS_NAMED_FE(COUNTER_NS, get, ZEND_FN(counter_get), NULL)
	ZEND_NS_NAMED_FE(COUNTER_NS, bump, ZEND_FN(counter_bump), NULL)
	ZEND_NS_NAMED_FE(COUNTER_NS, clear, ZEND_FN(counter_clear), NULL)
	PHP_FE_END
};

/* Define a request initialization function */
PHP_RINIT_FUNCTION(counter)
{
	COUNTER_G(basic_counter_value) = 0;
	return SUCCESS;
}

/* Create the module (extension) entry */
zend_module_entry counter_module_entry = {
	STANDARD_MODULE_HEADER,
	PHP_COUNTER_EXTNAME,
	php_counter_functions, /* Functions */
	NULL, /* MINIT */
	NULL, /* MSHUTDOWN */
	PHP_RINIT(counter), /* RINIT */
	NULL, /* RSHUTDOWN */
	NULL, /* MINFO */
	PHP_COUNTER_EXTVER,
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_COUNTER
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(counter)
#endif

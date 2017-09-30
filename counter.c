#include "php_counter.h"

#define COUNTER_RESOURCE_NAME "counter"
int le_counter_resource;

/* Declare global module variable */
ZEND_DECLARE_MODULE_GLOBALS(counter)

static void counter_resource_dtor(zend_resource *rsrc)
{
	counter_resource *r = (counter_resource*)rsrc->ptr;

	if (r) {
		efree(r);
	}
}

/* {{{ arginfo */


/* }}} */


/* {{{ proto resource counter_create( string name [, int initial_value [, int flags ]] )
   Creates a counter which maintains a single numeric value. */
PHP_FUNCTION(counter_create)
{
	counter_resource *r;
	r = emalloc(sizeof(counter_resource));
	r->value = 0;
	RETURN_RES(zend_register_resource(r, le_counter_resource));
}
/* }}} */

/* {{{ proto resource counter_get_value( resource counter )
   Get the current value of a counter resource. */
PHP_FUNCTION(counter_get_value)
{
	counter_resource *r;
	zval *zr;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_RESOURCE(zr)
	ZEND_PARSE_PARAMETERS_END();

	r = (counter_resource *)zend_fetch_resource(Z_RES_P(zr), COUNTER_RESOURCE_NAME, le_counter_resource);

	RETURN_LONG(r->value)
}
/* }}} */

/* {{{ proto void counter_bump_value( resource counter , int offset )
   Change the current value of a counter resource. */
PHP_FUNCTION(counter_bump_value)
{
	counter_resource *r;
	zval *zr;
	zend_long offset = 1;

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_RESOURCE(zr)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(offset)
	ZEND_PARSE_PARAMETERS_END();

	r = (counter_resource *)zend_fetch_resource(Z_RES_P(zr), COUNTER_RESOURCE_NAME, le_counter_resource);

	r->value += offset;
}
/* }}} */

/* {{{ proto void counter_reset_value( resource counter )
   Reset the current value of a counter resource. */
PHP_FUNCTION(counter_reset_value)
{
	counter_resource *r;
	zval *zr;
	zend_long offset = 1;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_RESOURCE(zr)
	ZEND_PARSE_PARAMETERS_END();

	r = (counter_resource *)zend_fetch_resource(Z_RES_P(zr), COUNTER_RESOURCE_NAME, le_counter_resource);

	r->value = 0;
}
/* }}} */

/* {{{ proto mixed counter_get_meta( resource counter, int attribute )
   Return a piece of meta information about a counter resource. */
PHP_FUNCTION(counter_get_meta)
{

}
/* }}} */


/* {{{ proto resource counter_get_named(string name)
   Retrieve an existing named counter as a resource. */
PHP_FUNCTION(counter_get_named)
{

}
/* }}} */


/* {{{ Function table */
const zend_function_entry php_counter_functions[] = {
	ZEND_NS_NAMED_FE(PHP_COUNTER_NS, counter_create, ZEND_FN(counter_create), NULL)
	ZEND_NS_NAMED_FE(PHP_COUNTER_NS, counter_get_value, ZEND_FN(counter_get_value), NULL)
	ZEND_NS_NAMED_FE(PHP_COUNTER_NS, counter_bump_value, ZEND_FN(counter_bump_value), NULL)
	ZEND_NS_NAMED_FE(PHP_COUNTER_NS, counter_reset_value, ZEND_FN(counter_reset_value), NULL)
	ZEND_NS_NAMED_FE(PHP_COUNTER_NS, counter_get_meta, ZEND_FN(counter_get_meta), NULL)
	ZEND_NS_NAMED_FE(PHP_COUNTER_NS, counter_get_named, ZEND_FN(counter_get_named), NULL)
	PHP_FE_END
};
/* }}} */

PHP_MINIT_FUNCTION(counter)
{
	le_counter_resource = zend_register_list_destructors_ex(
		counter_resource_dtor, NULL, COUNTER_RESOURCE_NAME, module_number
	);
}

/* {{{ Module struct */
zend_module_entry counter_module_entry = {
	STANDARD_MODULE_HEADER,
	PHP_COUNTER_EXTNAME,
	php_counter_functions, /* Functions */
	PHP_MINIT(counter), /* MINIT */
	NULL, /* MSHUTDOWN */
	NULL, /* RINIT */
	NULL, /* RSHUTDOWN */
	NULL, /* MINFO */
	PHP_COUNTER_EXTVER,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_COUNTER
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(counter)
#endif

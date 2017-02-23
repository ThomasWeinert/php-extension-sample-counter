--TEST--
Validate that extension was loaded.
--FILE--
<?php
echo extension_loaded("counter") ? 'true' : 'false';
?>
--EXPECT--
true

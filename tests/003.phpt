--TEST--
Increment the counter twice and output it.
--SKIPIF--
<?php if (!extension_loaded("counter")) print "skip"; ?>
--FILE--
<?php
\Counter\bump();
\Counter\bump();
echo \Counter\get();
?>
--EXPECT--
2

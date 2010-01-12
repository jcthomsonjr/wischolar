// $Id: README.txt,v 1.1 2009/07/28 00:03:44 deciphered Exp $

The File Aliases module extends the default functionality of the FileField
module and the core Upload module by adding a token customizable alias, allowing
files to have cleaner paths - while files will still live under the defined File
system path, aliases make the file appear to exist anywhere you wish.

File Aliases was written and is maintained by Stuart Clark (deciphered).
- http://stuar.tc/lark


Features
----------------

* Customizable File Alias field using Node tokens.
* Support for Private and Public file systems.


Required Modules
----------------

* FileField Paths - http://drupal.org/project/filefield_paths


Known issues
----------------

* Fields in Views

  Currently using the Fields output in Views will point to the physical location
  of the file, not the File Alias.
  Views Node output will display the File Alias as expected.


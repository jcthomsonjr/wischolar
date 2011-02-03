// $Id; 

Admin Form Columns allows one to define which of 3 regions they want a top level field element
to be in. They may choose from Main, Right, and Footer. 

Users may build Admin Form Columns directly into their forms by setting the #columns attribute on
the form itself, and then the #region attribute on any top level elements they wish to position.
Any element without a #region defined will be placed into the Main region by default. Setting a 
#region of 'none' will take the element out of the columns completely.
Note that this will work on any form, not just admin forms.

Admin Form Columns is based on Node Form Columns.
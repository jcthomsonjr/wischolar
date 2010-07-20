To create your own theme for vsites:

1. Copy this entire directory

2. Rename your new directory to the name of your new theme (example: my_theme)

3. In that new my_theme directory, rename the .css and .info files so they read my_theme.info, and my_theme.css, respectively.

4. Open the .info file with a text editor and change references to 'starter_vsite_theme' to 'my_theme'. Note: As you can select whether your theme is public (i.e. can be used by everyone on this installation) or private, choosing the name of the theme is important. Private themes must be named for the vsite they are designed for. For example if you are creating a site for a Professor Bob Smith, who has the domain 'bsmith', and want the theme to be only available to Bob Smith, you should name the theme 'bsmith'.

5. Open the .css file and change as you wish. (Peruse the theming documentation on http://openscholar.harvard.edu to avoid excessive nashing of teeth.)

5. Go to /admin/build/themes/select and enable your new custom theme.
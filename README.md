# Final Project

[![license](https://img.shields.io/badge/license-MIT-green)](LICENSE)
[![docs](https://img.shields.io/badge/docs-yes-brightgreen)](docs/README.md)

Read [this document](https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html) to understand the project
layout.

## Interface
![Interface](https://github.com/CS126SP20/final-project-earthy1024/blob/master/assets/UI.jpg)

### Dependencies
-[cmake]
### Library
-[libcurl](https://github.com/curl/curl.git)

-[Cinder](https://github.com/cinder/Cinder.git)

---
**Author**: Prithvi - [`prithvi4@illinois.edu`](mailto:prithvi4@illinois.edu)
 ---
This project is a simple drawing interface that uses the cinder library for application tools.
Features include font sizes and colors as well the ability to load images into the drawing.
The drawing can than be saved into a file of your choosing on your device.
Along with the ui functionality is functionality to upload an image to an online image hosting site.
The link to the site can then be sent to another web api to craete a qr and the image will be retrieved and stored on a local file.
The file can then be uploaded to the application and the code will allow the user to open the image online.
---
The curl library is not working properly on my machine and might be due to an outdated curl version. Check to make sure the curl on your machine is up to date otherwise the necessary curl protocols will not be supported.

 

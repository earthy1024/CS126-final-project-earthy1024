# [Where Did My Drawing Gogh?]

Author: [Prithvi Dharmaraj]

---
  For my project I would like to design some sort of basic drawing interface similar to Microsoft Paint. After a drawing is finished it is then converted to an image file and stored in a image hosting site and is assigned a qr code object as well through another website. The program then outputs the qr code and the code can be used to open the image on the internet.
  
  The drawing interface will use some aspects of the snake game interface. The cursor would be the driver used to manipulate it and will have much tinier block units to make the drawing less pixel-like. The qr code generation would come from a cinder block I found on github. 
  
  -For the first week I will spend it trying to develop the actual interface itself and testing if it works. This will likely roll over to the next week as well as it seems like a big chuck of code. 
  
  -The next part will integrating the QR code generation in my project.
  
  -Lastly I will add web request functionality to allow the image to be sent to the hosting site and retrieve the url for the image and convert to QRCode using a QRCode generation site.
  
External Library: https://github.com/curl/curl.git

Stretch Goals:

-Adding more than simple editing tools in the interface, such as different sizes and colors.

-Allow insertion of images into the interface.
-See if the application can be used with an online database.

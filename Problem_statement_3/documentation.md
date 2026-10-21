# 📝 Solution Documentation Template

---

## Problem Understanding
**What the problem is asking:** We are using Encryptions and Encoding to make message or data transfer secure. We must take in proper input, execute what the commands demand and return them. 

**Key concepts involved:** Understanding the Encoding and Encryption, then making an algorithm to take in the input as provided in the format. Processing the message, etc.

**My approach:** My main funciton takes in the input and executes one of the following funciton for each command. Either RSA_ENC,RSA_DEC,B64_ENC,B64_DEC and bonus question solutions have two functions FIND_D and RSATOY. I have used a lot of vectors in this problem instead of arrays cause the lenght of input message is variable. I have splitted every task into a function. And have used many string methods to make the task easier. I did not make it the most efficient but what i felt was the easiest to do. 

---

##  Conceptual Learning

### **New Concepts I Discovered**
- **[Concept Name]:** find and rfind : Used to find location of a string. find scans from left to right while rfind scans from right to left
- **[Another Concept]:** substr, extracts a substring from a string, taking a zero-based starting position and an optional character length to define the exact slice required

### **How I Applied These Concepts**
In used find and rfind to extract numbers from the RSA_ENC and RSA_DEC input. Also i used the substr while taking in the input in forms of commands to cut out the starting square brackets.(IK i could have use it in RSAextract fnc but forgot about it)

### **Real-World Connections**
Everywhere on the internet, RSA is essential.Base64 is used to convert binary data (like images, PDFs, or audio files) into safe ASCII text strings

### **A doubt from my side, once you have read my code**
How could have Classes and objects been used here. I have relied on funcitons and felt no repeated object so I have not used any OOPS but if I had to how and where would I have used them.


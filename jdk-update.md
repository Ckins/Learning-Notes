#Upadate the JDK

##Description
As the project requires Oracle-JDk-1.7  
I need to update 1.6 from 1.7  
  
##solution
1.Down JDk and exctract to /usr/lib/jvm/jdk1.7.0_79  
<!--lang:bash-->
    sudo tar xvzf jdk-7u79-sun-amd64.tar.gz

2.Make a link in /usr/lib/jvm/java-1.7.0-sun-amd64   
<!--lang:bash-->
    sudo ln -s /usr/lib/jvm/java-1.7.0-sun-amd64 /usr/lib/jvm/jdk1.7.0_79

3.Update the PATH (if you have set it in /etc/profile)   
<!--lang:bash-->
    sudo vim /etc/profile

4.update-alternatives   
<!--lang:bash-->
     sudo update-alternatives --set java /usr/local/java/jre1.7.0_40/bin/java
     sudo update-alternatives --set javac /usr/local/java/jdk1.7.0_40/bin/javac
     sudo update-alternatives --set javaws /usr/local/java/jre1.7.0_40/bin/javaws

5.choose the version you want   
<!--lang:bash-->
    update-alternatives --config java


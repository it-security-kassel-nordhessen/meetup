FROM openjdk:8-jdk-alpine
RUN mkdir /server && addgroup -S user && adduser -S user -G user && chown -R user:user /server
COPY vuln-app-demo.jar /server
COPY ysoserial-0.0.5.jar /server
RUN chown user:user /server/vuln-app-demo.jar
USER user
CMD ["java","-jar","/server/vuln-app-demo.jar"]
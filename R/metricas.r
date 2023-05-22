##############

library(dplyr)
library(ggplot2)
library(ggcorrplot)
library(e1071)
library(ROCR)
library(class)
library(rpart)
library(randomForest)
library(reshape)
library(kknn)
library(caret)
library(rpart.plot)
library(vcd)
library(PerformanceAnalytics)
library(factoextra)
library(FactoMineR)
library(carData)
library(car)
library(plyr)

#BBDD IRIS
head(iris)
dim(iris)
unique(iris$Species)
irisScale = scale(iris[,-5])



# determinar numero Optimo k (cluster)
#Elbow
fviz_nbclust(iris[,-5], kmeans, method = "wss") +
  geom_vline(xintercept = 2, linetype = 2)

# Average silhouette
fviz_nbclust(iris[,-5], kmeans, method = "silhouette")

### Gap statistic
fviz_nbclust(irisScale, kmeans, method = "gap_stat")


## MODELO KMEANS
fitK <- kmeans(iris[,-5], 3) ## Genera Moldelo ML no supervisado Kmeans/Identificar clases de las especies con valores numericos para un K=3
iris$cluster<-fitK$cluster ## agrega la columna cluster a la BBDD IRIS
fviz_cluster(fitK, data = iris[,-c(5,6)],geom = c("point")) ## dibuja los clusters indentificados para K=3



##Seleccionar variables - columnas, para analisis descriptivo de las variable de entrada
bbdd<-select(iris,1:4) 

# ESTADISTICA DESCRIPTIVA PARA VARIABLES DE ENTRADA
summary(bbdd) ## entrega descripcion estadistica de las variables de entrada
boxplot(bbdd,col = rainbow(ncol(trees)),las = 2, xlab = "", ylab = "") ## dibuja summary junto a outlayers para variables de entrada

#CORRELACION ML no supervisado, solo variables de entrada
cor(bbdd) ## entrega correlacion de las variables de entrada
Tabla_Corr <- chart.Correlation(bbdd,method = "pearson", plot=FALSE) ## dibuja correlacion de las variables de entrada


# ESTADISTICA DESCRIPTIVA PARA VARIABLES DE ENTRADA Y VARIABLE DE DECISION (VARIABLE DE SALIDA)
bbdd1 <- select(iris,6) ##Seleccionar variable - columnas, para analisis descriptivo de la variable de decision
summary(bbdd1) ## entrega descripcion estadistica de la variable de decision

#CORRELACION ML supervisado varables de entrada respecto a variable de decision
bbdd2 <- select(iris,1:4,6) ##Seleccionar variable - columnas, para analisis descriptivo de la variable de decision y variables de entrada
summary(bbdd2) ## entrega descripcion estadistica de la variable de decision y variables de entrada
boxplot(bbdd2,col = rainbow(ncol(trees)),las = 2, xlab = "", ylab = "") ## dibuja summary junto a outlayers para variables de entrada y variable de decision
cor(bbdd2) ## entrega correlacion de las variables de entrada y valiable de decision
Tabla_Corr <- chart.Correlation(bbdd2,method = "pearson", plot=FALSE) ## dibuja correlacion de las variables de entrada y variable de decision


##MACHINE LEARNIN NO SUPERVISADO

## PREDICCIONES / ACCURACY
table(Obs =iris$Species,Pred=iris$cluster) ## Predicciones, se puede sacar accuracy
iris$cluster<-factor(iris$cluster) ## tabla visual de las predicciones
iris$clus<-mapvalues(iris$cluster,c("1","2","3"),c("setosa","versicolor" ,"virginica")) ##Categoriza variables de decision str 
caret::confusionMatrix(iris$Species,iris$clus) ## entrega resumen del modelado, matriz de confusi?n y accuracy
Indicadores_KMEANS <- confusionMatrix(iris$Species,iris$clus)
Indicadores_KMEANS


##MACHINE LEARNING SUPERVISADO
bbdd3 <- select(iris,1:4,7) ##Seleccionar variable - columnas, para analisis de clasificacion/prediccion, donde se inlcuye columna 7 que est? como factor

##Entrenamiento y prueba 
set.seed(123)
training.samples <- bbdd3$clus %>% 
  createDataPartition(p = 0.8, list = FALSE)
ta.train <- bbdd3[training.samples, ]
ta.test <- bbdd3[-training.samples, ]

####### Modelo KNN ######

##Modelo KNN con datos de entrenamiento de tasa de aprobacion
knn_ta<-train.kknn(`clus` ~ .,data=ta.train,kmax=10)

##Prediccion del modelo KNN con datos de prueba de tasa de aprobacion
pred_knn_ta <-predict(knn_ta, newdata = ta.test)
pred_knn_ta


## DOCUMENTAR Y LO MISMO ABAJO
Indicadores_KNN<-confusionMatrix(ta.test$`clus`,pred_knn_ta)
Indicadores_KNN

##Matriz de confusion del modelo KNN con datos de validacion tasa de aprobacion
matriz_confusion_ta_knn <- table(ta.test$`clus`, pred_knn_ta)



####### Modelo SVM ######

##Modelo SVM con datos de entrenamiento de tasa de aprobacion
svm_ta<-svm(`clus`~.,data=ta.train,kernel="radial",type = "C-classification")

##Prediccion del modelo SVM con datos de prueba de tasa de aprobacion
pred_svm_ta <-predict(svm_ta, newdata = ta.test)

Indicadores_SVM<-confusionMatrix(ta.test$`clus`,pred_svm_ta)
Indicadores_SVM

##Matriz de confusion del modelo SVM con datos de validacion tasa de aprobacion
matriz_confusion_ta_svm <- table(ta.test$`clus`, pred_svm_ta)




####### Modelo DT ######

##Modelo DT con datos de entrenamiento de tasa de aprobacion
dt_ta <- rpart(`clus` ~ ., data = ta.train)

##Prediccion del modelo DT con datos de prueba de tasa de aprobacion
pred_dt_ta <-predict(dt_ta, newdata = ta.test, type = 'class')

Indicadores_DT<-confusionMatrix(ta.test$`clus`,pred_dt_ta)
Indicadores_DT

##Matriz de confusion del modelo DT con datos de validacion tasa de aprobacion
matriz_confusion_ta_dt <- table(ta.test$clus, pred_dt_ta)




####### Modelo NB ######

##Modelo NB con datos de entrenamiento de tasa de aprobacion
nb_ta<-naiveBayes(`clus`  ~ ., data = ta.train)

##Prediccion del modelo NB con datos de prueba de tasa de aprobacion
pred_nb_ta <-predict(nb_ta, newdata = ta.test)
Indicadores_NB<-confusionMatrix(ta.test$`clus`,pred_nb_ta)
Indicadores_NB

##Matriz de confusion del modelo NB con datos de validacion tasa de aprobacion
matriz_confusion_ta_nb <- table(pred_nb_ta,ta.test$`clus`)




####### Modelo RF ######

##Modelo RF con datos de entrenamiento de tasa de aprobacion
rf_ta<-randomForest(`clus` ~ .,data = ta.train,ntree = 250, na.action = na.roughfix)

##Prediccion del modelo RF con datos de prueba de tasa de aprobacion
pred_rf_ta <-predict(rf_ta, newdata = ta.test)
Indicadores_RF<-confusionMatrix(ta.test$`clus`,pred_rf_ta)
Indicadores_RF

##Matriz de confusion del modelo RF con datos de validacion tasa de aprobacion
matriz_confusion_ta_rf <- table(ta.test$`clus`, pred_rf_ta)




# COMPARACION ACCURACY

Resumen<-data.frame(KEANS=Indicadores_KMEANS$overall,SVM=Indicadores_SVM$overall,KNN=Indicadores_KNN$overall,
                    NB=Indicadores_NB$overall,DT=Indicadores_DT$overall,RF=Indicadores_RF$overall)
round(Resumen*100,2)





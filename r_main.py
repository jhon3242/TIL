myds <- data.frame(state.x77)
tsne <- Rtsne(X = myds, dim =2, perplexity=15)
mydt <- data.frame(tsne$Y)

ggplot(mydt, aes(x=X1, y=X2)) +
  geom_point(size=2)
tsne <- Rtsne(X = myds, dim = 3, perplexity=15)
mydt <- data.frame(tsne$Y)
scatter3d(x=mydt$X1, y=mydt$X2, z=mydt$X3)

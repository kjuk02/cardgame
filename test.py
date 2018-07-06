import tensorflow as tf
import matplotlib.pyplot as plt
import numpy as np

from tensorflow.examples.tutorials.mnist import input_data


# node1 = tf.constant(3.0, tf.float32)
# node2 = tf.constant(4.0)
# node3 = tf.add(node1, node2)
#
# sess = tf.Session()
# print("sess.run(node1, node2)",sess.run([node1, node2]))
# print("sess.run(node3): ",sess.run(node3))
#
# a = tf.placeholder(tf.float32)
# b = tf.placeholder(tf.float32)
# adder_node = a + b
# sess = tf.Session()
#
# print(sess.run(adder_node,  feed_dict={a: 3, b: 4.5}))
# print(sess.run(adder_node, feed_dict={a: [1,3],b: [2,4]}))
#-------------------------------------------------------------

#
# x_train = [1, 2, 3]
# y_train = [1, 2, 3]
#
# w = tf.Variable(tf.random_normal([1]), name='weight')
# b = tf.Variable(tf.random_normal([1]), name='bias')
#
# hypothesis = x_train * w + b
#
# cost = tf.reduce_mean(tf.square(hypothesis - y_train))
#
# optimizer = tf.train.GradientDescentOptimizer(learning_rate=0.01)
# train = optimizer.minimize(cost)
# sess = tf.Session()
#
# sess.run(tf.global_variables_initializer())
#
#
# for step in range(1001):
#     sess.run(train)
#     print(step, sess.run(cost), sess.run(w), sess.run(b))

#---------------------------------------------------------

# X = [1, 2, 3]
# Y = [1, 2, 3]
#
# W =tf.placeholder(tf.float32)
#
# hypothesis = X * W
#
# cost = tf.reduce_mean(tf.square(hypothesis - Y))
#
# sess = tf.Session()
#
# sess.run(tf.global_variables_initializer())
#
# W_val = []
# cost_val = []
#
# for i in range(-30, 50):
#     feed_W = i * 0.1
#     curr_cost, curr_W = sess.run([cost, W], feed_dict={W: feed_W})
#     W_val.append(curr_W)
#     cost_val.append(curr_cost)
#
# plt.plot(W_val, cost_val)
# plt.show()
#-----------------------------------------------------


# x1_data = [73., 93., 89., 96., 73.]
# x2_data = [80., 88., 91., 98., 66.]
# x3_data = [75., 93., 90., 100., 70.]
# y_data = [152., 185., 180., 196., 142.]
#
# x1 = tf.placeholder(tf.float32)
# x2 = tf.placeholder(tf.float32)
# x3 = tf.placeholder(tf.float32)
#
# Y = tf.placeholder(tf.float32)
#
# w1 = tf.Variable(tf.random_normal([1]), name='weight1')
# w2 = tf.Variable(tf.random_normal([1]), name='weight2')
# w3 = tf.Variable(tf.random_normal([1]), name='weight3')
# b = tf.Variable(tf.random_normal([1]), name='bias')
#
# hypothesis = x1 * w1 + x2 * w2 + x3 * w3 + b
#
# cost = tf.reduce_mean(tf.square(hypothesis - Y))
# optimizer = tf.train.GradientDescentOptimizer(learning_rate = 1e-5)
# train = optimizer.minimize(cost)
#
# sess = tf.Session()
# sess.run(tf.global_variables_initializer())
#
# for step in range(2001):
#     cost_val, hy_val, _ = sess.run([cost, hypothesis, train],
#                         feed_dict={x1: x1_data, x2: x2_data, x3: x3_data, Y: y_data})
#     if step % 10 ==0:
#         print(step, "cost: ", cost_val, "\nPrediction:\n", hy_val)
#
# #print(sess.run(hypothesis, feed_dict={x1: [71.], x2: [88.], x3: [70],}))
#------------------------------------------------------------------------

# x_data = [[73., 80., 75.],[93., 88., 93.],
#           [89., 91., 90.],[96., 98., 100.],[73., 66., 70.]]
# y_data = [[152.], [185.], [180.], [196.], [142.]]
#
# X = tf.placeholder(tf.float32, shape=[None, 3])
# Y = tf.placeholder(tf.float32, shape=[None, 1])
#
# W = tf.Variable(tf.random_normal([3, 1]), name='weight')
# b = tf.Variable(tf.random_normal([1]), name='bias')
#
# hypothesis = tf.matmul(X, W) + b
#
# cost = tf.reduce_mean(tf.square(hypothesis - Y))
#
# optimizer = tf.train.GradientDescentOptimizer(learning_rate=1e-5)
# train = optimizer.minimize(cost)
#
# sess = tf.Session()
# sess.run(tf.global_variables_initializer())
#
# for step in range(2001):
#     cost_val, hy_val, _ = sess.run([cost, hypothesis, train],
#                                    feed_dict={X: x_data, Y: y_data})
#     if step % 10 ==0:
#         print(step, "cost", cost_val, "\nPrdiction:\n", hy_val)
#---------------------------------------------------------------------

# xy = np.loadtxt('data-01-test-score.csv', delimiter=',', dtype=np.float32)
# x_data = xy[:, 0:-1]
# y_data = xy[:, [-1]]
#
# print(x_data.shape, x_data, len(x_data))
# print(y_data.shape, y_data)
#
# X = tf.placeholder(tf.float32, shape=[None, 3])
# Y = tf.placeholder(tf.float32, shape=[None, 1])
#
# W = tf.Variable(tf.random_normal([3, 1]), name='weight')
# b = tf.Variable(tf.random_normal([1]), name='bias')
#
# hypothesis = tf.matmul(X, W) + b
#
# cost = tf.reduce_mean(tf.square(hypothesis - Y))
#
# optimizer = tf.train.GradientDescentOptimizer(learning_rate=1e-5)
# train = optimizer.minimize(cost)
#
# sess = tf.Session()
# sess.run(tf.global_variables_initializer())
#
# for step in range(2001):
#     cost_val, hy_val, _ = sess.run([cost, hypothesis, train],
#                                    feed_dict={X: x_data, Y: y_data})
#     if step % 10 ==0:
#         print(step, "cost", cost_val, "\nPrdiction:\n", hy_val)
#
# print("Your score will be ", sess.run(hypothesis, feed_dict ={X: [[100, 70, 101]]}))
# print("Other score will be ", sess.run(hypothesis, feed_dict ={X: [[60, 70, 110], [90, 100, 80]]}))
#--------------------------------------------------------
# filename_queue = tf.train.string_input_producer(
#     ['data-01-test-score.csv', 'data-02-test-score.csv'], shuffle=False, name='filename_queue')
#
# reader = tf.TextLineReader()
# key, value = reader.read(filename_queue)
#
# # Default values, in case of empty columns. Also specifies the type of the
# # decoded result.
# record_defaults = [[0.], [0.], [0.], [0.]]
# xy = tf.decode_csv(value, record_defaults=record_defaults)
#
# # collect batches of csv in
# train_x_batch, train_y_batch = \
#     tf.train.batch([xy[0:-1], xy[-1:]], batch_size=10)
# # placeholders for a tensor that will be always fed.
# X = tf.placeholder(tf.float32, shape=[None, 3])
# Y = tf.placeholder(tf.float32, shape=[None, 1])
#
# W = tf.Variable(tf.random_normal([3, 1]), name='weight')
# b = tf.Variable(tf.random_normal([1]), name='bias')
#
# # Hypothesis
# hypothesis = tf.matmul(X, W) + b
#
# # Simplified cost/loss function
# cost = tf.reduce_mean(tf.square(hypothesis - Y))
#
# # Minimize
# optimizer = tf.train.GradientDescentOptimizer(learning_rate=1e-5)
# train = optimizer.minimize(cost)
#
# # Launch the graph in a session.
# sess = tf.Session()
# # Initializes global variables in the graph.
# sess.run(tf.global_variables_initializer())
#
# # Start populating the filename queue.
# coord = tf.train.Coordinator()
# threads = tf.train.start_queue_runners(sess=sess, coord=coord)
#
# for step in range(2001):
#     x_batch, y_batch = sess.run([train_x_batch, train_y_batch])
#     print(x_batch, "\n", y_batch)
#     cost_val, hy_val, _ = sess.run(
#         [cost, hypothesis, train], feed_dict={X: x_batch, Y: y_batch})
#     if step % 10 == 0:
#         print(step, "Cost: ", cost_val, "\nPrediction:\n", hy_val)
#
# coord.request_stop()
# coord.join(threads)
#
# # Ask my score
# print("Your score will be ",
#       sess.run(hypothesis, feed_dict={X: [[100, 70, 101]]}))
#
# print("Other scores will be ",
#       sess.run(hypothesis, feed_dict={X: [[60, 70, 110], [90, 100, 80]]}))
#-------------------------------------------------------------

# x_data = [[1, 2],[2, 3],[3, 1], [4, 3], [5, 3], [6, 2]]
# y_data = [[0],[0],[0],[1],[1],[1]]
#
# X = tf.placeholder(tf.float32, shape=[None, 2])
# Y = tf.placeholder(tf.float32, shape=[None, 1])
#
# W = tf.Variable(tf.random_normal([2,1]), name='weight')
# b = tf.Variable(tf.random_normal([1]), name='bias')
#
# hypothesis = tf.sigmoid(tf.matmul(X, W) +b)
#
# cost = -tf.reduce_mean(Y * tf.log(hypothesis) + (1 - Y) * tf.log(1 - hypothesis))
# train = tf.train.GradientDescentOptimizer(learning_rate = 0.01).minimize(cost)
#
# predicted = tf.cast(hypothesis > 0.5, dtype = tf.float32)
# accuracy = tf.reduce_mean(tf.cast(tf.equal(predicted, Y),dtype = tf.float32))
#
# with tf.Session() as sess:
#     sess.run(tf.global_variables_initializer())
#
#     for step in range(10000):
#         cost_val, _ = sess.run([cost, train], feed_dict ={X: x_data, Y:y_data})
#         if step %200 ==0:
#             print(step, cost_val)
#
#     h, c, a = sess.run([hypothesis, predicted, accuracy], feed_dict={X: x_data, Y: y_data})
#     print("\nHypothesis: ", h, "\ncorrect (Y): ", c, "\nAccuracy: ", a)
#------------------------------------------------------------------------------

# x_data = [[1, 2, 1, 1],
#           [2, 1, 3, 2],
#           [3, 1, 3, 4],
#           [4, 1, 5, 5],
#           [1, 7, 5, 5],
#           [1, 2, 5, 6],
#           [1, 6, 6, 6],
#           [1, 7, 7, 7]]
#
# y_data = [[0, 0, 1],
#           [0, 0, 1],
#           [0, 0, 1],
#           [0, 1, 0],
#           [0, 1, 0],
#           [0, 1, 0],
#           [1, 0, 0],
#           [1, 0, 0]]
#
# X = tf.placeholder("float", [None, 4])
# Y = tf.placeholder("float", [None, 3])
# nb_classes =3
#
# W = tf.Variable(tf.random_normal([4, nb_classes]), name ='weight')
# b = tf.Variable(tf.random_normal([nb_classes]), name='bias')
#
# hypothesis = tf.nn.softmax(tf.matmul(X, W) + b)
#
# cost = tf.reduce_mean(-tf.reduce_sum(Y * tf.log(hypothesis), axis=1))
#
# optimizer = tf.train.GradientDescentOptimizer(learning_rate= 0.1).minimize(cost)
#
# with tf.Session() as sess:
#     sess.run(tf.global_variables_initializer())
#
#     for step in range(2001):
#         sess.run(optimizer, feed_dict={X: x_data, Y:y_data})
#         if step % 200 == 0:
#             print(step, sess.run(cost, feed_dict={X: x_data, Y: y_data}))
#
#     print('-------------------')
#
#     a = sess.run(hypothesis, feed_dict={X:[[1, 11, 7 ,9]]})
#
#     print(a, sess.run(tf.argmax(a,1)))
#
#     print('-------------------')
#
#     b = sess.run(hypothesis, feed_dict={X: [[1, 3, 4, 3]]})
#
#     print(b, sess.run(tf.argmax(b,1)))
#     print('-------------------')
#
#     c = sess.run(hypothesis, feed_dict={X: [[1, 1, 0, 1]]})
#     print(c, sess.run(tf.argmax(c,1)))
#
#     print('-------------------')
#
#     all = sess.run(hypothesis, feed_dict= { X:[[1, 11, 7, 9], [1, 3, 4, 3], [1, 1, 0, 1]]})
#
#     print(all, sess.run(tf.argmax(all, 1)))
#
# x_data = np.array([[0, 0],[0, 1], [1, 0],[1, 1]], dtype=np.float32)
# y_data = np.array([[0], [1], [1], [0]], dtype=np.float32)
#
# X = tf.placeholder(tf.float32)
# Y = tf.placeholder(tf.float32)
# W = tf.Variable(tf.random_normal([2, 1], name='weight'))
# b = tf.Variable(tf.random_normal([1]), name='bias')
#
# hypothesis = tf.sigmoid(tf.matmul(X, W) + b)
#
# cost = -tf.reduce_mean(Y * tf.log(hypothesis) + (1 - Y) * tf.log(1-hypothesis))
# train = tf.train.GradientDescentOptimizer(learning_rate=0.1).minimize(cost)
#
# predicted = tf.cast(hypothesis > 0.5, dtype=tf.float32)
# accuracy = tf.reduce_mean(tf.cast(tf.equal(predicted, Y), dtype=tf.float32))
#
# with tf.Session() as sess:
#     sess.run(tf.global_variables_initializer())
#
#     for step in range(10001):
#         sess.run(train, feed_dict={X: x_data, Y: y_data})
#         if step % 100 ==0:
#             print(step, sess.run(cost, feed_dict={X: x_data, Y: y_data}),sess.run(W))
#
#     h, c, a =sess.run([hypothesis, predicted, accuracy], feed_dict={X: x_data, Y: y_data})
#     print("\nHypothesis: ", h, "\nCorrect: ", c,"\nAccuracy: ",a)
#
#--------------------------------------------------------------------------------
#
# sess = tf.InteractiveSession()
# image = np.array([[[[1], [2], [3]],
#                    [[4], [5], [6]],
#                    [[7], [8], [9]]]], dtype=np.float32)
# print(image.shape)
# plt.imshow(image.reshape(3,3), cmap='Greys')
# plt.show()

# from tensorflow.examples.tutorials.mnist import input_data
#
# tf.set_random_seed(777)  # reproducibility
#
# mnist = input_data.read_data_sets("MNIST_data/", one_hot=True)
# # Check out https://www.tensorflow.org/get_started/mnist/beginners for
# # more information about the mnist dataset
#
# # hyper parameters
# learning_rate = 0.001
# training_epochs = 20
# batch_size = 100
#
#
# class Model:
#
#     def __init__(self, sess, name):
#         self.sess = sess
#         self.name = name
#         self._build_net()
#
#     def _build_net(self):
#         with tf.variable_scope(self.name):
#             # dropout (keep_prob) rate  0.7~0.5 on training, but should be 1
#             # for testing
#             self.training = tf.placeholder(tf.bool)
#
#             # input place holders
#             self.X = tf.placeholder(tf.float32, [None, 784])
#
#             # img 28x28x1 (black/white), Input Layer
#             X_img = tf.reshape(self.X, [-1, 28, 28, 1])
#             self.Y = tf.placeholder(tf.float32, [None, 10])
#
#             # Convolutional Layer #1
#             conv1 = tf.layers.conv2d(inputs=X_img, filters=32, kernel_size=[3, 3],
#                                      padding="SAME", activation=tf.nn.relu)
#             # Pooling Layer #1
#             pool1 = tf.layers.max_pooling2d(inputs=conv1, pool_size=[2, 2],
#                                             padding="SAME", strides=2)
#             dropout1 = tf.layers.dropout(inputs=pool1,
#                                          rate=0.3, training=self.training)
#
#             # Convolutional Layer #2 and Pooling Layer #2
#             conv2 = tf.layers.conv2d(inputs=dropout1, filters=64, kernel_size=[3, 3],
#                                      padding="SAME", activation=tf.nn.relu)
#             pool2 = tf.layers.max_pooling2d(inputs=conv2, pool_size=[2, 2],
#                                             padding="SAME", strides=2)
#             dropout2 = tf.layers.dropout(inputs=pool2,
#                                          rate=0.3, training=self.training)
#
#             # Convolutional Layer #3 and Pooling Layer #3
#             conv3 = tf.layers.conv2d(inputs=dropout2, filters=128, kernel_size=[3, 3],
#                                      padding="SAME", activation=tf.nn.relu)
#             pool3 = tf.layers.max_pooling2d(inputs=conv3, pool_size=[2, 2],
#                                             padding="SAME", strides=2)
#             dropout3 = tf.layers.dropout(inputs=pool3,
#                                          rate=0.3, training=self.training)
#
#             # Dense Layer with Relu
#             flat = tf.reshape(dropout3, [-1, 128 * 4 * 4])
#             dense4 = tf.layers.dense(inputs=flat,
#                                      units=625, activation=tf.nn.relu)
#             dropout4 = tf.layers.dropout(inputs=dense4,
#                                          rate=0.5, training=self.training)
#
#             # Logits (no activation) Layer: L5 Final FC 625 inputs -> 10 outputs
#             self.logits = tf.layers.dense(inputs=dropout4, units=10)
#
#         # define cost/loss & optimizer
#         self.cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(
#             logits=self.logits, labels=self.Y))
#         self.optimizer = tf.train.AdamOptimizer(
#             learning_rate=learning_rate).minimize(self.cost)
#
#         correct_prediction = tf.equal(
#             tf.argmax(self.logits, 1), tf.argmax(self.Y, 1))
#         self.accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))
#
#     def predict(self, x_test, training=False):
#         return self.sess.run(self.logits,
#                              feed_dict={self.X: x_test, self.training: training})
#
#     def get_accuracy(self, x_test, y_test, training=False):
#         return self.sess.run(self.accuracy,
#                              feed_dict={self.X: x_test,
#                                         self.Y: y_test, self.training: training})
#
#     def train(self, x_data, y_data, training=True):
#         return self.sess.run([self.cost, self.optimizer], feed_dict={
#             self.X: x_data, self.Y: y_data, self.training: training})
#
# # initialize
# sess = tf.Session()
#
# models = []
# num_models = 2
# for m in range(num_models):
#     models.append(Model(sess, "model" + str(m)))
#
# sess.run(tf.global_variables_initializer())
#
# print('Learning Started!')
#
# # train my model
# for epoch in range(training_epochs):
#     avg_cost_list = np.zeros(len(models))
#     total_batch = int(mnist.train.num_examples / batch_size)
#     for i in range(total_batch):
#         batch_xs, batch_ys = mnist.train.next_batch(batch_size)
#
#         # train each model
#         for m_idx, m in enumerate(models):
#             c, _ = m.train(batch_xs, batch_ys)
#             avg_cost_list[m_idx] += c / total_batch
#
#     print('Epoch:', '%04d' % (epoch + 1), 'cost =', avg_cost_list)
#
# print('Learning Finished!')
#
# # Test model and check accuracy
# test_size = len(mnist.test.labels)
# predictions = np.zeros([test_size, 10])
# for m_idx, m in enumerate(models):
#     print(m_idx, 'Accuracy:', m.get_accuracy(
#         mnist.test.images, mnist.test.labels))
#     p = m.predict(mnist.test.images)
#     predictions += p
#
# ensemble_correct_prediction = tf.equal(
#     tf.argmax(predictions, 1), tf.argmax(mnist.test.labels, 1))
# ensemble_accuracy = tf.reduce_mean(
#     tf.cast(ensemble_correct_prediction, tf.float32))
# print('Ensemble accuracy:', sess.run(ensemble_accuracy))
#---------------------------------------------------------------------


# tf.set_random_seed(777)
#
# learning_rate = 0.1
#
# x_data = [[0, 0],
#           [0, 1],
#           [1, 0],
#           [1, 1]]
# y_data = [[0],
#           [1],
#           [1],
#           [0]]
#
# x_data = np.array(x_data, dtype=np.float32)
# y_data = np.array(y_data, dtype=np.float32)
#
# X = tf.placeholder(tf.float32, [None, 2])
# Y = tf.placeholder(tf.float32, [None, 1])
#
# W1 = tf.Variable(tf.random_normal([2, 10]), name='weight1')
# b1 = tf.Variable(tf.random_normal([10]), name='bias1')
# layer1 = tf.sigmoid(tf.matmul(X, W1) + b1)
#
# W2 = tf.Variable(tf.random_normal([10, 10]), name='weight2')
# b2 = tf.Variable(tf.random_normal([10]), name='bias2')
# layer2 = tf.sigmoid(tf.matmul(layer1, W2) + b2)
#
# W3 = tf.Variable(tf.random_normal([10, 10]), name='weight3')
# b3 = tf.Variable(tf.random_normal([10]), name='bias3')
# layer3 = tf.sigmoid(tf.matmul(layer2, W3) + b3)
#
# W4 = tf.Variable(tf.random_normal([10, 1]), name='weight3')
# b4 = tf.Variable(tf.random_normal([1]), name='bias4')
# hypothesis = tf.sigmoid(tf.matmul(layer3, W4) + b4)
#
# cost = -tf.reduce_mean(Y * tf.log(hypothesis) + (1-Y) * tf.log(1 - hypothesis))
#
# train = tf.train.GradientDescentOptimizer(learning_rate = learning_rate).minimize(cost)
#
# predicted = tf.cast(hypothesis > 0.5, dtype=tf.float32)
# accuracy = tf.reduce_mean(tf.cast(tf.equal(predicted, Y), dtype=tf.float32))
#
# with tf.Session() as sess:
#     sess.run(tf.global_variables_initializer())
#
#     for step in range(10001):
#         sess.run(train, feed_dict={X: x_data, Y: y_data})
#         if step % 100 ==0:
#             print(step, sess.run(cost, feed_dict={X: x_data, Y: y_data}), sess.run([W1, W2]))
#     h, c, a = sess.run([hypothesis, predicted, accuracy], feed_dict={X:x_data, Y:y_data})
#
#     print("\nHypothesis: ", h, "\nCorrect: ", c, "\nAccuracy: ", a)
#---------------------------------------------------------------
#
# import tensorflow as tf
# import random
# # import matplotlib.pyplot as plt
# from tensorflow.examples.tutorials.mnist import input_data
# tf.set_random_seed(777)  # reproducibility
#
# mnist = input_data.read_data_sets("MNIST_data/", one_hot=True)
# # Check out https://www.tensorflow.org/get_started/mnist/beginners for
# # more information about the mnist dataset
#
# # parameters
# learning_rate = 0.001
# training_epochs = 15
# batch_size = 100
#
# # input place holders
# X = tf.placeholder(tf.float32, [None, 784])
# Y = tf.placeholder(tf.float32, [None, 10])
#
# # weights & bias for nn layers
# W = tf.Variable(tf.random_normal([784, 10]))
# b = tf.Variable(tf.random_normal([10]))
#
# hypothesis = tf.matmul(X, W) + b
#
# # define cost/loss & optimizer
# cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(
#     logits=hypothesis, labels=Y))
# optimizer = tf.train.AdamOptimizer(learning_rate=learning_rate).minimize(cost)
#
# # initialize
# sess = tf.Session()
# sess.run(tf.global_variables_initializer())
#
# # train my model
# for epoch in range(training_epochs):
#     avg_cost = 0
#     total_batch = int(mnist.train.num_examples / batch_size)
#
#     for i in range(total_batch):
#         batch_xs, batch_ys = mnist.train.next_batch(batch_size)
#         feed_dict = {X: batch_xs, Y: batch_ys}
#         c, _ = sess.run([cost, optimizer], feed_dict=feed_dict)
#         avg_cost += c / total_batch
#
#     print('Epoch:', '%04d' % (epoch + 1), 'cost =', '{:.9f}'.format(avg_cost))
#
# print('Learning Finished!')
#
# # Test model and check accuracy
# correct_prediction = tf.equal(tf.argmax(tf.nn.softmax(hypothesis), 1), tf.argmax(Y, 1))
# accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))
# print('Accuracy:', sess.run(accuracy, feed_dict={
#       X: mnist.test.images, Y: mnist.test.labels}))
#
# # Get one and predict
# r = random.randint(0, mnist.test.num_examples - 1)
# print("Label: ", sess.run(tf.argmax(mnist.test.labels[r:r + 1], 1)))
# print("Prediction: ", sess.run(
#     tf.argmax(hypothesis, 1), feed_dict={X: mnist.test.images[r:r + 1]}))

import tensorflow as tf
import random
# import matplotlib.pyplot as plt

from tensorflow.examples.tutorials.mnist import input_data

tf.set_random_seed(777)  # reproducibility

mnist = input_data.read_data_sets("MNIST_data/", one_hot=True)
# Check out https://www.tensorflow.org/get_started/mnist/beginners for
# more information about the mnist dataset

# hyper parameters
learning_rate = 0.001
training_epochs = 1
batch_size = 100

# input place holders
X = tf.placeholder(tf.float32, [None, 784])
X_img = tf.reshape(X, [-1, 28, 28, 1])   # img 28x28x1 (black/white)
Y = tf.placeholder(tf.float32, [None, 10])

# L1 ImgIn shape=(?, 28, 28, 1)
W1 = tf.Variable(tf.random_normal([3, 3, 1, 32], stddev=0.01)) #가중치 & 필터 정의
#    Conv     -> (?, 28, 28, 32)
#    Pool     -> (?, 14, 14, 32)
L1 = tf.nn.conv2d(X_img, W1, strides=[1, 1, 1, 1], padding='SAME') #채워주기
L1 = tf.nn.relu(L1)
L1 = tf.nn.max_pool(L1, ksize=[1, 2, 2, 1],
                    strides=[1, 2, 2, 1], padding='SAME')

# L2 ImgIn shape=(?, 14, 14, 32)
W2 = tf.Variable(tf.random_normal([3, 3, 32, 64], stddev=0.01))
#    Conv      ->(?, 14, 14, 64)
#    Pool      ->(?, 7, 7, 64)
L2 = tf.nn.conv2d(L1, W2, strides=[1, 1, 1, 1], padding='SAME')
L2 = tf.nn.relu(L2)
L2 = tf.nn.max_pool(L2, ksize=[1, 2, 2, 1],
                    strides=[1, 2, 2, 1], padding='SAME')
L2_flat = tf.reshape(L2, [-1, 7 * 7 * 64])

# Final FC 7x7x64 inputs -> 10 outputs
W3 = tf.get_variable("W3", shape=[7 * 7 * 64, 10],
                     initializer=tf.contrib.layers.xavier_initializer())
b = tf.Variable(tf.random_normal([10]))
logits = tf.matmul(L2_flat, W3) + b

# define cost/loss & optimizer
cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(
    logits=logits, labels=Y))
optimizer = tf.train.AdamOptimizer(learning_rate=learning_rate).minimize(cost)

# initialize
sess = tf.Session()
sess.run(tf.global_variables_initializer())

# train my model
print('Learning started. It takes sometime.')
for epoch in range(training_epochs):
    avg_cost = 0
    total_batch = int(mnist.train.num_examples / batch_size)

    for i in range(total_batch):
        batch_xs, batch_ys = mnist.train.next_batch(batch_size)
        feed_dict = {X: batch_xs, Y: batch_ys}
        c, _ = sess.run([cost, optimizer], feed_dict=feed_dict)
        avg_cost += c / total_batch

    print('Epoch:', '%04d' % (epoch + 1), 'cost =', '{:.9f}'.format(avg_cost))

print('Learning Finished!')

# Test model and check accuracy
correct_prediction = tf.equal(tf.argmax(logits, 1), tf.argmax(Y, 1))
accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))
print('Accuracy:', sess.run(accuracy, feed_dict={
      X: mnist.test.images, Y: mnist.test.labels}))

# Get one and predict
r = random.randint(0, mnist.test.num_examples - 1)
print("Label: ", sess.run(tf.argmax(mnist.test.labels[r:r + 1], 1)))
print("Prediction: ", sess.run(
    tf.argmax(logits, 1), feed_dict={X: mnist.test.images[r:r + 1]}))
print(len(mnist.test.images[r:r + 1][0]))

# plt.imshow(mnist.test.images[r:r + 1].
#           reshape(28, 28), cmap='Greys', interpolation='nearest')
# plt.show()
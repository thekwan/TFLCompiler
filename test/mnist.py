import tensorflow as tf

print(tf.__version__)

# model define
model = tf.keras.Sequential([
    tf.keras.layers.Flatten(input_shape=(28,28)),
    tf.keras.layers.Dense(128, activation=None),
    tf.keras.layers.Dense(10)
    ])

model.summary()

# convert tensorflow model to TFLite model
converter = tf.lite.TFLiteConverter.from_keras_model(model)
tflite_model = converter.convert()

# Save the model
with open('utest1.tflite', 'wb') as f:
    f.write(tflite_model)

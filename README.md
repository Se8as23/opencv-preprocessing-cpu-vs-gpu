# Preprocesamiento de Imágenes con OpenCV: CPU vs GPU

Este proyecto demuestra técnicas de preprocesamiento de imágenes utilizando OpenCV, comparando el rendimiento y los resultados de las implementaciones en CPU y GPU. El enfoque está en operaciones comunes de procesamiento de imágenes, incluyendo suavizado Gaussiano, operaciones morfológicas (erosión y dilatación), detección de bordes con Canny y ecualización de histograma.

## Estructura del Proyecto

```
opencv-preprocessing-cpu-vs-gpu
├── src
│   ├── main.cpp               # Punto de entrada de la aplicación
│   ├── cpu_pipeline.cpp       # Funciones de procesamiento en CPU
│   ├── cpu_pipeline.hpp       # Encabezado para funciones CPU
│   ├── gpu_pipeline.cpp       # Funciones de procesamiento en GPU
│   ├── gpu_pipeline.hpp       # Encabezado para funciones GPU
│   ├── utils.cpp              # Funciones utilitarias
│   └── utils.hpp              # Encabezado de utilidades
├── include
│   └── opencv-preprocessing-cpu-vs-gpu
│       ├── cpu_pipeline.hpp    # Interfaz pública CPU
│       ├── gpu_pipeline.hpp    # Interfaz pública GPU
│       └── utils.hpp           # Interfaz pública utilidades
├── CMakeLists.txt             # Archivo de configuración CMake
├── README.md                  # Documentación del proyecto
└── data
    └── sample_images          # Carpeta para imágenes de ejemplo
```

## Instrucciones de Instalación

1. **Instalar dependencias**: Asegúrate de tener OpenCV y CUDA instalados en tu sistema. Puedes seguir las guías oficiales de OpenCV y NVIDIA según tu plataforma.
2. **Clonar el repositorio**: Clona este repositorio en tu máquina local.
3. **Compilar el proyecto**:
   - Navega al directorio del proyecto.
   - Crea un directorio de compilación: `mkdir build && cd build`
   - Ejecuta CMake: `cmake ..`
   - Compila el proyecto: `make`

## Uso

1. Coloca tus imágenes de ejemplo en la carpeta `data/sample_images`.
2. Ejecuta la aplicación: `./opencv-preprocessing-cpu-vs-gpu`
3. La aplicación procesará las imágenes usando ambos pipelines (CPU y GPU), mostrando los resultados y métricas de rendimiento para su comparación.

## Análisis de Resultados

El proyecto busca resaltar las diferencias en tiempo de procesamiento y calidad de salida entre las implementaciones en CPU y GPU de los algoritmos de procesamiento de imágenes. Se espera observar mejoras significativas en el rendimiento al usar la GPU, especialmente con imágenes grandes u operaciones complejas.

## Conclusión

Este proyecto sirve como ejemplo práctico de cómo aprovechar la aceleración por GPU para tareas de procesamiento de imágenes usando OpenCV. Proporciona una base para explorar y optimizar técnicas de procesamiento de imágenes en aplicaciones en tiempo real.
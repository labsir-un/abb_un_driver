# abb_un_driver
Disclaimer: Este código es basado en los repositorios a los que se hace referencia durante este README. 

Para el control de los ABB con ROS, existen dos grandes métodos de comunicación. Ambos desarrollados por **ros_industrial** y principalmente testeados en **melodic**. 

* **abb_driver:** Comunicación via custom sockets. Se abre un web socket desde el controlador con RAPID, y desde el PC, via PC_interface accedemos al socket para hacer el parseo de datos a nodos de ros
* **abb_robot_driver:** Usa el Robot Web Services (RWS) para sustituir los websockets, y con protocolo TCP/IP se habilita una API REST que permite lectura/escritura de los estados del motor. 
* 
### ABB Driver
Se encuentra en el [repositorio](https://github.com/ros-industrial/abb_driver). Tiene 6 archivos de RAPID (3 .mod y 3.sys) que deben ser cargados y asignados para ejecución al inicio del controlador. Estos son los encargados de construir los sockets para la comunicación 

> Para el caso de LabSIR UN, al tener un IRC5 con RW5, es la única opción para una conexión directa con el IRB desde ROS via Sockets 

#### Sockets TCP/IP
El driver monta un servidor TCP/IP en el conrolador del robot. Se requiere la opción de `PC-Interface` para que se pueda conectar via LAN con el computador 

### Getting started
#### Instalación de modulos en el controlador 

La instalación de los modulos en el pendant, la asignación de señales y la carga automática de los modulos en el controlador puede revisarse en este tutorial 

https://wiki.ros.org/abb_driver/Tutorials/InstallServer


> [!NOTE] Revisión de tutoriales
> Existen dos versiones del ABB Driver. EL ABB Driver y el ABB Robot Driver. Este ultimo requiere de los Robot Web Services (RWS) para funcionar. En nuestro caso, al no tener la licencia para optar por este modulo, se usará el antiguo ABB Driver basado en WebSockets para interactuar con el robot 


### Conexión de Red 

Para conectar ambos dispositivos (Controlador y PC), se debe conectar directamente al puerto LAN (No puerto de servicio) del controlador. Este se encuentro dentro del gabinete en la parte superior (Ver diagrama de conexión en el controlador). 

Si al hacer ping a la IP estática que aparece en el FlexPendant (System info > Controller propertis > Network Connections > Lan), no muestra una conexión exitosa, se debe modificar la interfaz de conexíon Ethernet para que se encuentre en la misma máscara de sub red y en el alcance del controlador. 

```bash
ping <robot-ip> 
```

En el caso de Macos, basta con entrar a configuraciones de red, elegir la interfaz de Ethernet usada, y cambiar a IPv4 Manual, asignando una IP similar a la del IRC5 y la misma máscara de subred. 

En la carpeta `\test` se puede ejecutar el archivo `simple_sock_conn.py`. 

```bash 
python test/simple_sock_connectoin.py <robot-ip>
```






### ABB Robot Driver 
Cuenta con 3 categorías. [Robot Driver](https://github.com/ros-industrial/abb_robot_driver)
1. [abb_rws_state_publisher](https://github.com/ros-industrial/abb_robot_driver/blob/master/abb_rws_state_publisher) Extrae los datos del robot ABB y los publica en ROS 
2. [abb_rws_service_provider](https://github.com/ros-industrial/abb_robot_driver/tree/master/abb_rws_service_provider) Levanta service servers, para interactuar con el controlador. 
3. [abb_egm_hardware_interface](https://github.com/ros-industrial/abb_robot_driver/blob/master/abb_egm_hardware_interface) Uso avanzado de control de HW a bajo nivel con nodos de ROS.

El RWS es un add-in del Robotware (RW). Para el controlador IRC5, debe actualizarse a RW > 6 para poder habilitar el RWS y conectar con el driver en ROS. Por defecto se usa el **puerto 80**. Para hacer las pruebas, basta con instalar la dependencia indicadas en el `abb_robot_driver` repo. 

Podemos importar todos la paquetes de ROS del repo con le siguiente comando en **vcs**

```
	vcs import src --input \\ 
	https://github.com/ros-industrial/abb_robot_driver/raw/master/pkgs.repos
```

Actualizamos y compilamos 

```
rosdep update
rosdep install --from-paths src --ignore-src --rosdistro humble
colcon build
```

#### Prueba de conexión (RWS)
Ejecutar el launch de abb_rws_state_publiser. Argumentos base ip_robot y puerto. 

```
ros2 launch abb_rws_state_publisher robot_ip:=127.0.0.1 port:=80 
```



---
## Migración a ROS2 

> [!IMPORTANT] Migración a ROS2
> Los paquetes mostrados en ros_industrial están montados en ROS1. Tenemos que hacer cambios sustanciales en los paquetes para que sean compatibles con ROS2

 Para hacer la migración a ROS2 basarse en [guía de migracion](Los paquetes mostrados en ros_industrial están montados en ROS1. Para hacer la migración ) 






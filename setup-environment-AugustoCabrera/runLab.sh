!/bin/bash -e

echo "🔨🔨🔨🔨🔨🔨🔨🔨🔨🔨🔨🔨🔨🔨🔨🔨🔨🔨"

if [ -d "./build" ]; then
    echo "-> 🚮 Removing old build directory..."
    rm -rf ./build/*
else
    echo "-> 👷 Creating build directory..."
    mkdir build
fi

echo "🔧🔧🔧🔧🔧🔧🔧🔧🔧🔧🔧🔧🔧🔧🔧🔧🔧🔧"
echo "-> 💻 Compiling project and 📝 building..."
# cd build && cmake -GNinja .. && ninja
cd build && cmake -GNinja -DRUN_TEST=1 .. && ninja


# Luego ejecuta CMake con el generador Ninja 
#(cmake -GNinja ..), lo que configura el proyecto 
# para ser compilado usando Ninja. Finalmente, ejecuta el
# comando ninja, que se encarga de compilar el proyecto 
#según la configuración proporcionada por CMake.


echo ""
echo "-> 🏃 Running project..."
echo ""
./FirstProjectInCMake


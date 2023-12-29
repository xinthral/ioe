# IoE 
Isles of Eris
This game engine is nothing more than a passion project for me. My intentions are to one day compile this into a game. Until then, the grind for a feature rich, 
highly modulated, but easily customizable game engine is more than an over-reach however I am undeterred. Taking my lumps along the way, we press on....more to come.

#### Documentation in HTML format: 
Using Doxygen document generation, you can make a library of web browsable documents detailing the entirety of the project.

```bash
make doc
```

#### Core Engine, vrooom: 
```bash
make engine 
```

#### AudioSuite Allows for sound testing
```bash
make audio
./mixer.exe -h
```

#### CLISuite Interfacing with that Line Command
```bash
make cli 
./engine.exe -h
```

#### TestSuite and debuggers delight:
```bash
make test
./tester.exe -h
```

#### HelpSuite, thar be treasure: 
```bash
make help
./helper.exe -h
```

# Conceptual Overview
Creating a game engine in C++ and integrating it with a web frontend using Django involves a multi-step process. 

## Design the Game Engine:
Define the architecture of the game engine, including components such as rendering, physics, input handling, and game logic.
Implement the core functionality of the game engine in C++.

#### Create a Web API:
Develop a web API in C++ that exposes endpoints for interacting with the game engine. I could use a framework like CppRESTSDK for building RESTful APIs in C++.
The API should handle requests related to game state, player actions, etc.

#### Build a Web Frontend with Django:
Use Django to create a web application that will serve as the frontend.
Implement views, templates, and static files to create the user interface.
Use Django's ORM to interact with the database.

#### Integrate Web Frontend with C++ API:
Use AJAX or other asynchronous techniques to make requests from the frontend to the C++ API.
Handle responses and update the frontend dynamically based on the game state.

#### WebSockets for Real-Time Communication:
For real-time updates, consider using WebSockets. Django Channels is an extension that adds WebSockets support to Django.
Implement WebSockets in both the frontend and the C++ backend to enable bidirectional communication.

#### Compile C++ Code for the Web:
Use tools like Emscripten to compile your C++ code to WebAssembly (Wasm), which can be run in modern web browsers.
This step involves modifying your C++ code to work within the constraints of the web environment.

#### Deploy:
Deploy your Django application and the compiled C++ code to a web server.

#### Security Considerations:
Be aware of security risks associated with executing native code on the web. Make sure to properly sanitize inputs, validate requests, and secure your API.

#### Testing:
Thoroughly test entire system to ensure that it works correctly. This includes testing the C++ game engine, the C++ API, and the Django frontend.
Creating a game engine is a complex task, and integrating it with web technologies adds another layer of complexity. Be prepared for a learning curve, 
especially if you are new to web development or game engine development. Additionally, there may be alternative approaches and technologies that suit your 
specific requirements, so consider exploring different options based on your project's needs.
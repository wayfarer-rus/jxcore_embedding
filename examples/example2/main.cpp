#include <stdlib.h>
#include <string.h>
#include <sstream>

#if defined(_MSC_VER)
// Sleep time for Windows is 1 ms while it's 1 ns for POSIX
// Beware using this for your app. This is just to give a
// basic idea on usage
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep(x)
#endif

#include "jx.h"


void callback(JXResult *results, int argc) {
  // do nothing
}

int main(int argc, char **args) {
  char *path = args[0];
  // Call JX_Initialize only once per app

  JX_Initialize(args[0], callback);
  // Creates a new engine for the current thread
  // It's our first engine instance hence it will be the
  // parent engine for all the other engine instances.
  // If you need to destroy this engine instance, you should
  // destroy everything else first. For the sake of this sample
  // we have our first instance sitting on the main thread
  // and it will be destroyed when the app exists.
  JX_InitializeNewEngine();

  char *contents = "var http = require('http'); \nhttp.createServer(function (req, res) { \nres.writeHead(200, {'Content-Type': 'text/plain'}); \nres.end('Hello World'); \n}).listen(1337, '127.0.0.1'); \nconsole.log('Server running at http://127.0.0.1:1337/');";

  // define the entry file contents
  JX_DefineMainFile(contents);

  JX_StartEngine();

  // loop for possible IO
  // or JX_Loop() without usleep / while
  JX_Loop();

  JX_StopEngine();
}

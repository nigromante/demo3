Release (build):  

  -- build compile folders for release
    ./scripts/app-build.sh

  --  compile & run
    ./scripts/app.sh

  --  manual run
    ./build/test/test


Debug (debug):

  --  build compile folders for debug
    ./scripts/debug-build.sh

  --  compile & run
    ./scripts/debug.sh

  --  manual debug
    lldb-20 ./debug/test/test

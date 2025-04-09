def get_app() -> FastAPI:
    if is_debug:
        app = FastAPI(
            root_path="/api",
            title="K12EDU AI",
            service_name="k12edu_ai",
            description="AI service for K12 education",
            version="0.0.1",
            contact={"name": "XuanYou-Lin(TsukiSama9292)", "email": "tsukisama9292@gmail.com"},
            openapi_tags=[
                {"name": "account", "description": "Account API"},
                {"name": "chat", "description": "Chat API"},
                {"name": "heartbeat", "description": "Heartbeat API"},
            ],
            license_info={
                "name": "Copyright (c) 2024 XuanYou-Lin(TsukiSama9292). All rights reserved.",
            },
            docs_url="/docs",
            redoc_url="/redoc",
            openapi_url="/openapi.json",
            debug=True,
        )
    else:
        app = FastAPI(
            root_path="/api",
            title="K12EDU AI",
            service_name="k12edu_ai",
            description="AI service for K12 education",
            version="0.0.1",
            contact={"name": "XuanYou-Lin(TsukiSama9292)", "email": "tsukisama9292@gmail.com"},
            license_info={
                "name": "Copyright (c) 2024 XuanYou-Lin(TsukiSama9292). All rights reserved.",
            },
            docs_url=None,
            redoc_url=None,
            openapi_url=None,
            debug=False,
        )
    app.include_router(router=api_router, prefix="")
    return app